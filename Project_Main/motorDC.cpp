#include <Arduino.h>
#include "motorDC.h"

void setDC(){
  pinMode(ENA, OUTPUT);
  pinMode(DIR, OUTPUT);
}

void spinDC(int t){
  int rep;
  for (rep=0; rep<t; rep++){
    digitalWrite(ENA, HIGH);


    //every minute change direction of rotation
    if (((rep/60)%2)==1){
      digitalWrite(DIR, HIGH);
    }else{
      digitalWrite(DIR, LOW);
    }
    delay(1000);
  }
  digitalWrite(ENA, LOW);
}
