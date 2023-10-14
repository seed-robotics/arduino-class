int val ;
int val2 ;

void setup() {
Serial.begin(9600);

}

void loop() {
if (Serial.available() > 0){
   val = Serial.parseInt();
   Serial.println(val);
   val2 = Serial.parseInt();
   Serial.println(val2);
   Serial.print("+:  ");
   Serial.println(val + val2); 
   Serial.print("-:  ");
   Serial.println(val - val2);
   Serial.print("*:  ");
   Serial.println(val * val2);
   Serial.print("/:  ");
   Serial.println(val / val2);
   Serial.print("%:  ");
   Serial.println(val % val2);
   
   

if (val % 2 == 0){
  Serial.print("val = artios");
  
}
else{
  Serial.print("val = perittos");
}

}

}
