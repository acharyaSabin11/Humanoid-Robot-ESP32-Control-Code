#pragma once
#include "./../constants.h"

class RightHand
{
    float shoulderPitchValue, shoulderRollValue, armValue;

public:
    // Default Constructor
    RightHand()
    {
    }

    RightHand(float shoulderPitch, float shoulderRoll, float arm)
    {
        this->shoulderPitchValue = shoulderPitch;
        this->shoulderRollValue = shoulderRoll;
        this->armValue = arm;
    }

    // Getters
    float shoulderPitch()
    {
        return (this->shoulderPitchValue * rightShoulderPitchMotorDirection) + rightShoulderPitchMotorOffset;
    }

    float shoulderRoll()
    {
        return (this->shoulderRollValue * rightShoulderRollMotorDirection) + rightShoulderRollMotorOffset;
    }

    float arm()
    {
        return (this->armValue * rightArmMotorDirection) + rightArmMotorOffset;
    }
};
