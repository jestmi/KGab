#ifndef MOTOR_DC_H
#define MOTOR_DC_H

#include <Arduino.h>


const int ENA = 13;
const int DIR = 12;

void setDC();


void spinDC(int t);

#endif
