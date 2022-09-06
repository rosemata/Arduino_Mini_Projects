// When the first button is pressed, the display should display “Interrupt received! 
// Press button 2 to continue” When the user presses button 2 the display goes back to displaying "We have been waiting for X seconds", and restarts the time a 0 seconds.

#include <LiquidCrystal.h>

LiquidCrystal lcd(12, 11, 5, 4, 3, 2);

const int buttonPin = 7;
const int buttonPin2 = 6; 
int buttonState = 0;
int buttonState2 = 0;
int count = 0;
int flag = 0;

void setup() {
  Serial.begin(9600);
  lcd.begin(16, 2);
  pinMode(buttonPin, INPUT);
  pinMode(buttonPin2, INPUT);

  attachInterrupt(digitalPinToInterrupt(buttonPin), interrupt, CHANGE); 
  attachInterrupt(digitalPinToInterrupt(buttonPin2), reset, CHANGE);
  
}

void loop() {
  
  buttonState = digitalRead(buttonPin);
  buttonState2 = digitalRead(buttonPin2);

  // if button1 is off, and flag is zero
  // call helper function which will print the message in lcd
  if (buttonState == LOW && flag == 0) {
    helper();
    delay(1000);
  }
  

  // if button1 is on, then we call interrupt function
  if (buttonState == HIGH) {
    interrupt();
    
    lcd.setCursor(0, 0);
    lcd.print("Interrupt received! Press ");
    lcd.println("button 2 to continue");
    lcd.setCursor(0, 1);
    
    Serial.println("Interrupt received! Press button 2 to continue");
    
    buttonState = LOW;
  }

  //  if button 2 is called reset flag and count variable  
  if (buttonState2 == HIGH && flag == 1) {
    reset();
  }

}

void helper() {
    lcd.setCursor(0, 0);
    lcd.print("We have been waiting for ");
    lcd.setCursor(0, 1);
    lcd.print(count);
    lcd.println(" seconds");
    
    Serial.print("We have been waiting for ");
    Serial.print(count);
    Serial.println(" seconds");
    count++;
    
}

// called when the button1 is pressed
void interrupt()
{
  flag = 1;
}

// called when the button2 is pressed
void reset()
{
  if (flag == 1)
  {
    count = 0;
    flag = 0;
  }
}
