int topright = 6;
int topleft = 10;
int belowtopright = 5;
int belowtopleft = 9;
int middleright = 4;
int middleleft = 8;
int bottomleft = 7;
int spaz;
int famas;

int pins[]={4,5,6,7,8,9,10};

int one []={0,0,0,1,0,0,0};
int two []={1,0,0,0,0,0,1};
int three []={1,0,0,1,0,0,1};
int four[] ={1,0,1,0,1,0,1};
int five []={1,0,1,1,1,0,1};
int six []={1,1,1,0,1,1,1};

void numbers(int inpin[]){
  for (int i=0;i<7;i++){
  digitalWrite(pins[i],inpin[i]);
  }
  delay(2000);
}

void setup() {
  
 Serial.begin(9600); 
 pinMode(6, OUTPUT);
pinMode(10, OUTPUT);
pinMode(5, OUTPUT);
pinMode(9, OUTPUT);
pinMode(4, OUTPUT);
 pinMode(8, OUTPUT);
pinMode(7, OUTPUT);


}
void loop() {
  if (digitalRead(2)==1){
  famas =random(1,7);
  
  if (famas==1){
    numbers(one);
  }
  else if (famas==2){
    numbers(two);
  }
  else if (famas==3){
    numbers(three);
  }
  else if (famas==4){
    numbers (four);
  }
  else if (famas==5){
    numbers(five);
  }
  else (famas==6);{
  numbers(six);
  }
  }
}
