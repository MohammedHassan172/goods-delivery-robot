/*******status: unfinished yet***********
*****************************************
*
*Name: ELsayed Ahmed Ibrahim
*Last edit : 8:40 pm 2/11/2023
*
*****************************************
*/

#define D0  2 //High Priority Intterupt
#define holes_wheel   //No. of holes in Encoder Wheel
int encoder_counter = 0; //to count the number of raising pulses
int RPM = 0;
unsigned long timer1 = 0;
void RMS_Motor(); 
void setup() {
  pinMode(D0, INPUT);
  Serial.begin(9600);
  attachIntterupt(digitalPinToIntterupt(D0) , RPM_Motor , RISING);
  timer1 = millies();
    
}

void loop() {
  if(millies()-timer1>=1000){
    RPM = (encoder_counter / holes_wheel) * 60;
  }
  
  Serial.print("RPM = ");
  Serial.print(RPM);
  delay(1000);
}
void RMS_Motor(){
  encoder_counter++;
}