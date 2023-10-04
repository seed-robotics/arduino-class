int count5 = 1;
int count7 = 1;
int count11 = 1;
int count13 = 1;
void setup(){
  Serial.begin(9600);
}

int printer(int count, int period) {
  if (millis() >= count*period){
  Serial.print("Hello, the time is : ");
  Serial.println(millis()/1000);
  return ++count;
}
}
void loop(){
   count5 = printer(count5, 5000);
   count7 = printer(count7, 7000);
   count11 = printer(count11, 11000);
   count13 = printer(count13, 13000);
}
