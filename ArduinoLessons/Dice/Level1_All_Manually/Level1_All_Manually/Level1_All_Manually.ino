//LED for DICE
int bottomLeft = 3;
int middleLeft = 5;
int upperLeft = 8;
int middle = 7;
int bottomRight = 4;
int middleRight = 6;
int upperRight = 9;

int state = 0;
long randNumber; 

void setup(){
  pinMode(bottomLeft, OUTPUT);
  pinMode(middleLeft, OUTPUT);
  pinMode(upperLeft, OUTPUT);
  pinMode(middle, OUTPUT);
  pinMode(bottomRight, OUTPUT);
  pinMode(middleRight, OUTPUT);
  pinMode(upperRight, OUTPUT);
  Serial.begin(9600);

}

 void loop(){

// Display Number 1 
digitalWrite(middle,HIGH);
delay(2000);
digitalWrite(middle,LOW);
// Display Number 2
digitalWrite(upperLeft,HIGH);
digitalWrite(bottomRight,HIGH);
delay(2000);
// Display Number 3 
digitalWrite(middle,HIGH);
digitalWrite(bottomRight,HIGH);
digitalWrite(upperLeft,HIGH);
delay(2000);
digitalWrite(middle,LOW);
// Display Number 4
digitalWrite(upperLeft,HIGH);
digitalWrite(bottomLeft,HIGH);
digitalWrite(bottomRight,HIGH);
digitalWrite(upperRight,HIGH);
delay(2000);
// Display Number 5
digitalWrite(upperLeft,HIGH);
digitalWrite(bottomLeft,HIGH);
digitalWrite(bottomRight,HIGH);
digitalWrite(upperRight,HIGH);
digitalWrite(middle,HIGH);
delay(2000);
digitalWrite(middle,LOW);
// Display Number 6
digitalWrite(upperLeft,HIGH);
digitalWrite(bottomLeft,HIGH);
digitalWrite(bottomRight,HIGH);
digitalWrite(upperRight,HIGH);
digitalWrite(middleRight,HIGH);
digitalWrite(middleLeft,HIGH);
delay(2000);

delay(3000);
digitalWrite(upperLeft,LOW);
digitalWrite(bottomLeft,LOW);
digitalWrite(bottomRight,LOW);
digitalWrite(upperRight,LOW);
digitalWrite(middleRight,LOW);
digitalWrite(middleLeft,LOW);
 }
		
