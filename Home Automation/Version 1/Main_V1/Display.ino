void displayHomeScreen() {
  lcd.setCursor(0, 0);
  lcd.print(rtc.getTimeStr());
  lcd.setCursor(9, 0);
  lcd.print(rtc.getDOWStr(FORMAT_SHORT));
  lcd.setCursor(0, 1);
  lcd.print(rtc.getDateStr());
  lcd.setCursor(0, 2);
  lcd.print("Temp:");
  lcd.setCursor(5, 2);
  lcd.print(dht.readTemperature());
  lcd.setCursor(0, 3);
  lcd.print("Humd:");
  lcd.setCursor(5, 3);
  lcd.print(dht.readHumidity());
  
  
  
  if (EEPROM.read(L1) == 1) {
    lcd.setCursor(13, 0);
    lcd.print("Led1:ON");
  } else {
    lcd.setCursor(13, 0);
    lcd.print("Led1:--");
  }
  if (EEPROM.read(L2) == 1) {
    lcd.setCursor(13, 1);
    lcd.print("Led2:ON");
  } else {
    lcd.setCursor(13, 1);
    lcd.print("Led2:--");
  }
  if (EEPROM.read(L3) == 1) {
    lcd.setCursor(13, 2);
    lcd.print("Led3:ON");
  } else {
    lcd.setCursor(13, 2);
    lcd.print("Led3:--");
  }
  if (EEPROM.read(L4) == 1) {
    lcd.setCursor(13, 3);
    lcd.print("Led4:ON");
  } else {
    lcd.setCursor(13, 3);
    lcd.print("Led4:--");
  }
}

