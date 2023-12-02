#include "main.h"


int Bonnok_P_X=3,Bonnok_P_Y=3;
int DIST_X=1,DIST_Y=2;
int X_Flag=0,Y_Flag=1;
int y=0,x=0;

void setup() 
  // put your setup code here, to run once:
{
pinMode(right_motor_p,OUTPUT);
pinMode(right_motor_N,OUTPUT);
pinMode(left_motor_p,OUTPUT);
pinMode(left_motor_N,OUTPUT);
pinMode( Rmotor_speed,OUTPUT);
pinMode( Rmotor_speed,OUTPUT);  
Serial.begin(9600);
pinMode(right,INPUT); 
pinMode(center,INPUT);    
pinMode(left,INPUT);     
 
}

void loop() {
  // put your main code here, to run repeatedly:
 y=DIST_Y - Bonnok_P_Y;
 x=DIST_X - Bonnok_P_X;
char check=x;

/******************************************************************************************** Moving in Y axis*********************************************************************************************/

y_axis: while (y!=0) {   
Serial.print(x);
Serial.print(" ");
Serial.print(y);
Serial.println(" ");



if (y < 0){
turn_180();
Y_Flag=-1; 
y *= (-1);
}
if ((digitalRead(left)==white)&&(digitalRead(center)==black)&&(digitalRead(right)==white)){     
forward();
}

 if ((digitalRead(left)==black)&&(digitalRead(center)==white)&&(digitalRead(right)==white)){
      
correct_left();
}

 if ((digitalRead(left)==white)&&(digitalRead(center)==white)&&(digitalRead(right)==black)){
      
correct_right();
}
 if ((digitalRead(left)==black)&&(digitalRead(center)==black)&&(digitalRead(right)==black)){
forward();
delay(500);   
  y--;
  Bonnok_P_Y += Y_Flag;
goto   y_axis;
}

 }
/******************************************************************************************** Rotation around X axis*********************************************************************************************/

if ((Y_Flag == 1) && (x > 0)){
turn_R90();
X_Flag=1;  
}
else if ((Y_Flag == 1) && (x < 0)){
turn_L90();
X_Flag=-1; 
x*=(-1);
}
else if ((Y_Flag == -1) && (x > 0)){
turn_L90();
X_Flag=1; 
}
else if ((Y_Flag == -1) && (x < 0)){
turn_R90();
X_Flag=-1; 
x*=(-1);
}

/********************************************************************************************Moving in X axis*********************************************************************************************/



X_axis: while (x !=0) {   
Serial.print(x);
Serial.print(" ");
Serial.print(y);
Serial.println(" ");  

if ((digitalRead(left)==white)&&(digitalRead(center)==black)&&(digitalRead(right)==white)){
      
forward();
}

 if ((digitalRead(left)==black)&&(digitalRead(center)==white)&&(digitalRead(right)==white)){
      
correct_left();
}

 if ((digitalRead(left)==white)&&(digitalRead(center)==white)&&(digitalRead(right)==black)){
      
correct_right();
}
 if ((digitalRead(left)==black)&&(digitalRead(center)==black)&&(digitalRead(right)==black)){
forward();
delay(500);    
  x--;
 Bonnok_P_X += X_Flag;
goto   X_axis;
}

 }

/*************************************************************************************************Parking*********************************************************************************************/

if (check != 0){
           if (X_Flag == 1){
             turn_L90();  
                    }        
           else if (X_Flag == -1){
              turn_R90();  
                  }
}
else if (Y_Flag == -1){
turn_180();  
}
Y_Flag=1,X_Flag=0;
stop();
}






