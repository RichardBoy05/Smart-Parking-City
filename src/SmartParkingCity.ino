/**
 *
 * This sketch is designed to manage a smart parking system using an Arduino board. 
 * It utilizes various sensors and components to monitor parking slot occupancy, 
 * control entry and exit gates, and manage lighting based on ambient light levels.
 * Key functionalities include:
 * - Connectivity with Arduino IoT Cloud to monitor and update parking status.
 * - Handling reconnection attempts to the cloud to ensure continuous connectivity.
 * - Detecting vehicle presence in specific parking slots using ultrasonic sensors.
 * - Regulating parking gate operation using infrared sensors and a servo motor.
 * - Automating lighting based on ambient light with a Light Dependent Resistor (LDR).
 * - Visualizing feedback on system status on the built-in LED matrix.
 * - Storing persistent data like parked vehicle counts in EEPROM internal memory.
 *
 */


#include <Servo.h>
#include <EEPROM.h>
#include <NewPing.h>
#include "thingProperties.h"
#include "ParkingSensor.h"
#include "LedMatrixConfig.h"
#include <Arduino_LED_Matrix.h>


// ----------------- global variables ----------------- //


// connectivity

const int MAX_RETRY_ATTEMPTS = 5; // maximum reconnection attempts allowed
const int CONNECTION_CHECK_INTERVAL = 5000; // interval for checking connection status in milliseconds
int connection_retry_count = 0;
unsigned long last_connection_check_time = 0;

// built-in LED matrix

const int LED_MATRIX_HEIGHT = 8;
const int LED_MATRIX_WIDTH = 12;
ArduinoLEDMatrix matrix;

// pins

const int EXIT_GATE_SENSOR = 0;
const int ENTRY_GATE_SENSOR = 1;
const int TIMED_SLOT_SENSOR_1 = 2;
const int TIMED_SLOT_LED_1 = 3;
const int FREE_SLOT_SENSOR_2 = 4;
const int FREE_SLOT_LED_2 = 5;
const int FREE_SLOT_SENSOR_1 = 6;
const int FREE_SLOT_LED_1 = 7;
const int TIMED_SLOT_SENSOR_2 = 8;
const int TIMED_SLOT_LED_2 = 9;
const int SERVO_MOTOR = 10 ; // must be ~PWM
const int GREEN_LIGHT = 11;
const int RED_LIGHT = 12;
const int NIGHT_LAMP_1 = A2;
const int NIGHT_LAMP_2 = A3;
const int NIGHT_LAMP_3 = A4;
const int LDR = A5;

// general

const int TOTAL_PARKING_SLOTS = 9;
int total_occupied_slots;

// free and timed parking slots

const float US_SENSOR_MAX_DISTANCE = 20.00; // max distance in cm

NewPing free_sonar_1 (FREE_SLOT_SENSOR_1, FREE_SLOT_SENSOR_1, US_SENSOR_MAX_DISTANCE);
NewPing free_sonar_2 (FREE_SLOT_SENSOR_2, FREE_SLOT_SENSOR_2 ,US_SENSOR_MAX_DISTANCE);
NewPing timed_sonar_1 (TIMED_SLOT_SENSOR_1, TIMED_SLOT_SENSOR_1, US_SENSOR_MAX_DISTANCE);
NewPing timed_sonar_2 (TIMED_SLOT_SENSOR_2, TIMED_SLOT_SENSOR_2, US_SENSOR_MAX_DISTANCE);

ParkingSensor free_parking_sensor_1(free_sonar_1, FREE_SLOT_LED_1, "F1");
ParkingSensor free_parking_sensor_2(free_sonar_2, FREE_SLOT_LED_2, "F2");
ParkingSensor timed_parking_sensor_1(timed_sonar_1, TIMED_SLOT_LED_1, "T1");
ParkingSensor timed_parking_sensor_2(timed_sonar_2, TIMED_SLOT_LED_2, "T2");

// toll parking

const int GATE_DETECTION_TIME = 3000; // in milliseconds
const int TOTAL_TOLL_PARKING_SLOTS = 5;
const int SERVO_DOWN_ANGLE = 6; // adjustment for 0 degrees
const int SERVO_UP_ANGLE = 103; // adjustment for 90 degrees

unsigned long entry_detection_time = 0;
unsigned long entry_undetection_time = 0;
unsigned long exit_detection_time = 0;
unsigned long exit_undetection_time = 0;

