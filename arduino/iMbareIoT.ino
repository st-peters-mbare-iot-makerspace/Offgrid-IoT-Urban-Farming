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
* EC  : A1
* PH  : A2
* Sound: A3
* RTC : I2C
* Sound
* Water Level: D6 
* Temperature:D7
*
*Actuators
* Fish Feeder: 
*
* Author  :  St Peter Mbare IoT Makerspace
* Version :  V1.0
* Date    :  2019-05-25
**********************************************************************/

#include <SPI.h>
#include <Wire.h>
#include "Sensors.h"
#include "Rtc.h"
#include "OneWire.h"
#include "Debug.h"
#include <SoftwareSerial.h>

// clock module
Rtc rtc;

// sensor monitor
Sensors sensors;

void setup() {
	Serial.begin(9600);
	rtc.setup();
	sensors.setup();


}


//********************************************************************************************
// function name: sensors.getValueBySensorNumber (0)
// Function Description: Get the sensor's values, and the different parameters represent the acquisition of different sensor data     
// Parameters: 0 ph value  
// Parameters: 1 temperature value    
// Parameters: 3 Conductivity
// return value: returns a double type of data
//********************************************************************************************

unsigned long updateTime = 0;

void loop() {
	rtc.update();
	sensors.update();
	// ************************* Serial debugging ******************
	if(millis() - updateTime > 2000)
	{
		updateTime = millis();
		//Serial.print(F("ph= "));
		//Serial.print(sensors.getValueBySensorNumber(0));
		//Serial.print(F("  Temp= "));
		Serial.print(sensors.getValueBySensorNumber(1));
		//Serial.print(F("  Ec= "));
		//Serial.print(sensors.getValueBySensorNumber(3));
	}
}



//* ***************************** Print the relevant debugging information ************** ************ * /
// Note: Arduino M0 need to replace Serial with SerialUSB when printing debugging information

// ************************* Serial debugging ******************
//Serial.print("ph= ");
//Serial.print(sensors.getValueBySensorNumber(0));
//Serial.print("  Temp= ");
//Serial.print(sensors.getValueBySensorNumber(1));
//Serial.print("  EC= ");
//Serial.println(sensors.getValueBySensorNumber(3));
