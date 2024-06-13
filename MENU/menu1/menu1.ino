

#include "LiquidCrystal.h"

LiquidCrystal lcd(7, 6, 5, 4, 3, 2);

#define BackBtn    A0
#define downBtn    A1
#define upBtn      A2
#define enterBtn   A3

#define greenLed 9
#define blueLed 10
#define yellowLed 11
#define redLed 12
#define fan 8

#define ONBOARD_LED 13

#define DEFAULT_DELAY 300

char buttonPressed = '0';

byte menuLevel = 0;     // Level 0: no menu display, display anything you like
                        // Level 1: display main menu
                        // Level 2: display sub menu

byte menu = 1;
byte sub = 1;

unsigned long relay_val_1 = 0;
unsigned long relay_val_2 = 0;
unsigned long relay_val_3 = 0;


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

  pinMode(BackBtn, INPUT_PULLUP);
  pinMode(downBtn, INPUT_PULLUP);
  pinMode(upBtn, INPUT_PULLUP);
  pinMode(enterBtn, INPUT_PULLUP);

  pinMode(greenLed,OUTPUT);
  pinMode(blueLed,OUTPUT);
  pinMode(yellowLed,OUTPUT);
  pinMode(redLed,OUTPUT);
  pinMode(fan,OUTPUT);

  showHomeScreen();
  
}

void loop() {

  checkButton();

  // You can do other things here below
}

void checkButton() {
  // Button Debouncing
  bool currRead_B = digitalRead(BackBtn);
  bool currRead_D = digitalRead(downBtn);
  bool currRead_U = digitalRead(upBtn);
  bool currRead_E = digitalRead(enterBtn);
  if (currRead_B != prevState_B) {
    prevTime_B = millis();
  }
  if (currRead_D != prevState_D) {
    prevTime_D = millis();
  }
  if (currRead_U != prevState_U) {
    prevTime_U = millis();
  }
  if (currRead_E != prevState_E) {
    prevTime_E = millis();
  }
  if ((millis() - prevTime_B) > waitTime_B) {
    if (currRead_B != currState_B) {
      currState_B = currRead_B;
      if (currState_B == LOW) {
        buttonPressed = 'B';
      } 
    }
  } else buttonPressed = '0';
  if ((millis() - prevTime_D) > waitTime_D) {
    if (currRead_D != currState_D) {
      currState_D = currRead_D;
      if (currState_D == LOW) {
        buttonPressed = 'D';
      } 
    }
  } else buttonPressed = '0';
  if ((millis() - prevTime_U) > waitTime_U) {
    if (currRead_U != currState_U) {
      currState_U = currRead_U;
      if (currState_U == LOW) {
        buttonPressed = 'U';
      } else {
        //buttonPressed = '0';
      }
    }
  } else buttonPressed = '0';
  if ((millis() - prevTime_E) > waitTime_E) {
    if (currRead_E != currState_E) {
      currState_E = currRead_E;
      if (currState_E == LOW) {
        buttonPressed = 'E';
      } 
    }
  } else buttonPressed = '0';

  prevState_B = currRead_B;
  prevState_D = currRead_D;
  prevState_U = currRead_U;
  prevState_E = currRead_E;

  processButton(buttonPressed);
}

