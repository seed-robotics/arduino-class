int pins[]={3,4,5,6,7,8,9};

int one[]={0,0,0,0,0,0,1};
int two[]={0,1,0,0,1,0,0};
int three[]={0,1,0,0,1,0,1};
int four[]={1,1,0,0,1,1,0};
int five[]={1,1,0,0,1,1,1};
int six[]={1,1,1,1,1,1,0};

int randomVal = 0;
int sensorVal = 0;

int button = 13;
int buttonVal = 0;

float sum = 0;
int count = 0;

int sensor =12;

void setup(){  for (int i=0; i<7; i++){
    pinMode(pins[i],OUTPUT);
  }
  Serial.begin(9600);
}

void loop(){

sensorVal = digitalRead(sensor);
buttonVal = digitalRead(button);






if(sensorVal == 0){
  

randomVal = random(1,7);
sum = sum + randomVal;
count++;
 

if(randomVal == 1){
 number(one);}

if(randomVal == 2){
 number(two);}

if(randomVal == 3){
 number(three);}

if(randomVal == 4){
 number(four);}

if(randomVal == 5){
 number(five);}

if(randomVal == 6){
 number(six);}




int temp = 0;
while(1) {
  delay(1);
  sensorVal = digitalRead(sensor);
  temp++;
  if(sensorVal==0) {
    Serial.print("O Mesos Oros ton zarion sou einai: ");
   Serial.println(sum/count);

   sum = 0;
   count = 0;
   break;
  }
  if(temp >= 1000) {
   
    break;
  }
}


}
}

void number(int num[]){
  for (int i=0; i<7; i++){
    digitalWrite(pins[i],num[i]);
    }

   delay(1500);
   clearAll();
}


void clearAll(){
  for (int i=0;i<7  ;i++){
    digitalWrite(pins[i],LOW);
  }
}
