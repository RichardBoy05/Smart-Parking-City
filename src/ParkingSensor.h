/*
 *
 * This sketch implements a ParkingSensor class that utilizes an ultrasonic sensor
 * to detect the presence of vehicles in parking slots. It manages LED indicators to
 * signal parking occupancy and vacancy, with specific handling for timed parking
 * slots, including a maximum occupation time limit and LED blinking when exceeded.
 * Additionally, it updates cloud variables to reflect parking states variation.
 *
 */


#include <Time.h>
#include <NewPing.h>

class ParkingSensor {

  private:

    NewPing sonar; // ultrasonic sensor object
    String id; // identifier for the parking sensor (F1, F2, T1, T2)
    float distance = 0; // distance measured by the ultrasonic sensor
    float duration = 0; // duration of the ultrasonic pulse travel  
    int led; // LED pin number
    boolean is_led_blinking = false;

    unsigned long detection_time = 0; // time when parking is detected
    unsigned long undetection_time = 0; // time when parking becomes vacant
    unsigned long occupation_time = 0; // occupation time of the slot
    unsigned long previous_blink = 0;  // time when the LED last blinked

    const float SOUND_SPEED = 0.0343; // speed of sound in cm/microseconds
    const float PK_DISTANCE_THRESHOLD = 5.00; // threshold distance for detecting parking, in cm
    const int SLOT_DETECTION_TIME = 3000; // minimum time to update the state of a parking slot in milliseconds
    const int MAX_OCCUPATION_TIME = 20000; // maximum occupation time for timed parking slots in milliseconds
    const int LED_BLINKING_INTERVAL = 500; // LED blinking interval in milliseconds

    
  public:

     /**
     * @brief Constructor for ParkingSensor class
     * @param sensor: ultrasonic sensor object
     * @param indicator_led: pin number for LED indicator
     * @param parking_id: identifier for the parking sensor
     */

    ParkingSensor(NewPing sensor, int indicator_led, String parking_id) : sonar(sensor), led(indicator_led), id(parking_id) {}


    void detectParking() {
    
     /**
     *
     * @brief Detects the presence of a vehicle in the parking slot and updates the LED indicator accordingly.
     * 
     * This method utilizes the ultrasonic sensor to measure the distance to the nearest object.
     * If the distance is within a specified threshold for a certain duration, the LED indicator 
     * is turned on. In the same way, the LED is turned off if a slot is vacant for a certain duration.
     *
     */
      
      if (id != "F1" && id != "F2" && id != "T1" && id != "T2") { // checks if parking ID is valid
        // incorrect parking id, can't proceed with the request
        return;
      }

      duration = sonar.ping(); // duration pulse in microseconds
      distance = (duration / 2) * SOUND_SPEED; // formula to calculate the distance from the sensor (cm)

      if (distance > 0 && distance < PK_DISTANCE_THRESHOLD) { // vehicle detected
        
        if (detection_time == 0) {
          detection_time = millis(); // records the time when parking is detected
        }

        if (occupation_time != 0) { // checks for max occupation time
          checkMaxOccupationTime();
        }

        undetection_time = 0; // if something is detected, the undetection time is set back to 0
        
        if (millis() - detection_time >= SLOT_DETECTION_TIME) { // parking occupied for SLOT_DETECTION_TIME
          
          if (!is_led_blinking) {
            digitalWrite(led, HIGH); // turns on the LED
          }
          checkMaxOccupationTime();
          updateCloudVariable(true);
        }
        
      } else {
        
        if (undetection_time == 0) { // no vehicle detected
          undetection_time = millis(); // records the time when parking becomes vacant
        }

        if (occupation_time != 0) { // checks for max occupation time
          checkMaxOccupationTime();
        } else {
          is_led_blinking = false;
        }

        detection_time = 0; // if nothing is detected, the detection time is set back to 0
        
        if (millis() - undetection_time >= SLOT_DETECTION_TIME) { // parking vacant for SLOT_DETECTION_TIME
          
          if (!is_led_blinking) {
            digitalWrite(led, LOW); // turns off the LED
          }
          occupation_time = 0;
          updateCloudVariable(false);
        }
      }
    };


  private:
     
    void updateCloudVariable(boolean state) {

     /**
     *
     * Updates the cloud variable based on parking state.
     * @param state: true if parking is occupied, false otherwise.
     *
     */
      
      if (id == "F1") {
        free_parking_slot_1 = state;
        free_parking_slot_1_int = state;
      } else if (id == "F2") {
        free_parking_slot_2 = state;
        free_parking_slot_2_int = state;
      } else if (id == "T1") {
        timed_parking_slot_1 = state;
        timed_parking_slot_1_int = state;
      } else if (id == "T2") {
        timed_parking_slot_2 = state;
        timed_parking_slot_2_int = state;
      }
      
    };

    void checkMaxOccupationTime() {

     /**
     *
     * Checks if the max occupation time is exceeded for timed parking slots.
     *
     */
       
      if (id.startsWith("T")) { // checks if id starts with "T", indicating a timed parking slot
        
        time_t unix_time = ArduinoCloud.getLocalTime(); // retrieves current timestamp from the cloud
        String time_str = ctime(&unix_time);
        String day = time_str.substring(0, 3);
        int hours = time_str.substring(10, 13).toInt();

        if (day != "Sun" && hours >= 8 && hours < 20) { // checks if it's not Sunday and time is between 8 AM and 8 PM
          
          if (occupation_time == 0) {
            occupation_time = millis();
          }

          if (millis() - occupation_time > MAX_OCCUPATION_TIME) { // checks if time exceeded MAX_OCCUPATION_TIME
            is_led_blinking = true;

            if (millis() - previous_blink >= LED_BLINKING_INTERVAL) { // regulates led blinking
              previous_blink = millis();
              digitalWrite(led, !digitalRead(led)); // alternates LED state
            }
            
          } else { // resets blinking       
            is_led_blinking = false;
          }
          
        } else { // resets blinking and occupation time if conditions not met
          is_led_blinking = false;
          occupation_time = 0;
        }
        
      } else { // resets blinking and occupation time if id doesn't start with "T"    
        is_led_blinking = false;
        occupation_time = 0;
      }
    }
};