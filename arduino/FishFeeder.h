#pragma once
#include "GravityRtc.h"

class FishFeeder{
  const int MotorPinA = 4; // direction motor 1 (Channel A)
  const int speed = 5; // for motor 1 (channel A)
  
  
public:
  FishFeeder();
  
  void turnLeft();

  void turnLCentre();

  void turnRight();

  void turnRCentre();

  void turnMotor();
  
  void feedFish();
  
};
