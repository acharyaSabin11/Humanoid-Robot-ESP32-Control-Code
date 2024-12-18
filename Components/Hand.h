#pragma once

class Hand
{
    float shoulderPitchOffset = 0, shoulderRollOffset = 0, armOffset = 0;
    float shoulderPitchValue, shoulderRollValue, armValue;

public:
    // Default Constructor
    Hand()
    {
    }

    Hand(float shoulderPitch, float shoulderRoll, float arm, float shoulderPitchOffset, float shoulderRollOffset, float armOffset)
    {
        this->shoulderPitchValue = shoulderPitch;
        this->shoulderRollValue = shoulderRoll;
        this->armValue = arm;
        this->shoulderPitchOffset = shoulderPitchOffset;
        this->shoulderRollOffset = shoulderRollOffset;
        this->armOffset = armOffset;
    }

    // Getters
    float shoulderPitch()
    {
        return this->shoulderPitchValue + this->shoulderPitchOffset;
    }

    float shoulderRoll()
    {
        return this->shoulderRollValue + this->shoulderRollOffset;
    }

    float arm()
    {
        return this->armValue + this->armOffset;
    }
};