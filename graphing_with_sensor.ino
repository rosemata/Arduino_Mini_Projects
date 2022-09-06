=

void setup() {
  // initialize the serial communication:
  Serial.begin(9600);
}

void loop() {
  // send the value of analog input 0:
//  Serial.print("A1: ");
  Serial.print(analogRead(A0));
  Serial.print(" ");
  Serial.println(analogRead(A1));
  delay(1000);
}
