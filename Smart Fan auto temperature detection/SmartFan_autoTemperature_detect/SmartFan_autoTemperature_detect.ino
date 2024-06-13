
//Date :- 19/8/22
// for DHT11, 
//      VCC: 5V or 3V
//      GND: GND
//      DATA: 2
//      enable pin : 3 (or any PWM pin for analog output)
//      moter pin 1 : 4
//      moter pin 2 : 5


#include <SimpleDHT.h>

int pinDHT11 = 2;
SimpleDHT11 dht11(pinDHT11);

int mp1 = 4;
int mp2 = 5;
int en = 3;            //any PWM pin

int valu ;

void setup() {
  
  Serial.begin(9600);
  pinMode(mp1,OUTPUT);
  pinMode(mp2,OUTPUT);
  pinMode(en,OUTPUT);
  
}


void loop() {
    
  digitalWrite(mp1,HIGH);
  digitalWrite(mp2,LOW);

  analogWrite(en,valu);



  
  Serial.println("=================================");
  Serial.println("Sample DHT11...");
  
  // read without samples.
  byte temperature = 0;
  byte humidity = 0;
  int err = SimpleDHTErrSuccess;
  if ((err = dht11.read(&temperature, &humidity, NULL)) != SimpleDHTErrSuccess) {
    Serial.print("Read DHT11 failed, err="); Serial.print(SimpleDHTErrCode(err));
    Serial.print(","); Serial.println(SimpleDHTErrDuration(err)); delay(1000);
    return;
  }
  
  Serial.print("Sample OK: ");
  Serial.print((int)temperature); Serial.print(" *C, "); 
  Serial.print((int)humidity); Serial.println(" H");
  
  // DHT11 sampling rate is 1HZ.
  delay(1500);
   Serial.println(valu);

  if(temperature <= 20 ){
    valu = 0;
    }
  if(temperature >= 25 && temperature < 30){
    valu = 30;
    }
  if(temperature >= 30 && temperature < 35){
    valu = 60;
    }
  if(temperature >= 35 && temperature < 40){
    valu = 120;
    }
  if(temperature >= 40 && temperature < 45){
    valu = 150;
    }
  if(temperature >= 45 && temperature < 50){
    valu = 180;
    }
  if(temperature >= 50 && temperature < 55){
    valu = 210;
    }
  if(temperature >= 55 && temperature < 60){
    valu = 220;
    }
  if(temperature >= 60 && temperature < 65){
    valu = 240;
    }
  if(temperature >= 65 && temperature < 70){
    valu = 250;
    }
  if(temperature >= 70){
    valu = 255;
    }                



 
}