Servo servo; // servo motor object
int servo_state = 0; // 0 (servo down), 1 (servo opened from outside), 2 (servo opened from inside)
boolean entry_gate = false;
boolean exit_gate = false;
boolean servo_ready_to_close = false;

// automatic lights

const int LDR_CALIBRATION_TIME = 5000; // in milliseconds
const int LDR_DETECTION_TIME = 2000; // in milliseconds
const float DARKNESS_THRESHOLD_FACTOR = 0.5; // threshold factor of current light level to consider it dark
float darkness_threshold;
unsigned long ldr_detection_time = 0;
unsigned long ldr_undetection_time = 0;


// ----------------- setup ----------------- //


void setup() { // runs once at the beginning

  // config

  matrix.begin(); // initializes LED matrix
  matrix.renderBitmap(setup_matrix, LED_MATRIX_HEIGHT, LED_MATRIX_WIDTH); // setup LED matrix

  initProperties(); // defined in thingProperties.h
  ArduinoCloud.begin(ArduinoIoTPreferredConnection, true); // connects to Arduino IoT Cloud
  setDebugMessageLevel(2);
  ArduinoCloud.printDebugInfo();

  // pin modes

  pinMode(NIGHT_LAMP_1, OUTPUT);
  pinMode(NIGHT_LAMP_2, OUTPUT);
  pinMode(NIGHT_LAMP_3, OUTPUT);
  pinMode(LDR, INPUT); 
  pinMode(RED_LIGHT, OUTPUT);
  pinMode(GREEN_LIGHT, OUTPUT);
  pinMode(EXIT_GATE_SENSOR, INPUT);
  pinMode(ENTRY_GATE_SENSOR, INPUT);
  pinMode(FREE_SLOT_LED_1, OUTPUT);
  pinMode(FREE_SLOT_LED_2, OUTPUT);
  pinMode(TIMED_SLOT_LED_1, OUTPUT);
  pinMode(TIMED_SLOT_LED_2, OUTPUT);

  // circuit setup

  setupAutoLights();
  setServoAngle(SERVO_DOWN_ANGLE);
  paid_parked_vehicles_count = EEPROM.read(0); // gets last value of paid parked vehicles from the internal memory
  
  digitalWrite(RED_LIGHT, LOW);
  digitalWrite(GREEN_LIGHT, HIGH);
  digitalWrite(FREE_SLOT_LED_1, LOW);
  digitalWrite(FREE_SLOT_LED_2, LOW);
  digitalWrite(TIMED_SLOT_LED_1, LOW);
  digitalWrite(TIMED_SLOT_LED_2, LOW);

  matrix.renderBitmap(running_matrix, LED_MATRIX_HEIGHT, LED_MATRIX_WIDTH); // running LED matrix
  
}


// ----------------- loop ----------------- //


void loop() { // runs indefinitely
  
  if (!connectionHandler()){ // handles Arduino IoT Cloud connectivity
    return;
  }

  updateParkingOccupationPercentage();

  autoLights();
  parkingAccessRegulator();

  free_parking_sensor_1.detectParking();
  free_parking_sensor_2.detectParking();
  timed_parking_sensor_1.detectParking();
  timed_parking_sensor_2.detectParking();

}


// ----------------- additional functions ----------------- //


boolean connectionHandler() {

 /**
 *
 * Checks if the device is connected to Arduino Cloud. If not connected,
 * it retries a limited number of times. After those retries, it stops
 * trying to reconnect to prevent indefinite code freezing.
 * 
 * @return True: connected successfully or maximum retry attempts exceeded (code can flow);
 * @return False: attempting reconnection (code temporarily blocked).
 *
 */
  
  if (connection_retry_count < MAX_RETRY_ATTEMPTS) { // stops updating after reaching max retry attempts
    ArduinoCloud.update();
  }

  unsigned long current_time = millis();
  
  if (current_time - last_connection_check_time >= CONNECTION_CHECK_INTERVAL) {
    // checks connection status at regular intervals

    last_connection_check_time = current_time;

    if (!ArduinoCloud.connected()) {
      
      if (connection_retry_count < MAX_RETRY_ATTEMPTS) {
        
        connection_retry_count++;
        matrix.renderBitmap(attempting_reconnection_matrix, LED_MATRIX_HEIGHT, LED_MATRIX_WIDTH); // attempting connection LED matrix
        
        return false; // trying to connect
      }

      matrix.renderBitmap(no_connection_matrix, LED_MATRIX_HEIGHT, LED_MATRIX_WIDTH); // attempting connection LED matrix
      
      return true; // exceeded maximum retry attempts
      
    } else {
      
      matrix.renderBitmap(running_matrix, LED_MATRIX_HEIGHT, LED_MATRIX_WIDTH); // running LED matrix
      connection_retry_count = 0; // reset retry count on successful connection
      
      return true; // successful connection
    }
    
  }
  
  return true; // no changes in connection status
}


