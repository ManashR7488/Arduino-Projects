void exicuteLight(){
  if( a == 1 && b == 1){
    digitalWrite(greenLed,HIGH);
  }
  if(a == 1 && b == 2){
    digitalWrite(greenLed,LOW);
  }
  if( a == 2 && b == 1){
    digitalWrite(blueLed,HIGH);
  }
  if(a == 2 && b == 2){
    digitalWrite(blueLed,LOW);
  }
  if( a == 3 && b == 1){
    digitalWrite(yellowLed,HIGH);
  }
  if(a == 3 && b == 2){
    digitalWrite(yellowLed,LOW);
  }
  if( a == 4 && b == 1){
    digitalWrite(redLed,HIGH);
  }
  if(a == 4 && b == 2){
    digitalWrite(redLed,LOW);
  }
  
}