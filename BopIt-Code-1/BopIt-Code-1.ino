void setup() {
  pinMode(13, INPUT); // start/stop button input
  pinMode(6, INPUT); // top/left input 
  pinMode(7, INPUT); // middle/middle input
  pinMode(8, INPUT); // bottom/right input
  
  pinMode(0, OUTPUT); // reset counter (top light = fail)
  pinMode(1, OUTPUT); // increment counter (middle light = success)

  pinMode(2, OUTPUT); // bottom output light on right, not being used currently

  //pinMode(9, OUTPUT); // bottom light signaling input 
  //pinMode(10, OUTPUT); // middle light signaling input
  pinMode(11, OUTPUT); // BUZZER OUTPUT FOR SIGNALING INPUTS (used to be top light signaling input)
  //TCCR2B = TCCR2B & 0b11111000 | 0x01;
  pinMode(12, OUTPUT); //start/stop indicator
  bool isRunning = false;

}

void loop() 
{
  bool isRunning = false;  
  digitalWrite(1, LOW);
  delay(500);

  // toggle start light and logic
  if(digitalRead(13) == HIGH) {
    digitalWrite(12, !digitalRead(12));
    
    if (digitalRead(12) == HIGH) {
      isRunning = true;
      Serial.print("start stop indicator turned on");
    }
    else {
      isRunning = false;
      Serial.print("start stop indicator turned off");
    }

    delay(5000);
  }  

  // constant while loop that gives/checks for inputs
  while (isRunning) {
    int randNumber = random(1,4); //generates random command number
      
    if(randNumber == 1) {
      digitalWrite(11, HIGH);
      delay(100);
      digitalWrite(11, LOW);
      delay(500);
      bool userInput = false;

      for(int i = 0; i < 3000; i++) { //loop checking for input from user
        delay(1);

        if (digitalRead(6) == HIGH && userInput == false) {
          Serial.print("correct input detected");
          digitalWrite(1, HIGH);
          delay(500);
          digitalWrite(1, LOW);
          delay(500);
          userInput = true;
        }
        else if (digitalRead(7) == HIGH && userInput == false) {
          digitalWrite(0, HIGH);
          delay(500);
          digitalWrite(0, LOW);
          delay(500);
          userInput = true;
        }
        else if (digitalRead(8) == HIGH && userInput == false) {
          digitalWrite(0, HIGH);
          delay(500);
          digitalWrite(0, LOW);
          delay(500);
          userInput = true;
        } 

      }

      if (userInput == false) {
        digitalWrite(0, HIGH);
        delay(500);
        digitalWrite(0, LOW);
        delay(500);
      }
      
      digitalWrite(11, LOW);
      delay(500);

    }
    else if(randNumber == 2) {
      digitalWrite(11, HIGH);
      delay(100);
      digitalWrite(11, LOW);
      delay(100);
      digitalWrite(11, HIGH);
      delay(100);
      digitalWrite(11, LOW);
      delay(500);
      bool userInput = false;

      for(int i = 0; i < 3000; i++) {
        delay(1);

        if (digitalRead(6) == HIGH && userInput == false) {
          digitalWrite(0, HIGH);
          delay(500);
          digitalWrite(0, LOW);
          delay(500);
          userInput = true;
        }
        else if (digitalRead(7) == HIGH && userInput == false) {
          Serial.print("correct input detected");
          digitalWrite(1, HIGH);
          delay(500);
          digitalWrite(1, LOW);
          delay(500);
          userInput = true;
        }
        else if (digitalRead(8) == HIGH && userInput == false) {
          digitalWrite(0, HIGH);
          delay(500);
          digitalWrite(0, LOW);
          delay(500);
          userInput = true;
        } 

      }

      if (userInput == false) {
        digitalWrite(0, HIGH);
        delay(500);
        digitalWrite(0, LOW);
        delay(500);
      }
      
      digitalWrite(11, LOW);
      delay(500);

    }
    else if(randNumber == 3) {
      digitalWrite(11, HIGH);
      delay(100);
      digitalWrite(11, LOW);
      delay(100);
      digitalWrite(11, HIGH);
      delay(100);
      digitalWrite(11, LOW);
      delay(100);
      digitalWrite(11, HIGH);
      delay(100);
      digitalWrite(11, LOW);
      delay(500);
      bool userInput = false;

      for(int i = 0; i < 3000; i++) {
        delay(1);

        if (digitalRead(6) == HIGH && userInput == false) {
          digitalWrite(0, HIGH);
          delay(500);
          digitalWrite(0, LOW);
          delay(500);
          userInput = true;
        }
        else if (digitalRead(7) == HIGH && userInput == false) {
          digitalWrite(0, HIGH);
          delay(500);
          digitalWrite(0, LOW);
          delay(500);
          userInput = true;
        }
        else if (digitalRead(8) == HIGH && userInput == false) {
          Serial.print("correct input detected");
          digitalWrite(1, HIGH);
          delay(500);
          digitalWrite(1, LOW);
          delay(500);
          userInput = true;
        } 

      }

      if (userInput == false) {
        digitalWrite(0, HIGH);
        delay(500);
        digitalWrite(0, LOW);
        delay(500);
      }
      
      digitalWrite(11, LOW);
      delay(500);

    }

    // still check for start button toggle
    if(digitalRead(13) == HIGH) {
      digitalWrite(12, !digitalRead(12));
      
      if (digitalRead(12) == HIGH) {
        isRunning = true;
      }
      else {
        isRunning = false;
      }

      delay(5000);
    }  

    delay(2000);
  }
}
