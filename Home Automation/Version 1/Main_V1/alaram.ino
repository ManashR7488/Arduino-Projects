void alaram(){
 if(check_alaram){
   if(t.hour == alaram_hours && t.min == alaram_minutes && t.sec == 00){
     startTime = currTime;
     AlaramTrue = true;
     check_alaram = false;
     T = false;
    }
 } 

  if(AlaramTrue == true){
    if(currTime - startTime >= alaramStopDelay){                      // 3 minute.
      AlaramTrue = false;
      lcd.clear();
      alaram_hours = 0;
      alaram_minutes = 0;
      digitalWrite(buzz,0);
    }
    if(currTime - blinkTime >= blinkDelay){
      blinkTime = currTime;
      blinkState = !blinkState;

      if(blinkState){
       if(menuLevel == 0){
        lcd.setCursor(11,2);
        lcd.write(1);  
       }
       digitalWrite(buzz,1);
      }
      else{
       if(menuLevel == 0){
             lcd.setCursor(11,2);
             lcd.print(" ");
        }     
        digitalWrite(buzz,0);
      
      }
    }
  }
}
