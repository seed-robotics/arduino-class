//call the relevant library file
#include <Servo.h>
#include <Wire.h>
#include <LiquidCrystal_I2C.h> 
#include "vars.h"

//Set the communication address of I2C to 0x27, display 16 characters every line, two lines in total
LiquidCrystal_I2C mylcd(0x27, 16, 2);

//set ports of two servos to digital 9 and 10
Servo servo_10;
Servo servo_9;

void setup() {
  Serial.begin(9600);//set baud rate to 9600
  components_init();
}

void loop() {
  auto_sensor();
  if (Serial.available() > 0) //serial reads the characters
  {
    val = Serial.read();//set val to character read by serial    
    Serial.println(char(val));//output val character in new lines
    pwm_control();
  }
  switch (val) {
    case 'a'://if val is character 'a'，program will circulate
      digitalWrite(13, HIGH); //set digital 13 to high level，LED   lights up
      break;//exit loop
    case 'b'://if val is character 'b'，program will circulate
      digitalWrite(13, LOW); //Set digital 13 to low level, LED is off
      break;//exit loop
    case 'c'://if val is character 'c'，program will circulate
      digitalWrite(12, HIGH); //set digital 12 to high level，NO of relay is connected to COM
      break;//exit loop
    case 'd'://if val is character 'd'，program will circulate
      digitalWrite(12, LOW); //set digital 12 to low level，NO of relay is disconnected to COM

      break;//exit loop
    case 'e'://if val is character 'e'，program will circulate
      birthday();//play birthday song
      break;//exit loop
    case 'f'://if val is character 'f'，program will circulate
      Ode_to_Joy();//play ode to joy song
      break;//exit loop
    case 'g'://if val is character 'g'，program will circulate
      noTone(3);//set digital 3 to stop playing music
      break;//exit loop
    case 'h'://if val is character 'h'，program will circulate
      Serial.println(light);//output the value of variable light in new lines
      delay(100);
      break;//exit loop
    case 'i'://if val is character 'i'，program will circulate
      Serial.println(gas);//output the value of variable gas in new lines
      delay(100);
      break;//exit loop
    case 'j'://if val is character 'j'，program will circulate
      Serial.println(soil);//output the value of variable soil in new lines
      delay(100); 
      break;//exit loop
    case 'k'://if val is character 'k'，program will circulate
      Serial.println(water);//output the value of variable water in new lines
      delay(100);
      break;//exit loop
    case 'l'://if val is character 'l'，program will circulate
      servo_9.write(180);//set servo connected to digital 9 to 180°
      delay(500);
      break;//exit loop
    case 'm'://if val is character 'm'，program will circulate
      servo_9.write(0);;//set servo connected to digital 9 to 0°
      delay(500);
      break;//exit loop
    case 'n'://if val is character 'n'，program will circulate
      servo_10.write(180);//set servo connected to digital 10 to 180°
      delay(500);
      break;//exit loop
    case 'o'://if val is character 'o'，program will circulate
      servo_10.write(0);//set servo connected to digital 10 to 0°
      delay(500);
      break;//exit loop
    case 'p'://if val is character 'p'，program will circulate
      digitalWrite(5, HIGH); //set digital 5 to high level, LED is on
      break;//exit loop
    case 'q'://if val is character 'q'，program will circulate
      digitalWrite(5, LOW); // set digital 5 to low level, LED is off
      break;//exit loop
    case 'r'://if val is character 'r'，program will circulate
      digitalWrite(7, LOW);
      digitalWrite(6, HIGH); //fan rotates anticlockwise at the fastest speed
      break;//exit loop
    case 's'://if val is character 's'，program will circulate
      digitalWrite(7, LOW);
      digitalWrite(6, LOW); //fan stops rotating
      break;//exit loop
  }
  delay(100);
}
