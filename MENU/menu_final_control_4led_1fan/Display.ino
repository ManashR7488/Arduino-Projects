void showHomeScreen() {
  lcd.clear();
  lcd.println("  Welcom  ");
  lcd.setCursor(0,1);
  lcd.println("Enter to conti..");
}

void updateMenu(){
  switch(menu){
    case 0:
     menu = 1;
    break;
    case 1:
     lcd.clear();
     lcd.print(">LIGHT'S");
     lcd.setCursor(0, 1);
     lcd.print(" FAN");
    break;
    case 2:
     lcd.clear();
     lcd.print(" LIGHT'S");
     lcd.setCursor(0, 1);
     lcd.print(">FAN");
    break;
    case 3:
     lcd.clear();
     lcd.print(">Set Alaram");
     lcd.setCursor(0, 1);
     lcd.print("          ");
    break;
    case 4:
     menu = 3;
    break;
  }
}
void updateSubLight(){
  switch(menu){
    case 0:
     menu = 1;
    break;
    case 1:
     lcd.clear();
     lcd.print(">GREEN LED");
     lcd.setCursor(0, 1);
     lcd.print(" BLUE LED");
    break;
    case 2:
     lcd.clear();
     lcd.print(" GREEN LED");
     lcd.setCursor(0, 1);
     lcd.print(">BLUE LED");
    break;
    case 3:
     lcd.clear();
     lcd.print(">YELLOW LED");
     lcd.setCursor(0, 1);
     lcd.print(" RED LED");
    break;
    case 4:
     lcd.clear();
     lcd.print(" YELLOW LED");
     lcd.setCursor(0, 1);
     lcd.print(">RED LED");
    break;
    case 5:
     menu = 4;
    break;
  }
}

void updateSubSubLight(){
  switch(menu){
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

void updateSubFan(){
  switch(menu){
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