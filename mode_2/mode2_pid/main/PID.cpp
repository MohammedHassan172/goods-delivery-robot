#include "HardwareSerial.h"
#include "PID.h"
/****************************************************************************************************************/


float kp = 2;
float ki = 1;
float kd = 1.3;
int pose = 0;

float integral = 0; 
float derivative = 0;
float out = 0;



int sensor_reads[3] = {0,0,0};
int max_read[3] = {0,0,0};
int min_read[3] = {100,100,100};
float err = 0;
float err_abs = 0;
float err_prev = 0;

void calpration(){


  for(int j = 0; j < 20; j++)
  {
    sensor_reads[0] = analogRead(right);
    if(sensor_reads[0] <= min_read[0])
    {
      min_read[0] = sensor_reads[0];
    }
    else if(sensor_reads[0] >= max_read[0])
    {
      max_read[0] = sensor_reads[0];
    }

    sensor_reads[1] = analogRead(center);
    if(sensor_reads[1] <= min_read[1])
    {
      min_read[1] = sensor_reads[1];
    }
    else if(sensor_reads[1] >= max_read[1])
    {
      max_read[1] = sensor_reads[1];
    }

    sensor_reads[2] = analogRead(left);
    if(sensor_reads[2] <= min_read[2])
    {
      min_read[2] = sensor_reads[2];
    }
    else if(sensor_reads[2] >= max_read[2])
    {
      max_read[2] = sensor_reads[2];
    }
     delay(500); 

  }

}
/******************************************************************************************************************/
void scaling(){
  sensor_reads[0] = analogRead(right);
  sensor_reads[1] = analogRead(center);
  sensor_reads[2] = analogRead(left);

  for(int i = 0; i < 3; i++)
  {
    int demontator = 0;
    float value = 0;
    demontator = max_read[i] - min_read[i];

    if(demontator != 0)
    {
      value = sensor_reads[i] - min_read[i];
      value = value * 1000;
      value = value/demontator;
    }

    if(value < 0)
    {
      value = 0;
    }
    else if (value > 1000) 
    {
      value = 1000;
    }
    sensor_reads[i] = value;
    // Serial.print(sensor_reads[i]);
    // Serial.print("\t");

  }
  // Serial.print("\n");


}
/*****************************************************************************************************************/
void cal_pos(){
   bool onLine = false;
  float avg = 0; 
  float sum = 0; 

  for (int i = 0; i < 3; i++)
  {
    float value = sensor_reads[i];

    // keep track of whether we see the line at all
    if (value > 200) { onLine = true; }

    // only average in values that are above a noise threshold
    if (value > 60)
    {
      avg += value * (i * 1000);
      sum += value;
    }
  }

  if (!onLine)
  {
    // If it last read to the left of center, return 0.
    if (pose < (3 - 1) * 1000 / 2)
    {
      pose =  0;
    }
    // If it last read to the right of center, return the max.
    else
    {
      pose = (3 - 1) * 1000;
    }
  }
  if(onLine)
  {
    pose = avg / sum;
  }
}
/*****************************************************************************************************************/
void pid_cal(){
err = 1000 - pose;
  
err_abs = abs(err);
  
  integral = (integral + err_abs) * (period_pid/1000.0);
  derivative = (err_abs - err_prev) / (period_pid/1000.0);

  out = err_abs * kp + integral * ki + derivative * kd;
  out = out / 100;


  if(out > max_speed)
  {
    out = max_speed / 100;
  }
  else if(out < base_speed)
  {
    out = base_speed / 100;
  }
  err_prev = err_abs;
}
