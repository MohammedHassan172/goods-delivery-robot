#ifndef MOTOR_MOVING_H
#define MOTOR_MOVING_H

/*************************includes*************************************/

#include <Arduino.h>

/*************************data declearation*************************************/

#define right_motor_p 10
#define right_motor_N 11
#define left_motor_p 8
#define left_motor_N 9
#define Rmotor_speed 6
#define Lmotor_speed 5

/*************************Functions*************************************/

void forward();
void reverse();
void Tleft();
void Tright();
void stop();
void turn_R90();
void turn_L90();
void turn_180();
#endif
