#ifndef PID_H
#define PID_H


/*************************includes*************************************/

#include <Arduino.h>
#include <Event.h>
#include <Timer.h>
#include "linefollower.h"

/************************* declearation*************************************/

#define period_pid 20

extern float kp;
extern float ki;
extern float kd;
extern int pose;

extern float integral; 
extern float derivative;
extern float out;



extern int sensor_reads[3];
extern int max_read[3];
extern int min_read[3];
extern float err;
extern float err_abs;
extern float err_prev;

/*************************Functions*************************************/
void calpration();
void scaling();
void cal_pos();
void pid_cal();
#endif