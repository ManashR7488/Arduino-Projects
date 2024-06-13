
#include "LiquidCrystal.h"

LiquidCrystal lcd(2, 3, 4, 5, 6, 7);

#define x_pin    A0
#define y_pin      A1

#define greenLed 9
#define blueLed 10
#define yellowLed 11
#define redLed 12
#define fan 13

#define d 300

char buttonPressed = '0';
byte menuLevel = 0;     // Level 0: no menu display, display anything you like
                        // Level 1: display main menu
                        // Level 2: display sub menu Light
                        // Level 3: display sub sub menu light
                        // Level 4: display sub menu fan
byte menu = 1;
byte sub = 1;

int a;
int b;
//int c;

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

unsigned long waitTime_B = 50;
unsigned long waitTime_D = 50;
unsigned long waitTime_U = 50;
unsigned long waitTime_E = 50;

void setup() {
  lcd.begin(16,2);

  Serial.begin(9600);

  pinMode(x_pin, INPUT);
  pinMode(y_pin, INPUT);

  pinMode(greenLed,OUTPUT);
  pinMode(blueLed,OUTPUT);
  pinMode(yellowLed,OUTPUT);
  pinMode(redLed,OUTPUT);
  pinMode(fan,OUTPUT);

  Serial.println("Manash");
  showHomeScreen();

}

void loop() {
  // put your main code here, to run repeatedly:
 checkButton();
 
}
