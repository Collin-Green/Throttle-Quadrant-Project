# Throttle-Quadrant-Project
This Repository contains materials that I used to create a basic throttle quadrant game controller.
This project uses an Arduino Micro with an ATMega32u4 in order to make a throttle game controller.
The "Joystick" library for Arduino by Matthew Heironimus was used in this project.  This project wouldn't be possible without it.

The project uses a potentiometer and a simple voltage divider to create the throttle.  The potentiometer is a sliding potentiometer of a max resistance of 10k.  The series resistance used for the voltage divider is 40k.

There are also buttons that are used for utility purposes as well as an analog stick breakout board as a slew stick.

Problems with mechanical assembly:

Getting a handle to stay on the potentiometer (hot glue won't stick to the metal on the pot.)

Keeping the throttle from sliding while moving the thottle (use sticky pads and weights to rememdy this issue)
