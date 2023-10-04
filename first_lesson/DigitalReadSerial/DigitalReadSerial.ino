

int pushButton=2;

int led =7;

// the setup routine runs once when you press reset:
void setup() {
 
  // initialize serial communication at 9600 bits per second:
  Serial.begin(9600);
  // make the pushbutton's pin an input:
  pinMode(pushButton, INPUT);
  pinMode(led, INPUT);
}

// the loop routine runs over and over again forever:
void loop() {
  // read the input pin:
  int buttonState = digitalRead(pushButton);
  // print out the state of the button:
  Serial.println(buttonState);
  delay(1);        // delay in between reads for stability
  if(buttonState==1){
   digitalWrite(7,HIGH);
   delay(3000);
   digitalWrite(7,LOW);
  }
}
