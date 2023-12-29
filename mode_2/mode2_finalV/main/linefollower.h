#ifndef LINEFOLLOER_H
#define LINEFOLLOER_H


/*************************includes*************************************/

#include <Arduino.h>
#include "Motor_moving.h"

/*************************data declearation*************************************/
#define white 0
#define black 1 

#define right A0
#define center A1    
#define left A2       


typedef struct {

     char X_postion;
    char  Y_postion;  
  
}Grid;
/*************************Functions*************************************/

void correct_right();
void correct_left();
#endif
