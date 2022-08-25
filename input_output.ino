

// 1- ROSELLE MATA - 664124994
// 2- Lab 2 - Input and Output  
// 3- Description - One switch increment a 3-bit count, one switch decrement a  3-bit count, if total > 7, resets back to zero
// 4- I expected this lab to be difficult, but it was easier to understand than the lab 1
// 5- References - references: https://docs.arduino.cc/built-in-examples/digital/Button
// 6- Demo: Amir Lab 3:56 pm January 31, 2022
const int Pin1 =  8;
const int Pin2 =  9;
const int Pin3 =  10;
const int buttonPin = 2; 
const int buttonPin2 = 3;
int count = 0;

int buttonState = 0;
int buttonState2 = 0;

void setup() {
  pinMode(Pin1, OUTPUT);
  pinMode(Pin2, OUTPUT);
  pinMode(Pin3, OUTPUT);

  pinMode(buttonPin, INPUT);
  pinMode(buttonPin2, INPUT);
  Serial.begin(9600);

}

void loop() {
  int a = 0;
  int b = 0;
  int c = 0;
  
  buttonState = digitalRead(buttonPin);
  buttonState2 = digitalRead(buttonPin2);

  if (buttonState == HIGH) {
    delay(1000);
    count++;
  }

  if (buttonState2 == HIGH) {
    delay(1000);
    count--;
  }
  
  // 001
  if (count == 1) {
    digitalWrite(Pin1, HIGH);
    digitalWrite(Pin2, LOW);
    digitalWrite(Pin3, LOW);
  }
  // 010
  else if (count == 2) {
    digitalWrite(Pin1, LOW);
    digitalWrite(Pin2, HIGH);
    digitalWrite(Pin3, LOW);
  }
  // 011
  else if (count == 3) {
    digitalWrite(Pin1, HIGH);
    digitalWrite(Pin2, HIGH);
    digitalWrite(Pin3, LOW);
  }
  // 100
  else if (count == 4) {
    digitalWrite(Pin1, LOW);
    digitalWrite(Pin2, LOW);
    digitalWrite(Pin3, HIGH);
  }
  // 101
  else if (count == 5) {
    digitalWrite(Pin1, HIGH);
    digitalWrite(Pin2, LOW);
    digitalWrite(Pin3, HIGH);
  }
  // 110
  else if (count == 6) {
    digitalWrite(Pin1, LOW);
    digitalWrite(Pin2, HIGH);
    digitalWrite(Pin3, HIGH);
  }
  
  //111
  else if (count == 7) {
    digitalWrite(Pin1, HIGH);
    digitalWrite(Pin2, HIGH);
    digitalWrite(Pin3, HIGH);
  }

  else {
    count = 0; 
    digitalWrite(Pin1, LOW);
    digitalWrite(Pin2, LOW);
    digitalWrite(Pin3, LOW);
  }

}
