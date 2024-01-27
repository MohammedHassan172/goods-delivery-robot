#include "main.h"


int Bonnok_P_X = 1, Bonnok_P_Y = 1;
int DIST_X = 3, DIST_Y = 3;
int X_Flag = 0, Y_Flag = 1;
int y = 0;
int x = 0;
char negative_flag = 0, particle_flag = 0, one_x_flag = 0;
char check = 0;
char check_avoidence = 0;
volatile bool avoid = LOW;
Timer t;
static void x_rotation();
void ISR_avoid();
#define margin 600
#define margin_err 5


void setup() {
  pinMode(right_motor_p, OUTPUT);
  pinMode(right_motor_N, OUTPUT);
  pinMode(left_motor_p, OUTPUT);
  pinMode(left_motor_N, OUTPUT);
  pinMode(Rmotor_speed, OUTPUT);
  pinMode(Lmotor_speed, OUTPUT);
  pinMode(right, INPUT);
  pinMode(center, INPUT);
  pinMode(left, INPUT);
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  pinMode(LED_BUILTIN, OUTPUT);
  Serial.begin(9600);
  t.every(period_pid, pid_cal);
  digitalWrite(LED_BUILTIN, HIGH);
  calpration();
  digitalWrite(LED_BUILTIN, LOW);
  delay(2000);

  //attachInterrupt(avoid , ISR_avoid , HIGH);
}

void loop() {
  y = DIST_Y - Bonnok_P_Y;
  x = DIST_X - Bonnok_P_X;
  check = x;
  char t = 0;
  while (t < 5) {
    t++;
    Particle_Detecter();
  }
  
  y_move();
  x_move();
  parking();
  stop();
}

