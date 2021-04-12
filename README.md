# Baremetal_Arduino_Tiltswitch
Takes the outputs of 2 2 pole tilt switches and displays their current state(s) on 4 LEDs. Each tilt switch covers 2 cardinal directions, and is named as such in the code. In other words, one switch will shine one light if the switch is tilted towards East, and turn on the other light if it goes West. The same is true of North/South with a different pair of LEDs.

To compile/run the program on the arduino, wire each output(digital pins 10-13) to LEDs on a breadboard that then go through resistors(2.2k was used in my case) to ground. The tilt switches I used are TM1000Q switches made by E-Switch.

Wire the center pins to +5V and the 2 outside pin sets to the East/West and North/South input pins(Digital pins 5/6 and 2/3), keep the pairing. My wiring can be seen in the below video as a reference.

Using either the Arduino IDE or your preferred method, find the COM port the Arduino is on. The default value for the compile script is port 3, so you may need to change it.

Then, using the included python script, type "python compile_script.py 4" into the command line after navigating to the code containing file. The program should compile and the LEDs should begin illuminating with movement of the tiltswitches.

See this video for demostration of code on the Arduino: https://youtu.be/dOw_kMjU6T8
