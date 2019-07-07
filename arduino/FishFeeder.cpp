#include "FishFeeder.h"
#include "Arduino.h"
extern GravityRtc gravityRtc;

FishFeeder::FishFeeder(){
  
  
  pinMode(MotorPinA, OUTPUT);
  pinMode(speed, OUTPUT);
}


void FishFeeder::turnLeft(){
  digitalWrite(MotorPinA, LOW);// set direction
  analogWrite(speed, 100);// set speed at maximum
  delay(500);// run for 5 seconds

  analogWrite(speed, 0);// stop motor A
}

void FishFeeder::turnLCentre(){
  digitalWrite(MotorPinA, HIGH);// set direction
  analogWrite(speed, 100);// set speed at maximum
  delay(500);// run for 5 seconds

  analogWrite(speed, 0);// stop motor A
  
}

void FishFeeder::turnRight(){
  digitalWrite(MotorPinA, HIGH);// set direction
  analogWrite(speed, 100);// set speed at maximum
  delay(500);// run for 5 seconds

  analogWrite(speed, 0);// stop motor A
}

void FishFeeder::turnRCentre(){
  digitalWrite(MotorPinA, LOW);// set direction
  analogWrite(speed, 100);// set speed at maximum
  delay(500);// run for 5 seconds

  analogWrite(speed, 0);// stop motor A
  
}

void FishFeeder::turnMotor() {
  turnLeft();
  //delay(500);
  turnLCentre();
  delay(1200);
  turnRight();
  //delay(500);
  turnRCentre();
  
}

void FishFeeder::feedFish(){
  gravityRtc.read();
  if(gravityRtc.minute==02){
    if(gravityRtc.second>=15 && gravityRtc.second<=45){
      turnMotor();
    }  
  }
}
