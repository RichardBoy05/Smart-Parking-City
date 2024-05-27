/*
 *
 * This sketch connects to a Wi-Fi network and uses the Arduino IoT Cloud to monitor and update 
 * the status of parking slots. The status includes free and timed parking slots, both in boolean and 
 * integer formats, as well as the count of paid parked vehicles and the overall occupation percentage 
 * of the parking area. Properties are defined and registered to the Arduino IoT Cloud to enable 
 * real-time monitoring and updates.
 *
 */


#include <ArduinoIoTCloud.h>
#include <Arduino_ConnectionHandler.h>

const char SSID[] = SECRET_SSID; // network SSID (name)
const char PASS[] = SECRET_OPTIONAL_PASS; // network password (use for WPA, or use as key for WEP)

bool free_parking_slot_1;
bool free_parking_slot_2;
bool timed_parking_slot_1;
bool timed_parking_slot_2;
int free_parking_slot_1_int;
int free_parking_slot_2_int;
int timed_parking_slot_1_int;
int timed_parking_slot_2_int;
int paid_parked_vehicles_count;
int occupation_percentage;

void initProperties(){

  ArduinoCloud.addProperty(free_parking_slot_1, READ, ON_CHANGE, NULL);
  ArduinoCloud.addProperty(free_parking_slot_2, READ, ON_CHANGE, NULL);
  ArduinoCloud.addProperty(timed_parking_slot_1, READ, ON_CHANGE, NULL);
  ArduinoCloud.addProperty(timed_parking_slot_2, READ, ON_CHANGE, NULL);
  ArduinoCloud.addProperty(free_parking_slot_1_int, READ, ON_CHANGE, NULL);
  ArduinoCloud.addProperty(free_parking_slot_2_int, READ, ON_CHANGE, NULL);
  ArduinoCloud.addProperty(timed_parking_slot_1_int, READ, ON_CHANGE, NULL);
  ArduinoCloud.addProperty(timed_parking_slot_2_int, READ, ON_CHANGE, NULL);
  ArduinoCloud.addProperty(paid_parked_vehicles_count, READ, ON_CHANGE, NULL);
  ArduinoCloud.addProperty(occupation_percentage, READ, ON_CHANGE, NULL);
  
}

WiFiConnectionHandler ArduinoIoTPreferredConnection(SSID, PASS);