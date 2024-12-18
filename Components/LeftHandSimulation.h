#include "./Hand.h"

class LeftHandSimulation
{
public:
    float timeData[4] = {0.7, 0.7, 0.7, 0.9};
    Hand handPositions[4];
    float shoulderPitchOffset = 90.0, shoulderRollOffset = 90.0, armOffset = 180.0;
    LeftHandSimulation()
    {
        handPositions[0] =
            Hand(0.0, 0.0, 0.0, shoulderPitchOffset, shoulderRollOffset, armOffset);
        handPositions[1] =
            Hand(65.8, 3.6, -5.5, shoulderPitchOffset, shoulderRollOffset, armOffset);
        handPositions[2] =
            Hand(65.7, -1.6, -32.9, shoulderPitchOffset, shoulderRollOffset, armOffset);
        handPositions[3] =
            Hand(62.1, -1.6, -32.9, shoulderPitchOffset, shoulderRollOffset, armOffset);
    };
};