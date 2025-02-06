#pragma once
#include "./../constants.h";

class LeftLeg
{
    float hipYawValue, hipPitchValue, hipRollValue, kneeValue, ankleValue, footValue;

public:
    // Default Constructor
    LeftLeg()
    {
    }

    LeftLeg(float hipYaw, float hipRoll, float hipPitch, float knee, float ankle, float foot)
    {
        this->hipYawValue = hipYaw;
        this->hipPitchValue = hipPitch;
        this->hipRollValue = hipRoll;
        this->kneeValue = knee;
        this->ankleValue = ankle;
        this->footValue = foot;
    }

    // Getters
    float hipYaw()
    {
        return (this->hipYawValue * leftHipYawMotorDirection) + leftHipYawMotorOffset;
    }

    float hipPitch()
    {
        return (this->hipPitchValue * leftHipPitchMotorDirection) + leftHipPitchMotorOffset;
    }

    float hipRoll()
    {
        return (this->hipRollValue * leftHipRollMotorDirection) + leftHipRollMotorOffset;
    }

    float knee()
    {
        return (this->kneeValue * leftKneeMotorDirection) + leftKneeMotorOffset;
    }

    float ankle()
    {
        return (this->ankleValue * leftAnkleMotorDirection) + leftAnkleMotorOffset;
    }

    float foot()
    {
        return (this->footValue * leftFootMotorDirection) + leftFootMotorOffset;
    }
};
