
#include <Servo.h>

Servo thumb;
Servo pointer;
Servo middleRing;
Servo pinky;

int position = 0;
int thumbPin = 8;
int pointerPin = 9;
int middleRingPin = 10;
int pinkyPin = 11;

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
  Serial.println("0 = Reset");
  Serial.println("1 = Open");
  Serial.println("2 = Close");
  Serial.println("3 = Motion Hand");
  Serial.println("4 = Motion Fingers");
  Serial.println("5 = Thumbs Up");
  Serial.println("6 = Number 1");
}

void loop() {
  char input;
  
  if (Serial.available() > 0) {
    input = Serial.read();

    if (input == '0') {
      Serial.println("Resetting...");
      reset();
    }

    if (input == '1') {
      Serial.println("Opening...");
      openHand();
    }

    if (input == '2') {
      Serial.println("Closing...");
      closeHand();
    }

    if (input == '3') {
      Serial.println("Motioning Hand...");
      motionHand();
    }

    if (input == '4') {
      Serial.println("Motioning Fings...");
      motionFingers();
    }    
    
    if (input == '5') {
      Serial.println("Thumbs up...");
      thumbsUp();
    }

    if (input == '6') {
      Serial.println("Number 1...");
      numberOne();
    }    
  }
}

void reset() {
  thumb.write(0);
  pointer.write(0);
  middleRing.write(0);
  pinky.write(0);
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
  reset();
  for(int x = 0; x < 3; x++) {
    for (position = 0; position < 90; position++) {
      pointer.write(position);
      middleRing.write(position);
      pinky.write(position);
    }
    
    for (position = 90; position > 0; position--) {
      pointer.write(position);
      middleRing.write(position);
      pinky.write(position);
    }
  }
}

void thumbsUp() {
  thumb.write(180);
  pointer.write(0);
  middleRing.write(0);
  pinky.write(0);
}

void numberOne() {
  thumb.write(180);
  pointer.write(0);
  middleRing.write(180);
  pinky.write(180);
}
