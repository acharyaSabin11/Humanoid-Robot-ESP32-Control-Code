#include "Wire.h"
#include "./globalObjects.h"
#include <ESP32Servo.h>

Servo rightHipYawServo;
Servo rightHipRollServo;
Servo rightHipPitchServo;
Servo rightKneeServo;
Servo rightAnkleServo;
Servo rightFootServo;
Servo leftHipYawServo;
Servo leftHipRollServo;
Servo leftHipPitchServo;
Servo leftKneeServo;
Servo leftAnkleServo;
Servo leftFootServo;
Servo headServo;

void initializeOtherServos()
{
    rightHipYawServo.attach(rightHipYawMotor);
    rightHipRollServo.attach(rightHipRollMotor);
    rightHipPitchServo.attach(rightHipPitchMotor);
    rightKneeServo.attach(rightKneeMotor);
    rightAnkleServo.attach(rightAnkleMotor);
    rightFootServo.attach(rightFootMotor);
    leftHipYawServo.attach(leftHipYawMotor);
    leftHipRollServo.attach(leftHipRollMotor);
    leftHipPitchServo.attach(leftHipPitchMotor);
    leftKneeServo.attach(leftKneeMotor);
    leftAnkleServo.attach(leftAnkleMotor);
    leftFootServo.attach(leftFootMotor);
    headServo.attach(headMotor);
}
void moveStep(int motorNumber, int angleInDegrees)
{
    switch (motorNumber)
    {
    case rightHipYawMotor:
        rightHipYawServo.write(angleInDegrees);
        break;
    case rightHipRollMotor:
        rightHipRollServo.write(angleInDegrees);
        break;
    case rightHipPitchMotor:
        rightHipPitchServo.write(angleInDegrees);
        break;
    case rightKneeMotor:
        rightKneeServo.write(angleInDegrees);
        break;
    case rightAnkleMotor:
        rightAnkleServo.write(angleInDegrees);
        break;
    case rightFootMotor:
        rightFootServo.write(angleInDegrees);
        break;
    case leftHipYawMotor:
        leftHipYawServo.write(angleInDegrees);
        break;
    case leftHipRollMotor:
        leftHipRollServo.write(angleInDegrees);
        break;
    case leftHipPitchMotor:
        leftHipPitchServo.write(angleInDegrees);
        break;
    case leftKneeMotor:
        leftKneeServo.write(angleInDegrees);
        break;
    case leftAnkleMotor:
        leftAnkleServo.write(angleInDegrees);
        break;
    case leftFootMotor:
        leftFootServo.write(angleInDegrees);
        break;
    case rightShoulderPitchMotor:
        buffer[0] = 13;
        buffer[1] = angleInDegrees;
        Wire.beginTransmission(i2cAddress);
        Wire.write(buffer, 2);
        Wire.endTransmission();

        break;
    case leftShoulderPitchMotor:
        buffer[0] = 3;
        buffer[1] = angleInDegrees;
        Wire.beginTransmission(i2cAddress);
        Wire.write(buffer, 2);
        Wire.endTransmission();
        break;
    case rightShoulderRollMotor:
        buffer[0] = 10;
        buffer[1] = angleInDegrees;
        Wire.beginTransmission(i2cAddress);
        Wire.write(buffer, 2);
        Wire.endTransmission();
        break;
    case leftShoulderRollMotor:
        buffer[0] = 5;
        buffer[1] = angleInDegrees;
        Wire.beginTransmission(i2cAddress);
        Wire.write(buffer, 2);
        Wire.endTransmission();
        break;
    case rightArmMotor:
        buffer[0] = 9;
        buffer[1] = angleInDegrees;
        Wire.beginTransmission(i2cAddress);
        Wire.write(buffer, 2);
        Wire.endTransmission();
        break;
    case leftArmMotor:
        buffer[0] = 6;
        buffer[1] = angleInDegrees;
        Wire.beginTransmission(i2cAddress);
        Wire.write(buffer, 2);
        Wire.endTransmission();
        break;
    case headMotor:
        headServo.write(angleInDegrees);
        break;
    default:
        break;
    }
    // Older Code
    //  if (motorNumber == 16)
    //  {
    //      rightArmServo.write(angleInDegrees);
    //  }
    //  else if (motorNumber == 17)
    //  {
    //      leftArmServo.write(angleInDegrees);
    //  }
    //  else if (motorNumber == 18)
    //  {
    //      torsoServo.write(angleInDegrees);
    //  }
    //  else if (motorNumber == 19)
    //  {
    //      headServo.write(angleInDegrees);
    //  }
    //  else
    //  {
    //      buffer[0] = motorNumber;
    //      buffer[1] = angleInDegrees;
    //      Wire.beginTransmission(i2cAddress);
    //      Wire.write(buffer, 2);
    //      Wire.endTransmission();
    //  }
}
