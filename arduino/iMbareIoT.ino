/*********************************************************************
* iMbareIoT.ino
* 
* Copyright (C)    2019   St Peters Mbare IoT Makerspace
* 
* GitHub Link :https://github.com/st-peters-mbare-iot-makerspace/offgrid-iot-urban-farming
* This Library is free software: you can redistribute it and/or modify
* it under the terms of the GNU General Public License as published by
* the Free Software Foundation, either version 3 of the License, or
* (at your option) any later version.
*
*
*
* Hardware platform   : Arduino Bluno
* Sensors
* 1. PH  : A0
* 2. EC  : A1
* 3. TEMPERATURE:D7
* 4. WATER LEVEL: D8
* 5. SOUND: A2
* 
* RTC : I2C
* 
* 
* Actuators
* 1. FISH FEEDER: 
*
* Author  :  St Peter Mbare IoT Makerspace
* Version :  V1.0
* Date    :  2019-05-25
**********************************************************************/

#include <SPI.h>
#include <Wire.h>

#include "Sensors.h"
#include "FishFeeder.h"

#include "Rtc.h"
#include "OneWire.h"
#include "Debug.h"
#include <SoftwareSerial.h>

// clock module
Rtc rtc;
double ph;
double temperature;
double ec;
bool waterLevel;
int sound;
String values;
// Collection of all sensors
Sensors sensors;
FishFeeder fishFeeder;
GravityRtc gravityRtc;
void setup() {
  
  gravityRtc.setup();
  gravityRtc.adjustRtc(F(__DATE__), F(__TIME__));
	
	rtc.setup();
  
	sensors.setup(); //Run setup oeprations for all sensors
  
  Serial.begin(112500);

}


//********************************************************************************************
// function name: sensors.getValueBySensorNumber (0)
// Function Description: Get the sensor's values, and the different parameters represent the acquisition of different sensor data     
// Parameters: 0 ph value  
// Parameters: 1 temperature value    
// Parameters: 2 Conductivity
// Parameters: 3 Water Level
// Parameters: 4 Sound
// return value: returns a double type of data
//********************************************************************************************

unsigned long updateTime = 0;

void loop() {
	
	fishFeeder.feedFish();
	rtc.update();
	sensors.update(); //Read and update measurements for all sensors 
	// ************************* Serial debugging ******************
	if(millis() - updateTime > 2000)
	{
		updateTime = millis();
		ph=sensors.getValueBySensorNumber(0);
		temperature=sensors.getValueBySensorNumber(1);
		ec=sensors.getValueBySensorNumber(2);
    waterLevel=sensors.getValueBySensorNumber(3);
    sound=sensors.getValueBySensorNumber(4);
    /*
      
    Serial.print("pH...");
    Serial.println(ph);
    Serial.print("Temperature...");
    Serial.println(temperature);
    Serial.print("EC...");
    Serial.println(ec);
    Serial.print("WaterLevel...");
    Serial.println(waterLevel);
    Serial.print("Sound...");
    Serial.println(sound);*/

    waterLevel=!waterLevel;
    values=String(ph)+" "+String(temperature)+" "+String(ec)+" "+String(waterLevel)+" "+String("1");
    Serial.println(values);
    delay(500);
	}
  //CHECK FISH FEED SCHEDULES AND FEED NOT ACTUATE ALL

  
}
