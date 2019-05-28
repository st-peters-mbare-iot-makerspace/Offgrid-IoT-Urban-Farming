/*********************************************************************
* Ec.h
*
* Copyright (C)    2019   St Peters Mbare IoT Makerspace
* 
* GitHub Link :https://github.com/st-peters-mbare-iot-makerspace/offgrid-iot-urban-farming
* This Library is free software: you can redistribute it and/or modify
* it under the terms of the GNU General Public License as published by
* the Free Software Foundation, either version 3 of the License, or
* (at your option) any later version.
*
* Description:Monitoring water quality parameters Conductivity
*
* 
* Sensor driver pin：A1 (Can be modified in the .cpp file:ECsensorPin(A1);)
*
* Author  :  St Peter Mbare IoT Makerspace
* Version :  V1.0
* Date    :  2019-05-25
**********************************************************************/

#pragma once
#include "Temperature.h"
#include "Sensor.h"

// external GravityTemperature ecTemperature;

class Ec:public Sensor
{
public:
	// Conductivity sensor pin
	int ecSensorPin;

	// Conductivity values
	double ECcurrent;


public:
	Ec(Sensor*);
	~Ec();

	// initialization
	void  setup ();

	// update the sensor data
	void  update ();

	// Get the sensor data
	double getValue();

private:
	// point to the temperature sensor pointer
	Sensor* ecTemperature = NULL;


	static const int numReadings = 5;
	unsigned int readings[numReadings] = { 0 };      // the readings from the analog input
	int index;
	double sum;
	unsigned long AnalogValueTotal;      // the running total
	unsigned int AnalogAverage;
	unsigned int averageVoltage;
	unsigned long AnalogSampleTime;
	unsigned long printTime;
	unsigned  long tempSampleTime;
	unsigned long AnalogSampleInterval;
	unsigned long printInterval ;

	// Calculate the average
  void calculateAnalogAverage();

	// Calculate the conductivity
	void calculateEc();
};

