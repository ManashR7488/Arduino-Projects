void displayHomeScreen() {

  if (hh < 10) {
    print(0, 0, "0");
    print(1, 0, hh);
  } else {
    print(0, 0, hh);
  }
  print(2, 0, ":");
  if (t.min < 10) {
    print(3, 0, "0");
    lcd.setCursor(4, 0);
    lcd.print(t.min);
  } else {
    lcd.setCursor(3, 0);
    lcd.print(t.min);
  }
  print(5, 0, ":");
  if (t.sec < 10) {
    print(6, 0, "0");
    lcd.setCursor(7, 0);
    lcd.print(t.sec);
  } else {
    lcd.setCursor(6, 0);
    lcd.print(t.sec);
  }
  if (prepand == "AM" || prepand == "PM") {
    print(9, 0, prepand);
  } else {
    if (prepand == "NOON") {
      lcd.clear();
      print(0, 0, "____________________");
      print(0, 1, "|"); 
      print(2, 1, "IT'S 12:00 NOON");
      print(19, 1, "|");
      print(0, 2, "GOOD AFTER NOON SIR.");
      print(0, 3, "____________________");
      for (int i = 0; i < 300; i++) {   /// one minute
        pin(buzz, HIGH);
        delay(100);
        pin(buzz, LOW);
        delay(100);
      }
      lcd.clear();
    } else if (prepand == "MidNight" && t.sec == 0) {
      lcd.clear();
      print(0, 0, "--------------------");
      print(0, 1, "|");
      print(5, 1, "IT'S 00:00 ");
      print(19, 1, "|");
      print(0, 2, "|");
      print(2, 2, "GOOD MORNING SIR.");
      print(19, 2, "|");
      print(0, 3, "____________________");
      for (int i = 0; i < 15; i++) {
        pin(buzz, HIGH);
        delay(100);
        pin(buzz, LOW);
        delay(100);
      }
      lcd.clear();
    }
  }
  lcd.setCursor(12, 0);
  lcd.print(rtc.getDOWStr(FORMAT_SHORT));
  lcd.setCursor(0, 1);
  lcd.print(rtc.getDateStr());
  print(0, 2, "Temp:");
  lcd.setCursor(5, 2);
  lcd.print(dht.readTemperature());
  print(0, 3, "Humd:");
  lcd.setCursor(5, 3);
  lcd.print(dht.readHumidity());


  if (EEPROM.read(L1) == 1) {
    print(16, 0, "L1:");
    lcd.setCursor(19, 0);
    lcd.write(2);
  } else {
    print(16, 0, "L1:-");
  }
  if (EEPROM.read(L2) == 1) {
    print(16, 1, "L2:");
    lcd.setCursor(19, 1);
    lcd.write(2);
  } else {
    print(16, 1, "L2:-");
  }
  if (EEPROM.read(L3) == 1) {
    print(16, 2, "L3:");
    lcd.setCursor(19, 2);
    lcd.write(2);
  } else {
    print(16, 2, "L3:-");
  }
  if (EEPROM.read(L4) == 1) {
    print(16, 3, "L4:");
    lcd.setCursor(19, 3);
    lcd.write(2);
  } else {
    print(16, 3, "L4:-");
  }
}

