#include "main.h"


int Bonnok_P_X = 1, Bonnok_P_Y = 1;
int DIST_X = 1, DIST_Y = 3;
int X_Flag = 0, Y_Flag = 1;
int y = 0, x = 0;
char negative_flag = 0 , particle_flag = 0 , one_x_flag = 0;
char avoidence = 0 , count = 0 , t = 0 ;

void setup()
// put your setup code here, to run once:
{
  pinMode(right_motor_p, OUTPUT);
  pinMode(right_motor_N, OUTPUT);
  pinMode(left_motor_p, OUTPUT);
  pinMode(left_motor_N, OUTPUT);
  pinMode( Rmotor_speed, OUTPUT);
  pinMode( Lmotor_speed, OUTPUT);
  pinMode(right, INPUT);
  pinMode(center, INPUT);
  pinMode(left, INPUT);
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  Serial.begin(9600);
}

void loop() {



  // put your main code here, to run repeatedly:
  y = DIST_Y - Bonnok_P_Y;
  x = DIST_X - Bonnok_P_X;
  char check = x;
  char check_avoidence = 0 ;

  /******************************************************************************************** Moving in Y axis*********************************************************************************************/
  ////////////////////////////////////////////////////// Ignoring first values of distance////////////////////////////////////////
  while ( count < 4 )
  {

    count++ ;

    Particle_Detecter() ;
  }
  ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
y_axis: while (y != 0) {


    Particle_Detecter() ;
    //delay(100);

    if (distance < 8 )
    {
      check_avoidence = 1 ;
      while (one_x_flag == 0)
      {
        if ((digitalRead(left) == white) && (digitalRead(center) == black) && (digitalRead(right) == white)) {
          if (particle_flag == 0)
          {
            reverse();

          }
          if (particle_flag == 1)
          {
            forward();
          }

        }

        if ((digitalRead(left) == black) && (digitalRead(center) == white) && (digitalRead(right) == white)) {
          if (particle_flag == 1)
          {
            correct_left();
          }
        }

        if ((digitalRead(left) == white) && (digitalRead(center) == white) && (digitalRead(right) == black)) {
          if (particle_flag == 1)
          {
            correct_right();
          }


        }
        if ((digitalRead(left) == black) && (digitalRead(center) == black) && (digitalRead(right) == black)) {
          if (particle_flag == 0)
          {
            stop();
            delay(500);
            forward();
            delay(700);
            stop();
            delay(1000);
            if ((Y_Flag == 1) && (x > 0)) {
              turn_R90();
              X_Flag = 1;
            }
            else if ((Y_Flag == 1) && (x < 0)) {
              turn_L90();
              X_Flag = -1;
              x *= (-1);
              negative_flag = 1 ;
            }
            else if ((Y_Flag == -1) && (x > 0)) {
              turn_L90();
              X_Flag = 1;
            }
            else if ((Y_Flag == -1) && (x < 0)) {
              turn_R90();
              X_Flag = -1;
              x *= (-1);
              negative_flag = 1 ;
            }
            ///////////////////////////////////////// x = 0 /////////////////////////
            else if ( x == 0 )
            {
              if ((Y_Flag == 1) && (Bonnok_P_X < MAX_X )) {
                turn_R90();
                X_Flag = 1;
              }
              else if ((Y_Flag == 1) && (Bonnok_P_X == MAX_X )) {
                turn_L90();
                X_Flag = -1;
              }
              else if ((Y_Flag == -1) && (Bonnok_P_X < MAX_X)) {
                turn_L90();
                X_Flag = 1;
              }
              else if ((Y_Flag == -1) && (Bonnok_P_X == MAX_X)) {
                turn_R90();
                X_Flag = -1;
              }
              check = -1 ;
            }
            particle_flag = 1 ;
          }
          //////////////////////////////////////////////////////////////////////
          else if (particle_flag == 1)
          {
            forward();
            delay(300);
            x--;
            Bonnok_P_X += X_Flag;
            if ( (Y_Flag == 1) && (X_Flag == 1) )
            {
              turn_L90();
            }
            else if ( (Y_Flag == 1) && (X_Flag == -1) )
            {
              turn_R90();
            }
            else if ( (Y_Flag == -1) && (X_Flag == 1) )
            {
              turn_R90();
            }
            else if ( (Y_Flag == -1) && (X_Flag == -1) )
            {
              turn_L90();
            }
            one_x_flag = 1 ;
          }






        }
      }
    }

    //////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    if (y < 0) {
      turn_180();
      Y_Flag = -1;
      y *= (-1);
    }
    if ((digitalRead(left) == white) && (digitalRead(center) == black) && (digitalRead(right) == white)) {
      forward();
    }

    if ((digitalRead(left) == black) && (digitalRead(center) == white) && (digitalRead(right) == white)) {

      correct_left();
    }

    if ((digitalRead(left) == white) && (digitalRead(center) == white) && (digitalRead(right) == black)) {

      correct_right();
    }
    if ((digitalRead(left) == black) && (digitalRead(center) == black) && (digitalRead(right) == black)) {
      forward();
      delay(300);
      y--;
      Bonnok_P_Y += Y_Flag;
      goto   y_axis;
    }

  }
  /******************************************************************************************** Rotation around X axis*********************************************************************************************/

  if ((Y_Flag == 1) && (x > 0)) {
    turn_R90();
    X_Flag = 1;
  }
  else if ((Y_Flag == 1) && (x < 0)) {
    turn_L90();
    X_Flag = -1;
    x *= (-1);
  }
  else if ((Y_Flag == -1) && (x > 0)) {
    turn_L90();
    X_Flag = 1;
  }
  else if ((Y_Flag == -1) && (x < 0)) {
    turn_R90();
    X_Flag = -1;
    x *= (-1);
  }

  /********************************************************************************************Moving in X axis*********************************************************************************************/
  particle_flag = 0 ;
  one_x_flag = 0;

