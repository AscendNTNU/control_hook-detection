//Detect if closed loop

//For å starte node i ROS:
//rosrun rosserial_python serial_node.py /dev/ttyACM0






#include <ros.h>
#include <std_msgs/Bool.h>

ros::NodeHandle nh;

std_msgs::Bool left_msg;
std_msgs::Bool right_msg;

ros::Publisher pub_claw_left("clawLEFT", &left_msg);
ros::Publisher pub_claw_right("clawRIGHT", &right_msg);


const int sensor_pin_1 = A0; //input_1 signal
const int sensor_pin_2 = A1; //input_2 signal


unsigned int sensor_value_1 = 0; //variable to store the value coming from the sensor
unsigned int sensor_value_2 = 0;

const int ledPin = 13;



void setup() {
  // put your setup code here, to run once:
  nh.initNode();
  nh.advertise(pub_claw_left);
  nh.advertise(pub_claw_right);
  
  pinMode(ledPin,OUTPUT);
  //Serial.begin(9600);

  
  
}

void loop() {
  // put your main code here, to run repeatedly:

  sensor_value_1 = analogRead(sensor_pin_1);
  sensor_value_2 = analogRead(sensor_pin_2);

  Serial.println(sensor_value_1);
  //Serial.println("/n");
  Serial.println(sensor_value_2);

  //Left sensor
  if (sensor_value_1 > 950) {
    digitalWrite(ledPin,HIGH);
    left_msg.data = 1;
    pub_claw_left.publish(&left_msg);
  }
  else {
    digitalWrite(ledPin,LOW);
    left_msg.data = 0;
    pub_claw_left.publish(&left_msg);
  }

  //Right sensor
  if (sensor_value_2 > 950) {
    digitalWrite(ledPin,HIGH);
    right_msg.data = 1;
    pub_claw_right.publish(&right_msg);
  }
  else {
    digitalWrite(ledPin,LOW);
    right_msg.data = 0;
    pub_claw_right.publish(&right_msg);
  }
  
  
  nh.spinOnce();
}
