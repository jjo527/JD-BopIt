int score;
int time;

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

void loop() {
    bool isRunning = false;
    digitalWrite(1, LOW);

    score = 0;
    time = 3000;

    // start button logic
    if(digitalRead(13) == HIGH) {
        digitalWrite(12, HIGH);
        isRunning = true;
        delay(1000);

        // LOGIC FOR STARTING AT 95
        // for(int i = 0; i < 95; i++) {
        //   good_input_fast();
        // }
    }

    // constant while loop that gives/checks for inputs
    while (isRunning) {
        int randNumber = random(1,4); //generates random command number

        check_winner(score);

        //check score
        while (score >= 99) {
            // start button logic
            if(digitalRead(13) == HIGH) {
                digitalWrite(1, LOW);
                reset();
                isRunning = false;
            }
        }

        if (!isRunning) {
            break;
        }

        if(randNumber == 1) {//first command check

            //give command
            buzz();
            bool userInput = false;

            //wait for user input
            for(int i = 0; i < time; i++) { //loop checking for input from user
                delay(1);

                if (digitalRead(6) == HIGH && userInput == false) {
                    good_input();
                    userInput = true;
                    break;
                }
                else if (digitalRead(7) == HIGH && userInput == false) {
                    bad_input();
                    userInput = true;
                    isRunning = false;
                    break;
                }
                else if (digitalRead(8) == HIGH && userInput == false) {
                    bad_input();
                    userInput = true;
                    isRunning = false;
                    break;
                }
            }

            if (userInput == false) {
                bad_input();
                isRunning = false;
            }

            digitalWrite(11, LOW);
            delay(500);

        }
        else if(randNumber == 2) {
            buzz();
            buzz();
            bool userInput = false;

            for(int i = 0; i < time; i++) {
                delay(1);

                if (digitalRead(6) == HIGH && userInput == false) {
                    bad_input();
                    userInput = true;
                    isRunning = false;
                    break;
                }
                else if (digitalRead(7) == HIGH && userInput == false) {
                    good_input();
                    userInput = true;
                    break;
                }
                else if (digitalRead(8) == HIGH && userInput == false) {
                    bad_input();
                    userInput = true;
                    isRunning = false;
                    break;
                }
            }

            if (userInput == false) {
                bad_input();
                isRunning = false;
            }

            digitalWrite(11, LOW);
            delay(500);

        }
        else if(randNumber == 3) {
            buzz();
            buzz();
            buzz();

            bool userInput = false;

            for(int i = 0; i < time; i++) {
                delay(1);

                if (digitalRead(6) == HIGH && userInput == false) {
                    bad_input();
                    userInput = true;
                    isRunning = false;
                    break;
                }
                else if (digitalRead(7) == HIGH && userInput == false) {
                    bad_input();
                    userInput = true;
                    isRunning = false;
                    break;
                }
                else if (digitalRead(8) == HIGH && userInput == false) {
                    good_input();
                    userInput = true;
                    break;
                }

            }

            if (userInput == false) {
                bad_input();
                isRunning = false;
            }

            digitalWrite(11, LOW);
            delay(500);
        }
    }
}

void bad_input() {
    digitalWrite(0, HIGH);
    delay(500);
    digitalWrite(0, LOW);
    delay(500);

    time = 3000;
    score = 0;
}

void reset() {
    digitalWrite(0, HIGH);
    digitalWrite(0, LOW);

    delay(500);

    time = 3000;
    score = 0;
}

void good_input() {
    Serial.print("correct input detected");
    digitalWrite(1, HIGH);
    delay(500);

    time -= 20;
    score += 1;


    if(score < 99) {
        digitalWrite(1, LOW);
        delay(500);
    }
}

void good_input_fast() {
    Serial.print("correct input detected");
    digitalWrite(1, HIGH);
    delay(10);
    digitalWrite(1, LOW);

    time -= 20;
    score += 1;
}


void buzz() {
    digitalWrite(11, HIGH);
    delay(100);
    digitalWrite(11, LOW);
    delay(100);
}

bool check_winner(int score) {
    if(score >= 99) {
        for(int i = 1; i <= 10; i++) {
            buzz();
        }
        return true;
    }

    return false;
}
