#ifndef WEIGHT_SENSOR_H
#define WEIGHT_SENSOR_H

#include <Arduino.h>

//zero the weight sensor
float zeroing();


//weigh the ingredients
void weighing(float z, int a);

#endif
