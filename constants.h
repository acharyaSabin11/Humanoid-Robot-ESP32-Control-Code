#pragma once;
/*  Serial  */
unsigned char i2cAddress = 128; // compatible to byte datatype of arduino
#define MAX_BYTES 24

// Define the time step for interpolating the middle values between time frames. Lesser the time step, more smooth the movement as more middle values are interpolated.
#define stepTime 50 // milliseconds

// Defining Motor Positions on the LU9685-20CU i.e. Define where each motor is connected to in the servo controller.
#define hipMotor 0
#define thighMotor 1
#define kneeMotor 2
#define ankleMotor 3
#define footMotor 4
#define rightShoulderPitchMotor 5
#define rightShoulderRollMotor 6
#define rightArmMotor 7
#define leftShoulderPitchMotor 8
#define leftShoulderRollMotor 9
#define leftArmMotor 10