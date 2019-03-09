/*
 * 3/8/19 So I got some math wrong for z value
 * but this should work in the serial port and
 * then clearview. i am working on implementing it
 * into clearview as of 8:14 pm EST
3/3/19
Turns out the joystick range error was due to voltage.
This code has working x y and z  in the serial port.
Bug: y when moved up is 0 and y when moved down is 1023
A fix is being worked on
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
Serial.begin(9600); 
} 
void loop() { 

xvalue1 = analogRead(0);  
//Serial.print("X1 :"); 
//Serial.print(xvalue1, DEC); 
xvalue2 = analogRead(2);
//Serial.print("X2 :");
//Serial.println(xvalue2, DEC); 

xvalueavg = (xvalue1+xvalue2)/2;

yvalue1 = analogRead(1);  
//Serial.print("Y1: ");  
//Serial.print(yvalue1, DEC);
yvalue2 = analogRead(3);
//Serial.print("Y2 :");
//Serial.println(yvalue2, DEC); 

yvalueavg = (yvalue1+yvalue2)/2;

Serial.print("xvalavg ");
Serial.println(xvalueavg);
Serial.print("yvalavg ");
Serial.println(yvalueavg);

zvalue1 = yvalue1;
zvalue2 = yvalue2;

if (zvalue1 < 490 && zvalue2 > 510){
  zvalueavg =((1023-zvalue1)+zvalue2)/2;
}
else {
  zvalueavg = 512;
}
if (zvalue1 > 510 && zvalue2 < 490) {
  zvalueavg =((1023-zvalue1)+zvalue2)/2;
}


//Serial.print("Z1: ");  
//Serial.print(zvalue1);
//Serial.print("Z2: ");
//Serial.println(zvalue2, DEC); 
Serial.print("Zvalueavg: ");
Serial.println(zvalueavg);

throttle = analogRead(4);
Serial.println(throttle);

delay(1000);
}

 
 
