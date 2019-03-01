int sensorPin = 5; 
int xvalue1 = 0, yvalue1 = 0;  
float xvalueavg = 0;
int xvalue2 = 0, yvalue2 = 0;
float yvalueavg = 0;
int zvalue1 = 0, zvalue2 = 0;
int zvalueavg = 0; // avg is used loosely
int center = 513;
void setup() { 
pinMode(3, OUTPUT);  
Serial.begin(9600); 
} 
void loop() { 
  // analog pins being read. check these
xvalue1 = analogRead(0);  
//Serial.print("X1 :"); 
//Serial.print(xvalue1, DEC); 
xvalue2 = analogRead(2);
//Serial.print("X2 :");
//Serial.println(xvalue2, DEC); 

xvalueavg = (xvalue1+xvalue2)/2;

yvalue1 = analogRead(1);  
Serial.print("Y1: ");  
Serial.print(yvalue1, DEC);
yvalue2 = analogRead(3);
Serial.print("Y2 :");
Serial.println(yvalue2, DEC); 

yvalueavg = (yvalue1+yvalue2)/2;

zvalue1=yvalue1;
zvalue2=yvalue2;
Serial.print("Z1: ");
Serial.print(zvalue1);
Serial.print("Z2: ");
Serial.println(zvalue2);

Serial.print("xvalavg ");
Serial.println(xvalueavg);
Serial.print("yvalavg ");
Serial.println(yvalueavg);
//maybe go back to before with the absolute value
if (zvalue1-center < zvalue2-center){
  zvalueavg = ((zvalue1-center)+(zvalue2-center))/2;
  }
if (zvalue1-center > zvalue2-center){
  zvalueavg = ((zvalue1-center)+(zvalue2-center))/2;
  }
else {
  ((zvalue1-center)+(zvalue2-center))/2;
}

Serial.print("zvalavg ");
Serial.println(zvalueavg);

delay(1000);
}

 
 
