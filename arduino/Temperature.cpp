/*********************************************************************
* Temperature.cpp
*
* Copyright (C)    2019   St Peters Mbare IoT Makerspace
* 
* GitHub Link :https://github.com/st-peters-mbare-iot-makerspace/offgrid-iot-urban-farming
* This Library is free software: you can redistribute it and/or modify
* it under the terms of the GNU General Public License as published by
* the Free Software Foundation, either version 3 of the License, or
* (at your option) any later version.
*
* Description:
*
* Author  :  St Peter Mbare IoT Makerspace
* Version :  V1.0
* Date    :  2019-05-25
**********************************************************************/

#include "Temperature.h"
#include <OneWire.h>
#include "Debug.h"

Temperature::Temperature(int pin)
{
	this->oneWire = new OneWire(pin);
}

Temperature::~Temperature()
{
}


//********************************************************************************************
// function name: setup ()
// Function Description: Initializes the sensor
//********************************************************************************************
void Temperature::setup()
{
}


//********************************************************************************************
// function name: update ()
// Function Description: Update the sensor value
//********************************************************************************************
void Temperature::update()
{
	if ( millis () - tempSampleTime >= tempSampleInterval)
	{
		tempSampleTime = millis ();
		temperature = TempProcess(ReadTemperature);  // read the current temperature from the  DS18B20
		TempProcess(StartConvert);                   //after the reading,start the convert for next reading
	}
}


//********************************************************************************************
// function name: getValue ()
// Function Description: Returns the sensor data
//********************************************************************************************
double Temperature::getValue()
{
	return temperature;
}


//********************************************************************************************
// function name: TempProcess ()
// Function Description: Analyze the temperature data
//********************************************************************************************
double Temperature::TempProcess(bool ch)
{
	static byte data[12];
	static byte addr[8];
	static float TemperatureSum;
	if (!ch) {
		if (!oneWire->search(addr)) {
			Debug::println("no temperature sensors on chain, reset search!");
			oneWire->reset_search();
			return 0;
		}
		if (OneWire::crc8(addr, 7) != addr[7]) {
			Debug::println("CRC is not valid!");
			return 0;
		}
		if (addr[0] != 0x10 && addr[0] != 0x28) {
			Debug::println("Device is not recognized!");
			return 0;
		}
		oneWire->reset();
		oneWire->select(addr);
		oneWire->write(0x44, 1); // start conversion, with parasite power on at the end
	}
	else {
		byte present = oneWire->reset();
		oneWire->select(addr);
		oneWire->write(0xBE); // Read Scratchpad
		for (int i = 0; i < 9; i++) { // we need 9 bytes
			data[i] = oneWire->read();
		}
		oneWire->reset_search();
		byte MSB = data[1];
		byte LSB = data[0];
		float tempRead = ((MSB << 8) | LSB); //using two's compliment
		TemperatureSum = tempRead / 16;
	}
	return TemperatureSum;
}
