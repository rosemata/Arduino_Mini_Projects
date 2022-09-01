Description - the code is supposed to take the input of photoresistor, depending on this the 4 leds will light up, partially light up, or light down. It'll take the input of the potentiometer, and depending on this, when we adjust the buzzer, it will have high or low pitch sound.


#include <LiquidCrystal.h>
const int Pin =  5;      // the number of the LED pin
const int Pin1 =  4;      // the number of the LED pin
const int Pin2 =  3;      // the number of the LED pin
const int Pin3 =  2;      // the number of the LED pin

int lightSensor = A0; // our photoresistor is connected to pin A0
int analogValue = 0; // store the input of a0
int buzz = 8; // our buzzer is connected to pin 8
int pot = A1; // potentiometer is connected to pin a1
int val; // store the input of potentionmeter

void setup() {
  pinMode(Pin, OUTPUT);
  pinMode(Pin1, OUTPUT);
  pinMode(Pin2, OUTPUT);
  pinMode(Pin3, OUTPUT);

  pinMode(buzz,OUTPUT);
  pinMode(pot,OUTPUT);
  Serial.begin(9600);
  
}

void loop()
{
//  store input value of photoresistor
  analogValue = analogRead(lightSensor);
  Serial.println(analogRead(lightSensor));

//  all light up
  if(analogValue <= 70)
  {
    digitalWrite(Pin, HIGH);
    digitalWrite(Pin1, HIGH);
    digitalWrite(Pin2, HIGH);
    digitalWrite(Pin3, HIGH);

    
  }
//  turn one led off
  else if(analogValue <= 100)
  {
    digitalWrite(Pin, HIGH);
    digitalWrite(Pin1, HIGH);
    digitalWrite(Pin2, HIGH);
    digitalWrite(Pin3, LOW);
  }

//  turn two led off
  else if(analogValue <= 200)
  {
    digitalWrite(Pin, HIGH);
    digitalWrite(Pin1, HIGH);
    digitalWrite(Pin2, LOW);
    digitalWrite(Pin3, LOW);
  }

//  turn three led off
  else if(analogValue <= 300)
  {
    digitalWrite(Pin, HIGH);
    digitalWrite(Pin1, LOW);
    digitalWrite(Pin2, LOW);
    digitalWrite(Pin3, LOW);
  }


//  if very bright turn all off
  else
  {
    digitalWrite(Pin, LOW);
    digitalWrite(Pin1, LOW);
    digitalWrite(Pin2, LOW);
    digitalWrite(Pin3, LOW);
  }


  // reads the input of potentiometer, and pass it to buzzer
  val = analogRead(pot);
  Serial.println(val); 
  digitalWrite(buzz,HIGH);
  delayMicroseconds(val);
  digitalWrite(buzz,LOW);
  delayMicroseconds(val);



}
