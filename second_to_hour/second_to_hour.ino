int val ;

int ores ;
int lepta ;
int deut ;
void setup() {
   Serial.begin(9600);
}


void loop() {
 
if (Serial.available() > 0){
  val = Serial.parseInt();
}
if (val>0){
ores = val/3600;
lepta = (val%3600)/60;
deut = (val%3600)%60;
Serial.print("ores = ");
Serial.print(ores);
Serial.print("  ");
Serial.print("lepta = ");
Serial.print(lepta);
Serial.print("  ");
Serial.print("deut = ");
Serial.println(deut);
delay(500);
val=0;
}
}
