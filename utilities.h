#include "Wire.h"
#include "./globalObjects.h"
#include <ESP32Servo.h>

Servo rightArmServo;
Servo leftArmServo;
Servo headServo;
Servo torsoServo;

void initializeOtherServos()
{
    rightArmServo.attach(14);
    leftArmServo.attach(25);
    headServo.attach(26);
    torsoServo.attach(27);
}
void moveStep(int motorNumber, int angleInDegrees)
{
    if (motorNumber == 16)
    {
        rightArmServo.write(angleInDegrees);
    }
    else if (motorNumber == 17)
    {
        leftArmServo.write(angleInDegrees);
    }
    else if (motorNumber == 18)
    {
        torsoServo.write(angleInDegrees);
    }
    else if (motorNumber == 19)
    {
        headServo.write(angleInDegrees);
    }
    {
        buffer[0] = motorNumber;
        buffer[1] = angleInDegrees;
        Wire.beginTransmission(i2cAddress);
        Wire.write(buffer, 2);
        Wire.endTransmission();
    }
}
