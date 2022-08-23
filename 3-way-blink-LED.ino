The goal is to turn on one LED at a time, while the other two is off. This will run in a loop interchangeably between 3 LED.

const int ledPin1 =  9;// the number of the LED pin
const int ledPin2 =  11;// the number of the LED pin
const int ledPin3 =  13;// the number of the LED pin

// Variables will change:
int ledState = HIGH;             // ledState used to set the LED
int ledState2 = LOW;
int ledState3 = LOW;

// Generally, you should use "unsigned long" for variables that hold time
// The value will quickly become too large for an int to store
unsigned long previousMillis = 0;        // will store last time LED was updated

// constants won't change:
const long interval = 1000;           // interval at which to blink (milliseconds)

void setup() {
  // set the digital pin as output:
  pinMode(ledPin1, OUTPUT);
  pinMode(ledPin2, OUTPUT);
  pinMode(ledPin3, OUTPUT);
}

void loop() {
  // here is where you'd put code that needs to be running all the time.

  // check to see if it's time to blink the LED; that is, if the difference
  // between the current time and last time you blinked the LED is bigger than
  // the interval at which you want to blink the LED.
  unsigned long currentMillis = millis();

  if (currentMillis - previousMillis >= interval) {
    // save the last time you blinked the LED
    previousMillis = currentMillis;

    // if the LED is off turn it on and vice-versa:
    if (ledState == HIGH && ledState2 == LOW && ledState3 == LOW) {
      ledState = LOW;
      ledState2 = HIGH;
      ledState3 = LOW;
    } else if (ledState == LOW && ledState2 == HIGH && ledState3 == LOW) {
      ledState = LOW;
      ledState2 = LOW;
      ledState3 = HIGH;
    } else {
      ledState = HIGH;
      ledState2 = LOW;
      ledState3 = LOW;
    }




    // set the LED with the ledState of the variable:
    digitalWrite(ledPin1, ledState);
    digitalWrite(ledPin2, ledState2);
    digitalWrite(ledPin3, ledState3);


  }
}
