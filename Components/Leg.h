#pragma once;

class Leg
{
    float hipOffset = 150, thighOffset = 150, kneeOffset = 40, ankleOffset = 20, footOffset = 110;
    float hipValue, thighValue, kneeValue, ankleValue, footValue;

public:
    Leg(float hip, float thigh, float knee, float ankle, float foot)
    {
        this->hipValue = hip;
        this->thighValue = thigh;
        this->kneeValue = knee;
        this->ankleValue = ankle;
        this->footValue = foot;
    }

    // Getters
    float hip()
    {
        return this->hipValue + this->hipOffset;
    }

    float thigh()
    {
        return this->thighValue + this->thighOffset;
    }

    float knee()
    {
        return this->kneeValue + this->kneeOffset;
    }

    float ankle()
    {
        return this->ankleValue + this->ankleOffset;
    }

    float foot()
    {
        return this->footValue + this->footOffset;
    }
};