#pragma once
#include "./../constants.h"

class LeftHand
{
    float shoulderPitchValue, shoulderRollValue, armValue;

public:
    // Default Constructor
    LeftHand()
    {
    }

    LeftHand(float shoulderPitch, float shoulderRoll, float arm)
    {
        this->shoulderPitchValue = shoulderPitch;
        this->shoulderRollValue = shoulderRoll;
        this->armValue = arm;
    }

    // Getters
    float shoulderPitch()
    {
        return (this->shoulderPitchValue * leftShoulderPitchMotorDirection) + leftShoulderPitchMotorOffset;
    }

    float shoulderRoll()
    {
        return (this->shoulderRollValue * leftShoulderRollMotorDirection) + leftShoulderRollMotorOffset;
    }

    float arm()
    {
        return (this->armValue * leftArmMotorDirection) + leftArmMotorOffset;
    }
};