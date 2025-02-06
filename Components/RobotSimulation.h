#include "./../constants.h"
#include "./../utilities.h"
#include "./../services/MyWebSocketClient.h"
#include "./../services/JsonDocument.h"
#include "./Robot.h"
class RobotSimulation
{
    // Intialize Each of the Body Part Model i.e Leg, Hand, Torso, Head
    // LeftHandSimulation leftHandSimulation = LeftHandSimulation();
    // LeftLegSimulation leftLegSimulation = LeftLegSimulation();
    // RightLegSimulation rightLegSimulation = RightLegSimulation();
    // RightHandSimulation rightHandSimulation = RightHandSimulation();

    // Step 1: Create the frames as in the robot simulation for each Simulations
    // For Walking Simulation
    static const int walkingFramesCount = 8;
    float walkingTime[walkingFramesCount] = {0.4, 0.64, 1.5, 0.88, 1.52, 0.72, 0.88, 0.88};
    float walkingFrames[walkingFramesCount][20] = {
        // Frame 0
        {10.0, 35.0, 0.0,
         10.0, -35.0, 0.0,
         0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
         0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
         0.0, 0.0},

        // Frame 1
        {10.0, 35.0, 0.0,
         10.0, -35.0, 0.0,
         0.0, 10.0, 0.0, 0.0, 0.0, -12.0,
         0.0, 10.0, 0.0, 0.0, 0.0, -12.0,
         0.0, 0.0},

        // {10.0, 35.0, 0.0,
        //  10.0, -35.0, 0.0,
        //  0.0, 12.0, 26.8, -60.5, 29.4, -12.0,
        //  0.0, 10.0, 0.0, 0.0, 0.0, -14.0,
        //  0.0, 0.0},
        // Frame 2
        {10.0, 35.0, 0.0,
         10.0, -35.0, 0.0,
         0.0, -10.0, 26.8, -60.5, 29.4, -12.0,
         0.0, -10.0, 0.0, 0.0, 0.0, -14.0,
         0.0, 0.0},

        // Frame 3
        {10.0, 35.0, 0.0,
         10.0, -35.0, 0.0,
         0.0, 13.0, 38.5, -40.2, 2.7, -10.2,
         0.0, 12.0, 0.0, 0.0, 0.0, -10.5,
         0.0, 0.0},
        // {10.0, 35.0, 0.0,
        //  10.0, -35.0, 0.0,
        //  0.0, 13.0, 38.5, -40.2, 2.7, -10.2,
        //  0.0, 36.0, 0.0, 0.0, 0.0, 30.5,
        //  0.0, 0.0},

        // Frame 4
        {10.0, 35.0, 0.0,
         10.0, -35.0, 0.0,
         0.0, 18.0, 25.5, -22.8, 9.6, 12.0,
         0.0, 10.0, 40.5, -16.5, 22.7, 30.0,
         0.0, 0.0},

        // Frame 5
        {10.0, 35.0, 0.0,
         10.0, -35.0, 0.0,
         0.0, -8.0, 0.0, 0.0, 0.0, 12.0,
         0.0, -13.0, 4.8, -60.5, 29.4, 12.0,
         0.0, 0.0},

        {10.0, 35.0, 0.0,
         10.0, -35.0, 0.0,
         0.0, -8.0, 0.0, 0.0, 0.0, 8.5,
         0.0, -8.0, 38.5, -40.2, 2.7, 8.2,
         0.0, 0.0},

        {10.0, 35.0, 0.0,
         10.0, -35.0, 0.0,
         0.0, 8.0, 1.5, -16.5, 22.7, -10.0,
         0.0, 8.0, 25.5, -29.8, 9.6, -10.0,
         0.0, 0.0}};

