int leds[6] = {5, 18, 19, 21, 22, 23};
const int buttonPin = 4;
int buttonState = LOW;

void setup() {
  for (int i = 0; i < 6; i++) {
    pinMode(leds[i], OUTPUT);
  }
  pinMode(buttonPin, INPUT_PULLUP);
}

void allLeds(int val) {
  for (int i = 0; i < 6; i++) {
    digitalWrite(leds[i], val);
  }
}

void loop() {
  buttonState = digitalRead(buttonPin);
  if (buttonState == LOW) {
    allLeds(HIGH);    
  } else {
    allLeds(LOW);
  }
}