X_axis: while (x != 0) {


    Particle_Detecter() ;
    //delay(100);

    if ( distance < 8 )
    {
      check_avoidence = 1 ;
      while (one_x_flag == 0)
      {
        if ((digitalRead(left) == white) && (digitalRead(center) == black) && (digitalRead(right) == white)) {
          if ( particle_flag == 0 )
          {
            reverse();
          }
          if ( particle_flag == 1 )
          {
            forward();
          }

        }

        if ((digitalRead(left) == black) && (digitalRead(center) == white) && (digitalRead(right) == white)) {

          correct_left();
        }

        if ((digitalRead(left) == white) && (digitalRead(center) == white) && (digitalRead(right) == black)) {

          correct_right();
        }
        if ((digitalRead(left) == black) && (digitalRead(center) == black) && (digitalRead(right) == black)) {
          if ( particle_flag == 0)
          {
            stop();
            delay(500);
            forward();
            delay(700);
            stop();
            delay(1000);
            if ((X_Flag == 1) && ( Bonnok_P_Y < MAX_Y )) {
              turn_L90();
              Y_Flag = 1;
            }
            else if ((X_Flag == 1) && ( Bonnok_P_Y == MAX_Y )) {
              turn_R90();
              Y_Flag = -1;
            }
            else if ((X_Flag == -1) && ( Bonnok_P_Y < MAX_Y)) {
              turn_R90();
              Y_Flag = 1;
            }
            else if ((X_Flag == -1) && ( Bonnok_P_Y == MAX_Y)) {
              turn_L90();
              Y_Flag = -1;
            }
            particle_flag = 1 ;
          }
          //////////////////////////////////////////////////////////////////////
          else if (particle_flag == 1)
          {
            forward();
            delay(500);
            y--;
            Bonnok_P_Y += Y_Flag;
            if ( (Y_Flag == 1) && (X_Flag == 1) )
            {
              turn_R90();
            }
            else if ( (Y_Flag == 1) && (X_Flag == -1) )
            {
              turn_L90();
            }
            else if ( (Y_Flag == -1) && (X_Flag == 1) )
            {
              turn_L90();
            }
            else if ( (Y_Flag == -1) && (X_Flag == -1) )
            {
              turn_R90();
            }
            one_x_flag = 1 ;
          }


        }


      }
    }

    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////


    if ((digitalRead(left) == white) && (digitalRead(center) == black) && (digitalRead(right) == white)) {

      forward();
    }

    if ((digitalRead(left) == black) && (digitalRead(center) == white) && (digitalRead(right) == white)) {

      correct_left();
    }

    if ((digitalRead(left) == white) && (digitalRead(center) == white) && (digitalRead(right) == black)) {

      correct_right();
    }
    if ((digitalRead(left) == black) && (digitalRead(center) == black) && (digitalRead(right) == black)) {
      forward();
      delay(300);
      x--;
      Bonnok_P_X += X_Flag;
      goto   X_axis;
    }

  }

  /*************************************************************************************************Parking*********************************************************************************************/



  if (check != 0) {
    if ( (X_Flag == 1)  ) {
      turn_L90();
    }
    else if ( (X_Flag == -1)  ) {
      turn_R90();
    }
    else if ( (check == 1) && (check_avoidence == 1) )
    {
      /* NOTHING */
    }
  }
  else if (Y_Flag == -1) {
    turn_180();
  }
  //////////////////////////////////////////////////////// REMAIN Y ///////////////////////////////////////////////
  if ( y != 0 )
  {
    if ( Y_Flag == -1 )
    {
      y *= (-1) ;
    }
    Y_Flag == 1 ;
    goto y_axis ;
  }
  /////////////////////////////////////////////////////////////////////


  Y_Flag = 1, X_Flag = 0;
  stop();
  y = 0 ;
  x = 0 ;
}


