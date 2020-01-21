//Detect if closed loop

//For å starte node i ROS:
//rosrun rosserial_python serial_node.py /dev/ttyACM0






#include <ros.h>
//#include <std_msgs/Bool.h>

#include <std_msgs/UInt8.h>

ros::NodeHandle nh;

 //std_msgs::Bool left_msg;
//std_msgs::Bool right_msg;

std_msgs::UInt8 claw_msg;


ros::Publisher pub_claw("claw_contact", &claw_msg);



const int sensor_pin_1 = A0; //input_1 signal
const int sensor_pin_2 = A1; //input_2 signal


unsigned int sensor_value_1 = 0; //variable to store the value coming from the sensor
unsigned int sensor_value_2 = 0;

const int ledPin = 13;



void setup() {
  // put your setup code here, to run once:
  nh.initNode();
  nh.advertise(pub_claw);
  
  pinMode(ledPin,OUTPUT);
  //Serial.begin(9600);
  
}

void loop() {

  sensor_value_1 = analogRead(sensor_pin_1);
  sensor_value_2 = analogRead(sensor_pin_2);

  //debug info
  Serial.println(sensor_value_1);
  Serial.println(sensor_value_2);
  //****


  if (sensor_value_1 > 950 && sensor_value_2 > 950) {
    digitalWrite(ledPin,HIGH);
    claw_msg.data = 3;
    pub_claw.publish(&claw_msg);
  }

  else if (sensor_value_1 > 950) {
    digitalWrite(ledPin,HIGH);
    claw_msg.data = 1;
    pub_claw.publish(&claw_msg);
  }
  
  else if (sensor_value_2 > 950) {
    digitalWrite(ledPin,HIGH);
    claw_msg.data = 2;
    pub_claw.publish(&claw_msg);
  }
  
  else {
    digitalWrite(ledPin,LOW);
    claw_msg.data = 0;
    pub_claw.publish(&claw_msg);
  }

  
  nh.spinOnce();
}