    // Step 2: Create a Robot Object Holding the Current State;
    Robot currentRobotState = Robot(0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0);

public:
    void moveToServerFrame(float rightShoulderPitch, float rightShoulderRoll, float rightArm, float leftShoulderPitch, float leftShoulderRoll, float leftArm, float rightHipYaw, float rightHipRoll, float rightHipPitch, float rightKnee, float rightAnkle, float rightFoot, float leftHipYaw, float leftHipRoll, float leftHipPitch, float leftKnee, float leftAnkle, float leftFoot, float head, float torso, float time)
    {
        Robot nextRobotState = Robot(rightShoulderPitch, rightShoulderRoll, rightArm, leftShoulderPitch, leftShoulderRoll, leftArm, rightHipYaw, rightHipRoll, rightHipPitch, rightKnee, rightAnkle, rightFoot, leftHipYaw, leftHipRoll, leftHipPitch, leftKnee, leftAnkle, leftFoot, head, torso);

        float numIter = time * 1000 / stepTime;

        // Calculating step value for each iteration.
        float leftShoulderPitchStep = (nextRobotState.leftShoulderPitch() - currentRobotState.leftShoulderPitch()) / numIter;
        float leftShoulderRollStep = (nextRobotState.leftShoulderRoll() - currentRobotState.leftShoulderRoll()) / numIter;
        float leftArmStep = (nextRobotState.leftArm() - currentRobotState.leftArm()) / numIter;

        float rightShoulderPitchStep = (nextRobotState.rightShoulderPitch() - currentRobotState.rightShoulderPitch()) / numIter;
        float rightShoulderRollStep = (nextRobotState.rightShoulderRoll() - currentRobotState.rightShoulderRoll()) / numIter;
        float rightArmStep = (nextRobotState.rightArm() - currentRobotState.rightArm()) / numIter;

        float leftHipYawStep = (nextRobotState.leftHipYaw() - currentRobotState.leftHipYaw()) / numIter;
        float leftHipPitchStep = (nextRobotState.leftHipPitch() - currentRobotState.leftHipPitch()) / numIter;
        float leftHipRollStep = (nextRobotState.leftHipRoll() - currentRobotState.leftHipRoll()) / numIter;
        float leftKneeStep = (nextRobotState.leftKnee() - currentRobotState.leftKnee()) / numIter;
        float leftAnkleStep = (nextRobotState.leftAnkle() - currentRobotState.leftAnkle()) / numIter;
        float leftFootStep = (nextRobotState.leftFoot() - currentRobotState.leftFoot()) / numIter;

        float rightHipYawStep = (nextRobotState.rightHipYaw() - currentRobotState.rightHipYaw()) / numIter;
        float rightHipPitchStep = (nextRobotState.rightHipPitch() - currentRobotState.rightHipPitch()) / numIter;
        float rightHipRollStep = (nextRobotState.rightHipRoll() - currentRobotState.rightHipRoll()) / numIter;
        float rightKneeStep = (nextRobotState.rightKnee() - currentRobotState.rightKnee()) / numIter;
        float rightAnkleStep = (nextRobotState.rightAnkle() - currentRobotState.rightAnkle()) / numIter;
        float rightFootStep = (nextRobotState.rightFoot() - currentRobotState.rightFoot()) / numIter;

        float headStep = (nextRobotState.head() - currentRobotState.head()) / numIter;
        float torsoStep = (nextRobotState.torso() - currentRobotState.torso()) / numIter;

        for (int j = 1; j <= numIter; j++)
        {

            // Move and update for Left Arm
            moveStep(leftShoulderPitchMotor, static_cast<int>(currentRobotState.leftShoulderPitch() + leftShoulderPitchStep * j));
            WSData::docRobotSimulation["LeftShoulderPitch"] = currentRobotState.leftShoulderPitch() + leftShoulderPitchStep * j;

            moveStep(leftShoulderRollMotor, static_cast<int>(currentRobotState.leftShoulderRoll() + leftShoulderRollStep * j));
            WSData::docRobotSimulation["LeftShoulderRoll"] = currentRobotState.leftShoulderRoll() + leftShoulderRollStep * j;

            moveStep(leftArmMotor, static_cast<int>(currentRobotState.leftArm() + leftArmStep * j));
            WSData::docRobotSimulation["LeftArm"] = currentRobotState.leftArm() + leftArmStep * j;

            // Move and update for Right Arm
            moveStep(rightShoulderPitchMotor, static_cast<int>(currentRobotState.rightShoulderPitch() + rightShoulderPitchStep * j));
            WSData::docRobotSimulation["RightShoulderPitch"] = currentRobotState.rightShoulderPitch() + rightShoulderPitchStep * j;

            moveStep(rightShoulderRollMotor, static_cast<int>(currentRobotState.rightShoulderRoll() + rightShoulderRollStep * j));
            WSData::docRobotSimulation["RightShoulderRoll"] = currentRobotState.rightShoulderRoll() + rightShoulderRollStep * j;

            moveStep(rightArmMotor, static_cast<int>(currentRobotState.rightArm() + rightArmStep * j));
            WSData::docRobotSimulation["RightArm"] = currentRobotState.rightArm() + rightArmStep * j;

            // Move and update for Left Leg
            moveStep(leftHipYawMotor, static_cast<int>(currentRobotState.leftHipYaw() + leftHipYawStep * j));
            WSData::docRobotSimulation["LeftHipYaw"] = currentRobotState.leftHipYaw() + leftHipYawStep * j;

            moveStep(leftHipPitchMotor, static_cast<int>(currentRobotState.leftHipPitch() + leftHipPitchStep * j));
            WSData::docRobotSimulation["LeftHipPitch"] = currentRobotState.leftHipPitch() + leftHipPitchStep * j;

            moveStep(leftHipRollMotor, static_cast<int>(currentRobotState.leftHipRoll() + leftHipRollStep * j));
            WSData::docRobotSimulation["LeftHipRoll"] = currentRobotState.leftHipRoll() + leftHipRollStep * j;

            moveStep(leftKneeMotor, static_cast<int>(currentRobotState.leftKnee() + leftKneeStep * j));
            WSData::docRobotSimulation["LeftKnee"] = currentRobotState.leftKnee() + leftKneeStep * j;

            moveStep(leftAnkleMotor, static_cast<int>(currentRobotState.leftAnkle() + leftAnkleStep * j));
            WSData::docRobotSimulation["LeftAnkle"] = currentRobotState.leftAnkle() + leftAnkleStep * j;

            moveStep(leftFootMotor, static_cast<int>(currentRobotState.leftFoot() + leftFootStep * j));
            WSData::docRobotSimulation["LeftFoot"] = currentRobotState.leftFoot() + leftFootStep * j;

            // Move and update for Right Leg
            moveStep(rightHipYawMotor, static_cast<int>(currentRobotState.rightHipYaw() + rightHipYawStep * j));
            WSData::docRobotSimulation["RightHipYaw"] = currentRobotState.rightHipYaw() + rightHipYawStep * j;

            moveStep(rightHipPitchMotor, static_cast<int>(currentRobotState.rightHipPitch() + rightHipPitchStep * j));
            WSData::docRobotSimulation["RightHipPitch"] = currentRobotState.rightHipPitch() + rightHipPitchStep * j;

            moveStep(rightHipRollMotor, static_cast<int>(currentRobotState.rightHipRoll() + rightHipRollStep * j));
            WSData::docRobotSimulation["RightHipRoll"] = currentRobotState.rightHipRoll() + rightHipRollStep * j;

            moveStep(rightKneeMotor, static_cast<int>(currentRobotState.rightKnee() + rightKneeStep * j));
            WSData::docRobotSimulation["RightKnee"] = currentRobotState.rightKnee() + rightKneeStep * j;

            moveStep(rightAnkleMotor, static_cast<int>(currentRobotState.rightAnkle() + rightAnkleStep * j));
            WSData::docRobotSimulation["RightAnkle"] = currentRobotState.rightAnkle() + rightAnkleStep * j;

            moveStep(rightFootMotor, static_cast<int>(currentRobotState.rightFoot() + rightFootStep * j));
            WSData::docRobotSimulation["RightFoot"] = currentRobotState.rightFoot() + rightFootStep * j;

            // Move and update for Head and Torso
            moveStep(headMotor, static_cast<int>(currentRobotState.head() + headStep * j));
            WSData::docRobotSimulation["Head"] = currentRobotState.head() + headStep * j;

            moveStep(torsoMotor, static_cast<int>(currentRobotState.torso() + torsoStep * j));
            WSData::docRobotSimulation["Torso"] = currentRobotState.torso() + torsoStep * j;

            Serial.println("Serializing JSON data");
            serializeJson(WSData::docRobotSimulation, WSData::serializedData);
            Serial.println(WSData::serializedData);
            Serial.println("Serialized JSON data");
            webSocket.sendTXT(WSData::serializedData);
            Serial.println("JSON data Sent");
            delay(stepTime - 30);
        }

        currentRobotState = nextRobotState;
    }

