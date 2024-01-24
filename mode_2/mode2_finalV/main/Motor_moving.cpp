#include "Motor_moving.h"
#include "linefollower.h"
#define r_speed 80
#define l_speed 80
#define r_speed_f 90
#define l_speed_f 90
void forward()
{
  analogWrite(Rmotor_speed,r_speed_f);  
  analogWrite(Lmotor_speed,l_speed_f);  
  digitalWrite(right_motor_p,HIGH);
  digitalWrite(right_motor_N,LOW);
  digitalWrite(left_motor_p,HIGH);
  digitalWrite(left_motor_N,LOW);
}
/**********************************************************************************************/
void reverse()
{
  analogWrite(Rmotor_speed,);  
  analogWrite(Lmotor_speed,70);   
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

analogWrite(Rmotor_speed,r_speed);  
analogWrite(Lmotor_speed,l_speed);   
digitalWrite(right_motor_p,LOW);
digitalWrite(right_motor_N,HIGH);
digitalWrite(left_motor_p,HIGH);
digitalWrite(left_motor_N,LOW);
delay(500);
while(digitalRead(center)!=black){  
analogWrite(Rmotor_speed,r_speed);  
analogWrite(Lmotor_speed,l_speed);   
digitalWrite(right_motor_p,LOW);
digitalWrite(right_motor_N,HIGH);
digitalWrite(left_motor_p,HIGH);
digitalWrite(left_motor_N,LOW);

} 

}
/**********************************************************************************************/
void turn_L90(){
  analogWrite(Rmotor_speed,r_speed);  
analogWrite(Lmotor_speed,l_speed);   
digitalWrite(right_motor_p,HIGH);
digitalWrite(right_motor_N,LOW);
digitalWrite(left_motor_p,LOW);
digitalWrite(left_motor_N,HIGH);
delay(500);
while(digitalRead(center)!=black){
analogWrite(Rmotor_speed,r_speed);  
analogWrite(Lmotor_speed,l_speed);   
digitalWrite(right_motor_p,HIGH);
digitalWrite(right_motor_N,LOW);
digitalWrite(left_motor_p,LOW);
digitalWrite(left_motor_N,HIGH);

}

}
/**********************************************************************************************/
void turn_180(){
analogWrite(Rmotor_speed,r_speed);  
analogWrite(Lmotor_speed,l_speed);   
digitalWrite(right_motor_p,LOW);
digitalWrite(right_motor_N,HIGH);
digitalWrite(left_motor_p,HIGH);
digitalWrite(left_motor_N,LOW);
delay(500);
while(digitalRead(center)!=black){  
analogWrite(Rmotor_speed,r_speed);  
analogWrite(Lmotor_speed,l_speed);   
digitalWrite(right_motor_p,LOW);
digitalWrite(right_motor_N,HIGH);
digitalWrite(left_motor_p,HIGH);
digitalWrite(left_motor_N,LOW);

} 
analogWrite(Rmotor_speed,r_speed);  
analogWrite(Lmotor_speed,l_speed);   
digitalWrite(right_motor_p,LOW);
digitalWrite(right_motor_N,HIGH);
digitalWrite(left_motor_p,HIGH);
digitalWrite(left_motor_N,LOW);
delay(250);
while(digitalRead(center)!=black){  
analogWrite(Rmotor_speed,r_speed);  
analogWrite(Lmotor_speed,l_speed);   
digitalWrite(right_motor_p,LOW);
digitalWrite(right_motor_N,HIGH);
digitalWrite(left_motor_p,HIGH);
digitalWrite(left_motor_N,LOW);

} 
}

