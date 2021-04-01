
#include <Servo.h>

Servo thumb;
Servo pointer;
Servo middleRing;
Servo pinky;

int position = 0;
int thumbPin = 8;
int pointerPin = 11;
int middleRingPin = 9;
int pinkyPin = 10;

void setup() {
  Serial.begin(9600);
 
  thumb.attach(thumbPin);
  pointer.attach(pointerPin);
  middleRing.attach(middleRingPin);
  pinky.attach(pinkyPin);

  thumb.write(position);
  pointer.write(position);
  middleRing.write(position);
  pinky.write(position);

  Serial.println("Key: ");
  Serial.println("0 = Open");
  Serial.println("1 = Close");
  Serial.println("2 = Motion Hand");
  Serial.println("3/4 = Motion Fingers");
}

void loop() {
  char input;
  
  if (Serial.available() > 0) {
    input = Serial.read();

    if (input == '0') {
      Serial.println("Opening...");
      openHand();
    }

    if (input == '1') {
      Serial.println("Closing...");
      closeHand();
    }

    if (input == '2') {
      Serial.println("Motioning Hand...");
      motionHand();
    }

    if (input == '3') {
      Serial.println("Motioning Fingers...");
      motionFingers();
    }

    if (input == '4') {
      Serial.println("Motioning Fingers...");
      motionFingersTwo();
    }
  }
}

void openHand() {
  for (position = 180; position > 0; position--) {
    thumb.write(position);
    pointer.write(position);
    middleRing.write(position);
    pinky.write(position);
    delay(15);
  }
}

void closeHand() {
  for (position = 0; position < 180; position++) {
    thumb.write(position);
    pointer.write(position);
    middleRing.write(position);
    pinky.write(position);
    delay(15);
  }
}

void motionHand() {
  if (position == 0) {
    closeHand();
    openHand();
  }

  if (position == 180) {
    openHand();
    closeHand();
  }
}

void motionFingers() {
  for (position = 180; position > 0; position--) {
    pointer.write(position);
    delay(15);
  }

  for (position = 180; position > 0; position--) {
    middleRing.write(position);
    delay(15);
  }
  
  for (position = 180; position > 0; position--) {
    pinky.write(position);
    delay(15);
  }
}

void motionFingersTwo() {
  for (position = 0; position < 180; position++) {
    pointer.write(position);
    delay(15);
  }

  for (position = 0; position < 180; position++) {
    middleRing.write(position);
    delay(15);
  }
  
  for (position = 0; position < 180; position++) {
    pinky.write(position);
    delay(15);
  }
}
