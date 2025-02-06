#pragma once;
/*  Serial  */
unsigned char i2cAddress = 128; // compatible to byte datatype of arduino
#define MAX_BYTES 24

// Define the time step for interpolating the middle values between time frames. Lesser the time step, more smooth the movement as more middle values are interpolated.
#define stepTime 50 // milliseconds

// Defining Motor Positions on the LU9685-20CU i.e. Define where each motor is connected to in the servo controller.
#define rightHipYawMotor 0
#define rightHipRollMotor 1
#define rightHipPitchMotor 2
#define rightKneeMotor 3
#define rightAnkleMotor 4
#define rightFootMotor 5
#define leftHipYawMotor 6
#define leftHipRollMotor 7
#define leftHipPitchMotor 8
#define leftKneeMotor 9
#define leftAnkleMotor 10
#define leftFootMotor 11
#define rightShoulderPitchMotor 12
#define leftShoulderPitchMotor 13
#define rightShoulderRollMotor 14
#define leftShoulderRollMotor 15
#define rightArmMotor 16
#define leftArmMotor 17
#define torsoMotor 18
#define headMotor 19

// Defining the Fixed Offset of motor to reach the initial position.
#define rightHipYawMotorOffset 84
#define rightHipRollMotorOffset 72
#define rightHipPitchMotorOffset 90
#define rightKneeMotorOffset 90
#define rightAnkleMotorOffset 136
#define rightFootMotorOffset 94
#define leftHipYawMotorOffset 80
#define leftHipRollMotorOffset 97
#define leftHipPitchMotorOffset 95
#define leftKneeMotorOffset 74
#define leftAnkleMotorOffset 130
#define leftFootMotorOffset 86
#define rightShoulderPitchMotorOffset 90
#define leftShoulderPitchMotorOffset 90
#define rightShoulderRollMotorOffset 90
#define leftShoulderRollMotorOffset 49
#define rightArmMotorOffset 90
#define leftArmMotorOffset 90
#define torsoMotorOffset 90 // Set randomly for now
#define headMotorOffset 90  // Set randomly for now

// Setting Direction to match the values directly from the simulation
#define rightHipYawMotorDirection -1       // Set Randomly for now
#define rightHipRollMotorDirection -1      // Set Randomly for now
#define rightHipPitchMotorDirection 1      // Set Randomly for now
#define rightKneeMotorDirection 1          // Set Randomly for now
#define rightAnkleMotorDirection -1        // Set Randomly for now
#define rightFootMotorDirection 1          // Set Randomly for now
#define leftHipYawMotorDirection -1        // Set Randomly for now
#define leftHipRollMotorDirection -1       // Set Randomly for now
#define leftHipPitchMotorDirection -1      // Set Randomly for now
#define leftKneeMotorDirection -1          // Set Randomly for now
#define leftAnkleMotorDirection 1          // Set Randomly for now
#define leftFootMotorDirection 1           // Set Randomly for now
#define rightShoulderPitchMotorDirection 1 // Set Randomly for now
#define leftShoulderPitchMotorDirection -1 // Set Randomly for now
#define rightShoulderRollMotorDirection -1 // Set Randomly for now
#define leftShoulderRollMotorDirection -1  // Set Randomly for now
#define rightArmMotorDirection 1           // Set Randomly for now
#define leftArmMotorDirection 1            // Set Randomly for now
#define torsoMotorDirection 1              // Set Randomly for now
#define headMotorDirection 1               // Set randomly for now