void updateMenu() {
  switch (menu) {
    case 0:
      menu = 1;
      break;
    case 1:
      lcd.clear();
      print(0, 0, ">LIGHT'S");
      print(0, 1, " FAN");
      print(0, 2, " SET ALARAM");
      print(0, 3, " SETING");

      if (EEPROM.read(L1) == 1 || EEPROM.read(L2) == 1 || EEPROM.read(L3) == 1 || EEPROM.read(L4) == 1) {
        lcd.setCursor(14, 0);
        lcd.write(2);
      } else {
        lcd.setCursor(14, 0);
        lcd.print(" ");
      }
      if (EEPROM.read(myfan) == 1) {
        lcd.setCursor(14, 1);
        lcd.write(2);
      } else {
        lcd.setCursor(14, 1);
        lcd.print(" ");
      }
      break;
    case 2:
      lcd.clear();
      print(0, 0, " LIGHT'S");
      print(0, 1, ">FAN");
      print(0, 2, " SET ALARAM");
      print(0, 3, " SETING");

      if (EEPROM.read(L1) == 1 || EEPROM.read(L2) == 1 || EEPROM.read(L3) == 1 || EEPROM.read(L4) == 1) {
        lcd.setCursor(14, 0);
        lcd.write(2);
      } else {
        lcd.setCursor(14, 0);
        lcd.print(" ");
      }
      if (EEPROM.read(myfan) == 1) {
        lcd.setCursor(14, 1);
        lcd.write(2);
      } else {
        lcd.setCursor(14, 1);
        lcd.print(" ");
      }
      break;
    case 3:
      lcd.clear();
      print(0, 0, " LIGHT'S");
      print(0, 1, " FAN");
      print(0, 2, ">SET ALARAM");
      print(0, 3, " SETING");

      if (EEPROM.read(L1) == 1 || EEPROM.read(L2) == 1 || EEPROM.read(L3) == 1 || EEPROM.read(L4) == 1) {
        lcd.setCursor(14, 0);
        lcd.write(2);
      } else {
        lcd.setCursor(14, 0);
        lcd.print(" ");
      }
      if (EEPROM.read(myfan) == 1) {
        lcd.setCursor(14, 1);
        lcd.write(2);
      } else {
        lcd.setCursor(14, 1);
        lcd.print(" ");
      }
      break;
    case 4:
      lcd.clear();
      print(0, 0, " LIGHT'S");
      print(0, 1, " FAN");
      print(0, 2, " SET ALARAM");
      print(0, 3, ">SETING");

      if (EEPROM.read(L1) == 1 || EEPROM.read(L2) == 1 || EEPROM.read(L3) == 1 || EEPROM.read(L4) == 1) {
        lcd.setCursor(14, 0);
        lcd.write(2);
      } else {
        lcd.setCursor(14, 0);
        lcd.print(" ");
      }
      if (EEPROM.read(myfan) == 1) {
        lcd.setCursor(14, 1);
        lcd.write(2);
      } else {
        lcd.setCursor(14, 1);
        lcd.print(" ");
      }
      break;
    case 5:
      menu = 4;
      break;
  }
}

void updateSubLight() {
  switch (menu) {
    case 0:
      menu = 1;
      break;
    case 1:
      lcd.clear();
      print(0, 0, ">Light 1");
      print(0, 1, " Light 2");
      print(0, 2, " Light 3");
      print(0, 3, " Light 4");

      if (EEPROM.read(L1) == 1) {
        lcd.setCursor(12, 0);
        lcd.write(2);
      } else {
        lcd.setCursor(12, 0);
        lcd.print(" ");
      }
      if (EEPROM.read(L2) == 1) {
        lcd.setCursor(12, 1);
        lcd.write(2);
      } else {
        lcd.setCursor(12, 1);
        lcd.print(" ");
      }
      if (EEPROM.read(L3) == 1) {
        lcd.setCursor(12, 2);
        lcd.write(2);
      } else {
        lcd.setCursor(12, 2);
        lcd.print(" ");
      }
      if (EEPROM.read(L4) == 1) {
        lcd.setCursor(12, 3);
        lcd.write(2);
      } else {
        lcd.setCursor(12, 3);
        lcd.print(" ");
      }
      break;
    case 2:
      lcd.clear();
      print(0, 0, " Light 1");
      print(0, 1, ">Light 2");
      print(0, 2, " Light 3");
      print(0, 3, " Light 4");

      if (EEPROM.read(L1) == 1) {
        lcd.setCursor(12, 0);
        lcd.write(2);
      } else {
        lcd.setCursor(12, 0);
        lcd.print(" ");
      }
      if (EEPROM.read(L2) == 1) {
        lcd.setCursor(12, 1);
        lcd.write(2);
      } else {
        lcd.setCursor(12, 1);
        lcd.print(" ");
      }
      if (EEPROM.read(L3) == 1) {
        lcd.setCursor(12, 2);
        lcd.write(2);
      } else {
        lcd.setCursor(12, 2);
        lcd.print(" ");
      }
      if (EEPROM.read(L4) == 1) {
        lcd.setCursor(12, 3);
        lcd.write(2);
      } else {
        lcd.setCursor(12, 3);
        lcd.print(" ");
      }
      break;
    case 3:
      lcd.clear();
      print(0, 0, " Light 1");
      print(0, 1, " Light 2");
      print(0, 2, ">Light 3");
      print(0, 3, " Light 4");

      if (EEPROM.read(L1) == 1) {
        lcd.setCursor(12, 0);
        lcd.write(2);
      } else {
        lcd.setCursor(12, 0);
        lcd.print(" ");
      }
      if (EEPROM.read(L2) == 1) {
        lcd.setCursor(12, 1);
        lcd.write(2);
      } else {
        lcd.setCursor(12, 1);
        lcd.print(" ");
      }
      if (EEPROM.read(L3) == 1) {
        lcd.setCursor(12, 2);
        lcd.write(2);
      } else {
        lcd.setCursor(12, 2);
        lcd.print(" ");
      }
      if (EEPROM.read(L4) == 1) {
        lcd.setCursor(12, 3);
        lcd.write(2);
      } else {
        lcd.setCursor(12, 3);
        lcd.print(" ");
      }
      break;
    case 4:
      lcd.clear();
      print(0, 0, " Light 1");
      print(0, 1, " Light 2");
      print(0, 2, " Light 3");
      print(0, 3, ">Light 4");

      if (EEPROM.read(L1) == 1) {
        lcd.setCursor(12, 0);
        lcd.write(2);
      } else {
        lcd.setCursor(12, 0);
        lcd.print(" ");
      }
      if (EEPROM.read(L2) == 1) {
        lcd.setCursor(12, 1);
        lcd.write(2);
      } else {
        lcd.setCursor(12, 1);
        lcd.print(" ");
      }
      if (EEPROM.read(L3) == 1) {
        lcd.setCursor(12, 2);
        lcd.write(2);
      } else {
        lcd.setCursor(12, 2);
        lcd.print(" ");
      }
      if (EEPROM.read(L4) == 1) {
        lcd.setCursor(12, 3);
        lcd.write(2);
      } else {
        lcd.setCursor(12, 3);
        lcd.print(" ");
      }
      break;
    case 5:
      menu = 4;
      break;
  }
}
void onOff() {
  switch (menu) {
    case 0:
      menu = 1;
      break;
    case 1:
      lcd.clear();
      print(0, 0, ">ON");
      print(0, 1, " OFF");
      break;
    case 2:
      lcd.clear();
      print(0, 0, " ON");
      print(0, 1, ">OFF");
      break;
    case 3:
      menu = 2;
      break;
  }
}

