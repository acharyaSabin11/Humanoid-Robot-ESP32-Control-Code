#include "Wire.h"
#include "./globalObjects.h"

void moveStep(int motorNumber, int angleInDegrees)
{
    buffer[0] = motorNumber;
    buffer[1] = angleInDegrees;
    Serial.println(buffer[0]);
    Serial.println(buffer[1]);
    Wire.beginTransmission(i2cAddress);
    Wire.write(buffer, 2);
    Wire.endTransmission();
}
