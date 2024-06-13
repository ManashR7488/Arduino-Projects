#define triacPulse 10
#define SW 7

int x=0;
void setup(){
   pinMode(2, INPUT);
   digitalWrite(2, INPUT_PULLUP); // pull up
   pinMode(triacPulse, OUTPUT);
   pinMode(SW, INPUT);
   digitalWrite(SW, INPUT_PULLUP);
    }

void loop() {
 
  if (!digitalRead(SW)){ // When the switch is closed
    x=analogRead(A0);
    attachInterrupt(0, acon, FALLING); // attach Interrupt at PIN2
    }  
  else if (digitalRead(SW)){ 
       detachInterrupt(0); // Detach Interrupt
     } 
  } 

void acon()  
   {
    delayMicroseconds((analogRead(A0) * 7) + 200); // read AD0 
    digitalWrite(triacPulse, HIGH);
    delayMicroseconds(50);  //delay 50 uSec on output pulse to turn on triac  
    digitalWrite(triacPulse, LOW);
   }