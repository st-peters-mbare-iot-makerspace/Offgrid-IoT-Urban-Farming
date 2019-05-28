/*********************************************************************
* GravityTemperature.h
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

#pragma once
#include "Sensor.h"
#include "OneWire.h"
#define StartConvert 0
#define ReadTemperature 1

class Temperature : public Sensor
{
public:
	// temperature sensor pin
	int temperaturePin;
	double temperature;

public:
	Temperature(int pin);
	~Temperature();

	// initialization
	void  setup ();

	// update the sensor data
	void  update ();

	// Get the sensor data
	double getValue();

private:

	OneWire * oneWire;
	unsigned  long tempSampleInterval = 850 ;
	unsigned  long tempSampleTime;

	// Analyze temperature data
	double TempProcess(bool ch);
};

