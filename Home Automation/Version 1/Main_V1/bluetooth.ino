void Bluetooth() {
  if (bt.available() > 0) {
    char receivedData[22];  // recive date and time value
    int index = 0;

    while (bt.available() > 0) {
      c = bt.read();
      if (c == '\n' || index == sizeof(receivedData) - 1) {
        receivedData[index] = '\0';  // Null-terminate the string
        break;
      }
      receivedData[index++] = c;
    }

    btData(receivedData, index);
  }
}

void btData(char* data, int length) {
  digitalWrite(buzz, HIGH);
  delay(80);
  digitalWrite(buzz, LOW);

  if (length == 21) {  //format: "hh:mm:ss dd:mm:yyyy D"

    if (isdigit(data[0]) && isdigit(data[1]) && data[2] == ':' && 
        isdigit(data[3]) && isdigit(data[4]) && data[5] == ':' &&
        isdigit(data[6]) && isdigit(data[7]) && data[8] == ' ' && 
        isdigit(data[9]) && isdigit(data[10]) && data[11] == ':' && 
        isdigit(data[12]) && isdigit(data[13]) && data[14] == ':' && 
        isdigit(data[15]) && isdigit(data[16]) && isdigit(data[17]) && 
        isdigit(data[18]) && data[19] == ' ' && isdigit(data[20])) {


      int hours = atoi(data);
      int minutes = atoi(data + 3);
      int seconds = atoi(data + 6);
      int day = atoi(data + 9);
      int month = atoi(data + 12);
      int year = atoi(data + 15);
      int dayOfWeek = atoi(data + 20);

      rtc.setTime(hours, minutes, seconds);
      rtc.setDate(day, month, year);
      rtc.setDOW(dayOfWeek);

      lcd.clear();
      lcd.setCursor(0, 0);
      lcd.print("Date and Time formate");
      lcd.setCursor(0, 1);
      lcd.print("received......");
      delay(2000);
      lcd.clear();

      
      lcd.setCursor(0, 0);
      lcd.print("RTC date and time");
      lcd.setCursor(0, 1);
      lcd.print("set successfully!");
      delay(2000);
      lcd.clear();
    }
  } else if (length == 5) {
    if (isdigit(data[0]) && isdigit(data[1]) && data[2] == ':' && 
        isdigit(data[3]) && isdigit(data[4])) {
      int hours = atoi(data);
      int minutes = atoi(data + 3);
      alaram_hours = hours;
      alaram_minutes = minutes;
      // RunAlaram = true;
      T = true;
      check_alaram = true;
    }
  }

  else {
    value = c;
  }
}