    void moveToFrame(int frameNumber, bool frameIncrease)
    {
        Robot nextRobotState = Robot(walkingFrames[frameNumber]);
        float time = 0.0;
        // Getting the time required to move from one frame to another
        if (frameIncrease)
        {
            if (frameNumber == 0)
            {
                time = walkingTime[7];
            }
            else
            {

                time = walkingTime[frameNumber - 1];
            }
        }
        else
        {
            if (frameNumber == 7)
            {
                time = walkingTime[7];
            }
            else
            {
                time = walkingTime[frameNumber];
            }
        }

        float numIter = time * 1000 / stepTime;

        // Calculating step value for each iteration.
        float leftShoulderPitchStep = (nextRobotState.leftShoulderPitch() - currentRobotState.leftShoulderPitch()) / numIter;
        float leftShoulderRollStep = (nextRobotState.leftShoulderRoll() - currentRobotState.leftShoulderRoll()) / numIter;
        float leftArmStep = (nextRobotState.leftArm() - currentRobotState.leftArm()) / numIter;

        float rightShoulderPitchStep = (nextRobotState.rightShoulderPitch() - currentRobotState.rightShoulderPitch()) / numIter;
        float rightShoulderRollStep = (nextRobotState.rightShoulderRoll() - currentRobotState.rightShoulderRoll()) / numIter;
        float rightArmStep = (nextRobotState.rightArm() - currentRobotState.rightArm()) / numIter;

        float leftHipYawStep = (nextRobotState.leftHipYaw() - currentRobotState.leftHipYaw()) / numIter;
        float leftHipPitchStep = (nextRobotState.leftHipPitch() - currentRobotState.leftHipPitch()) / numIter;
        float leftHipRollStep = (nextRobotState.leftHipRoll() - currentRobotState.leftHipRoll()) / numIter;
        float leftKneeStep = (nextRobotState.leftKnee() - currentRobotState.leftKnee()) / numIter;
        float leftAnkleStep = (nextRobotState.leftAnkle() - currentRobotState.leftAnkle()) / numIter;
        float leftFootStep = (nextRobotState.leftFoot() - currentRobotState.leftFoot()) / numIter;

        float rightHipYawStep = (nextRobotState.rightHipYaw() - currentRobotState.rightHipYaw()) / numIter;
        float rightHipPitchStep = (nextRobotState.rightHipPitch() - currentRobotState.rightHipPitch()) / numIter;
        float rightHipRollStep = (nextRobotState.rightHipRoll() - currentRobotState.rightHipRoll()) / numIter;
        float rightKneeStep = (nextRobotState.rightKnee() - currentRobotState.rightKnee()) / numIter;
        float rightAnkleStep = (nextRobotState.rightAnkle() - currentRobotState.rightAnkle()) / numIter;
        float rightFootStep = (nextRobotState.rightFoot() - currentRobotState.rightFoot()) / numIter;

        float headStep = (nextRobotState.head() - currentRobotState.head()) / numIter;
        float torsoStep = (nextRobotState.torso() - currentRobotState.torso()) / numIter;

        for (int j = 1; j <= numIter; j++)
        {

            // Move and update for Left Arm
            moveStep(leftShoulderPitchMotor, static_cast<int>(currentRobotState.leftShoulderPitch() + leftShoulderPitchStep * j));
            WSData::docRobotSimulation["LeftShoulderPitch"] = currentRobotState.leftShoulderPitch() + leftShoulderPitchStep * j;

            moveStep(leftShoulderRollMotor, static_cast<int>(currentRobotState.leftShoulderRoll() + leftShoulderRollStep * j));
            WSData::docRobotSimulation["LeftShoulderRoll"] = currentRobotState.leftShoulderRoll() + leftShoulderRollStep * j;

            moveStep(leftArmMotor, static_cast<int>(currentRobotState.leftArm() + leftArmStep * j));
            WSData::docRobotSimulation["LeftArm"] = currentRobotState.leftArm() + leftArmStep * j;

            // Move and update for Right Arm
            moveStep(rightShoulderPitchMotor, static_cast<int>(currentRobotState.rightShoulderPitch() + rightShoulderPitchStep * j));
            WSData::docRobotSimulation["RightShoulderPitch"] = currentRobotState.rightShoulderPitch() + rightShoulderPitchStep * j;

            moveStep(rightShoulderRollMotor, static_cast<int>(currentRobotState.rightShoulderRoll() + rightShoulderRollStep * j));
            WSData::docRobotSimulation["RightShoulderRoll"] = currentRobotState.rightShoulderRoll() + rightShoulderRollStep * j;

            moveStep(rightArmMotor, static_cast<int>(currentRobotState.rightArm() + rightArmStep * j));
            WSData::docRobotSimulation["RightArm"] = currentRobotState.rightArm() + rightArmStep * j;

            // For Left Leg
            moveStep(leftHipYawMotor, static_cast<int>(currentRobotState.leftHipYaw() + leftHipYawStep * j));
            WSData::docRobotSimulation["LeftHipYaw"] = currentRobotState.leftHipYaw() + leftHipYawStep * j;

            moveStep(leftHipPitchMotor, static_cast<int>(currentRobotState.leftHipPitch() + leftHipPitchStep * j));
            WSData::docRobotSimulation["LeftHipPitch"] = currentRobotState.leftHipPitch() + leftHipPitchStep * j;

            moveStep(leftHipRollMotor, static_cast<int>(currentRobotState.leftHipRoll() + leftHipRollStep * j));
            WSData::docRobotSimulation["LeftHipRoll"] = currentRobotState.leftHipRoll() + leftHipRollStep * j;

            moveStep(leftKneeMotor, static_cast<int>(currentRobotState.leftKnee() + leftKneeStep * j));
            WSData::docRobotSimulation["LeftKnee"] = currentRobotState.leftKnee() + leftKneeStep * j;

            moveStep(leftAnkleMotor, static_cast<int>(currentRobotState.leftAnkle() + leftAnkleStep * j));
            WSData::docRobotSimulation["LeftAnkle"] = currentRobotState.leftAnkle() + leftAnkleStep * j;

            moveStep(leftFootMotor, static_cast<int>(currentRobotState.leftFoot() + leftFootStep * j));
            WSData::docRobotSimulation["LeftFoot"] = currentRobotState.leftFoot() + leftFootStep * j;

            // Move and update for Right Leg
            moveStep(rightHipYawMotor, static_cast<int>(currentRobotState.rightHipYaw() + rightHipYawStep * j));
            WSData::docRobotSimulation["RightHipYaw"] = currentRobotState.rightHipYaw() + rightHipYawStep * j;

            moveStep(rightHipPitchMotor, static_cast<int>(currentRobotState.rightHipPitch() + rightHipPitchStep * j));
            WSData::docRobotSimulation["RightHipPitch"] = currentRobotState.rightHipPitch() + rightHipPitchStep * j;

            moveStep(rightHipRollMotor, static_cast<int>(currentRobotState.rightHipRoll() + rightHipRollStep * j));
            WSData::docRobotSimulation["RightHipRoll"] = currentRobotState.rightHipRoll() + rightHipRollStep * j;

            moveStep(rightKneeMotor, static_cast<int>(currentRobotState.rightKnee() + rightKneeStep * j));
            WSData::docRobotSimulation["RightKnee"] = currentRobotState.rightKnee() + rightKneeStep * j;

            moveStep(rightAnkleMotor, static_cast<int>(currentRobotState.rightAnkle() + rightAnkleStep * j));
            WSData::docRobotSimulation["RightAnkle"] = currentRobotState.rightAnkle() + rightAnkleStep * j;

            moveStep(rightFootMotor, static_cast<int>(currentRobotState.rightFoot() + rightFootStep * j));
            WSData::docRobotSimulation["RightFoot"] = currentRobotState.rightFoot() + rightFootStep * j;

            // Move and update for Head and Torso
            moveStep(headMotor, static_cast<int>(currentRobotState.head() + headStep * j));
            WSData::docRobotSimulation["Head"] = currentRobotState.head() + headStep * j;

            moveStep(torsoMotor, static_cast<int>(currentRobotState.torso() + torsoStep * j));
            WSData::docRobotSimulation["Torso"] = currentRobotState.torso() + torsoStep * j;

            Serial.println("Serializing JSON data");
            serializeJson(WSData::docRobotSimulation, WSData::serializedData);
            Serial.println(WSData::serializedData);
            Serial.println("Serialized JSON data");
            webSocket.sendTXT(WSData::serializedData);
            Serial.println("JSON data Sent");
            delay(stepTime);
        }

        currentRobotState = nextRobotState;
    }
    // void pickUpObject()
    // {
    //     Hand currentRightState = rightHandSimulation.handPositions[0];
    //     Hand nextRightState = rightHandSimulation.handPositions[1];
    //     Hand currentLeftState = leftHandSimulation.handPositions[0];
    //     Hand nextLeftState = leftHandSimulation.handPositions[1];
    //     int timeFramesCount = sizeof(rightHandSimulation.timeData) / sizeof(float);
    //     for (int i = 0; i < timeFramesCount; i++)
    //     {
    //         // int currValue = i % (timeFramesCount - 1);
    //         // Get time to move to next frame
    //         float time = rightHandSimulation.timeData[i];
    //         // Get number of iterations of to reach next frame
    //         float numIter = time * 1000 / stepTime;

