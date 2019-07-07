/*********************************************************************************************
* Sensors.cpp
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
*********************************************************************************************/


#include "Sensors.h"
#include "Ph.h"
#include "Ec.h"
#include "Temperature.h"
#include "WaterLevel.h"
#include "Sound.h"
//********************************************************************************************
// function name: sensors []
// Function Description: Store the array of sensors
// Parameters: 0 ph sensor
// Parameters: 1 temperature sensor
// Parameters: 3 Conductivity sensor
//********************************************************************************************

Sensors::Sensors()
{
	for (size_t i = 0; i < this->SensorCount; i++)
	{
		this->sensors[i] = NULL; //set all instances of sensors to NULL
	}

	this->sensors[0] = new Ph(); //Ph Sensor instance as array element
	this->sensors[1] = new Temperature(7); //Temperature Sensor instance on Digital pin 7 as array element
	this->sensors[2] = new Ec(this->sensors[1]); //as array element
	this->sensors[3] = new WaterLevel(8);
  this->sensors[4] = new Sound(A2);
}

//********************************************************************************************
// function name: ~ Sensors ()
// Function Description: Destructor, frees all sensors
//********************************************************************************************
Sensors::~Sensors()
{
	for (size_t i = 0; i < SensorCount; i++)
	{
		if (this->sensors[i])
		{
			delete this->sensors[i];
		}
	}
}


//********************************************************************************************
// function name: setup ()
// Function Description: Initializes all sensors
//********************************************************************************************
void Sensors::setup()
{
	for (size_t i = 0; i < SensorCount; i++)
	{
		if (this->sensors[i])
		{
			this->sensors[i]->setup();
		}
	}
}


//********************************************************************************************
// function name: update ()
// Function Description: Updates all sensor values
//********************************************************************************************
void Sensors::update()
{
	for (size_t i = 0; i < SensorCount; i++)
	{
		if (this->sensors[i])
		{
			this->sensors[i]->update();
		}
	}
}

//********************************************************************************************
// function name: getValueBySensorNumber ()
// Function Description: Get the sensor data
// Parameters: 0 ph sensor
// Parameters: 1 temperature sensor
// Parameters: 3 Conductivity sensor
// Return Value: Returns the acquired sensor data
//********************************************************************************************
double Sensors::getValueBySensorNumber(int num)
{
	if (num >= SensorCount)
	{
		return 0;
	}
	return this->sensors[num]->getValue();
}