void updateMenu() {  //menuLevel 1
  switch (menu) {
    case 0:
      menu = 1;
      break;
    case 1:
      lcd.clear();
      lcd.print(">LIGHT'S");
      lcd.setCursor(0, 1);
      lcd.print(" FAN");
      lcd.setCursor(0, 2);
      lcd.print(" SET ALARAM");
      lcd.setCursor(0, 3);
      lcd.print(" SETING");

      if (EEPROM.read(L1) == 1 || EEPROM.read(L2) == 1 || EEPROM.read(L3) == 1 || EEPROM.read(L4) == 1) {
        lcd.setCursor(14, 0);
        lcd.write(2);
      } else {
        lcd.setCursor(14, 0);
        lcd.print(" ");
      }
      if (EEPROM.read(Myfan) == 1) {
        lcd.setCursor(14, 1);
        lcd.write(2);
      } else {
        lcd.setCursor(14, 1);
        lcd.print(" ");
      }
      break;
    case 2:
      lcd.clear();
      lcd.print(" LIGHT'S");
      lcd.setCursor(0, 1);
      lcd.print(">FAN");
      lcd.setCursor(0, 2);
      lcd.print(" SET ALARAM");
      lcd.setCursor(0, 3);
      lcd.print(" SETING");

      if (EEPROM.read(L1) == 1 || EEPROM.read(L2) == 1 || EEPROM.read(L3) == 1 || EEPROM.read(L4) == 1) {
        lcd.setCursor(14, 0);
        lcd.write(2);
      } else {
        lcd.setCursor(14, 0);
        lcd.print(" ");
      }
      if (EEPROM.read(Myfan) == 1) {
        lcd.setCursor(14, 1);
        lcd.write(2);
      } else {
        lcd.setCursor(14, 1);
        lcd.print(" ");
      }
      break;
    case 3:
      lcd.clear();
      lcd.print(" LIGHT'S");
      lcd.setCursor(0, 1);
      lcd.print(" FAN");
      lcd.setCursor(0, 2);
      lcd.print(">SET ALARAM");
      lcd.setCursor(0, 3);
      lcd.print(" SETING");

      if (EEPROM.read(L1) == 1 || EEPROM.read(L2) == 1 || EEPROM.read(L3) == 1 || EEPROM.read(L4) == 1) {
        lcd.setCursor(14, 0);
        lcd.write(2);
      } else {
        lcd.setCursor(14, 0);
        lcd.print(" ");
      }
      if (EEPROM.read(Myfan) == 1) {
        lcd.setCursor(14, 1);
        lcd.write(2);
      } else {
        lcd.setCursor(14, 1);
        lcd.print(" ");
      }
      break;
    case 4:
      lcd.clear();
      lcd.print(" LIGHT'S");
      lcd.setCursor(0, 1);
      lcd.print(" FAN");
      lcd.setCursor(0, 2);
      lcd.print(" SET ALARAM");
      lcd.setCursor(0, 3);
      lcd.print(">SETING");

      if (EEPROM.read(L1) == 1 || EEPROM.read(L2) == 1 || EEPROM.read(L3) == 1 || EEPROM.read(L4) == 1) {
        lcd.setCursor(14, 0);
        lcd.write(2);
      } else {
        lcd.setCursor(14, 0);
        lcd.print(" ");
      }
      if (EEPROM.read(Myfan) == 1) {
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

void updateSubLight() {  //menuLevel 2
  switch (menu) {
    case 0:
      menu = 1;
      break;
    case 1:
      lcd.clear();
      lcd.print(">Light 1");
      lcd.setCursor(0, 1);
      lcd.print(" Light 2");
      lcd.setCursor(0, 2);
      lcd.print(" Light 3");
      lcd.setCursor(0, 3);
      lcd.print(" Light 4");

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
      lcd.print(" Light 1");
      lcd.setCursor(0, 1);
      lcd.print(">Light 2");
      lcd.setCursor(0, 2);
      lcd.print(" Light 3");
      lcd.setCursor(0, 3);
      lcd.print(" Light 4");

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
      lcd.print(" Light 1");
      lcd.setCursor(0, 1);
      lcd.print(" Light 2");
      lcd.setCursor(0, 2);
      lcd.print(">Light 3");
      lcd.setCursor(0, 3);
      lcd.print(" Light 4");

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
      lcd.print(" Light 1");
      lcd.setCursor(0, 1);
      lcd.print(" Light 2");
      lcd.setCursor(0, 2);
      lcd.print(" Light 3");
      lcd.setCursor(0, 3);
      lcd.print(">Light 4");

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

void onOff() {  //on off
  switch (menu) {
    case 0:
      menu = 1;
      break;
    case 1:
      lcd.clear();
      lcd.print(">ON");
      lcd.setCursor(0, 1);
      lcd.print(" OFF");
      break;
    case 2:
      lcd.clear();
      lcd.print(" ON");
      lcd.setCursor(0, 1);
      lcd.print(">OFF");
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
        lcd.setCursor(0, 0);
        lcd.print("Set Alaram");
        lcd.setCursor(0, 2);
        lcd.print("Time=>");
        if ( alaram_hours>= 10) {
          lcd.setCursor(6, 2);
          lcd.print(alaram_hours);
        } else {
          lcd.setCursor(6, 2);
          lcd.print("0");
          lcd.setCursor(7, 2);
          lcd.print(alaram_hours);
        }
        lcd.setCursor(8, 2);
        lcd.print(":");
        if (alaram_minutes >= 10) {
          lcd.setCursor(9, 2);
          lcd.print(alaram_minutes);
        } else {
          lcd.setCursor(9, 2);
          lcd.print("0");
          lcd.setCursor(10, 2);
          lcd.print(alaram_minutes);
        }
      } else {
        lcd.setCursor(6, 2);
        lcd.print("  ");
      }
    }
  } else if (menu == 1) {
    if (currTime - blinkTime >= 200) {
      blinkTime = currTime;
      blinkState = !blinkState;
      if (blinkState) {
        lcd.setCursor(0, 0);
        lcd.print("Set Alaram");
        lcd.setCursor(0, 2);
        lcd.print("Time=>");
        if (alaram_hours >= 10) {
          lcd.setCursor(6, 2);
          lcd.print(alaram_hours);
        } else {
          lcd.setCursor(6, 2);
          lcd.print("0");
          lcd.setCursor(7, 2);
          lcd.print(alaram_hours);
        }
        lcd.setCursor(8, 2);
        lcd.print(":");
        if (alaram_minutes >= 10) {
          lcd.setCursor(9, 2);
          lcd.print(alaram_minutes);
        } else {
          lcd.setCursor(9, 2);
          lcd.print("0");
          lcd.setCursor(10, 2);
          lcd.print(alaram_minutes);
        }
      } else {
        lcd.setCursor(9, 2);
        lcd.print("  ");
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
      lcd.setCursor(0, 0);
      lcd.print(">Time");
      lcd.setCursor(0, 1);
      lcd.print(" Date");
      lcd.setCursor(0, 2);
      lcd.print(" Day of week");
      lcd.setCursor(0, 3);
      lcd.print(" Add shortcut");
      break;
    case 2:
      lcd.clear();
      lcd.setCursor(0, 0);
      lcd.print(" Time");
      lcd.setCursor(0, 1);
      lcd.print(">Date");
      lcd.setCursor(0, 2);
      lcd.print(" Day of week");
      lcd.setCursor(0, 3);
      lcd.print(" Add shortcut");
      break;
    case 3:
      lcd.clear();
      lcd.setCursor(0, 0);
      lcd.print(" Time");
      lcd.setCursor(0, 1);
      lcd.print(" Date");
      lcd.setCursor(0, 2);
      lcd.print(">Day of week");
      lcd.setCursor(0, 3);
      lcd.print(" Add shortcut");
      break;
    case 4:
      lcd.clear();
      lcd.setCursor(0, 0);
      lcd.print(" Time");
      lcd.setCursor(0, 1);
      lcd.print(" Date");
      lcd.setCursor(0, 2);
      lcd.print(" Day of week");
      lcd.setCursor(0, 3);
      lcd.print(">Add shortcut");
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
        lcd.setCursor(0, 0);
        lcd.print("Set Time");
        lcd.setCursor(0, 2);
        lcd.print("Time=>");
        if (alaram_hours >= 10) {
          lcd.setCursor(6, 2);
          lcd.print(alaram_hours);
        } else {
          lcd.setCursor(6, 2);
          lcd.print("0");
          lcd.setCursor(7, 2);
          lcd.print(alaram_hours);
        }
        lcd.setCursor(8, 2);
        lcd.print(":");
        if (alaram_minutes >= 10) {
          lcd.setCursor(9, 2);
          lcd.print(alaram_minutes);
        } else {
          lcd.setCursor(9, 2);
          lcd.print("0");
          lcd.setCursor(10, 2);
          lcd.print(alaram_minutes);
        }
        lcd.setCursor(11, 2);
        lcd.print(":");
        if (alaram_sec >= 10) {
          lcd.setCursor(12, 2);
          lcd.print(alaram_sec);
        } else {
          lcd.setCursor(12, 2);
          lcd.print("0");
          lcd.setCursor(13, 2);
          lcd.print(alaram_sec);
        }
      } else {
        lcd.setCursor(6, 2);
        lcd.print("  ");
      }
    }
  } else if (menu == 1) {
    if (currTime - blinkTime >= 200) {
      blinkTime = currTime;
      blinkState = !blinkState;
      if (blinkState) {
        lcd.setCursor(0, 0);
        lcd.print("Set Time");
        lcd.setCursor(0, 2);
        lcd.print("Time=>");
        if (alaram_hours >= 10) {
          lcd.setCursor(6, 2);
          lcd.print(alaram_hours);
        } else {
          lcd.setCursor(6, 2);
          lcd.print("0");
          lcd.setCursor(7, 2);
          lcd.print(alaram_hours);
        }
        lcd.setCursor(8, 2);
        lcd.print(":");
        if (alaram_minutes >= 10) {
          lcd.setCursor(9, 2);
          lcd.print(alaram_minutes);
        } else {
          lcd.setCursor(9, 2);
          lcd.print("0");
          lcd.setCursor(10, 2);
          lcd.print(alaram_minutes);
        }
        lcd.setCursor(11, 2);
        lcd.print(":");
        if (alaram_sec >= 10) {
          lcd.setCursor(12, 2);
          lcd.print(alaram_sec);
        } else {
          lcd.setCursor(12, 2);
          lcd.print("0");
          lcd.setCursor(13, 2);
          lcd.print(alaram_sec);
        }
      } else {
        lcd.setCursor(9, 2);
        lcd.print("  ");
      }
    }
  } else if (menu == 2) {
    if (currTime - blinkTime >= 200) {
      blinkTime = currTime;
      blinkState = !blinkState;
      if (blinkState) {
        lcd.setCursor(0, 0);
        lcd.print("Set Time");
        lcd.setCursor(0, 2);
        lcd.print("Time=>");
        if (alaram_hours >= 10) {
          lcd.setCursor(6, 2);
          lcd.print(alaram_hours);
        } else {
          lcd.setCursor(6, 2);
          lcd.print("0");
          lcd.setCursor(7, 2);
          lcd.print(alaram_hours);
        }
        lcd.setCursor(8, 2);
        lcd.print(":");
        if (alaram_minutes >= 10) {
          lcd.setCursor(9, 2);
          lcd.print(alaram_minutes);
        } else {
          lcd.setCursor(9, 2);
          lcd.print("0");
          lcd.setCursor(10, 2);
          lcd.print(alaram_minutes);
        }
        lcd.setCursor(11, 2);
        lcd.print(":");
        if (alaram_sec >= 10) {
          lcd.setCursor(12, 2);
          lcd.print(alaram_sec);
        } else {
          lcd.setCursor(12, 2);
          lcd.print("0");
          lcd.setCursor(13, 2);
          lcd.print(alaram_sec);
        }
      } else {
        lcd.setCursor(12, 2);
        lcd.print("  ");
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
        lcd.setCursor(2, 0);
        lcd.print("Set Date");
        lcd.setCursor(0, 2);
        lcd.print("Date=>");
        if (day >= 10) {
          lcd.setCursor(6, 2);
          lcd.print(day);
        } else {
          lcd.setCursor(6, 2);
          lcd.print("0");
          lcd.setCursor(7, 2);
          lcd.print(day);
        }
        lcd.setCursor(8, 2);
        lcd.print(":");
        if (mon >= 10) {
          lcd.setCursor(9, 2);
          lcd.print(mon);
        } else {
          lcd.setCursor(9, 2);
          lcd.print("0");
          lcd.setCursor(10, 2);
          lcd.print(mon);
        }
        lcd.setCursor(11, 2);
        lcd.print(":");
        lcd.setCursor(12, 2);
        lcd.print(yer);
      } else {
        lcd.setCursor(6, 2);
        lcd.print("  ");
      }
    }
  } else if (menu == 1) {
    if (currTime - blinkTime >= 200) {
      blinkTime = currTime;
      blinkState = !blinkState;
      if (blinkState) {
        lcd.setCursor(2, 0);
        lcd.print("Set Date");
        lcd.setCursor(0, 2);
        lcd.print("Date=>");
        if (day >= 10) {
          lcd.setCursor(6, 2);
          lcd.print(day);
        } else {
          lcd.setCursor(6, 2);
          lcd.print("0");
          lcd.setCursor(7, 2);
          lcd.print(day);
        }
        lcd.setCursor(8, 2);
        lcd.print(":");
        if (mon >= 10) {
          lcd.setCursor(9, 2);
          lcd.print(mon);
        } else {
          lcd.setCursor(9, 2);
          lcd.print("0");
          lcd.setCursor(10, 2);
          lcd.print(mon);
        }
        lcd.setCursor(11, 2);
        lcd.print(":");
        lcd.setCursor(12, 2);
        lcd.print(yer);
      } else {
        lcd.setCursor(9, 2);
        lcd.print("  ");
      }
    }
  } else if (menu == 2) {
    if (currTime - blinkTime >= 200) {
      blinkTime = currTime;
      blinkState = !blinkState;
      if (blinkState) {
        lcd.setCursor(2, 0);
        lcd.print("Set Date");
        lcd.setCursor(0, 2);
        lcd.print("Date=>");
        if (day >= 10) {
          lcd.setCursor(6, 2);
          lcd.print(day);
        } else {
          lcd.setCursor(6, 2);
          lcd.print("0");
          lcd.setCursor(7, 2);
          lcd.print(day);
        }
        lcd.setCursor(8, 2);
        lcd.print(":");
        if (mon >= 10) {
          lcd.setCursor(9, 2);
          lcd.print(mon);
        } else {
          lcd.setCursor(9, 2);
          lcd.print("0");
          lcd.setCursor(10, 2);
          lcd.print(mon);
        }
        lcd.setCursor(11, 2);
        lcd.print(":");
        lcd.setCursor(12, 2);
        lcd.print(yer);
      } else {
        lcd.setCursor(12, 2);
        lcd.print("    ");
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
      lcd.setCursor(0, 0);
      lcd.print(">MONDAY");
      lcd.setCursor(0, 1);
      lcd.print(" TUESDAY");
      lcd.setCursor(0, 2);
      lcd.print(" WEDNESDAY");
      lcd.setCursor(0, 3);
      lcd.print(" THURSDAY");
      break;
    case 2:
      lcd.clear();
      lcd.setCursor(0, 0);
      lcd.print(" MONDAY");
      lcd.setCursor(0, 1);
      lcd.print(">TUESDAY");
      lcd.setCursor(0, 2);
      lcd.print(" WEDNESDAY");
      lcd.setCursor(0, 3);
      lcd.print(" THURSDAY");
      break;
    case 3:
      lcd.clear();
      lcd.setCursor(0, 0);
      lcd.print(" MONDAY");
      lcd.setCursor(0, 1);
      lcd.print(" TUESDAY");
      lcd.setCursor(0, 2);
      lcd.print(">WEDNESDAY");
      lcd.setCursor(0, 3);
      lcd.print(" THURSDAY");
      break;
    case 4:
      lcd.clear();
      lcd.setCursor(0, 0);
      lcd.print(" MONDAY");
      lcd.setCursor(0, 1);
      lcd.print(" TUESDAY");
      lcd.setCursor(0, 2);
      lcd.print(" WEDNESDAY");
      lcd.setCursor(0, 3);
      lcd.print(">THURSDAY");
      break;
    case 5:
      lcd.clear();
      lcd.setCursor(0, 0);
      lcd.print(">FRIDAY");
      lcd.setCursor(0, 1);
      lcd.print(" SATURDAY");
      lcd.setCursor(0, 2);
      lcd.print(" SUNDAY");
      break;
    case 6:
      lcd.clear();
      lcd.setCursor(0, 0);
      lcd.print(" FRIDAY");
      lcd.setCursor(0, 1);
      lcd.print(">SATURDAY");
      lcd.setCursor(0, 2);
      lcd.print(" SUNDAY");
      break;
    case 7:
      lcd.clear();
      lcd.setCursor(0, 0);
      lcd.print(" FRIDAY");
      lcd.setCursor(0, 1);
      lcd.print(" SATURDAY");
      lcd.setCursor(0, 2);
      lcd.print(">SUNDAY");
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
      lcd.setCursor(0, 0);
      lcd.print(">L1");
      lcd.setCursor(0, 1);
      lcd.print(" L2");
      lcd.setCursor(0, 2);
      lcd.print(" L3");
      lcd.setCursor(0, 3);
      lcd.print(" L4");

      if (EEPROM.read(vL1) == 1) {
        lcd.setCursor(6, 0);
        lcd.write(2);
      } else {
        lcd.setCursor(6, 0);
        lcd.print(" ");
      }
      if (EEPROM.read(vL2) == 1) {
        lcd.setCursor(6, 1);
        lcd.write(2);
      } else {
        lcd.setCursor(6, 1);
        lcd.print(" ");
      }
      if (EEPROM.read(vL3) == 1) {
        lcd.setCursor(6, 2);
        lcd.write(2);
      } else {
        lcd.setCursor(6, 2);
        lcd.print(" ");
      }
      if (EEPROM.read(vL4) == 1) {
        lcd.setCursor(6, 3);
        lcd.write(2);
      } else {
        lcd.setCursor(6, 3);
        lcd.print(" ");
      }
      break;
    case 2:
      lcd.clear();
      lcd.setCursor(0, 0);
      lcd.print(" L1");
      lcd.setCursor(0, 1);
      lcd.print(">L2");
      lcd.setCursor(0, 2);
      lcd.print(" L3");
      lcd.setCursor(0, 3);
      lcd.print(" L4");

      if (EEPROM.read(vL1) == 1) {
        lcd.setCursor(6, 0);
        lcd.write(2);
      } else {
        lcd.setCursor(6, 0);
        lcd.print(" ");
      }
      if (EEPROM.read(vL2) == 1) {
        lcd.setCursor(6, 1);
        lcd.write(2);
      } else {
        lcd.setCursor(6, 1);
        lcd.print(" ");
      }
      if (EEPROM.read(vL3) == 1) {
        lcd.setCursor(6, 2);
        lcd.write(2);
      } else {
        lcd.setCursor(6, 2);
        lcd.print(" ");
      }
      if (EEPROM.read(vL4) == 1) {
        lcd.setCursor(6, 3);
        lcd.write(2);
      } else {
        lcd.setCursor(6, 3);
        lcd.print(" ");
      }
      break;
    case 3:
      lcd.clear();
      lcd.setCursor(0, 0);
      lcd.print(" L1");
      lcd.setCursor(0, 1);
      lcd.print(" L2");
      lcd.setCursor(0, 2);
      lcd.print(">L3");
      lcd.setCursor(0, 3);
      lcd.print(" L4");

      if (EEPROM.read(vL1) == 1) {
        lcd.setCursor(6, 0);
        lcd.write(2);
      } else {
        lcd.setCursor(6, 0);
        lcd.print(" ");
      }
      if (EEPROM.read(vL2) == 1) {
        lcd.setCursor(6, 1);
        lcd.write(2);
      } else {
        lcd.setCursor(6, 1);
        lcd.print(" ");
      }
      if (EEPROM.read(vL3) == 1) {
        lcd.setCursor(6, 2);
        lcd.write(2);
      } else {
        lcd.setCursor(6, 2);
        lcd.print(" ");
      }
      if (EEPROM.read(vL4) == 1) {
        lcd.setCursor(6, 3);
        lcd.write(2);
      } else {
        lcd.setCursor(6, 3);
        lcd.print(" ");
      }
      break;
    case 4:
      lcd.clear();
      lcd.setCursor(0, 0);
      lcd.print(" L1");
      lcd.setCursor(0, 1);
      lcd.print(" L2");
      lcd.setCursor(0, 2);
      lcd.print(" L3");
      lcd.setCursor(0, 3);
      lcd.print(">L4");

      if (EEPROM.read(vL1) == 1) {
        lcd.setCursor(6, 0);
        lcd.write(2);
      } else {
        lcd.setCursor(6, 0);
        lcd.print(" ");
      }
      if (EEPROM.read(vL2) == 1) {
        lcd.setCursor(6, 1);
        lcd.write(2);
      } else {
        lcd.setCursor(6, 1);
        lcd.print(" ");
      }
      if (EEPROM.read(vL3) == 1) {
        lcd.setCursor(6, 2);
        lcd.write(2);
      } else {
        lcd.setCursor(6, 2);
        lcd.print(" ");
      }
      if (EEPROM.read(vL4) == 1) {
        lcd.setCursor(6, 3);
        lcd.write(2);
      } else {
        lcd.setCursor(6, 3);
        lcd.print(" ");
      }
      break;
    case 5:
      lcd.clear();
      lcd.setCursor(0, 0);
      lcd.print(">Fan");

      if (EEPROM.read(vMyfan) == 1) {
        lcd.setCursor(6, 0);
        lcd.write(2);
      } else {
        lcd.setCursor(6, 0);
        lcd.print(" ");
      }
      break;
    case 6:
      menu = 5;
      break;
  }
}