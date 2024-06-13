/*
 pleas read all the below commented lins before moveon atleastread the eeprom address
 this sketch is made by Manash Ranjan Mahanand.(MR2)
 Dt:- 05.12.2023.
  
  THE CIRCUIT 👇👇👇
 * LCD RS pin to analog pin A0
 * LCD Enable pin to analog pin A1              // if you have i2c display sheild then you can use that 
 * LCD D4 pin to analog pin A2                      it will reduce the pin  so you can get more pin's to connect other things.   
 * LCD D5 pin to analog pin A3
 * LCD D6 pin to analog pin A4                  //i am using 20*4 lcd you can use 20*2 lcd also ,a little code should be change .
 * LCD D7 pin to analog pin A5

 * JOY_STIC  X_pin A6                            // you can also use buttons insted of using joyStick
             Y_pin A7                              the code for button is commented in the check_button function 

 *HC-05  RX pin to digital pin 7
         TX pin to digital pin 6

 *RTC    CE pin    -> Arduino Digital 2
         I/O pin   -> Arduino Digital 3         // you can use any rtc module.try to use the module where the crystal is inside the 
         SCLK pin  -> Arduino Digital 4            ic to reduce errors.

 *DHT11  data pin to digital pin 5 

 *LIGHT's to digital pin 8,9,10,11
 *FAN to digital pin 12                       // you can also use a ac dimmer to control the speed of the fan
                                                 to do that you have to write the code for that.
                                                in this code i am not controlling the speed. i am making the dimmer circuit.
  *EEPROM
      add 0 - L1
      add 1 - L2
      add 2 - L3
      add 3 - L4
      add 4 - Fan
*/



#include <SoftwareSerial.h>
#include <LiquidCrystal.h>
#include <EEPROM.h>
#include "DS1302.h"
#include <DHT.h>

// #define triacPulse 3
// #define ZVC 2
#define DHTPIN 5  // Connect DHT11 data pin to digital pin 2
#define DHTTYPE DHT11
#define x_pin A6  //  define joystick pin
#define y_pin A7
#define d 300  // define a delay

DHT dht(DHTPIN, DHTTYPE);

LiquidCrystal lcd(A0, A1, A2, A3, A4, A5);
DS1302 rtc(2, 3, 4);
Time t;
SoftwareSerial bt(6, 7);  //rx and tx pin.

char value = 0;
char c;                                                       //variables
int alaram_hours, alaram_minutes, alaram_sec, day, mon, yer;  // variables for time date setings
int a;
int b;
char buttonPressed = '0';
byte menuLevel = 0;  // Level 0: no menu display, display anything you like
                     // Level 1: display main menu
                     // Level 2: display sub menu Light
                     // Level 3: display sub sub menu light
                     // Level 4: display sub menu fan
byte menu = 1;
//byte sub = 1;

// {       // eeprom address

int L1 = 0;
int L2 = 1;
int L3 = 2;
int L4 = 3;
int Myfan = 4;

int vL1 = 5;
int vL2 = 6;
int vL3 = 7;
int vL4 = 8;
int vMyfan = 9;

// }

int led1 = 9;
int led2 = 10;
int led3 = 11;
int led4 = 12;
int fan1 = 8;
int v1;  //Led fan and buzzz pin
int v2;
int v3;
int v4;
int f1;
int buzz = 13;

bool currState_B = HIGH;
bool currState_D = HIGH;
bool currState_U = HIGH;  //variables for menu
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

unsigned long currTime;
unsigned long prevTime;
unsigned long delayTime = 10000;
//bool backTrue = false;

unsigned long startTime;
unsigned long blinkTime;
unsigned long blinkDelay = 500;
bool AlaramTrue = false;
bool blinkState = false;
unsigned long alaramStopDelay = 180000;
bool T = false;
bool check_alaram = false;

byte bell[] = {
  B00100,
  B01110,
  B01110,  // byte for bell symbol
  B01110,
  B11111,
  B11111,
  B00000,
  B00100
};

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

  //pin setup and initialization
  // Serial.begin(9600);
  bt.begin(9600);
  lcd.begin(20, 4);
  dht.begin();
  lcd.createChar(1, bell);
  lcd.createChar(2, tick);
  rtc.halt(false);
  rtc.writeProtect(false);

  pinMode(led1, OUTPUT);
  digitalWrite(led1, LOW);
  pinMode(led2, OUTPUT);
  digitalWrite(led2, LOW);
  pinMode(led3, OUTPUT);
  digitalWrite(led3, LOW);
  pinMode(led4, OUTPUT);
  digitalWrite(led4, LOW);
  pinMode(fan1, OUTPUT);
  digitalWrite(fan1, LOW);
  pinMode(buzz, OUTPUT);
  pinMode(x_pin, INPUT);
  pinMode(y_pin, INPUT);
  // pinMode(ZVC, INPUT_PULLUP);
  // pinMode(triacPulse, OUTPUT);


  // lcd
  lcd.setCursor(4, 0);
  lcd.print("HELLO MANASH");
  lcd.setCursor(6, 1);
  lcd.print("WELCOME");
  lcd.setCursor(17, 3);
  lcd.print("MR2");


  for (int i = 0; i < 15; i++) {
    digitalWrite(buzz, HIGH);
    delay(100);
    digitalWrite(buzz, LOW);
    delay(100);
  }

  v1 = EEPROM.read(L1);  //Led fan and buzzz pin
  v2 = EEPROM.read(L2);
  v3 = EEPROM.read(L3);
  v4 = EEPROM.read(L4);
  f1 = EEPROM.read(Myfan);

  lcd.clear();
  displayHomeScreen();
}

void loop() {

  t = rtc.getTime();
  currTime = millis();

  checkButton();

  Bluetooth();

  ledcalculation();

  alaram();

  if (menuLevel == 0) {
    displayHomeScreen();
    if (T) {
      lcd.setCursor(11, 2);
      lcd.write(1);  //  display bell symbol
    }
  } else if (menuLevel == 5) {
    showAlaram();
  } else if (menuLevel == 7) {
    showTimeSeting();
  } else if (menuLevel == 8) {
    showDateSeting();
  }

  delay(5);
}
