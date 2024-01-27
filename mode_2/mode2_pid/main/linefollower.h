#ifndef LINEFOLLOER_H
#define LINEFOLLOER_H


/*************************includes*************************************/

#include <Arduino.h>
#include "Motor_moving.h"
#include "PID.h"

/*************************Macros declearation*************************************/
#define white 0
#define black 1 

#define right   A0
#define center  A1    
#define left    A2

#define base_speed 110
#define max_speed 150

/*************************Functions*************************************/

void Set_Speed();
void Tleft();
void Tright();
void correct_right();
void correct_left();
#endif