    //         // Calculate the angle step for each value of iteration;
    //         // Right Hand
    //         float rightShoulderPitchStep = (nextRightState.shoulderPitch() - currentRightState.shoulderPitch()) / numIter;
    //         float rightShoulderRollStep = (nextRightState.shoulderRoll() - currentRightState.shoulderRoll()) / numIter;
    //         float rightArmStep = (nextRightState.arm() - currentRightState.arm()) / numIter;
    //         // Left Hand
    //         float leftShoulderPitchStep = (nextLeftState.shoulderPitch() - currentLeftState.shoulderPitch()) / numIter;
    //         float leftShoulderRollStep = (nextLeftState.shoulderRoll() - currentLeftState.shoulderRoll()) / numIter;
    //         float leftArmStep = (nextLeftState.arm() - currentLeftState.arm()) / numIter;

    //         // Loop for numIter
    //         for (int j = 1; j <= numIter; j++)
    //         {
    //             // For Right Arm
    //             moveStep(rightShoulderPitchMotor, static_cast<int>(currentRightState.shoulderPitch() + rightShoulderPitchStep * j));
    //             moveStep(rightShoulderRollMotor, static_cast<int>(currentRightState.shoulderRoll() + rightShoulderRollStep * j));
    //             moveStep(rightArmMotor, static_cast<int>(currentRightState.arm() + rightArmStep * j));
    //             // For Left Arm
    //             moveStep(leftShoulderPitchMotor, static_cast<int>(currentLeftState.shoulderPitch() + leftShoulderPitchStep * j));
    //             moveStep(leftShoulderRollMotor, static_cast<int>(currentLeftState.shoulderRoll() + leftShoulderRollStep * j));
    //             moveStep(leftArmMotor, static_cast<int>(currentLeftState.arm() + leftArmStep * j));
    //             // Preparing JSON
    //             WSData::docRobotSimulation["type"] = "Pick Up";
    //             WSData::docRobotSimulation["RightShoulderPitch"] = currentRightState.shoulderPitch() + rightShoulderPitchStep * j;
    //             WSData::docRobotSimulation["RightShoulderRoll"] = currentRightState.shoulderRoll() + rightShoulderRollStep * j;
    //             WSData::docRobotSimulation["RightArm"] = currentRightState.arm() + rightArmStep * j;
    //             WSData::docRobotSimulation["LeftShoulderPitch"] = currentLeftState.shoulderPitch() + leftShoulderPitchStep * j;
    //             WSData::docRobotSimulation["LeftShoulderRoll"] = currentLeftState.shoulderRoll() + leftShoulderRollStep * j;
    //             WSData::docRobotSimulation["LeftArm"] = currentLeftState.arm() + leftArmStep * j;
    //             Serial.println("Serializing JSON data");
    //             serializeJson(WSData::docRobotSimulation, WSData::serializedData);
    //             Serial.println(WSData::serializedData);
    //             Serial.println("Serialized JSON data");
    //             webSocket.sendTXT(WSData::serializedData);
    //             Serial.println("JSON data Sent");
    //             delay(stepTime);
    //         }
    //         currentRightState = nextRightState;
    //         currentLeftState = nextLeftState;
    //         if (i == 2)
    //         {
    //             delay(4000);
    //         }
    //         nextRightState = rightHandSimulation.handPositions[(i + 2) % (timeFramesCount)];
    //         nextLeftState = leftHandSimulation.handPositions[(i + 2) % (timeFramesCount)];
    //     }
    // };

