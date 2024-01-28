#include "linefollower.h"

/*************************************************************************************************/

void Set_Speed()
{
  analogWrite(Rmotor_speed,base_speed + (out));  
  analogWrite(Lmotor_speed,base_speed + (out));
}

/*************************************************************************************************/

void Tleft()
{
  
  digitalWrite(right_motor_p,HIGH);
  digitalWrite(right_motor_N,LOW);
  digitalWrite(left_motor_p,LOW);
  digitalWrite(left_motor_N,HIGH);
}
/**********************************************************************************************/
void Tright()
{
  digitalWrite(right_motor_p,LOW);
  digitalWrite(right_motor_N,HIGH);
  digitalWrite(left_motor_p,HIGH);
  digitalWrite(left_motor_N,LOW);
}
/**********************************************************************************************/

void correct_right()
{
  Set_Speed();
  Tright();
}


/*************************************************************************************************/
void correct_left()
{
  Set_Speed();
  Tleft();
}
