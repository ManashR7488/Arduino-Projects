
#include <LiquidCrystal.h>

// initialize the library with the numbers of the interface pins
LiquidCrystal lcd(12, 11, 5, 4, 3, 2);
int lb = A2;
int rb = A3;
int sm = A4;
int d1 = 0;
void setup() {
    Serial.begin(9600);
  // set up the LCD's number of columns and rows:
  lcd.begin(16, 2);
   pinMode(lb,INPUT);
   pinMode(rb,INPUT);
   pinMode(sm,INPUT);
   
  // Print a message to the LCD.
  lcd.print("hello, world!");
  delay(1000);
}

void loop() {
 
  int LB = analogRead(lb);
  int RB = analogRead(rb);
  lcd.setCursor(0,0);
  lcd.print("Press a button");
   lcd.setCursor(0,1);
    lcd.print("<-[B],[B]->,(*)S");
    
   if(LB > 800){
    lcd.clear();
     for (int positionCounter = 0; positionCounter < 1; positionCounter++) 
 {
    lcd.setCursor(16,0);
        lcd.print("<:::::");
    lcd.scrollDisplayRight();
    
    delay(1);
  } 
        for (int positionCounter = 0; positionCounter < 23; positionCounter++) 
 {
    // scroll one position left:
    lcd.scrollDisplayLeft();
    // wait a bit:
    delay(d1);
    int val1 = analogRead(sm);
  int val = val1/4;
   Serial.print(val);
  Serial.print("  ");
    
  if(val >= 0 && val <= 20){
      d1 = 1100;
    }
  if(val >= 21 && val <= 40){
     d1 = 1000; 
    }
  if(val >= 41 && val <= 60){
      d1 = 900;
    }
  if(val >= 61 && val <= 80){
      d1 = 800;
    }
  if(val >= 81 && val <= 100){
      d1 = 700;
    }
  if(val >= 101 && val <= 130){
      d1 = 600;
    }
  if(val >= 131 && val <= 160){
      d1 = 500;
    }
  if(val >= 161 && val <= 200){
      d1 = 400;
    }
  if(val >= 201 && val <= 220){
      d1 = 300;
    }
   if(val >= 221 && val <= 240){
      d1 = 200;
    } 
  if(val >= 241 && val <= 255){
      d1 = 100;
    }
  }
        lcd.clear();
}
 
   if(RB > 500)
 {
     lcd.clear();
        for (int positionCounter = 0; positionCounter < 7; positionCounter++)
 {
    // scroll one position left:
  lcd.setCursor(0,0);
   lcd.print(":::::>");
    lcd.scrollDisplayLeft();
    // wait a bit:
    delay(1);
  }  
   for (int positionCounter = 0; positionCounter < 23; positionCounter++) 
  {
    // scroll one position left:
    lcd.scrollDisplayRight();
    // wait a bit:
    delay(d1);
    int val1 = analogRead(sm);
  int val = val1/4;
  Serial.print(val);
  Serial.print("  ");
   
  if(val >= 0 && val <= 20){
      d1 = 1100;
    }
  if(val >= 21 && val <= 40){
     d1 = 1000; 
    }
  if(val >= 41 && val <= 60){
      d1 = 900;
    }
  if(val >= 61 && val <= 80){
      d1 = 800;
    }
  if(val >= 81 && val <= 100){
      d1 = 700;
    }
  if(val >= 101 && val <= 130){
      d1 = 600;
    }
  if(val >= 131 && val <= 160){
      d1 = 500;
    }
  if(val >= 161 && val <= 200){
      d1 = 400;
    }
  if(val >= 201 && val <= 220){
      d1 = 300;
    }
   if(val >= 221 && val <= 240){
      d1 = 200;
    } 
  if(val >= 241 && val <= 255){
      d1 = 100;
   }        
  }  
        lcd.clear(); 
 }
}