void showAlaram() {
  if (menu == 0) {
    if (currTime - blinkTime >= 200) {
      blinkTime = currTime;
      blinkState = !blinkState;

      if (blinkState) {
        print(0, 0, "Set Alaram");
        print(0, 2, "Time=>");
        if (hour >= 10) {
          print(6, 2, hour);
        } else {
          print(6, 2, "0");
          print(7, 2, hour);
        }
        print(8, 2, ":");
        if (min >= 10) {
          print(9, 2, min);
        } else {
          print(9, 2, "0");
          print(10, 2, min);
        }
      } else {
        print(6, 2, "  ");
      }
    }
  } else if (menu == 1) {
    if (currTime - blinkTime >= 200) {
      blinkTime = currTime;
      blinkState = !blinkState;
      if (blinkState) {
        print(0, 0, "Set Alaram");
        print(0, 2, "Time=>");
        if (hour >= 10) {
          print(6, 2, hour);
        } else {
          print(6, 2, "0");
          print(7, 2, hour);
        }
        print(8, 2, ":");
        if (min >= 10) {
          print(9, 2, min);
        } else {
          print(9, 2, "0");
          print(10, 2, min);
        }
      } else {
        print(9, 2, "  ");
      }
    }
  }
}

void showSeting() {
  switch (menu) {
    case 0:
      menu = 1;
      break;
    case 1:
      lcd.clear();
      print(0, 0, ">Time");
      print(0, 1, " Date");
      print(0, 2, " Day of week");
      print(0, 3, " Add shortcut");
      break;
    case 2:
      lcd.clear();
      print(0, 0, " Time");
      print(0, 1, ">Date");
      print(0, 2, " Day of week");
      print(0, 3, " Add shortcut");
      break;
    case 3:
      lcd.clear();
      print(0, 0, " Time");
      print(0, 1, " Date");
      print(0, 2, ">Day of week");
      print(0, 3, " Add shortcut");
      break;
    case 4:
      lcd.clear();
      print(0, 0, " Time");
      print(0, 1, " Date");
      print(0, 2, " Day of week");
      print(0, 3, ">Add shortcut");
      break;
    case 5:
      menu = 4;
      break;
  }
}

