int leds[6] = {21, 19, 18, 5, 4, 15};

bool goingUp = true;
const int buttonPin = 23;
int buttonState = LOW;
bool animation = true;
int currentLed = 0;
unsigned long lastStep = 0;
const int stepTime = 100;
int chosenLed = 0;
leds.size()
void setup() {
  for (int i = 0; i < 6; i++) {
    pinMode(leds[i], OUTPUT); 
  }
  pinMode(buttonPin, INPUT_PULLUP);
  randomSeed(analogRead(34));
  chosenLed = chooseLed();

}

int chooseLed() {
  int chosen = leds[random(0,6)];
  for (int i = 0; i<3; i++) {
    digitalWrite(chosen, HIGH);
    delay(250);
    digitalWrite(chosen, LOW);
    delay(250);
  }
  return chosen;
}

void allOff() {
  for (int i = 0; i < 6; i++)  {
    digitalWrite(leds[i], LOW);
  }
}

void allLeds(int val) {
  for (int i = 0; i < 6; i++) {
    digitalWrite(leds[i], val);
  }
}

void moveLight() {
  if(millis() - lastStep >= stepTime) {
    allOff();
    digitalWrite(leds[currentLed], HIGH);

    if (goingUp) {
      currentLed++;
    } else {
      currentLed--;
    }

    if (currentLed < 0) {
      currentLed = 1;
      goingUp = true;
    } else if (currentLed >= 6) {
      currentLed = 4;
      goingUp = false;
    }
    lastStep = millis();
  }
}

void loop() {
  buttonState = digitalRead(buttonPin);
  if (buttonState == LOW) {
    animation = false;
  }
  if (animation) {
    moveLight();
  } else {
    allOff();
    if (leds[currentLed] == chosenLed) {
      allLeds(HIGH);
    } else {
      digitalWrite(leds[currentLed], HIGH);
    }
  }

}