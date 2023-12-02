#include "linefollower.h"

void correct_right(){

  digitalWrite(right_motor_p,LOW);
  digitalWrite(right_motor_N,LOW);
  digitalWrite(left_motor_p,HIGH);
  digitalWrite(left_motor_N,LOW);
}


/*************************************************************************************************/
void correct_left(){

 digitalWrite(right_motor_p,HIGH);
  digitalWrite(right_motor_N,LOW);
  digitalWrite(left_motor_p,LOW);
  digitalWrite(left_motor_N,LOW);
}