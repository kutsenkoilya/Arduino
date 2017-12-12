/*
 Stepper.h - - Stepper library for Wiring/Arduino - Version 0.5
 
 Original library     (0.1) by Tom Igoe.
 Two-wire modifications   (0.2) by Sebastian Gassner
 Combination version   (0.3) by Tom Igoe and David Mellis
 Bug fix for four-wire   (0.4) by Tom Igoe, bug fix from Noah Shibley
 Add Half Step mode      (0.5) by D Traynor
 ********Adapted for Arduino Kit geared stepper motor (28BYJ-48) by Rudy Schlaf 2/2014*********
 ********Test for other motors!****************************************************************
 
 Drives a unipolar or bipolar stepper motor using  2 wires or 4 wires
 
 When wiring multiple stepper motors to a microcontroller,
 you quickly run out of output pins, with each motor requiring 4 connections.
 
 By making use of the fact that at any time two of the four motor
 coils are the inverse  of the other two, the number of
 control connections can be reduced from 4 to 2.
 
 A slightly modified circuit around a Darlington transistor array or an L293 H-bridge
 connects to only 2 microcontroler pins, inverts the signals received,
 and delivers the 4 (2 plus 2 inverted ones) output signals required
 for driving a stepper motor.
 
 The sequence of for fullstep control signals for 4 control wires is as follows:
 
 # Modified from the original 1010, 0110, 0101, 1001 - since the 28BYJ-48 motor would not reverse
 
 Step C0 C1 C2 C3
 1  1  0  0  0
 2  0  1  0  0
 3  0  0  1  0
 4  0  0  0  1
 
 # Added this 8 step sequence for halfstep control for 4 control wires as follows: (not tested for 28BYJ-48)
 
 Step C0 C1 C2 C3
 1  1  0  0  1
 2  1  0  0  0
 3  1  1  0  0
 4  0  1  0  0
 5  0  1  1  0
 6  0  0  1  0
 7  0  0  1  1
 8  0  0  0  1
 
 The sequence of controls signals for 2 control wires is as follows
 (columns C1 and C2 from above):
 
 Step C0 C1 (not tested for 28BYJ-48)
 1  0  1
 2  1  1
 3  1  0
 4  0  0
 
 The circuits can be found at
 http://www.arduino.cc/en/Tutorial/Stepper
 */

// ensure this library description is only included once
#ifndef StepperAK_h
#define StepperAK_h

// library interface description
class Stepper {
public:
    // constructors:
    // Additional parameter for the modulo count
    Stepper(int number_of_steps, int motor_pin_1, int motor_pin_2);
    Stepper(int number_of_steps, int motor_pin_1, int motor_pin_2, int motor_pin_3, int motor_pin_4);    
    // speed setter method:
    void setSpeed(long whatSpeed);
    
    // mover method:
    void step(int number_of_steps);
    
    int version(void);
    
private:
    void stepMotor(int this_step);
    
    int direction;        // Direction of rotation
    int speed;          // Speed in RPMs
    unsigned long step_delay;    // delay between steps, in ms, based on speed
    int number_of_steps;      // total number of steps this motor can take
    int pin_count;        // whether you're driving the motor with 2 or 4 pins
    int step_number;        // which step the motor is on
    
    // motor pin numbers:
    int motor_pin_1;
    int motor_pin_2;
    int motor_pin_3;
    int motor_pin_4;
    
    // Used to indicate the number of steps in each sequence
    int mod_count;
    
    long last_step_time;      // time stamp in ms of when the last step was taken
};

#endif