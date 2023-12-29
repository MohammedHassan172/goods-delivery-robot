#ifndef ULTRASONIC_H
#define ULTRASONIC_H

/******************************* INCLUDES *************************/
#include <Arduino.h>

/******************************* DEFINES **************************/
#define trigPin    4
#define echoPin    A3
// servo A5
// Rx 0
// tx 1
#define NO_PARTICLE 0
#define PARTICLE    1
extern float duration; 
extern float distance;
extern char ret;

/***************************** FUNCTION DECLRTION *******************/
char Particle_Detecter(void);


#endif
