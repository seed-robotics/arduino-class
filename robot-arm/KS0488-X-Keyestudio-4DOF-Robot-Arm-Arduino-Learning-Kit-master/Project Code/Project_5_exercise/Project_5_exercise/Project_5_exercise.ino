#include <Servo.h>  //add Servo library file
Servo myservo1;  // create servo object to control a servo
Servo myservo2;
Servo myservo3;
Servo myservo4;  

int pos1=90, pos2=60, pos3=130, pos4=0;  // define the variable of 4 servo angle,and assign the initial value (that is the boot posture angle value) 

const int right_X = A2; // define the right X pin to A2
const int right_Y = A5; //define the right Y pin to A5
const int right_key = 7; // define the right key to 7(the value of Z axis)
const int left_X = A3; // define the left X pin to A3
const int left_Y = A4;  // define the left Y pin to A4
const int left_key = 6; // define the left key to 6(the value of Z axis)

int x1,y1,z1;  //define a variable to store the read Joystick value
int x2,y2,z2;

void setup() 
{
  Serial.begin(9600); //  set the baud rate to 9600 

  //start up posture 
  myservo1.write(pos1);  
  delay(1000);
  myservo2.write(pos2);
  myservo3.write(pos3);
  myservo4.write(pos4);
  delay(1500);

  pinMode(right_key, INPUT);   // set the right/left key to INPUT
  pinMode(left_key, INPUT);
  myservo1.attach(A1);  //set the control pin of Servo1 to A1
  myservo2.attach(A0);  //set the control pin of Servo2 to A0
  myservo3.attach(8);   //set the control pin of Servo3 to D8
  myservo4.attach(9);   //set the control pin of Servo4 to D9
}
 
void loop() 
{
  x1 = analogRead(right_X); // read the value of right X axis
  y1 = analogRead(right_Y);  // read the value of right Y axis
  z1 = digitalRead(right_key);  ////read the value of right Z axi
  x2 = analogRead(left_X);  //read the value of left X axis
  y2 = analogRead(left_Y);  //read the value of left Y axis
  z2 = digitalRead(left_key);  //read the value of left Z axis 
  // delay(5);  //lower the speed overall

  //clamp claw
  claw();
}



  
  //rotate
  rotate();
  //Right Servo
  right_ser();
  //Left Servo
  left_ser();
}

//Claw
void claw()
{
    //Claw
  if(x2<50) //if push the left joystick to the right
  {
      pos4=pos4-1;  //current angle of servo 4 subtracts 1（change the value you subtract, thus change the closed speed of claw）
      //Serial.println(pos4);
      myservo4.write(pos4);  //Servo4 operates the action，claw gradually closes
      delay(5);
      if(pos4<0)  //if pos4 value subtracts to 0
      {            //（change value according to real situation）
        pos4=0;   //stop subtraction when reduce to 0
      }
   }
  if(x2>1000) ////if push the left joystick to the left 
  {
      pos4=pos4+2; // current angle of servo 4 plus 2（change the value you plus, thus change the open speed of claw）

      //Serial.println(pos4);
      myservo4.write(pos4); //Servo4 operates the motion, the claw gradually opens.

      delay(5);
      if(pos4>110)  //limit the largest angle when open the claw 
      {
        pos4=110;                                
      }
  }
}
 
