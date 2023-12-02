#include "Motor_moving.h"

void forward()
{
  analogWrite(Rmotor_speed,73);  
  analogWrite(Lmotor_speed,73);  
  digitalWrite(right_motor_p,HIGH);
  digitalWrite(right_motor_N,LOW);
  digitalWrite(left_motor_p,HIGH);
  digitalWrite(left_motor_N,LOW);
}
/**********************************************************************************************/
void reverse()
{
  analogWrite(Rmotor_speed,74);  
  analogWrite(Lmotor_speed,77);   
  digitalWrite(right_motor_p,LOW);
  digitalWrite(right_motor_N,HIGH);
  digitalWrite(left_motor_p,LOW);
  digitalWrite(left_motor_N,HIGH);
}
/**********************************************************************************************/
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
void stop()
{
   digitalWrite(right_motor_p,LOW);
  digitalWrite(right_motor_N,LOW);
  digitalWrite(left_motor_p,LOW);
  digitalWrite(left_motor_N,LOW);
}

/**********************************************************************************************/
void turn_R90(){
  
analogWrite(Rmotor_speed,73);  
analogWrite(Lmotor_speed,73);   
digitalWrite(right_motor_p,LOW);
  digitalWrite(right_motor_N,HIGH);
  digitalWrite(left_motor_p,HIGH);
  digitalWrite(left_motor_N,LOW);
delay(630);

  
}
/**********************************************************************************************/
void turn_L90(){
analogWrite(Rmotor_speed,73);  
analogWrite(Lmotor_speed,73);   
digitalWrite(right_motor_p,HIGH);
  digitalWrite(right_motor_N,LOW);
  digitalWrite(left_motor_p,LOW);
  digitalWrite(left_motor_N,HIGH);
delay(630);
}
/**********************************************************************************************/
void turn_180(){
analogWrite(Rmotor_speed,73);  
analogWrite(Lmotor_speed,73);   
digitalWrite(right_motor_p,LOW);
  digitalWrite(right_motor_N,HIGH);
  digitalWrite(left_motor_p,HIGH);
  digitalWrite(left_motor_N,LOW);
delay(1550);
}

