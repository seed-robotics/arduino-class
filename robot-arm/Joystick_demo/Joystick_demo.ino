#include <Servo.h>
#define joyX A0
#define joyY A1  
#define joyX2 A2
#define joyY2 A3 
int xval=0;
int yval=0;
int xval2=0;
int yval2=0;

int servox;
int servoy;
int pos=90;
int pos2=90;
int pos3=90;
int pos4=90;
Servo servo1;
Servo servo2;
Servo servo3;
Servo servo4;
int pin=2;

void setup() {
Serial.begin(9600);
servo1.attach(9);
servo2.attach(10);
servo3.attach(11);
servo4.attach(12);
pinMode (joyX, INPUT) ;                     
pinMode (joyY, INPUT) ;
pinMode (joyX2, INPUT) ;                     
pinMode (joyY2, INPUT) ;
pinMode(pin, INPUT_PULLUP );
}

void loop() {
 xval=analogRead(A0);
 yval=analogRead(A1);
 xval2=analogRead(A2);
 yval2=analogRead(A3);


if (xval>900 && pos<150){
  servo1.write(pos);
  pos+=2;
  delay(30);
}
else if (xval<280 && pos>75){
  servo1.write(pos);
  pos-=2;
  delay(30);
}

Serial.println(yval);
if (yval>1000 && pos2<180){
  servo2.write(pos2);
   pos2+=3;
   delay(30);
}
else if (yval<10 && pos2>0){
  servo2.write(pos2);
  pos2-=3;
  delay(30);
}


if (digitalRead(pin)==LOW){
servo1.write(90);
servo2.write(90);
servo3.write(90);
servo4.write(90);
Serial.println("pressed");
delay(10);
}

//3RD JOINT
if (yval2>800 && pos3<160){
  servo3.write(pos3);
  pos3+=2;
//  Serial.println(pos2);
  delay(30);
}
else if (yval2<380 && pos3>85){
  servo3.write(pos3);
  pos3-=2;
//  Serial.println(pos2);
  delay(30);
}

//DAGANA
if (xval2>800 && pos4<190){
  servo4.write(pos4);
  Serial.println(pos4);
  pos4+=3;
  delay(30);
}
else if (xval2<380 && pos4>25){
  servo4.write(pos4);
   Serial.println(pos4);
  pos4-=3;
//  Serial.println(pos2);
  delay(30);
}
//DAGANA

}
