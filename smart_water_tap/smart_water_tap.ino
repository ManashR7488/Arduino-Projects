
  const int trigPin = 7;
  const int echoPin = 6;
  int moterpin1 = 3;
  int moterpin2 = A5; 
  long duration;
  int distanceCm,distanceInch;
  
  void setup (){
    
  
    pinMode(trigPin,OUTPUT);
    pinMode(echoPin,INPUT);
    pinMode(11,OUTPUT);
    pinMode(moterpin1,OUTPUT);
    pinMode(moterpin2,OUTPUT);
   

   
    Serial.begin(9600);

}


  void loop(){
    digitalWrite(trigPin,LOW);
    delayMicroseconds(2);
    digitalWrite(trigPin,HIGH);
    delayMicroseconds(10);
    digitalWrite(trigPin,LOW);
    
    duration = pulseIn(echoPin,HIGH);
    distanceCm =duration*0.034/2;
    delay(10);
    delayMicroseconds(2);
   
    
      if(( distanceCm<=15))
      {
         Serial.println(distanceCm);
        delay(100);
        digitalWrite(11,HIGH);
         
        digitalWrite(moterpin2,1023); 
        delay(2000);     
      }    
    else if (distanceCm>15)
        {
        digitalWrite(11,LOW);
        digitalWrite(moterpin2,LOW); 
        }
    
    
 }
