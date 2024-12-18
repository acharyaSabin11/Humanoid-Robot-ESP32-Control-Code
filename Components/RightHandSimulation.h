#include "./Hand.h"

class RightHandSimulation
{
public:
    float timeData[4] = {0.7, 0.7, 0.7, 0.9};
    Hand handPositions[4];
    float shoulderPitchOffset = 90.0, shoulderRollOffset = 160.0, armOffset = 0.0;

    RightHandSimulation()
    {
        handPositions[0] =
            Hand(0.0, 0.0, 0.0, shoulderPitchOffset, shoulderRollOffset, armOffset);
        handPositions[1] =
            Hand(-67.7, -1.6, 1.9, shoulderPitchOffset, shoulderRollOffset, armOffset);
        handPositions[2] =
            Hand(-65.7, 1.6, 32.9, shoulderPitchOffset, shoulderRollOffset, armOffset);
        handPositions[3] =
            Hand(-62.1, 1.6, 32.9, shoulderPitchOffset, shoulderRollOffset, armOffset);
    };
};