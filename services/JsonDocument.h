#include <ArduinoJson.h>

namespace WSData
{

    JsonDocument docRobotSimulation;
    String serializedData;
    void initializeJsonData()
    {
        // Preparing JSON
        docRobotSimulation["type"] = "";
        docRobotSimulation["RightShoulderPitch"] = 0.0;
        docRobotSimulation["RightShoulderRoll"] = 0.0;
        docRobotSimulation["RightArm"] = 0.0;
        docRobotSimulation["LeftShoulderPitch"] = 0.0;
        docRobotSimulation["LeftShoulderRoll"] = 0.0;
        docRobotSimulation["LeftArm"] = 0.0;
        docRobotSimulation["Torso"] = 0.0;
        docRobotSimulation["RightHipYaw"] = 0.0;
        docRobotSimulation["RightHipRoll"] = 0.0;
        docRobotSimulation["RightHipPitch"] = 0.0;
        docRobotSimulation["RightKnee"] = 0.0;
        docRobotSimulation["RightAnkle"] = 0.0;
        docRobotSimulation["RightFoot"] = 0.0;
        docRobotSimulation["LeftHipYaw"] = 0.0;
        docRobotSimulation["LeftHipRoll"] = 0.0;
        docRobotSimulation["LeftHipPitch"] = 0.0;
        docRobotSimulation["LeftKnee"] = 0.0;
        docRobotSimulation["LeftAnkle"] = 0.0;
        docRobotSimulation["LeftFoot"] = 0.0;
    }

    // Automatically call the initializer when the library is included
    struct Initializer
    {
        Initializer()
        {
            initializeJsonData();
        }
    };

    // Create an instance of the Initializer struct (runs on library load)
    Initializer initializer;
}