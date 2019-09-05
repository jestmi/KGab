#ifndef STEPPER_AND_SERVO_H
#define STEPPER_AND_SERVO_H

#include <Arduino.h>
#include <Stepper.h>

void step_setup(); //setup stepper motor

void stepIngr(int n); //select ingredient

void stepStart(int n);

void servoOpn();

void servoCls();


#endif
