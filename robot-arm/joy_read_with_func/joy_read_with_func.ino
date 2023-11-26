const int right_X = A1; // define the right X pin to A2 
const int right_Y = A2; // define the right Y pin to A5 
const int right_key = A0; //define the right key pin to 7（that is the value Z）
const int left_X = A4; //define the left X pin to A3
const int left_Y = A5;  // define the left Y pin to A4
const int left_key = A3; //define the left key pin to 8（that is the value Z） 
int test;
void setup() 
{
  Serial.begin(9600); //  set the baud rate to 9600
}

void loop() 
{ int test;
  joy_read(right_X,right_Y,right_key,"right",1);
  joy_read(left_X,left_Y,left_key,"left",0);

}


void joy_read(int w1,int w2,int w3,char test[20],int end){
  int x1;
  int y1;
  int z1;
  x1 = analogRead(w1); // read the value of right X 
  y1 = analogRead(w2);  // read the value of right Y 
  z1 = analogRead(w3);  //// read the value of right Z 
    //Serial.println("**********right**********");
  Serial.print(test);
  Serial.print("_X = "); // on the serial monitor, print out right_X = 
  Serial.print(x1 ,DEC); // print out the value of right X and line wrap
  Serial.print("  ");
  Serial.print(test);
  Serial.print("_Y = ");
  Serial.print(y1 ,DEC);
  Serial.print("  ");
  Serial.print(test);
  Serial.print("_key = ");
  Serial.print(z1 ,DEC);
  if(end==1)
  Serial.print(" ||| "); 
  else
  Serial.println("");
}
