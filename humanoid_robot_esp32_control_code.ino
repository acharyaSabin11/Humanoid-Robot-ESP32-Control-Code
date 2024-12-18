// For I2C communication.
#include <Wire.h>
// #include "./Components/LegSimulation.h"
#include "./Components/RobotSimulation.h"
#include "./constants.h"
#include "./globalObjects.h"

// Custom Classes

// My One time Objects
// LegSimulation rightLegSimulation = LegSimulation();
// Leg currentState = rightLegSimulation.legPositions[0];
// Leg nextState = rightLegSimulation.legPositions[1];
// int timeFramesCount = sizeof(rightLegSimulation.timeData) / sizeof(float);
RobotSimulation robotSimulation = RobotSimulation();

void setup()
{
  // For Communication with computer
  Serial.begin(115200);
  // For I2C communication begining
  Wire.begin();
}

void loop()
{
  robotSimulation.pickUpObject();
  delay(2000);

  // Wire.beginTransmission(i2cAddress);
  // buffer[0] = 10;
  // buffer[1] = 120;
  // Wire.write(buffer,2);
  // Wire.endTransmission();
  // // STEPS:
  // //  1. Loop for each value of time frames;
  // for (int i = 0; i < timeFramesCount; i++)
  // {
  //   // int currValue = i % (timeFramesCount - 1);
  //   // Get time to move to next frame
  //   float time = rightLegSimulation.timeData[i];
  //   // Get number of iterations of to reach next frame
  //   float numIter = time * 1000 / stepTime;

  //   // Calculate the angle step for each value of iteration;
  //   float hipStep = (nextState.hip() - currentState.hip()) / numIter;
  //   float thighStep = (nextState.thigh() - currentState.thigh()) / numIter;
  //   float kneeStep = (nextState.knee() - currentState.knee()) / numIter;
  //   float ankleStep = (nextState.ankle() - currentState.ankle()) / numIter;
  //   float footStep = (nextState.foot() - currentState.foot()) / numIter;
  //   Serial.print("Frame");
  //   Serial.println(i);
  //   Serial.println(currentState.foot());
  //   // Loop for numIter
  //   for (int j = 1; j <= numIter; j++)
  //   {
  //     // For Hip
  //     moveStep(hipMotor, static_cast<int>(currentState.hip() + hipStep * j));
  //     // For Thigh
  //     moveStep(thighMotor, static_cast<int>(currentState.thigh() + thighStep * j));
  //     // For Knee
  //     moveStep(kneeMotor, static_cast<int>(currentState.knee() + kneeStep * j));
  //     // For Ankle
  //     moveStep(ankleMotor, static_cast<int>(currentState.ankle() + ankleStep * j));
  //     // For Foot
  //     moveStep(footMotor, static_cast<int>(currentState.foot() + footStep * j));
  //     delay(stepTime);
  //   }
  //   // delay(1000);

  //   // currentState = rightLegSimulation.legPositions[(i+1)%(timeFramesCount-1)];
  //   currentState = nextState;
  //   nextState = rightLegSimulation.legPositions[(i + 2) % (timeFramesCount - 1)];
  // }
  // Wire.endTransmission();
}
