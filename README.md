Useless Box

A useless box is basically a machine which turns itself off. However, with a few additional servos, and a little programming... 

A demo video of the box. Because of randomization the video doesn't include all different behavior patterns - there are more...

https://www.youtube.com/watch?v=cCtrusTWms4

Features / Surprises

Control the door and "hand" separately



I utilized the MotorShield is clearly overkill for this project it reduces the complexity of the required electronics knowledge (and soldering) quite a bit.



Hardware
Electronics - Parts List
The following parts were used:
Amount 	Part Type 	Properties
1 	Arduino Uno 	
1 	MotorShield 	Rev3
2 	Basic Servo 	You should use a high-torque servo for the arm
1 	Micro Servo 	
1 	Metallic Toggle Switch 	
1	Power Supply
2	Leds



Material

Wooden box with enough space to fit everything into
Some chipboard ~ 4mm to build the arm and mountings
Cables



Tools

Solder
screwdriver



Operation

My useless box fulfills of course the basic functionality of turning itself off. But using a few additional pieces of equipment it can:



Software

The box has basically a fixed set of "moves" it can do to turn of the switch after it has been turned on. To make things a little more interesting, the moves are randomly used to surprise the operator.

The whole code is quite easy - there's nothing special about it. I've created a few bases classes to control every peripheral and another class "Moves" to implement the patterns. This is mainly because the basic Arduino way of programming leads to lots of code duplication and unreadable code.
