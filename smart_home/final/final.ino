
#include <Servo.h>
#include <Wire.h>
#include <LiquidCrystal_I2C.h>


#define PIR_MOTION_SENSOR_PIN     2
#define BUZZER_PIN                3
#define BUTTON_ONE_PIN            4
#define LED_YELLOW_PIN            5
#define FAN_REVERSE_PIN           6
#define FAN_NORMAL_PIN            7
#define BUTTON_TWO_PIN            8
#define SERVO_DOOR_PIN            9
#define SERVO_WINDOW_PIN         10
#define RELAY_PIN                12
#define LED_WHITE_PIN            13
#define MQ2_SENSOR_PIN           A0
#define PHOTOCELL_SENSOR_PIN     A1
#define SOIL_HUMIDITY_SENSOR_PIN A2
#define STEAM_SENSOR             A3

#define GAS_DANGER_VALUE         700
#define PHOTOCELL_NIGHT_VALUE    300
#define PIR_MOTION_MOVE_VALUE    1
#define STEAM_RAIN_VALUE         1000
#define SOIL_DROUGHT_VALUE       1000

struct ExtInfo {
  int gasValue;
  int photoCellSensorValue;
  int pirMotionSensorValue;
  int steamSensorValue;
  int soilHumiditySensorValue;
};

struct State {
  bool gasDanger;
  bool nightMonitoring;
  bool rain;
  bool soilDrought;
  bool windowOpen;
  bool doorOpen;
  bool relayState;
  bool whiteLEDState;
  bool yellowLEDState;
  char fanState;
};

LiquidCrystal_I2C lcd(0x27, 16, 2);
Servo servoWindow;
Servo servoDoor;

const String doorPassword = ".--.-.";
int sendCount = 0;
int recvCount = 0;
String password;

State stateInfo;
ExtInfo extInfo;

void setup() {

  Serial.begin(115200);

  lcd.init();
  lcd.backlight();


  servoWindow.attach(SERVO_WINDOW_PIN);
  servoWindow.write(0);

  servoDoor.attach(SERVO_DOOR_PIN);
  servoDoor.write(0);


  pinMode(FAN_REVERSE_PIN, OUTPUT);
  pinMode(FAN_NORMAL_PIN, OUTPUT);
  stopFan();


  pinMode(BUTTON_ONE_PIN, INPUT);

  pinMode(BUTTON_TWO_PIN, INPUT);
  
  pinMode(PIR_MOTION_SENSOR_PIN, INPUT);

  pinMode(BUZZER_PIN, OUTPUT);

  pinMode(MQ2_SENSOR_PIN, INPUT);

  pinMode(PHOTOCELL_SENSOR_PIN, INPUT);

  pinMode(LED_WHITE_PIN, OUTPUT);

  pinMode(STEAM_SENSOR, INPUT);

  pinMode(SOIL_HUMIDITY_SENSOR_PIN, INPUT);

  pinMode(RELAY_PIN, OUTPUT);

  pinMode(LED_YELLOW_PIN, OUTPUT);


  stateInfo.gasDanger       = false;
  stateInfo.nightMonitoring = false;
  stateInfo.rain            = false;
  stateInfo.soilDrought     = false;
  stateInfo.windowOpen      = false;
  stateInfo.doorOpen        = false;
  stateInfo.relayState      = false;
  stateInfo.whiteLEDState   = false;
  stateInfo.yellowLEDState  = false;
  stateInfo.fanState        = '0';
}

void loop() {
  
  extInfo = checkExternalInformation();
  sendWifiData(extInfo);
  recvWifiData();
  emergencyProcess(extInfo, stateInfo);
  normalProcess(extInfo, stateInfo);

  delay(100);
}


ExtInfo checkExternalInformation() {
  ExtInfo result;
  result.gasValue                = getGasValue();
  result.photoCellSensorValue    = getPhotoCellValue();
  result.pirMotionSensorValue    = getPIRMotionSensorValue();
  result.steamSensorValue        = getSteamSensorValue();
  result.soilHumiditySensorValue = getSoilHumiditySensorValue();
  return result;
}


