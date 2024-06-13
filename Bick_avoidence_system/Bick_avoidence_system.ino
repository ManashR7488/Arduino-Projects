#include <LiquidCrystal.h>
 
 LiquidCrystal lcd(A0,A1,A2,A3,A4,A5);// RS,E,D4,D5,D6,D7 // defines pins numbers const 
const int trigPin = 9; 
const int echoPin = 10; // defines variables 

long duration; 
int distance=0;
int distance1=0; 
int distance2=0; 

double Speed=0;  

int led = 2;
int buzzer = 3;

void setup() { 
 lcd.begin(16, 2);// LCD 16X2 
  pinMode(trigPin, OUTPUT); // Sets the trigPin as an Output 
    pinMode(echoPin, INPUT); // Sets the echoPin as an Input 
    pinMode(led, OUTPUT);
    pinMode(buzzer,OUTPUT); 
    Serial.begin(9600); // Starts the serial communication 
    } 
void loop() { //calculating Speed 
    distance1 = ultrasonicRead(); //calls ultrasoninicRead() function below 
    delay(160);//giving a time gap of 1 sec 
    distance2 = ultrasonicRead(); //calls ultrasoninicRead() function below //formula change in distance divided by change in time 
    Speed = (distance2 - distance1)/1.0; //as the time gap is 1 sec we divide it by 1. //Displaying Speed 
    Serial.print("Speed in cm/s :"); 
    Serial.println(); 
    lcd.setCursor(0,1); 
    lcd.print("Speed cm/s "); 
    lcd.print(Speed); // LED indicator
    if(distance <= 10){
        digitalWrite(led,HIGH);
        digitalWrite(buzzer,HIGH);
    } 
    else{
       digitalWrite(led,LOW);
        digitalWrite(buzzer,LOW);
     
    }
   } 

float ultrasonicRead () { // Clears the trigPin 
    digitalWrite(trigPin, LOW); 
    delayMicroseconds(2); // Sets the trigPin on HIGH state for 10 micro seconds 
    digitalWrite(trigPin, HIGH); 
    delayMicroseconds(10); 
    digitalWrite(trigPin, LOW); // Reads the echoPin, returns the sound wave travel time in microseconds 
    duration = pulseIn(echoPin, HIGH); //calculating distance 
    distance= duration*0.034/2; // Prints the distance on the Serial Monitor 
    Serial.print("Distance in cm : "); 
    Serial.println(distance); 
    lcd.setCursor(0,0); 
    lcd.print("Dist. in cm "); 
    lcd.print(distance); 
    lcd.print(" "); 
    return distance; 
    }