void showTimeSeting() {
  if (menu == 0) {
    if (currTime - blinkTime >= 200) {
      blinkTime = currTime;
      blinkState = !blinkState;

      if (blinkState) {
        print(0, 0, "Set Time");
        print(0, 2, "Time=>");
        if (hour >= 10) {
          print(6, 2, hour);
        } else {
          print(6, 2, "0");
          print(7, 2, hour);
        }
        print(8, 2, ":");
        if (min >= 10) {
          print(9, 2, min);
        } else {
          print(9, 2, "0");
          print(10, 2, min);
        }
        print(11, 2, ":");
        if (sec >= 10) {
          print(12, 2, sec);
        } else {
          print(12, 2, "0");
          print(13, 2, sec);
        }
      } else {
        print(6, 2, "  ");
      }
    }
  } else if (menu == 1) {
    if (currTime - blinkTime >= 200) {
      blinkTime = currTime;
      blinkState = !blinkState;
      if (blinkState) {
        print(0, 0, "Set Time");
        print(0, 2, "Time=>");
        if (hour >= 10) {
          print(6, 2, hour);
        } else {
          print(6, 2, "0");
          print(7, 2, hour);
        }
        print(8, 2, ":");
        if (min >= 10) {
          print(9, 2, min);
        } else {
          print(9, 2, "0");
          print(10, 2, min);
        }
        print(11, 2, ":");
        if (sec >= 10) {
          print(12, 2, sec);
        } else {
          print(12, 2, "0");
          print(13, 2, sec);
        }
      } else {
        print(9, 2, "  ");
      }
    }
  } else if (menu == 2) {
    if (currTime - blinkTime >= 200) {
      blinkTime = currTime;
      blinkState = !blinkState;
      if (blinkState) {
        print(0, 0, "Set Time");
        print(0, 2, "Time=>");
        if (hour >= 10) {
          print(6, 2, hour);
        } else {
          print(6, 2, "0");
          print(7, 2, hour);
        }
        print(8, 2, ":");
        if (min >= 10) {
          print(9, 2, min);
        } else {
          print(9, 2, "0");
          print(10, 2, min);
        }
        print(11, 2, ":");
        if (sec >= 10) {
          print(12, 2, sec);
        } else {
          print(12, 2, "0");
          print(13, 2, sec);
        }
      } else {
        print(12, 2, "  ");
      }
    }
  }
}

void showDateSeting() { 
  if (menu == 0) {
    if (currTime - blinkTime >= 200) {
      blinkTime = currTime;
      blinkState = !blinkState;
      if (blinkState) {
        print(2, 0, "Set Date");
        print(0, 2, "Date=>");
        if (day >= 10) {
          print(6, 2, day);
        } else {
          print(6, 2, "0");
          print(7, 2, day);
        }
        print(8, 2, ":");
        if (mon >= 10) {
          print(9, 2, mon);
        } else {
          print(9, 2, "0");
          print(10, 2, mon);
        }
        print(11, 2, ":");
        print(12, 2, yer);
      } else {
        print(6, 1, "  ");
      }
    }
  } else if (menu == 1) {
    if (currTime - blinkTime >= 200) {
      blinkTime = currTime;
      blinkState = !blinkState;
      if (blinkState) {
        print(2, 0, "Set Date");
        print(0, 2, "Date=>");
        if (day >= 10) {
          print(6, 2, day);
        } else {
          print(6, 2, "0");
          print(7, 2, day);
        }
        print(8, 2, ":");
        if (mon >= 10) {
          print(9, 2, mon);
        } else {
          print(9, 2, "0");
          print(10, 2, mon);
        }
        print(11, 2, ":");
        print(12, 2, yer);
      } else {
        print(9, 2, "  ");
      }
    }
  } else if (menu == 2) {
    if (currTime - blinkTime >= 200) {
      blinkTime = currTime;
      blinkState = !blinkState;
      if (blinkState) {
        print(2, 0, "Set Date");
        print(0, 2, "Date=>");
        if (day >= 10) {
          print(6, 2, day);
        } else {
          print(6, 2, "0");
          print(7, 2, day);
        }
        print(8, 2, ":");
        if (mon >= 10) {
          print(9, 2, mon);
        } else {
          print(9, 2, "0");
          print(10, 2, mon);
        }
        print(11, 2, ":");
        print(12, 2, yer);
      } else {
        print(12, 2, "    ");
      }
    }
  }
}

void showDOWseting() {
  switch (menu) {
    case 0:
      menu = 1;
      break;
    case 1:
      lcd.clear();
      print(0, 0, ">MONDAY");
      print(0, 1, " TUESDAY");
      print(0, 2, " WEDNESDAY");
      print(0, 3, " THURSDAY");
      break;
    case 2:
      lcd.clear();
      print(0, 0, " MONDAY");
      print(0, 1, ">TUESDAY");
      print(0, 2, " WEDNESDAY");
      print(0, 3, " THURSDAY");
      break;
    case 3:
      lcd.clear();
      print(0, 0, " MONDAY");
      print(0, 1, " TUESDAY");
      print(0, 2, ">WEDNESDAY");
      print(0, 3, " THURSDAY");
      break;
    case 4:
      lcd.clear();
      print(0, 0, " MONDAY");
      print(0, 1, " TUESDAY");
      print(0, 2, " WEDNESDAY");
      print(0, 3, ">THURSDAY");
      break;
    case 5:
      lcd.clear();
      print(0, 0, ">FRIDAY");
      print(0, 1, " SATURDAY");
      print(0, 2, " SUNDAY");
      break;
    case 6:
      lcd.clear();
      print(0, 0, " FRIDAY");
      print(0, 1, ">SATURDAY");
      print(0, 2, " SUNDAY");
      break;
    case 7:
      lcd.clear();
      print(0, 0, " FRIDAY");
      print(0, 1, " SATURDAY");
      print(0, 2, ">SUNDAY");
      break;
    case 8:
      menu = 7;
      break;
  }
}