void sendWifiData(ExtInfo extInfo) {
  if(Serial.availableForWrite() >= 44) {
    if(sendCount == 0) {
      Serial.print("Gas Values:");
      Serial.println(strPad(extInfo.gasValue, 4));
      Serial.print("photoCellSensorValue:");
      Serial.println(strPad(extInfo.photoCellSensorValue, 4));
      Serial.print("pirMotionSensorValue:");
      Serial.println(strPad(extInfo.pirMotionSensorValue, 4));
      Serial.print("steamSensorValue:");
      Serial.println(strPad(extInfo.steamSensorValue, 4));
      Serial.print("soilHumiditySensorValue:");
      Serial.println(strPad(extInfo.soilHumiditySensorValue, 4));
      sendCount = 100;
    } else {
      sendCount--;
    }
  }
}

void recvWifiData() {
  if (Serial.available()) {
    stateInfo.gasDanger       = (char)Serial.read() == 1 ? true : false;
    stateInfo.nightMonitoring = (char)Serial.read() == 1 ? true : false;
    stateInfo.rain            = (char)Serial.read() == 1 ? true : false;
    stateInfo.soilDrought     = (char)Serial.read() == 1 ? true : false;
    stateInfo.windowOpen      = (char)Serial.read() == 1 ? true : false;
    stateInfo.doorOpen        = (char)Serial.read() == 1 ? true : false;
    stateInfo.relayState      = (char)Serial.read() == 1 ? true : false;
    stateInfo.whiteLEDState   = (char)Serial.read() == 1 ? true : false;
    stateInfo.yellowLEDState  = (char)Serial.read() == 1 ? true : false;
    stateInfo.fanState        = (char)Serial.read();
  }
}
//           if(Serial.readString( )=="start")
//           {
//            Serial.print("gasDanger");
//            Serial.println(stateInfo.nightMonitoring);
//            stateInfo.nightMonitoring=true;
//            }
//            else if (Serial.readString()=="stop"){
//              stateInfo.nightMonitoring==false;
//            }




void emergencyProcess(ExtInfo extInfo, State stateInfo) {

  if((extInfo.gasValue > GAS_DANGER_VALUE) || stateInfo.gasDanger == true) {
    gasDangerProcess();
  }

  if((extInfo.photoCellSensorValue < PHOTOCELL_NIGHT_VALUE) || stateInfo.nightMonitoring == true) {
    if((extInfo.pirMotionSensorValue == PIR_MOTION_MOVE_VALUE)) {
      onWhiteLED();
    } else {
      offWhiteLED();
    }
  }
  

  if((extInfo.steamSensorValue > STEAM_RAIN_VALUE) || stateInfo.rain == true) {
    steamRainProcess();
  }
 
  if((extInfo.soilHumiditySensorValue > SOIL_DROUGHT_VALUE) || stateInfo.soilDrought == true) {
    soilDroughtProcess();
  }
}


void gasDangerProcess() {

  setLCD(0, 1, "Gas Danger!!");

  tone(BUZZER_PIN, 440);
  delay(125);
  delay(100);
  noTone(BUZZER_PIN);
  delay(100);
  tone(BUZZER_PIN, 440);
  delay(125);
  delay(100);
  noTone(BUZZER_PIN);
}


void steamRainProcess() {

  setLCD(0, 1, "Rain");
  servoWindow.write(180);
}


void soilDroughtProcess() {
 
  setLCD(0, 1, "Please Rain some!");

  tone(BUZZER_PIN, 440);
  delay(125);
  delay(100);
  noTone(BUZZER_PIN);
  delay(100);
  tone(BUZZER_PIN, 440);
  delay(125);
  delay(100);
  noTone(BUZZER_PIN);
}


