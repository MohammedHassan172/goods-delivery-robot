/*
*************Status: Finished************
*****************************************
*
*Name: ELsayed Ahmed Ibrahim
*Last edit : 8:05 am 3/11/2023
*
*****************************************
******************PINS*******************
- VCC
- GND
- TLL Output "D0"
- Analog Output "A0"
*/

#define A0  3 
#define holes_wheel   //No. of holes in Encoder Wheel
volatile byte pulses = 0; //to count the number of raising pulses
int RPM = 0;
unsigned long timer1 = 0;
void RMS_Motor(); 
void setup() {
  pinMode(A0, INPUT);
  Serial.begin(9600);
  attachIntterupt(digitalPinToIntterupt(A0) , RPM_Motor , RISING);
  timer1 = millies();
    
}

void loop() {
  if(millies()-timer1>=(1000/holes_wheel)){
    RPM = pulses * 60;
    timer = millies();
    Serial.println("RPM = ");
    Serial.print(RPM);
    pulses = 0;
  }
}
void RMS_Motor(){
  pulses++;
}