int Right = 11;
int Left  = 10;
int RightLed = 13;
int LeftLed  = 12;
int buttonStateRight = 0;
int buttonStateLeft = 0;
void setup() {
  // put your setup code here, to run once:
  pinMode(Left, INPUT);
  pinMode(Right, INPUT);
  pinMode(LeftLed, OUTPUT);
  pinMode(RightLed, OUTPUT);

}

void loop() {
  // put your main code here, to run repeatedly:
buttonStateLeft = digitalRead(Left);
buttonStateRight = digitalRead(Right);
     if (buttonStateLeft == HIGH and buttonStateRight == LOW) {
     LeftTurn();
  }  if (buttonStateRight == HIGH and buttonStateLeft == LOW) {
     RightTurn(); 
  }    if (buttonStateRight == HIGH and buttonStateLeft == HIGH){
     ErrorBlink();
  }
}

void RightTurn() {
 digitalWrite(RightLed, HIGH);
    delay(400);
    digitalWrite(RightLed, LOW);
    delay(400);
    digitalWrite(RightLed, HIGH);
    delay(400);
    digitalWrite(RightLed, LOW);
    delay(400);
    digitalWrite(RightLed, HIGH);
    delay(400);
    digitalWrite(RightLed, LOW);
}
void LeftTurn() {
    digitalWrite(LeftLed, HIGH);
    delay(400);
    digitalWrite(LeftLed, LOW);
    delay(400);
    digitalWrite(LeftLed, HIGH);
    delay(400);
    digitalWrite(LeftLed, LOW);
    delay(400);
    digitalWrite(LeftLed, HIGH);
    delay(400);
    digitalWrite(LeftLed, LOW);
}
void ErrorBlink() {
	digitalWrite(LeftLed, HIGH);
	digitalWrite(RightLed, HIGH);
	delay(500);
	digitalWrite(LeftLed, LOW);
	digitalWrite(RightLed, LOW);
	delay(500);
}
