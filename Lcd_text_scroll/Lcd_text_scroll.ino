#include <LiquidCrystal.h>

// initialize the library with the numbers of the interface pins
LiquidCrystal lcd(12, 11, 5, 4, 3, 2);

void setup() {
  // set up the LCD's number of columns and rows:
  lcd.begin(16, 2);
  // Print a message to the LCD.
  lcd.print("hello, world!");
  delay(1000);
}

void loop() {
  
    lcd.clear();
    for (int positionCounter = 0; positionCounter < 32; positionCounter++) {
    // scroll one position left:
    lcd.scrollDisplayLeft();
        lcd.setCursor(16,0);
        lcd.print("HELLO, WORLD!");
    // wait a bit:
    delay(10000);
  }
lcd.clear();
    lcd.clear();
   for (int positionCounter = 0; positionCounter < 16; positionCounter++) {
    // scroll one position left:
    lcd.scrollDisplayLeft();
        lcd.setCursor(0,1);
        lcd.print("HELLO, WORLD!");
    // wait a bit:
    delay(1);
  }

  
for (int positionCounter = 0; positionCounter < 32; positionCounter++) {
    // scroll one position left:
    lcd.scrollDisplayRight();
       
      
    // wait a bit:
    delay(10000);
  }
  delay(100);

}