void parkingAccessRegulator(){

 /**
 *
 * @brief Controls access to a parking area using sensor inputs and a servo motor for gate operation.
 * 
 * This function reads inputs from entry and exit gate sensors and controls the behavior of the 
 * access gate based on the detected conditions. The function manages the parking area occupancy 
 * and regulates gate operations accordingly. It utilizes timers to handle gate opening and closing 
 * events triggered by sensor detections.
 *
 */

  entry_gate = !digitalRead(ENTRY_GATE_SENSOR);
  exit_gate = !digitalRead(EXIT_GATE_SENSOR);

  if (servo_state == 0){ // bar is down

    if (paid_parked_vehicles_count >= TOTAL_TOLL_PARKING_SLOTS){ // parking area is full, red light
      if (digitalRead(GREEN_LIGHT) == HIGH){
        digitalWrite(GREEN_LIGHT, LOW);
        digitalWrite(RED_LIGHT, HIGH);
      }
    }

    if (!entry_gate && !exit_gate){ // nothing is detected
      entry_detection_time = 0;
      exit_detection_time = 0;

      if (paid_parked_vehicles_count < TOTAL_TOLL_PARKING_SLOTS){ // parking area not full, green light
        digitalWrite(GREEN_LIGHT, HIGH);
        digitalWrite(RED_LIGHT, LOW);
        return;
      }
        
    }

    if (entry_gate && exit_gate){ // if for some reason both the sensors are active, the gate is blocked the red light is activated
      entry_detection_time = 0;
      exit_detection_time = 0;
      digitalWrite(GREEN_LIGHT, LOW);
      digitalWrite(RED_LIGHT, HIGH);
      return;
    }

    if (paid_parked_vehicles_count < TOTAL_TOLL_PARKING_SLOTS){ // parking area not full, green light
      digitalWrite(GREEN_LIGHT, HIGH);
      digitalWrite(RED_LIGHT, LOW);
    }

    // ENTRY GATE DETECTION

    if (entry_gate && paid_parked_vehicles_count < TOTAL_TOLL_PARKING_SLOTS){
      exit_detection_time = 0;

      if (entry_detection_time == 0){
        entry_detection_time = millis(); // starting timer...
      }

      if  (millis() - entry_detection_time >= GATE_DETECTION_TIME){ // timer expires, servo opened from OUTSIDE
     
        setServoAngle(SERVO_UP_ANGLE);
        servo_state = 1; // sets servo state to 1
        
      }

      return;
    }

    // EXIT GATE DETECTION
    
    if (exit_gate){
      entry_detection_time = 0;
      
      if (exit_detection_time == 0){
        exit_detection_time = millis(); // starting timer...
      }

      if  (millis() - exit_detection_time >= GATE_DETECTION_TIME){ // timer expired, servo opened from INSIDE

        setServoAngle(SERVO_UP_ANGLE);
        servo_state = 2; // sets servo state to 2
      }

      return;
    }
    
  } else { // bar is up

    if (servo_state == 1){ // servo = 1 -> opened from outside -> we deal with the inside sensor

      if (exit_gate && !servo_ready_to_close) { // exit gate must be activated first
        servo_ready_to_close = true;
      }

    if (servo_ready_to_close && exit_undetection_time == 0 && !exit_gate) { // exit gate is no longer true, starting timer...
      exit_undetection_time = millis(); 
    }

    if (exit_undetection_time != 0 && millis() - exit_undetection_time >= GATE_DETECTION_TIME) { // timer expired

      servo_state = 0; // sets servo state to 0

      setServoAngle(SERVO_DOWN_ANGLE);
      
      servo_ready_to_close = false;   
      exit_undetection_time = 0;
      entry_detection_time = 0;   
      updateParkedVehiclesCount(1); // adds 1 vehicle
      
    }

  } else { // servo = 2 -> opened from inside -> we deal with the outside sensor

    if (entry_gate && !servo_ready_to_close) { // entry gate must be activated first
        servo_ready_to_close = true;
      }

    if (servo_ready_to_close && entry_undetection_time == 0 && !entry_gate) { // entry gate is no longer true, starting timer...
      entry_undetection_time = millis();
    }

    if (entry_undetection_time != 0 && millis() - entry_undetection_time >= GATE_DETECTION_TIME) { // timer expired
      
      servo_state = 0; // sets servo state to 0

      setServoAngle(SERVO_DOWN_ANGLE);
      
      servo_ready_to_close = false; 
      entry_undetection_time = 0;
      exit_detection_time = 0;
      updateParkedVehiclesCount(-1); // subtracts 1 vehicle
      
    }
      
    }   
    
  }
  
}


