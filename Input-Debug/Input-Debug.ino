void setup() {
  pinMode(13, INPUT); // start/stop button input
  pinMode(6, INPUT); // top/left input 
  pinMode(7, INPUT); // middle/middle input
  pinMode(8, INPUT); // bottom/right input
  
  pinMode(0, OUTPUT); // reset counter (top light = fail)
  pinMode(1, OUTPUT); // increment counter (middle light = success)

  pinMode(2, OUTPUT); // bottom output light on right, not being used currently

  pinMode(9, OUTPUT); // bottom light signaling input 
  pinMode(10, OUTPUT); // middle light signaling input
  pinMode(11, OUTPUT); // top light signaling input
  pinMode(12, OUTPUT); //start/stop indicator
  bool isRunning = false;

}

void loop() 
{
  if (digitalRead(6) == HIGH) {
    digitalWrite(11, HIGH);
    delay(500);
    digitalWrite(11, LOW);
  }
  else if (digitalRead(7) == HIGH) {
    digitalWrite(10, HIGH);
    delay(500);
    digitalWrite(10, LOW);
  }
  else if (digitalRead(8) == HIGH) {
    digitalWrite(9, HIGH);
    delay(500);
    digitalWrite(9, LOW);
  }
}
