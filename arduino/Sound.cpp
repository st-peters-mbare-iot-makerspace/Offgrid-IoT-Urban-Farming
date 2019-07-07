/*********************************************************************
* Sound.cpp
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
#include "Sound.h"
#include "Arduino.h"

  Sound::Sound(int pin){
    this->pin=pin;
  }
  
	void Sound::setup(){
    
	}
	void Sound::update(){
    soundIn=analogRead(pin);
	}
	double Sound::getValue(){
    return soundIn;
	}
