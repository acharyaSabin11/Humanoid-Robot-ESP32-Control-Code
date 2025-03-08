#pragma once;
/*  Serial  */
unsigned char i2cAddress = 128; // compatible to byte datatype of arduino
#define MAX_BYTES 24

// Define the time step for interpolating the middle values between time frames. Lesser the time step, more smooth the movement as more middle values are interpolated.
#define stepTime 50 // milliseconds

// Defining Motor Positions on the LU9685-20CU i.e. Define where each motor is connected to in the servo controller.
#define rightHipYawMotor 15
#define rightHipRollMotor 2
#define rightHipPitchMotor 4
#define rightKneeMotor 5
#define rightAnkleMotor 18
#define rightFootMotor 19
#define leftHipYawMotor 33
#define leftHipRollMotor 25
#define leftHipPitchMotor 26
#define leftKneeMotor 27
#define leftAnkleMotor 14
#define leftFootMotor 12
#define rightArmMotor 80
#define leftArmMotor 90
#define rightShoulderRollMotor 60
#define leftShoulderRollMotor 70
#define rightShoulderPitchMotor 40
#define leftShoulderPitchMotor 50
#define headMotor 23

// Defining the Fixed Offset of motor to reach the initial position.
// #define rightHipYawMotorOffset 94
// #define rightHipRollMotorOffset 90
// #define rightHipPitchMotorOffset 90
// #define rightKneeMotorOffset 119
// #define rightAnkleMotorOffset 105
// #define rightFootMotorOffset 85
// #define leftHipYawMotorOffset 92
// #define leftHipRollMotorOffset 92
// #define leftHipPitchMotorOffset 99
// #define leftKneeMotorOffset 70
// #define leftAnkleMotorOffset 81
// #define leftFootMotorOffset 86
// #define rightShoulderRollMotorOffset 65
// #define leftShoulderRollMotorOffset 105
// #define rightShoulderPitchMotorOffset 37
// #define leftShoulderPitchMotorOffset 135
// #define rightArmMotorOffset 90
// #define leftArmMotorOffset 83
// #define headMotorOffset 90 // Set randomly for now

#define rightHipYawMotorOffset 100
#define rightHipRollMotorOffset 90
#define rightHipPitchMotorOffset 101
#define rightKneeMotorOffset 92
#define rightAnkleMotorOffset 73
#define rightFootMotorOffset 85
#define leftHipYawMotorOffset 92
#define leftHipRollMotorOffset 92
#define leftHipPitchMotorOffset 95
#define leftKneeMotorOffset 84
#define leftAnkleMotorOffset 97
#define leftFootMotorOffset 86
#define rightShoulderRollMotorOffset 65
#define leftShoulderRollMotorOffset 105
#define rightShoulderPitchMotorOffset 37
#define leftShoulderPitchMotorOffset 135
#define rightArmMotorOffset 90
#define leftArmMotorOffset 83
#define headMotorOffset 90


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
#define headMotorDirection 1               // Set randomly for now