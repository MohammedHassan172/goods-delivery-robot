#include <ros.h>
#include <std_msgs/Float64MultiArray.h>
// #include <Servo.h>
#include <ESP32Servo.h>
#include <std_msgs/UInt16.h>


//Set up the ros node and publisher
std_msgs::Float64MultiArray Distance;
ros::Publisher pub_sonar("sonar",&Distance);
ros::NodeHandle nh;

#define trigPin_1 13
#define echoPin_1 14

#define trigPin_2 27
#define echoPin_2 26

#define trigPin_3 25
#define echoPin_3 33

#define trigPin_4 32
#define echoPin_4 35

char trig_pins[4] = {trigPin_1,trigPin_2,trigPin_3,trigPin_4};
char echo_pins[4] = {echoPin_1,echoPin_2,echoPin_3,echoPin_4};
float distances[4] = {0.0,0.0,0.0,0.0};

// int trigPin = 13;    // Trigger
// int echoPin = 14;    // Echo

// defines variables
long duration;
// float distance;
Servo servo;

void servo_cb( const std_msgs::UInt16& cmd_msg){
  servo.write(cmd_msg.data); //set servo angle, should be from 0-180  
}

ros::Subscriber<std_msgs::UInt16> sub("servo", servo_cb);

void setup() {
 
  Serial.begin(57600); // Starts the serial communication
  //Define inputs and outputs
  pinMode(trigPin_1, OUTPUT);
  pinMode(echoPin_1, INPUT);
  pinMode(trigPin_2, OUTPUT);
  pinMode(echoPin_2, INPUT);
  pinMode(trigPin_3, OUTPUT);
  pinMode(echoPin_3, INPUT);
  pinMode(trigPin_4, OUTPUT);
  pinMode(echoPin_4, INPUT);
  nh.initNode();
  nh.advertise(pub_sonar);
  nh.subscribe(sub);
  Distance.layout.dim = (std_msgs::MultiArrayDimension *) malloc(sizeof(std_msgs::MultiArrayDimension) * 4);
  Distance.layout.dim[0].label = "reads";
  Distance.layout.dim[0].size = 4;
  Distance.layout.dim[0].stride = 1 * 4;
  Distance.data = (float *)malloc(sizeof(float)*4);
  Distance.layout.dim_length = 0;
  Distance.data_length = 4;
  ESP32PWM::allocateTimer(0);
	ESP32PWM::allocateTimer(1);
	ESP32PWM::allocateTimer(2);
	ESP32PWM::allocateTimer(3);
	servo.setPeriodHertz(50); 
  servo.attach(16); //attach it to pin 9
}




void loop() {
// Clears the trigPin
distance_read();

// Serial.print(distances[0]);
// Serial.print("\t");
// Serial.print(distances[1]);
// Serial.print("\t");
// Serial.print(distances[2]);
// Serial.print("\t");

// Serial.print(distances[3]);
// Serial.println("\t");

Distance.data[0]=distances[0];
Distance.data[1]=distances[1];
Distance.data[2]=distances[2];
Distance.data[3]=distances[3];
pub_sonar.publish(&Distance);
nh.spinOnce();

delay(100);
}

void distance_read()
{
   for(int i = 0; i < 4; i++)
  {
    digitalWrite(trig_pins[i], LOW);
    delayMicroseconds(2);

    // Sets the trigPin on HIGH state for 10 micro seconds
    digitalWrite(trig_pins[i], HIGH);
    delayMicroseconds(10);
    digitalWrite(trig_pins[i], LOW);

    // Reads the echoPin, returns the sound wave travel time in microseconds
    duration = pulseIn(echo_pins[i], HIGH);

    // Calculating the distance
    distances[i]= duration*0.034/2;
    //publishing data

  }

}