void setServoAngle(int angle){

 /**
 *
 * Attaches the servo motor to a specific pin, writes
 * the desired angle to position the motor, waits briefly 
 * to allow the motor to reach the desired position, and then 
 * detaches the servo to prevent jittering and reduce power consumption.
 *
 * @param angle: desired angle to set the servo motor to
 
 */
  
  servo.attach(SERVO_MOTOR);
  servo.write(angle);
  delay(50); // small delay to allow the motor positioning before detaching it
  servo.detach();
  
}

void setupAutoLights(){

 /**
 *
 * Turns off the night lights.
 * Reads the light level for LDR_CALIBRATION_TIME milliseconds,
 * gets the average value and sets the darkness_threshold accordingly.
 * NOTE: Ensure that this setup occurs in an environment representing
 * the typical expected LIGHT LEVEL; avoid executing it in darkness.
 *
 */

  digitalWrite(NIGHT_LAMP_1, LOW);
  digitalWrite(NIGHT_LAMP_2, LOW);
  digitalWrite(NIGHT_LAMP_3, LOW);

  int iterations = 0;
  int sum = 0;

  while (millis() < LDR_CALIBRATION_TIME){  
    sum += analogRead(LDR);
    iterations ++;  
  }
  
  darkness_threshold = (sum/iterations) * DARKNESS_THRESHOLD_FACTOR;
}


void autoLights(){

/**
*
* Monitors the light level using an LDR sensor and activates 
* night lamps based on whether the light level remains below
* above a defined darkness threshold for a specified duration.
*
*/

  int light = analogRead(LDR);

  if (light < darkness_threshold) { // dark
        if (ldr_detection_time == 0) {
          ldr_detection_time = millis();
        }
        ldr_undetection_time = 0;
    
        if (millis() - ldr_detection_time >= LDR_DETECTION_TIME) {
          digitalWrite(NIGHT_LAMP_1, HIGH);
          digitalWrite(NIGHT_LAMP_2, HIGH);
          digitalWrite(NIGHT_LAMP_3, HIGH);
        }
      } else { // light
    
        if (ldr_undetection_time == 0) {
          ldr_undetection_time = millis();
        }
        ldr_detection_time = 0;
        if (millis() - ldr_undetection_time >= LDR_DETECTION_TIME) {
          digitalWrite(NIGHT_LAMP_1, LOW);
          digitalWrite(NIGHT_LAMP_2, LOW);
          digitalWrite(NIGHT_LAMP_3, LOW);
        }
  }
  
}


void updateParkedVehiclesCount(int change){

 /**
 *
 * Adds or subtract 1 to the paid_parked_vehicles_count cloud variable.
 * Ensures that paid_parked_vehicles_count is always >= 0
 * Stores the value in the EEPROM internal memory.
 *
 * @param change: +-1, indicates the change of vehicles parked.
 *
 */

  if (change != 1 && change != -1){
    // vehicle change can only be equal to +-1
    return;
  }

  if (paid_parked_vehicles_count + change < 0){
    // something is wrong with the vehicles counting
    return;
  }

  paid_parked_vehicles_count += change;
  EEPROM.put(0, paid_parked_vehicles_count); // stores to memory
  
}


void updateParkingOccupationPercentage(){
  
 /**
 *
 * This function sums the counts of various occupied parking slots 
 * (free, timed, and paid) and calculates the occupation percentage 
 * based on the total number of parking slots.
 *
 */

  total_occupied_slots = free_parking_slot_1_int + free_parking_slot_2_int + timed_parking_slot_1_int + timed_parking_slot_2_int + paid_parked_vehicles_count;
  occupation_percentage = (float)total_occupied_slots / TOTAL_PARKING_SLOTS * 100;
  
}
