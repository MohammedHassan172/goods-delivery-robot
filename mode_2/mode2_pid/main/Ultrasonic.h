#ifndef ULTRASONIC_H
#define ULTRASONIC_H

/******************************* INCLUDES *************************/
#include <Arduino.h>

/*******************************Macros Declearation**************************/
#define trigPin    4
#define echoPin    A3

extern volatile float distance;

/***************************** FUNCTION DECLRTION *******************/
void Particle_Detecter(void);


#endif