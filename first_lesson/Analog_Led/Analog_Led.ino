
int button = 9;
int axle = A0;
int led = 11;
int buttonVal = 0;
int axleVal = 0;
int ledVal = 0;





void setup() {

 pinMode(button, INPUT);
 pinMode(led, OUTPUT);
}

void loop() {

axleVal = analogRead(axle);


if(axleVal < 400 && ledVal > 0){

  ledVal = ledVal - 2;
  delay(20);
  analogWrite(led,ledVal);
}

if(axleVal > 600 && ledVal < 255){

  ledVal = ledVal + 2;
  delay(20);
  analogWrite(led,ledVal);
}



}
