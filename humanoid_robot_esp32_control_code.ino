// For I2C communication.
#include <Wire.h>
#include "./Components/LegSimulation.h"

// Define where each motor is connected to in the servo controller.
#define hipMotor 0
#define thighMotor 1
#define kneeMotor 2
#define ankleMotor 3
#define footMotor 4

// Define the time step for interpolating the middle values between time frames. Lesser the time step, more smooth the movement as more middle values are interpolated.
#define stepTime 50 // milliseconds

// Custom Classes

/*  Serial  */
#define MAX_BYTES 24
byte buffer[MAX_BYTES];
byte i2cAddress = 128;

// My One time Objects
LegSimulation rightLegSimulation = LegSimulation();
Leg currentState = rightLegSimulation.legPositions[0];
Leg nextState = rightLegSimulation.legPositions[1];
int timeFramesCount = sizeof(rightLegSimulation.timeData) / sizeof(float);

void setup()
{
  // For Communication with computer
  Serial.begin(115200);
  // For I2C communication begining
  Wire.begin();
}

void loop()
{
  // STEPS:
  //  1. Loop for each value of time frames;
  for (int i = 0; i < timeFramesCount; i++)
  {
    // int currValue = i % (timeFramesCount - 1);
    // Get time to move to next frame
    float time = rightLegSimulation.timeData[i];
    // Get number of iterations of to reach next frame
    float numIter = time * 1000 / stepTime;

    // Calculate the angle step for each value of iteration;
    float hipStep = (nextState.hip() - currentState.hip()) / numIter;
    float thighStep = (nextState.thigh() - currentState.thigh()) / numIter;
    float kneeStep = (nextState.knee() - currentState.knee()) / numIter;
    float ankleStep = (nextState.ankle() - currentState.ankle()) / numIter;
    float footStep = (nextState.foot() - currentState.foot()) / numIter;
    Serial.print("Frame");
    Serial.println(i);
    Serial.println(currentState.foot());
    // Loop for numIter
    for (int j = 1; j <= numIter; j++)
    {
      // Serial.print("HipStep");
      // Serial.println(hipStep);
      // For Hip
      moveStep(hipMotor, static_cast<int>(currentState.hip() + hipStep * j));
      // //For Thigh
      moveStep(thighMotor, static_cast<int>(currentState.thigh() + thighStep * j));
      // //For Knee
      moveStep(kneeMotor, static_cast<int>(currentState.knee() + kneeStep * j));
      // //For Ankle
      moveStep(ankleMotor, static_cast<int>(currentState.ankle() + ankleStep * j));
      // For Foot
      moveStep(footMotor, static_cast<int>(currentState.foot() + footStep * j));
      delay(stepTime);
      // Serial.println(buffer[0]);
      // wire.write()
    }
    // delay(1000);

    // currentState = rightLegSimulation.legPositions[(i+1)%(timeFramesCount-1)];
    currentState = nextState;
    nextState = rightLegSimulation.legPositions[(i + 2) % (timeFramesCount - 1)];
  }
  // Wire.endTransmission();
}

void moveStep(int motorNumber, int angleInDegrees)
{
  buffer[0] = motorNumber;
  buffer[1] = angleInDegrees;
  Serial.println(buffer[0]);
  Serial.println(buffer[1]);
  // delay(10);
  Wire.beginTransmission(i2cAddress);
  Wire.write(buffer, 2);
  Wire.endTransmission();
}
