
#include "UnoJoy.h"

/*
 * 3/8/19 - Should work in clearview? It is being tested
 * as of 8:18 pm EST
3/5/19 Uploads to arduino. Throttle may be broken but i'd like to try
modifying clearview settings first
*/

int sensorPin = 5; 
int xvalue1 = 0, yvalue1 = 0;  
float xvalueavg = 0;
int xvalue2 = 0, yvalue2 = 0;
float yvalueavg = 0;
int zvalue1 = 0, zvalue2 = 0;
float zvalueavg = 0;
int center = 503; //yvalavg at no sticks moving
int throttle = 0;

void setup() { 
  pinMode(3, OUTPUT);
  setupUnoJoy();  
} 

void loop() { 
  dataForController_t controllerData = getControllerData();
  setControllerData(controllerData);

  xvalue1 = analogRead(0);  
  xvalue2 = analogRead(2);
  xvalueavg = (xvalue1+xvalue2)/2;

  yvalue1 = analogRead(1);  
  yvalue2 = analogRead(3);
  yvalueavg = (yvalue1+yvalue2)/2;

  zvalue1 = yvalue1;
  zvalue2 = yvalue2;
// want to take absolute value of center - zval
//left down right up =0; left up right down = 1023. match this with if + in between.
  if (zvalue1 < 490 && zvalue2 > 510){
    zvalueavg =((1023-zvalue1)+zvalue2)/2;
  }
  else {
    zvalueavg = 512;
  }
  if (zvalue1 > 510 && zvalue2 < 490) {
    zvalueavg =((1023-zvalue1)+zvalue2)/2;
  }

  throttle = analogRead(4);
  delay(100);
}
dataForController_t getControllerData(void){
  dataForController_t controllerData = getBlankDataForController();
  controllerData.leftStickX = xvalueavg;
  controllerData.leftStickY = yvalueavg;
  controllerData.rightStickX = throttle;
  controllerData.rightStickY = zvalueavg;
  // And return the data!
  return controllerData;
}
