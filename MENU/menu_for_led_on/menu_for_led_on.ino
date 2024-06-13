#include<LiquidCrystal.h>

LiquidCrystal lcd(7,6,5,4,3,2);
int uB = 8;
int dB = 9;
int sB = 10;
int menu = 1;
int led = 11;
int ledControl = 1;


void setup(){
    lcd.begin(16,2);
    pinMode(uB,INPUT_PULLUP);
    pinMode(dB,INPUT_PULLUP);
     pinMode(sB,INPUT_PULLUP);
    pinMode(led,OUTPUT);
      pageMenu();
  
    }
void loop(){
       
    if(!digitalRead(dB)){
        menu++;
     
        delay(100);
     while(!digitalRead(dB)); 
       
    }
    if(!digitalRead(uB)){
        menu--;
      
       delay(100);
     while(!digitalRead(uB)); 
}
    if(!digitalRead(sB)){
        action1();
     
        delay(100);
       while(!digitalRead(sB)); 
      
    
}
  
     if(!digitalRead(dB)){
        ledControl++;
        ledGreen();
        delay(100);
     while(!digitalRead(dB)); 
       
    }
    if(!digitalRead(uB)){
        ledControl--;
       ledGreen();
       delay(100);
     while(!digitalRead(uB)); 
}
    if(!digitalRead(sB)){
        delay(100);
       while(!digitalRead(sB)); 
 }
        
     
  
    }
void pageMenu(){
    switch(menu){
        case 0:
        menu = 1;
        break;
    case 1:
    lcd.clear();
    lcd.print(">led green");
    lcd.setCursor(0,1);
    lcd.print(" led blue");
    break;
    case 2:
    lcd.clear();
    lcd.print(" led green");
    lcd.setCursor(0,1);
    lcd.print(">led blue");
    break;
      case 3:
        menu = 2;
        break;
    } 
}
void action1(){
    switch(menu){
        case 1:
         ledGreen();
        delay(2000);
        break;
        case 2 :
        ledBlue();
        delay(2000);
        break;
        
    }

}

void ledGreen(){
    switch(ledControl){
        case 0:
        ledControl = 1;
        break;
        case 1:
         lcd.clear();
        lcd.print(">led on");
         lcd.setCursor(0,1);
        lcd.print(" led off");
        break;
        case 2:
         lcd.clear();
        lcd.print(" led on");
         lcd.setCursor(0,1);
        lcd.print(">led off");
        break;
        case 3:
          ledControl = 2;
        break;
    }
}
void ledBlue(){
       lcd.clear();
    lcd.print("Manash");
    delay(1000);
}