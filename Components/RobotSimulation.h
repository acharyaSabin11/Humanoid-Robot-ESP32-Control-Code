#include "./LeftHandSimulation.h"
#include "./RightHandSimulation.h"
#include "./../constants.h"
#include "./Hand.h"
#include "./../utilities.h"

class RobotSimulation
{
    LeftHandSimulation leftHandSimulation = LeftHandSimulation();
    RightHandSimulation rightHandSimulation = RightHandSimulation();

public:
    void pickUpObject()
    {
        Hand currentRightState = rightHandSimulation.handPositions[0];
        Hand nextRightState = rightHandSimulation.handPositions[1];
        Hand currentLeftState = leftHandSimulation.handPositions[0];
        Hand nextLeftState = leftHandSimulation.handPositions[1];
        int timeFramesCount = sizeof(rightHandSimulation.timeData) / sizeof(float);
        for (int i = 0; i < timeFramesCount; i++)
        {
            // int currValue = i % (timeFramesCount - 1);
            // Get time to move to next frame
            float time = rightHandSimulation.timeData[i];
            // Get number of iterations of to reach next frame
            float numIter = time * 1000 / stepTime;

            // Calculate the angle step for each value of iteration;
            // Right Hand
            float rightShoulderPitchStep = (nextRightState.shoulderPitch() - currentRightState.shoulderPitch()) / numIter;
            float rightShoulderRollStep = (nextRightState.shoulderRoll() - currentRightState.shoulderRoll()) / numIter;
            float rightArmStep = (nextRightState.arm() - currentRightState.arm()) / numIter;
            // Left Hand
            float leftShoulderPitchStep = (nextLeftState.shoulderPitch() - currentLeftState.shoulderPitch()) / numIter;
            float leftShoulderRollStep = (nextLeftState.shoulderRoll() - currentLeftState.shoulderRoll()) / numIter;
            float leftArmStep = (nextLeftState.arm() - currentLeftState.arm()) / numIter;

            // Loop for numIter
            for (int j = 1; j <= numIter; j++)
            {
                // For Right Arm
                moveStep(rightShoulderPitchMotor, static_cast<int>(currentRightState.shoulderPitch() + rightShoulderPitchStep * j));
                moveStep(rightShoulderRollMotor, static_cast<int>(currentRightState.shoulderRoll() + rightShoulderRollStep * j));
                moveStep(rightArmMotor, static_cast<int>(currentRightState.arm() + rightArmStep * j));
                // For Left Arm
                moveStep(leftShoulderPitchMotor, static_cast<int>(currentLeftState.shoulderPitch() + leftShoulderPitchStep * j));
                moveStep(leftShoulderRollMotor, static_cast<int>(currentLeftState.shoulderRoll() + leftShoulderRollStep * j));
                moveStep(leftArmMotor, static_cast<int>(currentLeftState.arm() + leftArmStep * j));
                delay(stepTime);
            }
            currentRightState = nextRightState;
            currentLeftState = nextLeftState;
            nextRightState = rightHandSimulation.handPositions[(i + 2) % (timeFramesCount - 1)];
            nextLeftState = leftHandSimulation.handPositions[(i + 2) % (timeFramesCount - 1)];
        }
    };
};