/*********************************************************************
* Ph.h
*
* Copyright (C)    2019   St Peters Mbare IoT Makerspace
* 
* GitHub Link :https://github.com/st-peters-mbare-iot-makerspace/offgrid-iot-urban-farming
* This Library is free software: you can redistribute it and/or modify
* it under the terms of the GNU General Public License as published by
* the Free Software Foundation, either version 3 of the License, or
* (at your option) any later version.
*
* Description:Monitoring water quality parameters ph
*
*
* Sensor driver pin：A2 
*
* Author  :  St Peter Mbare IoT Makerspace
* Version :  V1.0
* Date    :  2019-05-25
**********************************************************************/

#pragma once
#include <Arduino.h>
#include "Sensor.h"
class Ph:public Sensor
{
public:
	// ph sensor pin
	int phSensorPin;

	// offset compensation
	float offset;

	// Take the sample interval
	int samplingInterval;
private:
	static const int arrayLength = 5;
	int pHArray [arrayLength];    // stores the average value of the sensor return data
	double pHValue, voltage;
	double averageVoltage;
	double sum;

public:
	Ph();
	~Ph() {};
	// initialization
	void  setup ();

	// update the sensor data
	void  update ();

	// Get the sensor data
	double getValue();
};