void normalProcess(ExtInfo extInfo, State stateInfo) {

  int button1Count = 0;
  int button2Count = 0;

  byte button1Value = getButton1();
  byte button2Value = getButton2();


  if (button1Value == 0) {
    while (button1Value == 0 && button1Count < 10) {
      button1Value = getButton1();
      button1Count++;
      delay(100);
    }
  }

  if (button1Count >= 1 && button1Count < 5) {

    password = String(password) + String(".");
    setLCD(0, 1, password);
  } else if(button1Count >= 5) {

    password = String(password) + String("-");
    setLCD(0, 1, password);
  }


  if (button2Value == 0) {
    while (button2Value == 0 && button2Count < 10) {
      button2Value = getButton2();
      button2Count++;
      delay(100);
    }
  }

  if (button2Count >= 1) {
    if(password == doorPassword) {
      password = "";
      setLCD(0, 0, "OPEN!");
      servoDoor.write(100);
      delay(5000);
      setLCD(0, 0, "PassWord?:");
    } else {
      password = "";
      setLCD(0, 0, "ERROR!");
      delay(5000);
      setLCD(0, 0, "PassWord?:");
    }
  }


  if (stateInfo.doorOpen == true) {
    servoDoor.write(90);
  } else if(stateInfo.doorOpen == false) {
    servoDoor.write(0);
  }


  if (stateInfo.windowOpen == true) {
    servoWindow.write(90);
  } else if(stateInfo.windowOpen == false) {
    servoWindow.write(0);
  }


  if (stateInfo.yellowLEDState == true) {
    onYellowLED();
  } else if(stateInfo.yellowLEDState == false) {
    offYellowLED();
  }

  if (stateInfo.whiteLEDState == true) {
    onWhiteLED();
  } else if(stateInfo.whiteLEDState == false) {
    offWhiteLED();
  }


  if (stateInfo.relayState == true) {
    onRelay();
  } else if(stateInfo.relayState == false) {
    offRelay();
  }

  if (stateInfo.fanState == '1') {
    normalFan();
  } else if(stateInfo.fanState == '2') {
    reverseFan();
  } else if(stateInfo.fanState == '0') {
    stopFan();
  }
}


void setLCD(int column, int line, String printWord) {
  lcd.clear();
  lcd.setCursor(column, line);
  lcd.print(printWord);
}


void onWhiteLED() { digitalWrite(LED_WHITE_PIN, HIGH); }
void offWhiteLED() { digitalWrite(LED_WHITE_PIN, LOW); }
void onYellowLED() { digitalWrite(LED_YELLOW_PIN, HIGH); }
void offYellowLED() { digitalWrite(LED_YELLOW_PIN, LOW); }


int getGasValue() { return analogRead(MQ2_SENSOR_PIN); }
int getPhotoCellValue() { return analogRead(PHOTOCELL_SENSOR_PIN); }
int getSteamSensorValue() { return analogRead(STEAM_SENSOR); }
int getPIRMotionSensorValue() {
  Serial.print("PIR");
  Serial.println(digitalRead(PIR_MOTION_SENSOR_PIN));
  return digitalRead(PIR_MOTION_SENSOR_PIN); }
int getSoilHumiditySensorValue() {return analogRead(SOIL_HUMIDITY_SENSOR_PIN); }


byte getButton1(){ return digitalRead(BUTTON_ONE_PIN);}
byte getButton2(){ return digitalRead(BUTTON_TWO_PIN);}


void stopFan() {
  digitalWrite(FAN_REVERSE_PIN, LOW);
  digitalWrite(FAN_NORMAL_PIN, LOW);
}

void normalFan() {
  digitalWrite(FAN_REVERSE_PIN, LOW);
  digitalWrite(FAN_NORMAL_PIN, HIGH);
} 

void reverseFan() {
  digitalWrite(FAN_REVERSE_PIN, HIGH);
  digitalWrite(FAN_NORMAL_PIN, LOW);
}


void offRelay() { digitalWrite(RELAY_PIN, LOW); }
void onRelay() { digitalWrite(RELAY_PIN, HIGH); }


String strPad(int num,int zeroCount){
  String str = String(num);
  String returnStr = "";
  if(zeroCount <= str.length()){
    return str;
  }
  for(int i = 0;i < zeroCount - str.length();i++){
    returnStr += '0';
  }
  return returnStr + str;
}
