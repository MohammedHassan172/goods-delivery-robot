#include "Motor_moving.h"

/**********************************************************************************************/
void forward()
{
  Set_Speed();
  digitalWrite(right_motor_p,HIGH);
  digitalWrite(right_motor_N,LOW);
  digitalWrite(left_motor_p,HIGH);
  digitalWrite(left_motor_N,LOW);
}
/**********************************************************************************************/
void reverse()
{
  Set_Speed();  
  digitalWrite(right_motor_p,LOW);
  digitalWrite(right_motor_N,HIGH);
  digitalWrite(left_motor_p,LOW);
  digitalWrite(left_motor_N,HIGH);
}
/**********************************************************************************************/

void stop()
{
  digitalWrite(right_motor_p,LOW);
  digitalWrite(right_motor_N,LOW);
  digitalWrite(left_motor_p,LOW);
  digitalWrite(left_motor_N,LOW);
}

/**********************************************************************************************/
void turn_R90()
{
  correct_right();
  delay(200);
  while(digitalRead(center)!=black)
  {  
  correct_right();
  } 
}
/**********************************************************************************************/
void turn_L90()
{
  correct_left();
  delay(200);
  while(digitalRead(center)!=black)
  {
  correct_left();
  }
}
/**********************************************************************************************/
void turn_180()
{
  turn_R90();
  delay(200);
  turn_R90();
  delay(200);
}
/**********************************************************************************************/


