#pragma once
#include "./../constants.h";

class RightLeg
{
    float hipYawValue, hipPitchValue, hipRollValue, kneeValue, ankleValue, footValue;

public:
    // Default Constructor
    RightLeg()
    {
    }

    RightLeg(float hipYaw, float hipRoll, float hipPitch, float knee, float ankle, float foot)
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
        return (this->hipYawValue * rightHipYawMotorDirection) + rightHipYawMotorOffset;
    }

    float hipPitch()
    {
        return (this->hipPitchValue * rightHipPitchMotorDirection) + rightHipPitchMotorOffset;
    }

    float hipRoll()
    {
        return (this->hipRollValue * rightHipRollMotorDirection) + rightHipRollMotorOffset;
    }

    float knee()
    {
        return (this->kneeValue * rightKneeMotorDirection) + rightKneeMotorOffset;
    }

    float ankle()
    {
        return (this->ankleValue * rightAnkleMotorDirection) + rightAnkleMotorOffset;
    }

    float foot()
    {
        return (this->footValue * rightFootMotorDirection) + rightFootMotorOffset;
    }
};