    // void walkingMotion()
    // {
    //     Leg currentRightState = rightLegSimulation.legPositions[0];
    //     Leg nextRightState = rightLegSimulation.legPositions[1];
    //     Leg currentLeftState = leftLegSimulation.legPositions[0];
    //     Leg nextLeftState = leftLegSimulation.legPositions[1];
    //     int timeFramesCount = sizeof(rightLegSimulation.timeData) / sizeof(float);

    //     for (int i = 0; i < timeFramesCount; i++)
    //     {
    //         // Get time to move to next frame
    //         float time = rightLegSimulation.timeData[i];
    //         // Get number of iterations to reach the next frame
    //         float numIter = time * 1000 / stepTime;

    //         // Calculate the angle step for each value of iteration
    //         // Right Leg
    //         float rightHipYawStep = (nextRightState.hipYaw() - currentRightState.hipYaw()) / numIter;
    //         float rightHipPitchStep = (nextRightState.hipPitch() - currentRightState.hipPitch()) / numIter;
    //         float rightHipRollStep = (nextRightState.hipRoll() - currentRightState.hipRoll()) / numIter;
    //         float rightKneeStep = (nextRightState.knee() - currentRightState.knee()) / numIter;
    //         float rightAnkleStep = (nextRightState.ankle() - currentRightState.ankle()) / numIter;
    //         float rightFootStep = (nextRightState.foot() - currentRightState.foot()) / numIter;

