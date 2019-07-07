/*********************************************************************
* WaterLevel.h
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
#include "WaterLevel.h"
#include "Arduino.h"

  WaterLevel::WaterLevel(int pin){
    this->pin=pin;
  }
	void WaterLevel::setup(){
    pinMode(pin,INPUT);
	}
	
	void WaterLevel::update(){
    notLeaking=digitalRead(pin);   
	}
	
	double WaterLevel::getValue(){
    return notLeaking;
	}
