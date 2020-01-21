# control_hook-detection
Arduino code for detecting contact with antenna module using an electric circuit


* (for detecting other kinds of hooks, contact Simen)


*********************

Using an Arduino UNO and a simple electric circuit, we can detect if the left and/or right hook on the Drone has contact with the antenna module. This Arduino is set up as a ROS node. 

*********************

How it's set up:

A circuit on each claw with a 5v output is connected into the A0, A1 ports of the Arduino. Input impedance is 100MOhm. Make sure the inputs are on Pull Down.

The ROS message will output an integer code on the topic /claw_contact

The code:
0 - no detection
1 - left hook
2 - right hook
3 - both


