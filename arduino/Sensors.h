/*********************************************************************
* Sensors.h
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
/*
sensors :
0,ph
1,ec
2.waterlevel
*/
class Sensors
{
private:
	static const int SensorCount = 10;

public:
	Sensor *sensors[SensorCount] = {0}; //Array of sensors
public:
	Sensors();
	~Sensors();

	// initialize all sensors
	void  setup ();

	// update all sensor values
	void  update ();

	// Get the sensor data
	double getValueBySensorNumber(int num);
};
