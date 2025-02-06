// For I2C communication.
#include <Wire.h>
// For Wifi Connection
#include <WiFi.h>
// #include "./Components/LegSimulation.h"
#include "./Components/RobotSimulation.h"
#include "./constants.h"
#include "./globalObjects.h"
#include "./services/MyWebSocketClient.h"
#include <ArduinoJson.h>

// Wifi Credentials
const char *ssid = "Sabin@2G@ClassicTech";
const char *password = "19161214Sabin@";

// Server Details
const char *serverHost = "192.168.254.6";
int serverPort = 3000;
const char *serverPath = "/?apiKey=a1b2-c3d4-e5f6-g7h8-i9";

bool clientConnected = false;

// Functions Declarations
// Event handler for web socket client events
void webSocketEvent(WStype_t type, uint8_t *payload, size_t length);
// Function to setup wifi connection with NodeMCU
void setupWifi();
// Function that runs after getting the data from the server
void runWithPayload(uint8_t *payload, size_t length);

// Custom Classes

// My One time Objects
// LegSimulation rightLegSimulation = LegSimulation();
// Leg currentState = rightLegSimulation.legPositions[0];
// Leg nextState = rightLegSimulation.legPositions[1];
// int timeFramesCount = sizeof(rightLegSimulation.timeData) / sizeof(float);
RobotSimulation robotSimulation = RobotSimulation();

void setup()
{
  // For Communication with computer
  Serial.begin(115200);
  Serial.println("Welcome to Enhanced Humanoid Robot Project!");
  // Function to setup wifi connection.
  setupWifi();
  // Initializing the web socket client
  webSocket.begin(serverHost, serverPort, serverPath);
  // Providing the event handler to the web socket client
  webSocket.onEvent(webSocketEvent);
  // IF connection with the sever is failed, then try to reconnect with the server every 5 seconds.
  webSocket.setReconnectInterval(5000);
  // For I2C communication begining
  Wire.begin();

  // initializing other servos
  initializeOtherServos();
}

void loop()
{
  // calling the loop method of websocket client to keep the connection alive and keep connection with the server. DO NOT REMOVE THIS LINE
  webSocket.loop();
  // if (clientConnected)
  // {
  //   Serial.println('Picking Up Object');
  //   robotSimulation.walkingMotion();
  // }
  // delay(2000);

  // Wire.beginTransmission(i2cAddress);
  // buffer[0] = 10;
  // buffer[1] = 120;
  // Wire.write(buffer,2);
  // Wire.endTransmission();
  // // STEPS:
  // //  1. Loop for each value of time frames;
  // for (int i = 0; i < timeFramesCount; i++)
  // {
  //   // int currValue = i % (timeFramesCount - 1);
  //   // Get time to move to next frame
  //   float time = rightLegSimulation.timeData[i];
  //   // Get number of iterations of to reach next frame
  //   float numIter = time * 1000 / stepTime;

  //   // Calculate the angle step for each value of iteration;
  //   float hipStep = (nextState.hip() - currentState.hip()) / numIter;
  //   float thighStep = (nextState.thigh() - currentState.thigh()) / numIter;
  //   float kneeStep = (nextState.knee() - currentState.knee()) / numIter;
  //   float ankleStep = (nextState.ankle() - currentState.ankle()) / numIter;
  //   float footStep = (nextState.foot() - currentState.foot()) / numIter;
  //   Serial.print("Frame");
  //   Serial.println(i);
  //   Serial.println(currentState.foot());
  //   // Loop for numIter
  //   for (int j = 1; j <= numIter; j++)
  //   {
  //     // For Hip
  //     moveStep(hipMotor, static_cast<int>(currentState.hip() + hipStep * j));
  //     // For Thigh
  //     moveStep(thighMotor, static_cast<int>(currentState.thigh() + thighStep * j));
  //     // For Knee
  //     moveStep(kneeMotor, static_cast<int>(currentState.knee() + kneeStep * j));
  //     // For Ankle
  //     moveStep(ankleMotor, static_cast<int>(currentState.ankle() + ankleStep * j));
  //     // For Foot
  //     moveStep(footMotor, static_cast<int>(currentState.foot() + footStep * j));
  //     delay(stepTime);
  //   }
  //   // delay(1000);

  //   // currentState = rightLegSimulation.legPositions[(i+1)%(timeFramesCount-1)];
  //   currentState = nextState;
  //   nextState = rightLegSimulation.legPositions[(i + 2) % (timeFramesCount - 1)];
  // }
  // Wire.endTransmission();
}

