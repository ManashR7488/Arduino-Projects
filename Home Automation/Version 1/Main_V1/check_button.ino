void checkButton() {

  // bool currRead_B = digitalRead(BackBtn);
  // bool currRead_D = digitalRead(downBtn);           //if use buttons comment line 8 to 30. and un comment line 3 to 6.
  // bool currRead_U = digitalRead(upBtn);             // and also define buttons pin like BackBtn,downBtn,upBtn,enterBtn.
  // bool currRead_E = digitalRead(enterBtn);

  delay(100);
  bool currRead_B = HIGH;
  bool currRead_U = HIGH;
  bool currRead_D = HIGH;
  bool currRead_E = HIGH;

  int x = map(analogRead(x_pin), 0, 1023, 0, 10);
  int y = map(analogRead(y_pin), 0, 1023, 0, 10);


  if (x <= 2) {
    currRead_B = LOW;
  } else if (x >= 7) {
    currRead_E = LOW;
  } else {
    currRead_B = HIGH;
    currRead_E = HIGH;
  }

  if (y <= 2) {
    currRead_U = LOW;
  } else if (y >= 7) {
    currRead_D = LOW;
  } else {
    currRead_U = HIGH;
    currRead_D = HIGH;
  }

  if (currRead_B != prevState_B) {
    prevTime_B = millis();
  }
  if (currRead_D != prevState_D) {
    prevTime_D = millis();
  }
  if (currRead_U != prevState_U) {
    prevTime_U = millis();
  }
  if (currRead_E != prevState_E) {
    prevTime_E = millis();
  }
  if ((millis() - prevTime_B) > waitTime) {
    if (currRead_B != currState_B) {
      currState_B = currRead_B;
      if (currState_B == LOW) {
        buttonPressed = 'B';
      }
    }
  } else buttonPressed = '0';
  if ((millis() - prevTime_D) > waitTime) {
    if (currRead_D != currState_D) {
      currState_D = currRead_D;
      if (currState_D == LOW) {
        buttonPressed = 'D';
      }
    }
  } else buttonPressed = '0';
  if ((millis() - prevTime_U) > waitTime) {
    if (currRead_U != currState_U) {
      currState_U = currRead_U;
      if (currState_U == LOW) {
        buttonPressed = 'U';
      } else {
        buttonPressed = '0';
      }
    }
  } else buttonPressed = '0';
  if ((millis() - prevTime_E) > waitTime) {
    if (currRead_E != currState_E) {
      currState_E = currRead_E;
      if (currState_E == LOW) {
        buttonPressed = 'E';
      }
    }
  } else buttonPressed = '0';

  prevState_B = currRead_B;
  prevState_D = currRead_D;
  prevState_U = currRead_U;
  prevState_E = currRead_E;

  processButton(buttonPressed);
}
