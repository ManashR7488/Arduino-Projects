void processButton(char buttonPressed) {
  switch (menuLevel) {
    case 0:  // Level 0
      switch (buttonPressed) {
        case 'E':
          menuLevel = 1;
          menu = 1;
          updateMenu();
          prevTime = currTime;
          delay(d);
          break;
        case 'U':
          break;
        case 'D':
          break;
        case 'B':
          if (EEPROM.read(L1) == 0 && EEPROM.read(L2) == 0 && EEPROM.read(L3) == 0 && EEPROM.read(L4) == 0) {
            if (EEPROM.read(vL1) == 1) {
              EEPROM.update(L1, 1);
            }
            if (EEPROM.read(vL2) == 1) {
              EEPROM.update(L2, 1);
            }
            if (EEPROM.read(vL3) == 1) {
              EEPROM.update(L3, 1);
            }
            if (EEPROM.read(vL4) == 1) {
              EEPROM.update(L4, 1);
            }
          }
          if (EEPROM.read(Myfan) == 0) {
            if (EEPROM.read(vMyfan) == 1) {
              EEPROM.update(Myfan, 1);
            }
          }
          delay(d);
          break;
      }
      break;
    case 1:  // Level 1,main menu
      if ((currTime - prevTime) >= delayTime) {
        lcd.clear();
        menuLevel = 0;
      }
      switch (buttonPressed) {
        case 'E':
          prevTime = currTime;
          if (menu == 1) {
            updateSubLight();
            menuLevel = 2;
            updateSubLight();
          } else if (menu == 2) {
            onOff();
            menuLevel = 4;
            a = menu;
            menu = 1;
            onOff();
          } else if (menu == 3) {
            lcd.clear();
            showAlaram();
            menuLevel = 5;
            menu = 0;
            showAlaram();
          } else if (menu == 4) {
            lcd.clear();
            showSeting();
            menuLevel = 6;
            menu = 1;
            showSeting();
          }
          delay(d);
          break;
        case 'U':
          prevTime = currTime;
          menu--;
          updateMenu();
          delay(d);
          break;
        case 'D':
          prevTime = currTime;
          menu++;
          updateMenu();
          delay(d);
          break;
        case 'B':
          menuLevel = 0;
          lcd.clear();
          displayHomeScreen();
          delay(d);
          break;
        default:
          break;
      }
      break;
    case 2:  // Level 2, light sub menu, light1,light2,.......
      if ((currTime - prevTime) >= delayTime) {
        lcd.clear();
        menuLevel = 0;
      }
      switch (buttonPressed) {
        case 'E':
          prevTime = currTime;
          a = menu;
          onOff();
          menuLevel = 3;
          menu = 1;
          onOff();
          delay(d);
          break;
        case 'U':
          prevTime = currTime;
          menu--;
          updateSubLight();
          delay(d);
          break;
        case 'D':
          prevTime = currTime;
          menu++;
          updateSubLight();
          delay(d);
          break;
        case 'B':
          prevTime = currTime;
          menuLevel = 1;
          menu = 1;
          updateMenu();
          delay(d);
          break;
        default:
          break;
      }
      break;
    case 3:  // Level 3, light sub sub menu,   (on, off)
      if ((currTime - prevTime) >= delayTime) {
        lcd.clear();
        menuLevel = 0;
      }
      switch (buttonPressed) {
        case 'E':
          prevTime = currTime;
          onOff();
          menuLevel = 3;
          b = menu;
          exicuteLight();
          // menu = a;
          b = 0;
          onOff();
          delay(d);
          break;
        case 'U':
          prevTime = currTime;
          menu--;
          onOff();
          delay(d);
          break;
        case 'D':
          prevTime = currTime;
          menu++;
          onOff();
          delay(d);
          break;
        case 'B':
          prevTime = currTime;
          menuLevel = 2;
          menu = a;
          updateSubLight();
          delay(d);
          break;
      }
      break;
    case 4:  // Level 4, fan sub menu, (on, off)
      if ((currTime - prevTime) >= delayTime) {
        lcd.clear();
        menuLevel = 0;
      }
      switch (buttonPressed) {
        case 'E':
          prevTime = currTime;
          updateMenu();
          menuLevel = 1;
          b = menu;
          exicuteFan();
          menu = a;
          b = 0;
          updateMenu();
          delay(d);
          break;
        case 'U':
          prevTime = currTime;
          menu--;
          onOff();
          delay(d);
          break;
        case 'D':
          prevTime = currTime;
          menu++;
          onOff();
          delay(d);
          break;
        case 'B':
          prevTime = currTime;
          menuLevel = 1;
          menu = 2;
          updateMenu();
          delay(d);
          break;
      }
      break;
    case 5:  // Level 5, alaram seting ......
      if ((currTime - prevTime) >= delayTime) {
        lcd.clear();
        alaram_hours = 0;
        alaram_minutes = 0;
        menuLevel = 0;
      }
      switch (buttonPressed) {
        case 'E':
          prevTime = currTime;
          lcd.clear();
          if (menu == 1) {
            check_alaram = true;
            T = true;
            menuLevel = 1;
            menu = 3;
            updateMenu();
          } else if (menu == 0) {
            menu = 1;
          }
          delay(d);
          break;
        case 'U':
          prevTime = currTime;
          if (menu == 0) {
            if (alaram_hours < 23) {
              alaram_hours++;
            } else {
              alaram_hours = 0;
            }
          } else if (menu == 1) {
            if (alaram_minutes < 59) {
              alaram_minutes++;
            } else {
              alaram_minutes = 0;
            }
          }
          showAlaram();
          delay(100);
          break;
        case 'D':
          prevTime = currTime;
          if (menu == 0) {
            if (alaram_hours > 0) {
              alaram_hours--;
            } else {
              alaram_hours = 0;
            }
          } else if (menu == 1) {
            if (alaram_minutes > 0) {
              alaram_minutes--;
            } else {
              alaram_minutes = 0;
            }
          }
          showAlaram();
          delay(100);
          break;
        case 'B':
          if (menu == 0) {
            menuLevel = 1;
            menu = 3;
            alaram_hours = 0;
            alaram_minutes = 0;
            lcd.clear();
            updateMenu();
          }
          if (menu == 1) {
            menu = 0;
          }
          delay(d);
          break;
        default:
          break;
      }
      break;
    case 6:  // Level 6, Seting menu.......,time,date,etc.....
      if ((currTime - prevTime) >= delayTime) {
        lcd.clear();
        menuLevel = 0;
      }
      switch (buttonPressed) {
        case 'E':
          prevTime = currTime;
          if (menu == 1) {
            lcd.clear();
            alaram_hours = t.hour;
            alaram_minutes = t.min;
            alaram_sec = t.sec;
            showTimeSeting();
            menuLevel = 7;
            menu = 0;
            showTimeSeting();
          } else if (menu == 2) {
            lcd.clear();
            day = t.date;
            mon = t.mon;
            yer = t.year;
            showDateSeting();
            menuLevel = 8;
            menu = 0;
            showDateSeting();
          } else if (menu == 3) {
            showDOWseting();
            menuLevel = 9;
            menu = 1;
            showDOWseting();
          } else if (menu == 4) {
            showShortcut();
            menuLevel = 10;
            menu = 1;
            showShortcut();
          }
          delay(d);
          break;
        case 'U':
          prevTime = currTime;
          menu--;
          showSeting();
          delay(d);
          break;
        case 'D':
          prevTime = currTime;
          menu++;
          showSeting();
          delay(d);
          break;
        case 'B':
          prevTime = currTime;
          menu = 4;
          menuLevel = 1;
          updateMenu();
          delay(d);
          break;
        default:
          break;
      }
      break;
    case 7:  // Level 7, sub seting of seting menu => time.........
      if ((currTime - prevTime) >= delayTime) {
        lcd.clear();
        alaram_hours = 0;
        alaram_minutes = 0;
        menuLevel = 0;
      }
      switch (buttonPressed) {
        case 'E':
          prevTime = currTime;
          // lcd.clear();
          if (menu == 2) {
            rtc.setTime(alaram_hours, alaram_minutes, 00);
            alaram_hours = 0;
            alaram_minutes = 0;
            menuLevel = 6;
            menu = 1;
            showSeting();
          } else if (menu == 1) {
            menu = 2;
          } else if (menu == 0) {
            menu = 1;
          }
          delay(400);
          break;
        case 'U':
          prevTime = currTime;
          if (menu == 0) {
            if (alaram_hours < 23) {
              alaram_hours++;
            } else {
              alaram_hours = 0;
            }
          } else if (menu == 1) {
            if (alaram_minutes < 59) {
              alaram_minutes++;
            } else {
              alaram_minutes = 0;
            }
          } else if (menu == 2) {
            if (alaram_sec < 59) {
              alaram_sec++;
            } else {
              alaram_sec = 0;
            }
          }
          showTimeSeting();
          delay(100);
          break;
        case 'D':
          prevTime = currTime;
          if (menu == 0) {
            if (alaram_hours > 0) {
              alaram_hours--;
            } else {
              alaram_hours = 23;
            }
          } else if (menu == 1) {
            if (alaram_minutes > 0) {
              alaram_minutes--;
            } else {
              alaram_minutes = 59;
            }
          } else if (menu == 2) {
            if (alaram_sec > 0) {
              alaram_sec--;
            } else {
              alaram_sec = 59;
            }
          }
          showTimeSeting();
          delay(100);
          break;
        case 'B':
          if (menu == 2) {
            menu = 1;
            // showTime();
          } else if (menu == 1) {
            menu = 0;
            // showTime();
          } else if (menu == 0) {
            menuLevel = 6;
            menu = 1;
            alaram_hours = 0;
            alaram_minutes = 0;
            alaram_sec = 0;
            lcd.clear();
            showSeting();
          }
          delay(d);
          break;
        default:
          break;
      }
      break;
    case 8:  // Level 8, sub seting of seting menu => date.........
      if ((currTime - prevTime) >= delayTime) {
        lcd.clear();
        menuLevel = 0;
      }
      switch (buttonPressed) {
        case 'E':
          prevTime = currTime;
          if (menu == 0) {
            menu = 1;
          } else if (menu == 1) {
            menu = 2;
          } else if (menu == 2) {
            rtc.setDate(day, mon, yer);
            menuLevel = 6;
            menu = 2;
            showSeting();
          }
          delay(d);
          break;
        case 'U':
          prevTime = currTime;
          if (menu == 0) {
            if (day < 31) {
              day++;
            } else {
              day = 1;
            }
          } else if (menu == 1) {
            if (mon < 12) {
              mon++;
            } else {
              mon = 1;
            }
          } else if (menu == 2) {
            yer++;
          }
          showDateSeting();
          delay(100);
          break;
        case 'D':
          prevTime = currTime;
          if (menu == 0) {
            if (day > 1) {
              day--;
            } else {
              day = 31;
            }
          } else if (menu == 1) {
            if (mon > 1) {
              mon--;
            } else {
              mon = 12;
            }
          } else if (menu == 2) {
            yer--;
          }
          delay(100);
          break;
        case 'B':
          prevTime = currTime;
          if (menu == 0) {
            menuLevel = 6;
            menu = 2;
            showSeting();
          } else if (menu == 1) {
            menu = 0;
          } else if (menu == 2) {
            menu = 1;
          }
          delay(d);
          break;
        default:
          break;
      }
      break;
    case 9:  // Level 9, sub seting of seting menu => day of week....
      if ((currTime - prevTime) >= delayTime) {
        lcd.clear();
        menuLevel = 0;
      }
      switch (buttonPressed) {
        case 'E':
          prevTime = currTime;
          rtc.setDOW(menu);
          showSeting();
          menuLevel = 6;
          menu = 3;
          showSeting();
          delay(d);
          break;
        case 'U':
          prevTime = currTime;
          showDOWseting();
          menu--;
          showDOWseting();
          delay(d);
          break;
        case 'D':
          prevTime = currTime;
          showDOWseting();
          menu++;
          showDOWseting();
          delay(d);
          break;
        case 'B':
          prevTime = currTime;
          showSeting();
          menuLevel = 6;
          menu = 3;
          showSeting();
          delay(d);
          break;
        default:
          break;
      }
      break;
    case 10: // Level 10, sub seting of seting => add shortcut......
      if ((currTime - prevTime) >= delayTime) {
        lcd.clear();
        menuLevel = 0;
      }
      switch (buttonPressed) {
        case 'E':
          prevTime = currTime;
          if (menu == 1) {
            a = menu;
            menu = 1;
            onOff();
            menuLevel = 11;
            onOff();
          } else if (menu == 2) {
            a = menu;
            menu = 1;
            onOff();
            menuLevel = 11;
            onOff();
          } else if (menu == 3) {
            a = menu;
            menu = 1;
            onOff();
            menuLevel = 11;
            onOff();
          } else if (menu == 4) {
            a = menu;
            menu = 1;
            onOff();
            menuLevel = 11;
            onOff();
          } else if (menu == 5) {
            a = menu;
            menu = 1;
            onOff();
            menuLevel = 11;
            onOff();
          }
          delay(d);
          break;
        case 'U':
          prevTime = currTime;
          menu--;
          showShortcut();
          delay(d);
          break;
        case 'D':
          prevTime = currTime;
          menu++;
          showShortcut();
          delay(d);
          break;
        case 'B':
          prevTime = currTime;
          menuLevel = 6;
          menu = 4;
          showSeting();
          delay(d);
          break;
        default:
          break;
      }
      break;
    case 11: // Level11, shortcut toggle menu on off......
      if ((currTime - prevTime) >= delayTime) {
        lcd.clear();
        menuLevel = 0;
      }
      switch (buttonPressed) {
        case 'E':
          prevTime = currTime;
          if (a == 1 && menu == 1) {
            EEPROM.update(vL1, 1);
          } else if (a == 1 && menu == 2) {
            EEPROM.update(vL1, 0);
          } else if (a == 2 && menu == 1) {
            EEPROM.update(vL2, 1);
          } else if (a == 2 && menu == 2) {
            EEPROM.update(vL2, 0);
          } else if (a == 3 && menu == 1) {
            EEPROM.update(vL3, 1);
          } else if (a == 3 && menu == 2) {
            EEPROM.update(vL3, 0);
          } else if (a == 4 && menu == 1) {
            EEPROM.update(vL4, 1);
          } else if (a == 4 && menu == 2) {
            EEPROM.update(vL4, 0);
          } else if (a == 5 && menu == 1) {
            EEPROM.update(vMyfan, 1);
          } else if (a == 5 && menu == 2) {
            EEPROM.update(vMyfan, 0);
          }
          menuLevel = 10;
          menu = a;
          showShortcut();
          delay(d);
          break;
        case 'U':
          prevTime = currTime;
          menu--;
          onOff();
          delay(d);
          break;
        case 'D':
          prevTime = currTime;
          menu++;
          onOff();
          delay(d);
          break;
        case 'B':
          prevTime = currTime;
          menuLevel = 10;
          menu = a;
          showShortcut();
          delay(d);
          break;
        default:
          break;
      }
      break;
  }
}