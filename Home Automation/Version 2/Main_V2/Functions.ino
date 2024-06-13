void pin(int a, bool b) {
  digitalWrite(a, b);
}

template<typename dataType>
void print(int a, int b, dataType c) {
  lcd.setCursor(a, b);
  lcd.print(c);
}

void ring(int Pin,int durationINmillisec){
  pin(Pin, HIGH);
  delay(durationINmillisec);
  pin(Pin, LOW);
}

void calculateTime() {
  hh = t.hour;
  prepand = (hh >= 12) ? "PM" : "AM";
  hh = (hh >= 12) ? (hh - 12) : hh;

  if (hh == 0 && prepand == "PM") {
    if (t.min == 0) {
      hh = 12;
      prepand = "NOON";
    } else {
      hh = 12;
      prepand = "PM";
    }
  }
  if (hh == 0 && prepand == "AM") {
    if (t.min == 0) {
      hh = 12;
      prepand = "MidNight";
    } else {
      hh = 12;
      prepand = "AM";
    }
  }
}