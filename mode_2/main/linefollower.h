#ifndef LINEFOLLOER_H
#define LINEFOLLOER_H


/*************************includes*************************************/

#include <Arduino.h>
#include "Motor_moving.h"

/*************************data declearation*************************************/
#define white 0
#define black 1 

#define right 13 
#define center 12    
#define left 7       


typedef struct {

     char X_postion;
    char  Y_postion;  
  
}Grid;
/*************************Functions*************************************/

void correct_right();
void correct_left();
#endif