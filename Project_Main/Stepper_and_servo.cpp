#include <Arduino.h>
#include "Stepper_and_Servo.h"
#include <Stepper.h>
#define STEPS 48

Stepper stepper(STEPS, 11, 10, 9, 8);
void step_setup() {
  stepper.setSpeed(10);
  pinMode(5, OUTPUT);
}


void stepIngr(int n) {
  stepper.step(6 * n);   //no. of ingredient multiplied by six because it takes 6 steps
  delay(100);             //for the motor to rotate 45 degree
}

void stepStart(int n) {
  stepper.step(-6 * n);   //return motor to its starting position
  delay(100);
}

void servoOpn() {
  int rep;
  for (rep = 0; rep < 100; rep++) {
    digitalWrite(5, HIGH);
    delay(3);
    digitalWrite(5, LOW);
    delay(17);
  }
}

void servoCls() {
  int rep;
  for (rep = 0; rep < 100; rep++) {
    digitalWrite(5, HIGH);
    delay(0);
    digitalWrite(5, LOW);
    delay(20);
  }
}
