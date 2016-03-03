# line-follow

The aim of this project is to build a line follower robot with minimum number of ready-made parts such as IR sensors and PCBs. We make our own PCB and sensors so that we can cut down on the costs and learn more about the working of some specific circuits.

In this 'bot', we use an Arduino Uno R3, an open source hardware from Arduino/Genuino which is built upon AtMel AtMega328P micro-controller. Also in the bot is two 100 RPM DC motors and a metal chassis. To run the bot, we use a 12 V Lead-Acid battery which has a maximum current output of 1.2 A in an hour.

To regulate the output voltage of the Lead-Acid battery, we use a IC7805 to bring the voltage down to 5V. We use seperate power supply for Arduino which is a 9V Hi-Watt non-rechargeable battery. To run the motors, we use a L293D motor driver to drive the motors using Arduino.

Coming to the sensor positions, we have lined up 5 IR receiver - emitter pairs in the front. The output of the IR receiver is sent back to the Arduino. We are still discussing about the need for the sixth sensor which might be put up in front of the bot, and ahead of the existing sensors so that we can detect the end of the line or detect a discontinuity.
