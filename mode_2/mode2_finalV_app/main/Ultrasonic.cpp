#include "Ultrasonic.h"

float duration = 0 ; 
float distance = 9 ;
char ret = 0 ;

char Particle_Detecter(void) {
  
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);

  duration = pulseIn(echoPin, HIGH);
  distance = (duration*.0343)/2;
  delay(10);
  

  if(distance < 8 )
  {
    ret = 1 ;
  }
if(distance > 8)
  {
    ret = 0 ;
  }
  return ret ;
}
