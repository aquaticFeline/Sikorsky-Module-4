
#include "UnoJoy.h"

/*
3/9/19 - Works in clearview as intended! Changed throttle to max and 512 to yvalueavg in else statement
 * 3/8/19 - Should work in clearview? It is being tested
 * as of 8:18 pm EST
3/5/19 Uploads to arduino. Throttle may be broken but i'd like to try
modifying clearview settings first
*/


//Initialize Variables
int sensorPin = 5; 
int xvalue1 = 0, yvalue1 = 0;  
int xvalueavg = 510;
int xvalue2 = 0, yvalue2 = 0;
int yvalueavg = 510;
int zvalue1 = 0, zvalue2 = 0;
int zvalueavg = 510;
int throttle = 1023;


//Setup Pins
void setup() { 
  pinMode(3, OUTPUT);
  setupUnoJoy();  
  //Serial.begin(9600);
} 


//Main calculation loop
void loop() { 
  dataForController_t controllerData = getControllerData();
  setControllerData(controllerData);

  //Get x values from pins
  xvalue1 = analogRead(A0);  
  xvalue2 = analogRead(A2);
  //Calculate X average
  xvalueavg = ((xvalue1+xvalue2)/2);

  //Get Y value from pins
  yvalue1 = analogRead(A1);  
  yvalue2 = analogRead(A3);
  //Calculate Y average
  yvalueavg = ((yvalue1+yvalue2)/2);

  //Threshold for Y stick
  if((abs((yvalue1 - yvalue2)) < 16) && (yvalueavg > 496 && yvalueavg < 536)) {
    yvalueavg = 510;
  }

  //Threshold for X stick
  if((abs((xvalue1 - xvalue2)) < 16) && (xvalueavg > 489 && xvalueavg < 521)) {
    xvalueavg = 510;
  }


  //Calculate Z Rotations (YAW)
  if(yvalue2 > 768 && yvalue1 < 256) {
    zvalueavg = (abs(yvalue1) + abs(yvalue2)) - 1021;
  } else if(yvalue2 < 256 && yvalue1 > 768) {
     zvalueavg = (abs(yvalue1) + abs(yvalue2));
  } else {
    zvalueavg = 510;
  }

  

  //Serial.println(zvalueavg);

  throttle = analogRead(A4);

  

  
  delay(100);
}
dataForController_t getControllerData(void){
  dataForController_t controllerData = getBlankDataForController();
 
  //Send data to Clearview
  controllerData.leftStickY = (yvalueavg) >>2;
  
  controllerData.leftStickX = (xvalueavg) >>2;

  controllerData.rightStickY = (zvalueavg) >>2;

  controllerData.rightStickX = throttle >>2;
  
  // And return the data!
  return controllerData;
}
