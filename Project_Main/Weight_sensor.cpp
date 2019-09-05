#include <Arduino.h>
#include "Weight_sensor.h"

float zeroing() {
  float zeroed;
  zeroed = analogRead(0);
  return zeroed;
  Serial.println(zeroed);

}

void weighing(float z, int a) {
  int rep = 1;
  float amount = (a * 0.072727)+ z;
  float weight = 0;
  float compare;

  //constantly compare the current weight against desired weight

  while (rep == 1) {

    Serial.println(weight);
    weight = analogRead(0);
    compare = weight;
    delay (1000);
    
    if (weight >= amount) {
      rep = 0;
     delay (1000);
    }
  }
}