void showShortcut() {
  switch (menu) {
    case 0:
      menu = 1;
      break;
    case 1:
      lcd.clear();
      print(0, 0, ">L1");
      print(0, 1, " L2");
      print(0, 2, " L3");
      print(0, 3, " L4");

      if (EEPROM.read(vL1) == 1) {
        lcd.setCursor(6, 0);
        lcd.write(2);
      } else {
        print(6, 0, " ");
      }
      if (EEPROM.read(vL2) == 1) {
        lcd.setCursor(6, 1);
        lcd.write(2);
      } else {
        print(6, 1, " ");
      }
      if (EEPROM.read(vL3) == 1) {
        lcd.setCursor(6, 2);
        lcd.write(2);
      } else {
        print(6, 2, " ");
      }
      if (EEPROM.read(vL4) == 1) {
        lcd.setCursor(6, 3);
        lcd.write(2);
      } else {
        print(6, 3, " ");
      }
      break;
    case 2:
      lcd.clear();
      print(0, 0, " L1");
      print(0, 1, ">L2");
      print(0, 2, " L3");
      print(0, 3, " L4");

      if (EEPROM.read(vL1) == 1) {
        lcd.setCursor(6, 0);
        lcd.write(2);
      } else {
        print(6, 0, " ");
      }
      if (EEPROM.read(vL2) == 1) {
        lcd.setCursor(6, 1);
        lcd.write(2);
      } else {
        print(6, 1, " ");
      }
      if (EEPROM.read(vL3) == 1) {
        lcd.setCursor(6, 2);
        lcd.write(2);
      } else {
        print(6, 2, " ");
      }
      if (EEPROM.read(vL4) == 1) {
        lcd.setCursor(6, 3);
        lcd.write(2);
      } else {
        print(6, 3, " ");
      }

      break;
    case 3:
      lcd.clear();
      print(0, 0, " L1");
      print(0, 1, " L2");
      print(0, 2, ">L3");
      print(0, 3, " L4");

      if (EEPROM.read(vL1) == 1) {
        lcd.setCursor(6, 0);
        lcd.write(2);
      } else {
        print(6, 0, " ");
      }
      if (EEPROM.read(vL2) == 1) {
        lcd.setCursor(6, 1);
        lcd.write(2);
      } else {
        print(6, 1, " ");
      }
      if (EEPROM.read(vL3) == 1) {
        lcd.setCursor(6, 2);
        lcd.write(2);
      } else {
        print(6, 2, " ");
      }
      if (EEPROM.read(vL4) == 1) {
        lcd.setCursor(6, 3);
        lcd.write(2);
      } else {
        print(6, 3, " ");
      }
      break;
    case 4:
      lcd.clear();
      print(0, 0, " L1");
      print(0, 1, " L2");
      print(0, 2, " L3");
      print(0, 3, ">L4");

      if (EEPROM.read(vL1) == 1) {
        lcd.setCursor(6, 0);
        lcd.write(2);
      } else {
        print(6, 0, " ");
      }
      if (EEPROM.read(vL2) == 1) {
        lcd.setCursor(6, 1);
        lcd.write(2);
      } else {
        print(6, 1, " ");
      }
      if (EEPROM.read(vL3) == 1) {
        lcd.setCursor(6, 2);
        lcd.write(2);
      } else {
        print(6, 2, " ");
      }
      if (EEPROM.read(vL4) == 1) {
        lcd.setCursor(6, 3);
        lcd.write(2);
      } else {
        print(6, 3, " ");
      }
      break;
    case 5:
      lcd.clear();
       print(0, 0, ">Fan");

      if (EEPROM.read(vmyfan) == 1) {
        lcd.setCursor(6, 0);
        lcd.write(2);
      } else {
        print(6, 0, " ");
      }
      break;
    case 6:
      menu = 5;
      break;
  }
}
