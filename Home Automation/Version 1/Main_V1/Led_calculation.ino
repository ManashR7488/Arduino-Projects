void ledcalculation(){ 
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
      EEPROM.update(Myfan, f1);
      value = 0;
      break;
    case 'f':
      v1 = v2 = v3 = v4 = 1;
      value = 0;
      break;
    case 'g':
      v1 = v2 = v3 = v4 = 0;
      value = 0;
      break;
    default:
      break;
  }

  if (EEPROM.read(L1) == 1) {
    digitalWrite(led1, HIGH);
  } else {
    digitalWrite(led1, LOW);
  }

  if (EEPROM.read(L2) == 1) {
    digitalWrite(led2, HIGH);
  } else {
    digitalWrite(led2, LOW);
  }

  if (EEPROM.read(L3) == 1) {
    digitalWrite(led3, HIGH);
  } else {
    digitalWrite(led3, LOW);
  }

  if (EEPROM.read(L4) == 1) {
    digitalWrite(led4, HIGH);
  } else {
    digitalWrite(led4, LOW);
  }

  if (EEPROM.read(Myfan) == 1) {
    digitalWrite(fan1, HIGH);
  } else {
    digitalWrite(fan1, LOW);
  }
}

void exicuteLight(){
  if( a == 1 && b == 1){
    EEPROM.update(L1, 1);
    menu = 2;
  }
  if(a == 1 && b == 2){
    EEPROM.update(L1, 0);
    menu = 1;
  }
  if( a == 2 && b == 1){
    EEPROM.update(L2, 1);
    menu = 2;
  }
  if(a == 2 && b == 2){
    EEPROM.update(L2, 0);
     menu = 1;
  }
  if( a == 3 && b == 1){
    EEPROM.update(L3, 1);
    menu = 2;
  }
  if(a == 3 && b == 2){
    EEPROM.update(L3, 0);
    menu = 1;
  }
  if( a == 4 && b == 1){
    EEPROM.update(L4, 1);
    menu = 2;
  }
  if(a == 4 && b == 2){
    EEPROM.update(L4, 0);
    menu = 1;
  }
  
}

void exicuteFan(){
  if( a == 2 && b == 1){
    EEPROM.update(Myfan,1);
  }
  if(a == 2 && b == 2){
    EEPROM.update(Myfan, 0);
  }
}
