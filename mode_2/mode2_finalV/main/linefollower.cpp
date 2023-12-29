#include "linefollower.h"
#define r_speed 96
#define l_speed 96
void correct_right(){
  analogWrite(Rmotor_speed,r_speed);  
  analogWrite(Lmotor_speed,l_speed);  
  digitalWrite(right_motor_p,LOW);
  digitalWrite(right_motor_N,HIGH);
  digitalWrite(left_motor_p,HIGH);
  digitalWrite(left_motor_N,LOW);
}


/*************************************************************************************************/
void correct_left(){
analogWrite(Rmotor_speed,r_speed);  
analogWrite(Lmotor_speed,l_speed);  
 digitalWrite(right_motor_p,HIGH);
  digitalWrite(right_motor_N,LOW);
  digitalWrite(left_motor_p,LOW);
  digitalWrite(left_motor_N,HIGH);
}
