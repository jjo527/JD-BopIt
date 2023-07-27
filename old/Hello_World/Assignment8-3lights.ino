//shelby wilson
//Tom's comment
//JJ's Comment

void setup() {
  pinMode(7, INPUT);
  pinMode(0, OUTPUT);
  pinMode(1, OUTPUT);
  pinMode(2, OUTPUT);

}

void loop() {
  digitalWrite(0, LOW);
  digitalWrite(1, LOW);
  digitalWrite(2, LOW);

  if(digitalRead(7) == HIGH) {
    // blink bottom light
    digitalWrite(2, HIGH);
    delay(500);            
    digitalWrite(2, LOW);  
    delay(500);

    // blink middle light
    digitalWrite(1, HIGH);
    delay(500);            
    digitalWrite(1, LOW);  
    delay(500);

    // blink top light
    digitalWrite(0, HIGH);
    delay(500);            
    digitalWrite(0, LOW);  
    delay(500);    
  }  
}
