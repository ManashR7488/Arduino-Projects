void processButton(char buttonPressed){
  switch(menuLevel){
    case 0: //level 0
     switch(buttonPressed){
      case 'E':
       menuLevel = 1;
       menu = 1;
       updateMenu();
       delay(d);
      break;
      case 'U':
      break;
      case 'D':
      break;
      case 'B':
      break;
     }
    break;
    case 1:      // Level 1,main menu
     switch (buttonPressed){
      case 'E':
       if(menu == 1){
         updateSubLight();
         menuLevel = 2;
         updateSubLight();
       }
       else if(menu == 2){
        updateSubFan();
        menuLevel =4;
        a = menu;
        menu = 1;
        updateSubFan();
       }
       else if(menu == 3){
         lcd.clear();
         lcd.print("Under develop..");
         delay(2000);
         menuLevel = 1;
         updateMenu();
        }
       delay(d);
      break;
      case 'U':
       menu--;
       updateMenu();
       delay(d);
      break;
      case 'D':
       menu++;
       updateMenu();
       delay(d);
      break;
      case 'B':
       menuLevel = 0;
       showHomeScreen();
       delay(d);
      break;
      default:
      break;
     }
    break;
    case 2:
     switch(buttonPressed){
      case 'E':
       a = menu;
       updateSubSubLight();
       menuLevel = 3;      
       menu = 1;
       updateSubSubLight();
       delay(d);
      break;
      case 'U':
       menu--;
       updateSubLight();
       delay(d);
      break;
      case 'D':
       menu++;
       updateSubLight();
       delay(d);
      break;
      case 'B':
       menuLevel = 1;
       menu = 1;
       updateMenu();
       delay(d);
      break;
      default:
      break;
     }
    break;
    case 3:
     switch(buttonPressed){
      case 'E':
       updateSubLight();
       menuLevel = 2;
       b = menu;
       exicuteLight();
       menu = a;
       b = 0;
       updateSubLight();
       delay(d);
      break;
      case 'U':
       menu--;
       updateSubSubLight();
       delay(d);
      break;
      case 'D':
       menu++;
       updateSubSubLight();
       delay(d);
      break;
      case 'B':
       menuLevel = 2;
       menu = a;
       updateSubLight();
       delay(d);
      break;
     }
    break;
    case 4:
     switch(buttonPressed){
      case 'E':
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
       menu--;
       updateSubSubLight();
       delay(d);
      break;
      case 'D':
       menu++;
       updateSubSubLight();
       delay(d);
      break;
      case 'B':
       menuLevel = 1;
       menu = 2;
       updateMenu();
       delay(d);
      break;
     }
    break;
  }
}