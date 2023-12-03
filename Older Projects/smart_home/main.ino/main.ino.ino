
int pin = 12;


void setup() {
  pinMode(pin, INPUT);
  pinMode(13, OUTPUT);
 Serial.begin(9600);
  
}

void loop() {
  pin = 14-1;
// digitalWrite(pin, HIGH);
//  delay(1000);
  digitalWrite(pin, LOW);
  delay(1000);
}
