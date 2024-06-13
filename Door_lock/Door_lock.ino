#include <Keypad.h>

#include <LiquidCrystal.h>

 

  const byte ROWS = 4;  //four rows

const byte COLS = 4;  //three columns

char keys[ROWS][COLS] = {

  { '1', '2', '3', 'A' },

  { '4', '5', '6', 'B' },

  { '7', '8', '9', 'C' },

  { '*', '0', '#', 'D' }

};

byte rowPins[ROWS] = { 3, 4, 5, 6 };  //connect to the row pinouts of the keypad

byte colPins[COLS] = { 7, 8, 9, 10 };  //connect to the column pinouts of the keypad

 

  Keypad keypad = Keypad(makeKeymap(keys), rowPins, colPins, ROWS, COLS);

 

// 16x2 LCD

#define rs A0

#define en A1

#define d4 A2

#define d5 A3

#define d6 A4

#define d7 A5

  // initialize the library with the numbers of the interface pins

  LiquidCrystal lcd(rs, en, d4, d5, d6, d7);

  String password = "1234";

String mypassword;
String A = "A";
String B = "B";
String C = "C";
String star = "*";
String has = "#";
 

  int redled = 12;

int greenled = 13;

 int buzzer = 11;

int counter = 0;

int attempts = 0;

int max_attempts = 3;

 

  void
  setup() {

    Serial.begin(9600);

      // set up the LCD's number of columns and rows: 

  lcd.begin(16, 2);

    

  pinMode(redled, OUTPUT);

    pinMode(greenled, OUTPUT);

    pinMode(buzzer, OUTPUT);

    digitalWrite(redled, LOW);

    digitalWrite(greenled, LOW);

    

  Serial.println("enter password");

      lcd.print("Enter Password:");
}

  

  void
  loop()

{

    

    keypadfunction();
}

 

  void
  keypadfunction()

{

  char key = keypad.getKey();

    

  if (key) {

        Serial.println(key);

        counter = counter + 1;

        lcd.setCursor(counter, 1);

        lcd.print("*");

      
  }

    if (key == '1')

  {

      digitalWrite(buzzer, HIGH);
    delay(100);
    digitalWrite(buzzer, LOW);

        mypassword = mypassword + 1;
       

  
  }

    

    if (key == '2')

  {

      digitalWrite(buzzer, HIGH);
    delay(100);
    digitalWrite(buzzer, LOW);
        mypassword = mypassword + 2;
      

  
  }

    

  if (key == '3')

  {
    digitalWrite(buzzer, HIGH);
    delay(100);
    digitalWrite(buzzer, LOW);
        mypassword = mypassword + 3;

      
  }

    

   if (key == '4')

  {

       digitalWrite(buzzer, HIGH);
    delay(100);
    digitalWrite(buzzer, LOW);

        mypassword = mypassword + 4;
      

  
  }

    

  if (key == '5')

  {
    digitalWrite(buzzer, HIGH);
    delay(100);
    digitalWrite(buzzer, LOW);
      

    mypassword = mypassword + 5;

      
  }

    

   if (key == '6')

  {

       digitalWrite(buzzer, HIGH);
    delay(100);
    digitalWrite(buzzer, LOW);

        mypassword = mypassword + 6;

      
  }

    

   if (key == '7')

  {

      digitalWrite(buzzer, HIGH);
    delay(100);
    digitalWrite(buzzer, LOW);
        mypassword = mypassword + 7;

      
  }

   

   if (key == '8')

  {

      digitalWrite(buzzer, HIGH);
    delay(100);
    digitalWrite(buzzer, LOW);
        mypassword = mypassword + 8;

      
  }

    

  if (key == '9')

  {

      digitalWrite(buzzer, HIGH);
    delay(100);
    digitalWrite(buzzer, LOW);
        mypassword = mypassword + 9;

      
  }

               

    if (key == '0')

  {

      digitalWrite(buzzer, HIGH);
    delay(100);
    digitalWrite(buzzer, LOW);
        mypassword = mypassword + 0;

      
  }

     if (key == 'A')

  {

      digitalWrite(buzzer, HIGH);
    delay(100);
    digitalWrite(buzzer, LOW);
       
    
  
  }

  if (key == 'B')

      {

        digitalWrite(buzzer, HIGH);
      delay(100);
      digitalWrite(buzzer, LOW);
         

  
    }

    if (key == 'C')

  {

      digitalWrite(buzzer, HIGH);
    delay(100);
    digitalWrite(buzzer, LOW);
      

  
  }

  if (key == '#')

      {

        digitalWrite(buzzer, HIGH);
      delay(100);
      digitalWrite(buzzer, LOW);
        

  
    }
  if (key == '*')

      {

        digitalWrite(buzzer, HIGH);
      delay(100);
      digitalWrite(buzzer, LOW);
       

  
    }

          if (key == 'D')

  {

        Serial.println(mypassword);

        

      if (password == mypassword)

    {

      lcd.clear();

      lcd.println("Welcome To");

      lcd.setCursor(0, 1);

      lcd.println("ElectroniClinic");

      digitalWrite(greenled, HIGH);

      delay(5000);

      digitalWrite(greenled, LOW);

      mypassword = "";

      counter = 0;

      attempts = 0;

      lcd.clear();

      lcd.setCursor(0, 0);

      lcd.println("Enter password");
    }

    else

    {

      Serial.println("wrong");

      digitalWrite(greenled, LOW);

      attempts = attempts + 1;
      if (attempts == 1) {
        for (int i = 0; i <= 1; i++) {
          digitalWrite(buzzer, HIGH);
          digitalWrite(redled, HIGH);
          delay(100);
          digitalWrite(buzzer, LOW);
          digitalWrite(redled, LOW);
          delay(100);
        }
      }
      if (attempts == 2) {
        for (int i = 0; i <= 2; i++) {
          digitalWrite(buzzer, HIGH);
          digitalWrite(redled, HIGH);
          delay(100);
          digitalWrite(buzzer, LOW);
          digitalWrite(redled, LOW);
          delay(100);
        }
      }

      if (attempts >= max_attempts)

      {

          lcd.clear();

          lcd.setCursor(0, 0);

          lcd.print("Locked Out");
        for (int i = 0; i <= 3; i++) {
          digitalWrite(buzzer, HIGH);
          digitalWrite(redled, HIGH);
          delay(100);
          digitalWrite(buzzer, LOW);
          digitalWrite(redled, LOW);
          delay(100);
        }
        for (int t = 60; t >= 0; t--) {
          digitalWrite(redled, HIGH);
          delay(500);
          digitalWrite(redled, LOW);
          delay(500);
          lcd.setCursor(14, 0);
          lcd.print(t);
        }

        attempts = 0;

         
      }

      mypassword = "";

      counter = 0;

      lcd.clear();

      lcd.setCursor(0, 0);

      lcd.print("Wrong Password");

      delay(1000);
    }

    lcd.setCursor(0, 1);

    lcd.print("max attempts 3");

    delay(1000);

    lcd.clear();

    lcd.println("Enter password");

    lcd.setCursor(0, 1);
  }
}
}
