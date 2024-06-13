#include<LiquidCrystal.h>


LiquidCrystal lcd(A0,A1,A2,A3,A4,A5);
   int trigPin =9;
  int echoPin =10;
   long duration;
  String distanceM;
   int distance;
  int led  = 2;
  int buzzer = 3; 

 void setup(){
    lcd.begin(16,2);
    pinMode(trigPin,OUTPUT);
    pinMode(echoPin,INPUT);
    pinMode(led,OUTPUT);
     pinMode(buzzer,OUTPUT);
}
    
 void loop(){
    digitalWrite(trigPin,LOW);
    delayMicroseconds(2);
    
    digitalWrite(trigPin,HIGH);
    delayMicroseconds(10);
    digitalWrite(trigPin,LOW);
    
    duration = pulseIn(echoPin,HIGH);
    
    distance = duration*0.034/2;
    delay(100);
distanceM = distance/100; 
    delay(100); 
    Serial.print(distance);
    lcd.setCursor(0,0);
    lcd.print("Dist(cm):");
  lcd.setCursor(0,1);  
 lcd.print("Dist(m):");
    lcd.setCursor(9,0);  
    lcd.print(distance);
    lcd.print("    ");
   lcd.setCursor(8,1);
   lcd.print(distanceM);
    lcd.print("    ");  
 
    
    if(distance <= 200){
        digitalWrite(led,HIGH);
        digitalWrite(buzzer,HIGH);
    } 
    else{
        digitalWrite(led,LOW);
        digitalWrite(buzzer,LOW);
    }
       
    
}
