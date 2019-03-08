/* Read Jostick
  * ------------
  *
  * Reads two analog pins that are supposed to be
  * connected to a jostick made of two potentiometers
  *
  * We send three bytes back to the comp: one header and two
  * with data as signed bytes, this will take the form:
  *     Jxy\r\n
  *
  * x and y are integers and sent in ASCII 
  * 
  * http://www.0j0.org | http://arduino.berlios.de
  * copyleft 2005 DojoDave for DojoCorp
  */

 int ledPin = 13;
 int joyPin1 = 0;                 // slider variable connecetd to analog pin 0
 int joyPin2 = 1;                 // slider variable connecetd to analog pin 1
 int joyPin3 = 2;                 // slider variable connecetd to analog pin 2
 int joyPin4 = 3;                 // slider variable connecetd to analog pin 3
 
 int value1 = 0;                  // variable to read the value from the analog pin 0
 int value1b = 0;
 int value2 = 0;                  // variable to read the value from the analog pin 1
 int value2b = 0;
 int value3 = 0;                  // variable to read the value from the analog pin 2
 int value3b = 0;
 int value4 = 0;                  // variable to read the value from the analog pin 3
 int value4b = 0;

 void setup() {
  pinMode(ledPin, OUTPUT);              // initializes digital pins 0 to 7 as outputs
  Serial.begin(9600);
 }
 
 int smoothValue(int data, int data2) {
  data -= 504;
  data2 -= 504;
  return ((data + data2) / 225);
 }

 void loop() {
  // reads the value of the variable resistor 
  value1 = analogRead(joyPin1);   
  // this small pause is needed between reading
  // analog pins, otherwise we get the same value twice
  delay(50);             
  // reads the value of the variable resistor 
  value1b = analogRead(joyPin1);
  value2 = analogRead(joyPin2);   
  delay(1);
  value2b = analogRead(joyPin2);
  value3 = analogRead(joyPin3);
  delay(1);
  value3b = analogRead(joyPin3);
  value4 = analogRead(joyPin4);
  delay(1);
  value4b = analogRead(joyPin4);

  Serial.println(smoothValue(value1, value1b));
  //Serial.println(smoothValue(value2, value2b));
  //Serial.println(treatValue(value3));
  //Serial.println(treatValue(value4));
 }
