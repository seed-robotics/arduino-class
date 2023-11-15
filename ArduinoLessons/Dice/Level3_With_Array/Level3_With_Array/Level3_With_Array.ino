//LED for DICE
int pins[]={3,4,5,6,7,8,9};
const int pinsNum = sizeof(pins) / sizeof(pins[0]); 
int one[]={0,0,0,0,1,0,0};
int two[]={0,1,0,0,0,1,0};
int three[]={0,1,0,0,1,1,0};
int four[]={1,1,0,0,0,1,1};
int five[]={1,1,0,0,1,1,1};
int six[]={1,1,1,1,0,1,1};

int state = 0;
long randNumber;
int delTime=500;

void setup(){
  for (int i=0;i<pinsNum;i++){
    pinMode(pins[i],OUTPUT);
  }
  Serial.begin(9600);
}

 void loop(){
   number(one);
   number(two);
   number(three);
   number(four);
   number(five);
   number(six);
 }

void number(int num[]){
  for (int i=0;i<pinsNum;i++){
    digitalWrite(pins[i],num[i]);
  }
  delay(delTime);
  clearAll();
}
  
void clearAll(){
  for (int i=0;i<pinsNum;i++){
    digitalWrite(pins[i],LOW);
  }
}