    //         // Left Leg
    //         float leftHipYawStep = (nextLeftState.hipYaw() - currentLeftState.hipYaw()) / numIter;
    //         float leftHipPitchStep = (nextLeftState.hipPitch() - currentLeftState.hipPitch()) / numIter;
    //         float leftHipRollStep = (nextLeftState.hipRoll() - currentLeftState.hipRoll()) / numIter;
    //         float leftKneeStep = (nextLeftState.knee() - currentLeftState.knee()) / numIter;
    //         float leftAnkleStep = (nextLeftState.ankle() - currentLeftState.ankle()) / numIter;
    //         float leftFootStep = (nextLeftState.foot() - currentLeftState.foot()) / numIter;

    //         // Loop for numIter
    //         for (int j = 1; j <= numIter; j++)
    //         {
    //             // For Right Leg
    //             moveStep(rightHipYawMotor, static_cast<int>(currentRightState.hipYaw() + rightHipYawStep * j));
    //             moveStep(rightHipPitchMotor, static_cast<int>(currentRightState.hipPitch() + rightHipPitchStep * j));
    //             moveStep(rightHipRollMotor, static_cast<int>(currentRightState.hipRoll() + rightHipRollStep * j));
    //             moveStep(rightKneeMotor, static_cast<int>(currentRightState.knee() + rightKneeStep * j));
    //             moveStep(rightAnkleMotor, static_cast<int>(currentRightState.ankle() + rightAnkleStep * j));
    //             moveStep(rightFootMotor, static_cast<int>(currentRightState.foot() + rightFootStep * j));