void processButton(char buttonPressed) {
  switch(menuLevel) {
    case 0: // Level 0
      switch ( buttonPressed ) {
        case 'E': // Enter
          menuLevel = 1;
          menu = 1;
          updateMenu();
          delay(DEFAULT_DELAY);
          break;
        case 'U': // Up
          break;
        case 'D': // Down
          break;
        case 'B': // Back
          break;
        default:
          break;
      }
      break;
    case 1: // Level 1, main menu
      switch ( buttonPressed ) {
        case 'E': // Enter
          updateSub();
          menuLevel = 2;  // go to sub menu
          updateSub();
          delay(DEFAULT_DELAY);
          break;
        case 'U': // Up
          menu++;
          updateMenu();
          delay(DEFAULT_DELAY);
          break;
        case 'D': // Down
          menu--;
          updateMenu();
          delay(DEFAULT_DELAY);
          break;
        case 'B': // Back
          menuLevel = 0;  // hide menu, go back to level 0
          showHomeScreen();
          delay(DEFAULT_DELAY);
          break;
        default:
          break;
      } 
      break;
    case 2: // Level 2, sub menu
      switch ( buttonPressed ) {
        case 'E': 
          subSubmenu();
          menuLevel = 3;
          subSubmenu();
          delay(DEFAULT_DELAY);
          break;
        case 'U': // U
          menu++;
          updateSub();
          delay(DEFAULT_DELAY);
          break;
        case 'D': // D
          menu--;
          updateSub();
          delay(DEFAULT_DELAY);
          break;
        case 'B': // Back
          menuLevel = 1;  // hide menu, go back to level 0
          updateMenu();
          delay(DEFAULT_DELAY);
          break;
        default:
          break;
      } 
      break;
    case 3: // Level 3, sub menu of sub menu
      switch ( buttonPressed ) {
        case 'E': 
          updateSub();
          menuLevel = 2;
          updateSub();
          delay(DEFAULT_DELAY);
          break;
        case 'U': // U
          menu++;
          subSubmenu();
          delay(DEFAULT_DELAY);
          break;
        case 'D': // D
          menu--;
          subSubmenu();
          delay(DEFAULT_DELAY);
          break;
        case 'B': // Back
          menuLevel = 2;  // hide menu, go back to level 0
          updateSub();
          delay(DEFAULT_DELAY);
    
          break;
    default:
      break;
  }
}

void showHomeScreen() {
  lcd.clear();
  lcd.println("  Welcom  ");
  lcd.setCursor(0,1);
  lcd.println("Enter to conti..");
}

void updateMenu() {
  switch (menu) {
    case 0:
      menu = 1;
      break;
    case 1:
      lcd.clear();
      lcd.print(">LIGHT'S");
      lcd.setCursor(0, 1);
      lcd.print(" FAN");
      break;
    case 2:
      lcd.clear();
      lcd.print(" LIGHT'S");
      lcd.setCursor(0, 1);
      lcd.print(">FAN");
      break;
    case 3:
      lcd.clear();
      lcd.print(" FAN");
      lcd.setCursor(0, 1);
      lcd.print(">Set Alaram");
      break;
    case 4:
      menu = 3;
      break;
  }
}
void updateSub() {
  switch (menu) {
    case 0:
      break;
    case 1:
      lcd.clear();
      lcd.print(">light 1");
      lcd.setCursor(0, 1);
      lcd.print(" light 2");
      lcd.print(relay_val_1);
      break;
    case 2:
      lcd.clear();
      lcd.print(" light 1");
      lcd.setCursor(0, 1);
      lcd.print(">light 2");
      lcd.print(relay_val_2);
      break;
    case 3:
      lcd.clear();
      lcd.print(">light 3");
      lcd.setCursor(0, 1);
      lcd.print(" light 4");
      lcd.print(relay_val_3);
      break;
    case 4:
      lcd.clear();
      lcd.print(" light 3");
      lcd.setCursor(0, 1);
      lcd.print(">light 4");
      lcd.print(relay_val_3);
      break;
      case 5:
      menu = 4;
      break;
  }
}


void subSubmenu(){

 switch (menu) {
    case 0:
      break;
    case 1:
      lcd.clear();
      lcd.print(">ON");
      lcd.setCursor(0, 1);
      lcd.print(" OFF");
      lcd.print(relay_val_1);
      break;
    case 2:
      lcd.clear();
      lcd.print(" ON");
      lcd.setCursor(0, 1);
      lcd.print(">OFF");
      lcd.print(relay_val_2);
      break;
    case 3:
      menu = 2;
      break;
    
  }

}