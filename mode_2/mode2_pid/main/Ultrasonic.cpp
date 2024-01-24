#include "Ultrasonic.h"

float duration = 0 ; 
volatile float distance = 9 ;
char ret = 0 ;

void Particle_Detecter(void)
{
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
  duration = pulseIn(echoPin, HIGH);
  distance = (duration*0.0175); // duration * (350*0.0001/2) = duration * 0.0175
  delay(10);
}