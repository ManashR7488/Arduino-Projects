void ledcalculation() {
  switch (value) {
    case 'a':
      v1 = 1 - v1;
      EEPROM.update(L1, v1);
      value = 0;
      break;
    case 'b':
      v2 = 1 - v2;
      EEPROM.update(L2, v2);
      value = 0;
      break;
    case 'c':
      v3 = 1 - v3;
      EEPROM.update(L3, v3);
      value = 0;
      break;
    case 'd':
      v4 = 1 - v4;
      EEPROM.update(L4, v4);
      value = 0;
      break;
    case 'e':
      f1 = 1 - f1;
      EEPROM.update(myfan, f1);
      value = 0;
      break;
    case 'f':
      all = 1 - all;
      if(all == 1){
        v1 = v2 = v3 = v4 = 1;
      }else{
        v1 = v2 = v3 = v4 = 0;
      }
      EEPROM.update(L1, v1);
      EEPROM.update(L2, v2);
      EEPROM.update(L3, v3);
      EEPROM.update(L4, v4);
      value = 0;
      break;
    default:
      break;
  }

  if (EEPROM.read(L1) == 1) {
    pin(led[0], HIGH);
  } else {
    pin(led[0], LOW);
  }

  if (EEPROM.read(L2) == 1) {
    pin(led[1], HIGH);
  } else {
    pin(led[1], LOW);
  }

  if (EEPROM.read(L3) == 1) {
    pin(led[2], HIGH);
  } else {
    pin(led[2], LOW);
  }

  if (EEPROM.read(L4) == 1) {
    pin(led[3], HIGH);
  } else {
    pin(led[3], LOW);
  }

  if (EEPROM.read(myfan) == 1) {
    pin(fan, HIGH);
  } else {
    pin(fan, LOW);
  }
}

void exicuteLight() {
  if (a == 1 && b == 1) {
    EEPROM.update(L1, 1);
    menu = 2;
  }
  if (a == 1 && b == 2) {
    EEPROM.update(L1, 0);
    menu = 1;
  }
  if (a == 2 && b == 1) {
    EEPROM.update(L2, 1);
    menu = 2;
  }
  if (a == 2 && b == 2) {
    EEPROM.update(L2, 0);
    menu = 1;
  }
  if (a == 3 && b == 1) {
    EEPROM.update(L3, 1);
    menu = 2;
  }
  if (a == 3 && b == 2) {
    EEPROM.update(L3, 0);
    menu = 1;
  }
  if (a == 4 && b == 1) {
    EEPROM.update(L4, 1);
    menu = 2;
  }
  if (a == 4 && b == 2) {
    EEPROM.update(L4, 0);
    menu = 1;
  }
}

void exicuteFan() {
  if (a == 2 && b == 1) {
    EEPROM.update(myfan, 1);
  }
  if (a == 2 && b == 2) {
    EEPROM.update(myfan, 0);
  }
}
