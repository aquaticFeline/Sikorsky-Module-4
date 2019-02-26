
#include "UnoJoy.h"

// Define our pins
int TrianglePin = 4;
int SquarePin = 5;
int CrossPin = 3;
int CirclePin = 2;

int r2Pin = 7;
int r1Pin = 6;
//l1Pin = A1;
//l2Pin = A2;


int LeftPin = 8;
int UpPin = 9;
int RightPin = 10;
int DownPin = 11;

int StartPin =  12;
//SelectPin = A3;

void setup(){
  setupPins();
  setupUnoJoy();
}

void loop(){
  // Always be getting fresh data
  dataForController_t controllerData = getControllerData();
  setControllerData(controllerData);
}

void setupPins(void){
  // Set all the digital pins as inputs
  // with the pull-up enabled, except for the 
  // two serial line pins
  for (int i = 2; i <= 12; i++){
    pinMode(i, INPUT);
    digitalWrite(i, HIGH);
  }
  pinMode(A1, INPUT);
  digitalWrite(A1, HIGH);
  pinMode(A2, INPUT);
  digitalWrite(A2, HIGH);
   pinMode(A3, INPUT);
  digitalWrite(A3, HIGH);
}

dataForController_t getControllerData(void){
  
  // Set up a place for our controller data
  //  Use the getBlankDataForController() function, since
  //  just declaring a fresh dataForController_t tends
  //  to get you one filled with junk from other, random
  //  values that were in those memory locations before
  dataForController_t controllerData = getBlankDataForController();
  // Since our buttons are all held high and
  //  pulled low when pressed, we use the "!"
  //  operator to invert the readings from the pins
  controllerData.triangleOn = !digitalRead(TrianglePin);
  controllerData.circleOn = !digitalRead(CirclePin);
  controllerData.squareOn = !digitalRead(SquarePin);
  controllerData.crossOn = !digitalRead(CrossPin);
  
  controllerData.r1On = !digitalRead(r1Pin);
  controllerData.r2On = !digitalRead(r2Pin);
  controllerData.l1On = !digitalRead(A1);
  controllerData.l2On = !digitalRead(A2);
  
  
  
  controllerData.dpadUpOn = !digitalRead(UpPin);
  controllerData.dpadDownOn = !digitalRead(DownPin);
  controllerData.dpadLeftOn = !digitalRead(LeftPin);
  controllerData.dpadRightOn = !digitalRead(RightPin);
  
  controllerData.startOn = !digitalRead(StartPin);
  controllerData.selectOn = !digitalRead(A3);
  
  // And return the data!
  return controllerData;
}