    //             // For Left Leg
    //             moveStep(leftHipYawMotor, static_cast<int>(currentLeftState.hipYaw() + leftHipYawStep * j));
    //             moveStep(leftHipPitchMotor, static_cast<int>(currentLeftState.hipPitch() + leftHipPitchStep * j));
    //             moveStep(leftHipRollMotor, static_cast<int>(currentLeftState.hipRoll() + leftHipRollStep * j));
    //             moveStep(leftKneeMotor, static_cast<int>(currentLeftState.knee() + leftKneeStep * j));
    //             moveStep(leftAnkleMotor, static_cast<int>(currentLeftState.ankle() + leftAnkleStep * j));
    //             moveStep(leftFootMotor, static_cast<int>(currentLeftState.foot() + leftFootStep * j));

    //             // Preparing JSON
    //             WSData::docRobotSimulation["type"] = "Walking Motion";
    //             WSData::docRobotSimulation["RightHipYaw"] = currentRightState.hipYaw() + rightHipYawStep * j;
    //             WSData::docRobotSimulation["RightHipPitch"] = currentRightState.hipPitch() + rightHipPitchStep * j;
    //             WSData::docRobotSimulation["RightHipRoll"] = currentRightState.hipRoll() + rightHipRollStep * j;
    //             WSData::docRobotSimulation["RightKnee"] = currentRightState.knee() + rightKneeStep * j;
    //             WSData::docRobotSimulation["RightAnkle"] = currentRightState.ankle() + rightAnkleStep * j;
    //             WSData::docRobotSimulation["RightFoot"] = currentRightState.foot() + rightFootStep * j;
    //             WSData::docRobotSimulation["LeftHipYaw"] = currentLeftState.hipYaw() + leftHipYawStep * j;
    //             WSData::docRobotSimulation["LeftHipPitch"] = currentLeftState.hipPitch() + leftHipPitchStep * j;
    //             WSData::docRobotSimulation["LeftHipRoll"] = currentLeftState.hipRoll() + leftHipRollStep * j;
    //             WSData::docRobotSimulation["LeftKnee"] = currentLeftState.knee() + leftKneeStep * j;
    //             WSData::docRobotSimulation["LeftAnkle"] = currentLeftState.ankle() + leftAnkleStep * j;
    //             WSData::docRobotSimulation["LeftFoot"] = currentLeftState.foot() + leftFootStep * j;

