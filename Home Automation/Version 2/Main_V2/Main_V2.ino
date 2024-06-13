/*
This is the updated version of the the first program(Version 1 Home Automation).
*/

#include <SoftwareSerial.h>
#include <LiquidCrystal.h>
#include <EEPROM.h>
#include "DS1302.h"
#include <DHT.h>

//=============================  pins  ================================//
#define DHTPIN 5
#define DHTTYPE DHT11
#define xPin A6
#define yPin A7
#define fan 8
#define buzz 13
#define d 300  //define a delay

//================================  initialization  ==============================================//
SoftwareSerial bt(6, 7);
LiquidCrystal lcd(A0, A1, A2, A3, A4, A5);
DHT dht(DHTPIN, DHTTYPE);
DS1302 rtc(2, 3, 4);
Time t;


//=====================================  logics  ========================================//
byte menu = 1;
byte menuLevel = 0;
byte a, b;
byte v1 = 0, v2 = 0, v3 = 0, v4 = 0, f1 = 0 ,all = 0;
byte L1 = 0, L2 = 1, L3 = 2, L4 = 3, myfan = 4;
byte vL1 = 5, vL2 = 6, vL3 = 7, vL4 = 8, vmyfan = 9;
char buttonPressed = '0';
char value = '0';
char c;
int a_hour, a_min, hour, min, sec, hh, day, mon, yer;
int led[] = { 9, 10, 11, 12 };
String prepand;
String 

//================================= for general timiing =============================================//
unsigned long currTime;
unsigned long prevTime;
long backDelay = 10000;

//================================ for button debounce ============================================//
bool currState_B = HIGH;
bool currState_D = HIGH;
bool currState_U = HIGH;
bool currState_E = HIGH;

bool prevState_B = HIGH;
bool prevState_D = HIGH;
bool prevState_U = HIGH;
bool prevState_E = HIGH;

unsigned long prevTime_B = 0;
unsigned long prevTime_D = 0;
unsigned long prevTime_U = 0;
unsigned long prevTime_E = 0;

unsigned long waitTime = 50;

//====================================  for Alaram  ============================================================//
unsigned long startTime;
unsigned long alaramStopDelay = 180000;
bool check_alaram = false;
bool AlaramTrue = false;
bool T = false;

//======================================  for display blink ====================================================//
unsigned long blinkTime;
long blinkDelay = 500;
bool blinkState = false;

//==============================  bell symbol charecter ======================================//
byte bell[] = {
  B00100,
  B01110,
  B01110,
  B01110,
  B11111,
  B11111,
  B00000,
  B00100
};

//=============================== tick symbole charecter  =========================================================//
byte tick[] = {
  B00000,
  B00000,
  B00001,
  B00011,
  B10110,
  B11100,
  B01000,
  B00000
};

void setup() {

  bt.begin(9600);
  lcd.begin(20, 4);
  dht.begin();
  rtc.halt(false);
  rtc.writeProtect(false);
  lcd.createChar(1, bell);
  lcd.createChar(2, tick);

  for (int i = 0; i < 4; i++) {
    pinMode(led[i], OUTPUT);
    digitalWrite(led[i], LOW);
  }
  // pinMode(led1, OUTPUT); pin(led1, LOW);
  // pinMode(led2, OUTPUT); pin(led2, LOW);
  // pinMode(led3, OUTPUT); pin(led3, LOW);
  // pinMode(led4, OUTPUT); pin(led4, LOW);
  pinMode(fan, OUTPUT);  pin(fan, LOW);
  pinMode(buzz, OUTPUT); pin(buzz, LOW);
  pinMode(xPin, INPUT);
  pinMode(yPin, INPUT);

  v1 = EEPROM.read(L1);
  v2 = EEPROM.read(L2);
  v3 = EEPROM.read(L3);
  v4 = EEPROM.read(L4);
  f1 = EEPROM.read(myfan);

  print(4, 0, "HELLO MANASH");
  print(6, 1, "WELCOME");
  print(17, 3, "MR2");

  for (int i = 0; i < 15; i++) {
    pin(buzz, HIGH);
    delay(100);
    pin(buzz, LOW);
    delay(100);
  }

  lcd.clear();
  displayHomeScreen();
}

void loop() {
  t = rtc.getTime();
  currTime = millis();

  calculateTime();

  if (menuLevel == 0) {
    displayHomeScreen();
    if (T) {
      lcd.setCursor(11, 2);
      lcd.write(1);  //  display bell symbol
    }
  }else if (menuLevel == 5) {
    showAlaram();
  } else if (menuLevel == 7) {
    showTimeSeting();
  } else if (menuLevel == 8) {
    showDateSeting();
  }

  Bluetooth();

  checkButton();

  ledcalculation();

  alaram();



  delay(5);
}
