#ifndef MAIN_H
#define MAIN_H

#define MAX_X 3
#define MAX_Y 3

/*************************includes*************************************/

#include "Motor_moving.h"
#include "linefollower.h"
#include "Ultrasonic.h"
#include "PID.h"


/*************************Macros declearation*************************************/
/*************************Functions*************************************/

void y_move();
void x_move();
void parking();
void short_cut_y();
void short_cut_x();

#endif