    //             Serial.println("Serializing JSON data");
    //             serializeJson(WSData::docRobotSimulation, WSData::serializedData);
    //             Serial.println(WSData::serializedData);
    //             Serial.println("Serialized JSON data");
    //             webSocket.sendTXT(WSData::serializedData);
    //             Serial.println("JSON data Sent");
    //             // webSocket.ping();
    //             delay(stepTime);
    //         }

    //         currentRightState = nextRightState;
    //         currentLeftState = nextLeftState;

    //         nextRightState = rightLegSimulation.legPositions[(i + 2) % timeFramesCount];
    //         nextLeftState = leftLegSimulation.legPositions[(i + 2) % timeFramesCount];
    //         delay(10000); // Delay of 10 seconds just to visualize.
    //     }
    // };

    // void moveToFrameWalkingMotion(int frameNumber)
    // {
    //     // Frame number starts from 0
    //     int timeFramesCount = sizeof(rightLegSimulation.timeData) / sizeof(float);
    //     Leg currentRightState = rightLegSimulation.legPositions[frameNumber];
    //     Leg nextRightState = rightLegSimulation.legPositions[(frameNumber + 1) % timeFramesCount];
    //     Leg currentLeftState = leftLegSimulation.legPositions[frameNumber];
    //     Leg nextLeftState = leftLegSimulation.legPositions[(frameNumber + 1) % timeFramesCount];
    // }
};