/**********************************************************************************************/
// void ISR_avoid() {
//   if (y > 0) {
//     short_cut_y();
//     avoid = LOW;
//   } else if (x > 0) {
//     short_cut_x();
//     avoid = LOW;
//   }
// }
/**********************************************************************************************/
void y_move() {
  if (y < 0) {
    turn_180();
    Y_Flag = -1;
    y *= (-1);
  }
  while (y > 0) {
    scaling();
    cal_pos();
    t.update();
    Particle_Detecter();
    if (distance <= 8 && distance > 0) {
      // avoid = HIGH;
      short_cut_y();
    } else {
      // avoid = LOW;
    }

    if ((sensor_reads[0] > margin) && (sensor_reads[1] > margin) && (sensor_reads[2] > margin))  {
      forward();
      delay(600);
      y--;
      Bonnok_P_Y += Y_Flag;
    }

    else if (err < -margin_err)  //the comparison sign might be wrong if the "correct" functions names are the reverse of the actual movement.
    {
      correct_left();
    }

    else if (err > margin_err) {
      correct_right();
    } 
    else if((sensor_reads[0] < margin) && (sensor_reads[1] > margin) && (sensor_reads[2] < margin)) 
    {
      forward();
    }
  }
}
/**********************************************************************************************/
void x_rotation() {

  if ((Y_Flag == 1) && (x > 0)) {
    turn_R90();
    X_Flag = 1;
  } else if ((Y_Flag == 1) && (x < 0)) {
    turn_L90();
    X_Flag = -1;
    x *= (-1);
  } else if ((Y_Flag == -1) && (x > 0)) {
    turn_L90();
    X_Flag = 1;
  } else if ((Y_Flag == -1) && (x < 0)) {
    turn_R90();
    X_Flag = -1;
    x *= (-1);
  }
}
/**********************************************************************************************/
void x_move() {
  x_rotation();
  while (x > 0) {
    scaling();
    cal_pos();
    t.update();
    Particle_Detecter();
    if (distance <= 8 && distance > 0) {
      // avoid = HIGH;
      short_cut_x();
    } 
    // else {
    //   // avoid = LOW;
    // }


    if ((sensor_reads[0] > margin) && (sensor_reads[1] > margin) && (sensor_reads[2] > margin))  {
      forward();
      delay(600);
      x--;
      Bonnok_P_X += X_Flag;
    }

    else if (err < -margin_err)  //the comparison sign might be wrong if the "correct" functions names are the reverse of the actual movement.
    {
      correct_left();
    }

    else if (err > margin_err) {
      correct_right();
    } 
    else if((sensor_reads[0] < margin) && (sensor_reads[1] > margin) && (sensor_reads[2] < margin)) 
    {
      
      forward();
    }
  }
}
/**********************************************************************************************/
void parking() {
  if (check != 0) {
    if ((X_Flag == 1)) {
      turn_L90();
      X_Flag = 0;
    } else if ((X_Flag == -1)) {
      turn_R90();
      X_Flag = 0;
    } else if ((check == 1) && (check_avoidence == 1)) {
    }
  } else if (Y_Flag == -1) {
    turn_180();
    Y_Flag = 1;
  }
}
/**********************************************************************************************/
void short_cut_y() {
  check_avoidence = 1;
  while (one_x_flag == 0) {
    scaling();
    cal_pos();
    t.update();
    if ((digitalRead(left) == white) && (digitalRead(center) == black) && (digitalRead(right) == white)) {
      if (particle_flag == 0) {
        reverse();
      }
      if (particle_flag == 1) {
        forward();
      }
    }

    if (err > margin_err)  //the comparison sign might be wrong if the "correct" functions names are the reverse of the actual movement.
    {
      correct_right();
    }

    else if (err < -margin_err) {
      correct_left();
    } 
    else if((sensor_reads[0] < margin) && (sensor_reads[1] > margin) && (sensor_reads[2] < margin)) 
    {
      reverse();
    }
    if ((sensor_reads[0] > margin) && (sensor_reads[1] > margin) && (sensor_reads[2] > margin))  {
      if (particle_flag == 0) {
        stop();
        delay(500);
        forward();
        delay(800);
        stop();
        delay(1000);
        if ((Y_Flag == 1) && (x > 0)) {
          turn_R90();
          X_Flag = 1;
        } else if ((Y_Flag == 1) && (x < 0)) {
          turn_L90();
          X_Flag = -1;
          x *= (-1);
          negative_flag = 1;
        } else if ((Y_Flag == -1) && (x > 0)) {
          turn_L90();
          X_Flag = 1;
        } else if ((Y_Flag == -1) && (x < 0)) {
          turn_R90();
          X_Flag = -1;
          x *= (-1);
          negative_flag = 1;
        }
        ///////////////////////////////////////// x = 0 /////////////////////////
        else if (x == 0) {
          if ((Y_Flag == 1) && (Bonnok_P_X < MAX_X)) {
            turn_R90();
            X_Flag = 1;
          } else if ((Y_Flag == 1) && (Bonnok_P_X == MAX_X)) {
            turn_L90();
            X_Flag = -1;
          } else if ((Y_Flag == -1) && (Bonnok_P_X < MAX_X)) {
            turn_L90();
            X_Flag = 1;
          } else if ((Y_Flag == -1) && (Bonnok_P_X == MAX_X)) {
            turn_R90();
            X_Flag = -1;
          }
          check = -1;
        }
        particle_flag = 1;
      }
      //////////////////////////////////////////////////////////////////////
      else if (particle_flag == 1) {
        forward();
        delay(300);
        x--;
        Bonnok_P_X += X_Flag;
        if ((Y_Flag == 1) && (X_Flag == 1)) {
          turn_L90();
        } else if ((Y_Flag == 1) && (X_Flag == -1)) {
          turn_R90();
        } else if ((Y_Flag == -1) && (X_Flag == 1)) {
          turn_R90();
        } else if ((Y_Flag == -1) && (X_Flag == -1)) {
          turn_L90();
        }
        one_x_flag = 1;
      }
    }
  }
}
/**********************************************************************************************/
void short_cut_x() {
  check_avoidence = 1;
  while (one_x_flag == 0) {
    scaling();
    cal_pos();
    t.update();
    if ((digitalRead(left) == white) && (digitalRead(center) == black) && (digitalRead(right) == white)) {
      if (particle_flag == 0) {
        reverse();
      }
      if (particle_flag == 1) {
        forward();
      }
    }

    if (err > margin_err)  //the comparison sign might be wrong if the "correct" functions names are the reverse of the actual movement.
    {
      correct_right();
    }

    else if (err < -margin_err) {
      correct_left();
    } 
   else if((sensor_reads[0] < margin) && (sensor_reads[1] > margin) && (sensor_reads[2] < margin)) 
    {
      reverse();
    }
    if ((sensor_reads[0] > margin) && (sensor_reads[1] > margin) && (sensor_reads[2] > margin))  {
      if (particle_flag == 0) {
        stop();
        delay(500);
        forward();
        delay(800);
        stop();
        delay(1000);
        if ((X_Flag == 1) && (Bonnok_P_Y < MAX_Y)) {
          turn_L90();
          Y_Flag = 1;
        } else if ((X_Flag == 1) && (Bonnok_P_Y == MAX_Y)) {
          turn_R90();
          Y_Flag = -1;
        } else if ((X_Flag == -1) && (Bonnok_P_Y < MAX_Y)) {
          turn_R90();
          Y_Flag = 1;
        } else if ((X_Flag == -1) && (Bonnok_P_Y == MAX_Y)) {
          turn_L90();
          Y_Flag = -1;
        }
        particle_flag = 1;
      }
      //////////////////////////////////////////////////////////////////////
      else if (particle_flag == 1) {
        forward();
        delay(500);
        y--;
        Bonnok_P_Y += Y_Flag;
        if ((Y_Flag == 1) && (X_Flag == 1)) {
          turn_R90();
        } else if ((Y_Flag == 1) && (X_Flag == -1)) {
          turn_L90();
        } else if ((Y_Flag == -1) && (X_Flag == 1)) {
          turn_L90();
        } else if ((Y_Flag == -1) && (X_Flag == -1)) {
          turn_R90();
        }
        one_x_flag = 1;
      }
    }
  }
}
