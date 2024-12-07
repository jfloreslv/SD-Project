#include "arduino_secrets.h"
/* 
  Sketch generated by the Arduino IoT Cloud Thing "Untitled"
  https://create.arduino.cc/cloud/things/5d37b76c-41c2-46c5-b0e2-224b2ced3136 

  Arduino IoT Cloud Variables description

  The following variables are automatically generated and updated when changes are made to the Thing

  bool uvLightState;

  Variables which are marked as READ/WRITE in the Cloud Thing will also have functions
  which are called when their values are changed from the Dashboard.
  These functions are generated with the Thing and added at the end of this sketch.
*/

#include "thingProperties.h"

const int uvLightPin = 2; //Pin connected to UV Light via MOSFET gate

void setup() {
  // Initialize serial and wait for port to open:
  Serial.begin(9600);
  // This delay gives the chance to wait for a Serial Monitor without blocking if none is found
  delay(1500); 

  //Set up UV Light pin as OUTPUT
  pinMode(uvLightPin,OUTPUT);
  digitalWrite(uvLightPin,LOW); //Ensures UV Light is OFF at startup
  
  // Defined in thingProperties.h (Initialize IoT Cloud Properties)
  initProperties();

  // Connect to Arduino IoT Cloud
  ArduinoCloud.begin(ArduinoIoTPreferredConnection);

 /*  The following function allows you to obtain more information
     related to the state of network and IoT Cloud connection and errors
     the higher number the more granular information you’ll get.
     The default is 0 (only errors).
     Maximum is 4
 */
  setDebugMessageLevel(2);
  ArduinoCloud.printDebugInfo();
}

void loop() {
  ArduinoCloud.update();
  // Your code here 
  
}


/*
  Since UvLightState is READ_WRITE variable, onUvLightStateChange() is
  executed every time a new value is received from IoT Cloud.
*/
void onUvLightStateChange()  {
  // Add your code here to act upon UvLightState change
  if(uvLightState){
    // Turn ON the UV Light
    digitalWrite(uvLightPin,HIGH);
    Serial.println("UV Light is ON");
  } else {
    // Turn OFF the UV Light
    digitalWrite(uvLightPin,LOW);
    Serial.println("UV Light is OFF");
  }
    
}
