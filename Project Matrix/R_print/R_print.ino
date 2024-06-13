//created by MR??
//8*8 matrix print R

int gnd[]={6, 7, 8, 9, 10, 11, 12, 13};
int R[8]={B00000001, B01100011, B11110110, B10011100, B10011000, B11111111, B11111111,B00000000};

byte dataPinRow=2;
int clockPinRow=4;
int latchPinRow=3;
int timer=1;

void setup() {
  // put your setup code here, to run once:
pinMode(6, OUTPUT);
pinMode(7, OUTPUT);
pinMode(8, OUTPUT);
pinMode(9, OUTPUT);
pinMode(10, OUTPUT);
pinMode(11, OUTPUT);
pinMode(12, OUTPUT);
pinMode(13, OUTPUT);

//DDRD=B11111111;
pinMode(dataPinRow, OUTPUT);
pinMode(clockPinRow, OUTPUT);
pinMode(latchPinRow, OUTPUT);

digitalWrite(6, HIGH);
digitalWrite(7, HIGH);
digitalWrite(8, HIGH);
digitalWrite(9, HIGH);
digitalWrite(10, HIGH);
digitalWrite(11, HIGH);
digitalWrite(12, HIGH);
digitalWrite(13, HIGH);
}

void loop() {
  // put your main code here, to run repeatedly:

  for (int j=0; j<=7; j++)
  {
    byte font = A[j];
    
   // int thisRow = j;
    digitalWrite(gnd[j], LOW);
    {
      digitalWrite(latchPinRow, LOW);
           
            shiftOut (dataPinRow, clockPinRow, LSBFIRST, font);;  // turn the pin on:
            digitalWrite(latchPinRow, HIGH);
            
    }
    delay(timer);
    digitalWrite(gnd[j], HIGH);
 }
}
