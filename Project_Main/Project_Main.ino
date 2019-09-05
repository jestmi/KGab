#include "Stepper_and_servo.h"
#include "Weight_sensor.h"
#include "motorDC.h"

void setup() {
  setNet();
  step_setup();
  setDC();

}

void loop() {
  int test[10] = {100, 100, 100, 100, 100, 100, 100, 100, 100, 200};
  int rec1[10] = {100, 0, 0, 150, 0, 0, 0, 0, 50, 100};
  int rep;
  int recipe = 0;
  float zeroed;

  while (recipe == 0) {
    netLoop(&recipe);
  }

  switch (recipe) {
    case 1:
      for (rep = 0; rep < 8; rep++) {
        if (test[rep] != 0) {
          stepIngr(rep);
          zeroed = zeroing();
          servoOpn();
          weighing(zeroed, test[rep]);
          servoCls();
          stepStart(rep);
        }
      }
      if (test[8] != 0) {
        zeroed = zeroing();
        digitalWrite(3, HIGH);
        weighing(zeroed, test[8]);
        digitalWrite(3, LOW);
      }
      spinDC(test[9]);

      break;


    case 2:
      for (rep = 0; rep < 8; rep++) {
        if (rec1[rep] != 0) {
          stepIngr(rep);
          zeroed = zeroing();
          servoOpn();
          weighing(zeroed, rec1[rep]);
          servoCls();
          stepStart(rep);
        }
      }
      if (rec1[8] != 0) {
        zeroed = zeroing();
        digitalWrite(3, HIGH);
        weighing(zeroed, rec1[8]);
        digitalWrite(3, LOW);
      }
      spinDC(rec1[9]);

      break;
  }



}