// Functions Implementations

void setupWifi()
{
  WiFi.begin(ssid, password);
  Serial.printf("Connecting to the wifi with ssid %s\n", ssid);
  while (WiFi.status() != WL_CONNECTED)
  {
    delay(500);
    Serial.print(".");
  }
  Serial.printf("\nConnected to WiFi network %s with IP Address:", ssid);
  Serial.println(WiFi.localIP());
}

void webSocketEvent(WStype_t type, uint8_t *payload, size_t length)
{
  switch (type)
  {
  case WStype_DISCONNECTED:
    Serial.printf("\n[WSC] Disconnected");
    clientConnected = false;
    break;
  case WStype_CONNECTED:
    Serial.printf("\n[WSC] Connected to url: %s\n", payload);
    clientConnected = true;
    break;
  case WStype_TEXT:
    Serial.printf("\n[WSC] got text: %s\n", payload);
    // std::string payloadString = payload;
    runWithPayload(payload, length);
    // if any operation need to be performed with the received data, then do it here.
    break;
  case WStype_BIN:
    Serial.printf("\n[WSC] got binary of length: %u\n", length);
    // if any operation need to be performed with the received data, then do it here.
    break;
  case WStype_PING:
    Serial.printf("\n[WSC] get ping\n");
    break;
  case WStype_PONG:
    Serial.printf("\n[WSC] get pong\n");
    break;
  }
}

void runWithPayload(uint8_t *payload, size_t length)
{
  JsonDocument doc;
  // Convert payload to a proper format and deserialize
  char jsonPayload[length + 1];
  memcpy(jsonPayload, payload, length);
  jsonPayload[length] = '\0'; // Add null-terminator to identify as proper json data

  DeserializationError error = deserializeJson(doc, jsonPayload);
  if (error)
  {
    Serial.printf("Failed to parse JSON: %s\n", error.c_str());
    return;
  }
  // Access the JSON keys and values
  String type = doc["type"];
  Serial.println(type);
  if (type == "motion-planning")
  {

    int motor = doc["key"];
    int angle = doc["value"];

    Serial.printf("The motor %d is to be moved to %d angle\n", motor, angle);
    moveStep(motor, angle);
    // buffer[0] = motor;
    // buffer[1] = angle;
    // Wire.beginTransmission(i2cAddress);
    // Wire.write(buffer, 2);
    // Wire.endTransmission();
    webSocket.sendTXT("Data Received");
  }
  else if (type == "frame-change")
  {
    int frameNumber = doc["frameNumber"];
    bool frameIncrease = doc["frameIncrease"];
    Serial.println(frameNumber);
    Serial.println(frameIncrease);
    robotSimulation.moveToFrame(frameNumber, frameIncrease);
  }
  else if (type == "server-frame")
  {
    float doc10 = doc["10"];
    Serial.println(doc10);
    robotSimulation.moveToServerFrame(doc["0"], doc["1"], doc["2"], doc["3"], doc["4"], doc["5"], doc["6"], doc["7"], doc["8"], doc["9"], doc["10"], doc["11"], doc["12"], doc["13"], doc["14"], doc["15"], doc["16"], doc["17"], doc["18"], doc["19"], doc["20"]);
  }
  // if (key != nullptr) {
  //     Serial.printf("The motor %s is to be moved to %d angle\n", motor, value);
  // } else {
  //     Serial.println("Key or value missing in the JSON payload.");
  // }
}