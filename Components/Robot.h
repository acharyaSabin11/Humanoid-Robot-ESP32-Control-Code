#pragma once
#include "./../constants.h";

class Robot
{
    float leftShoulderPitchValue, leftShoulderRollValue, leftArmValue;
    float rightShoulderPitchValue, rightShoulderRollValue, rightArmValue;
    float leftHipYawValue, leftHipPitchValue, leftHipRollValue, leftKneeValue, leftAnkleValue, leftFootValue;
    float rightHipYawValue, rightHipPitchValue, rightHipRollValue, rightKneeValue, rightAnkleValue, rightFootValue;
    float headValue, torsoValue;

public:
    // Default Constructor
    Robot()
    {
    }

    Robot(float rightShoulderPitch, float rightShoulderRoll, float rightArm, float leftShoulderPitch, float leftShoulderRoll, float leftArm, float rightHipYaw, float rightHipRoll, float rightHipPitch, float rightKnee, float rightAnkle, float rightFoot, float leftHipYaw, float leftHipRoll, float leftHipPitch, float leftKnee, float leftAnkle, float leftFoot, float head, float torso)
    {
        // Left Arm
        this->leftShoulderPitchValue = leftShoulderPitch;
        this->leftShoulderRollValue = leftShoulderRoll;
        this->leftArmValue = leftArm;
        // Right Arm
        this->rightShoulderPitchValue = rightShoulderPitch;
        this->rightShoulderRollValue = rightShoulderRoll;
        this->rightArmValue = rightArm;
        // Left Leg
        this->leftHipYawValue = leftHipYaw;
        this->leftHipPitchValue = leftHipPitch;
        this->leftHipRollValue = leftHipRoll;
        this->leftKneeValue = leftKnee;
        this->leftAnkleValue = leftAnkle;
        this->leftFootValue = leftFoot;
        // Right Leg
        this->rightHipYawValue = rightHipYaw;
        this->rightHipPitchValue = rightHipPitch;
        this->rightHipRollValue = rightHipRoll;
        this->rightKneeValue = rightKnee;
        this->rightAnkleValue = rightAnkle;
        this->rightFootValue = rightFoot;
        // Head and Torso
        this->headValue = head;
        this->torsoValue = torso;
    }

    // Constructor Overloading
    Robot(float *angleData)
    {

        // Left Arm
        this->rightShoulderPitchValue = angleData[0];
        this->rightShoulderRollValue = angleData[1];
        this->rightArmValue = angleData[2];

        // Right Arm
        this->leftShoulderPitchValue = angleData[3];
        this->leftShoulderRollValue = angleData[4];
        this->leftArmValue = angleData[5];

        // Left Leg
        this->rightHipYawValue = angleData[6];
        this->rightHipRollValue = angleData[7];
        this->rightHipPitchValue = angleData[8];
        this->rightKneeValue = angleData[9];
        this->rightAnkleValue = angleData[10];
        this->rightFootValue = angleData[11];

        // Right Leg
        this->leftHipYawValue = angleData[12];
        this->leftHipRollValue = angleData[13];
        this->leftHipPitchValue = angleData[14];
        this->leftKneeValue = angleData[15];
        this->leftAnkleValue = angleData[16];
        this->leftFootValue = angleData[17];

        // Head and Torso
        this->headValue = angleData[18];
        this->torsoValue = angleData[19];
    }

    // Getters

    // Left Arm
    float leftShoulderPitch()
    {
        return (this->leftShoulderPitchValue * leftShoulderPitchMotorDirection) + leftShoulderPitchMotorOffset;
    }

    float leftShoulderRoll()
    {
        return (this->leftShoulderRollValue * leftShoulderRollMotorDirection) + leftShoulderRollMotorOffset;
    }

    float leftArm()
    {
        return (this->leftArmValue * leftArmMotorDirection) + leftArmMotorOffset;
    }

    // Right Arm
    float rightShoulderPitch()
    {
        return (this->rightShoulderPitchValue * rightShoulderPitchMotorDirection) + rightShoulderPitchMotorOffset;
    }

    float rightShoulderRoll()
    {
        return (this->rightShoulderRollValue * rightShoulderRollMotorDirection) + rightShoulderRollMotorOffset;
    }

    float rightArm()
    {
        return (this->rightArmValue * rightArmMotorDirection) + rightArmMotorOffset;
    }

    // Left Leg
    float leftHipYaw()
    {
        return (this->leftHipYawValue * leftHipYawMotorDirection) + leftHipYawMotorOffset;
    }

    float leftHipPitch()
    {
        return (this->leftHipPitchValue * leftHipPitchMotorDirection) + leftHipPitchMotorOffset;
    }

    float leftHipRoll()
    {
        return (this->leftHipRollValue * leftHipRollMotorDirection) + leftHipRollMotorOffset;
    }

    float leftKnee()
    {
        return (this->leftKneeValue * leftKneeMotorDirection) + leftKneeMotorOffset;
    }

    float leftAnkle()
    {
        return (this->leftAnkleValue * leftAnkleMotorDirection) + leftAnkleMotorOffset;
    }

    float leftFoot()
    {
        return (this->leftFootValue * leftFootMotorDirection) + leftFootMotorOffset;
    }

    // Right Leg
    float rightHipYaw()
    {
        return (this->rightHipYawValue * rightHipYawMotorDirection) + rightHipYawMotorOffset;
    }

    float rightHipPitch()
    {
        return (this->rightHipPitchValue * rightHipPitchMotorDirection) + rightHipPitchMotorOffset;
    }

    float rightHipRoll()
    {
        return (this->rightHipRollValue * rightHipRollMotorDirection) + rightHipRollMotorOffset;
    }

    float rightKnee()
    {
        return (this->rightKneeValue * rightKneeMotorDirection) + rightKneeMotorOffset;
    }

    float rightAnkle()
    {
        return (this->rightAnkleValue * rightAnkleMotorDirection) + rightAnkleMotorOffset;
    }

    float rightFoot()
    {
        return (this->rightFootValue * rightFootMotorDirection) + rightFootMotorOffset;
    }
    // Head and Torso
    float head()
    {
        return (this->headValue * headMotorDirection) + headMotorOffset;
    }

    float torso()
    {
        return (this->torsoValue * torsoMotorDirection) + torsoMotorOffset;
    }
};