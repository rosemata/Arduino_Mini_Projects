# Description - user will input date and time. It will confirm if date is valid, including leap years. Date will output to LCD if valid. And it will start ticking.


#include <LiquidCrystal.h>
#include <TimeLib.h>

LiquidCrystal lcd(12, 11, 5, 4, 3, 2);
char receivedChar[100];
bool statement;
int months, days, years, hours, mins, seconds = 0;
int columns = 16;
int rows = 2;
int monthEntered = 0;
int flag = 0;
bool leap = false;
int days_reset= 0;


void setup() {
  Serial.begin(9600);
  lcd.begin(16, 2);
  Serial.println("Enter date and time with format: ");
  Serial.println(" month  day year hour minutes seconds ");
  Serial.println(" 08     11  1999 02   06      21 ");
  Serial.println(" ");
}

void loop() {
  
  /* function to received input, parse inout, and verify date and time*/
  inputReceived();
  /* function to print date and time*/
  inputPrint(); 
  
  delay(1000);
  lcd.clear();
}


/* function to received input, parse inout, and verify date and time*/
void inputReceived() {
  flag = 0;
  if (Serial.available() > 0) {
    int input_length = Serial.readBytesUntil('\n', receivedChar, 100);


    /*
     * month  [0][1]
     * day    [3][4]
     * year   [6][7][8][9]
     * hour   [11][12]
     * mins   [14][15]
     * secs   [17][18]
     */
     

    /* Parsing month */
    if (receivedChar[0] - '0' == 1) { months += 10; }

    /* Parsing days */
    if (receivedChar[3] - '0' == 1) { days += 10; }
    if (receivedChar[3] - '0' == 2) { days += 20; }
    if (receivedChar[3] - '0' == 3) { days += 30; }

    /* Parsing years */
    if (receivedChar[6] - '0' > 0) { 
      years += ((receivedChar[6] - '0') * 1000);
      years += ((receivedChar[7] - '0') * 100);
      years += ((receivedChar[8] - '0') * 10);
    }

    /* Parsing hours */
    if (receivedChar[11] - '0' == 1) { hours += 10; }
    if (receivedChar[11] - '0' == 2) { hours += 20; }

    /* Parsing mins */
    if (receivedChar[14] - '0' > 0) { mins += ((receivedChar[14] - '0') * 10); }

    /* Parsing seconds */
    if (receivedChar[17] - '0' > 0) { seconds += ((receivedChar[17] - '0') * 10); }

    months += receivedChar[1] - '0';
    days += receivedChar[4] - '0';
    years += receivedChar[9] - '0';
    hours += receivedChar[12] - '0';
    mins += receivedChar[15] - '0';
    seconds += receivedChar[18] - '0';
    
    /* Check if months entered is in range 1-12 */
    if (months < 1 || months > 12) { 
       Serial.println("Month entered is invalid, try again ");
       reset();
    }

    /* Check if year entered is a leap */
    if (years % 4 == 0 && months == 2) {
      leap = true;
      int num = months % 4;
      days_reset = 28;
    }

    /* Check if year entered is in range 0-9999 */
    if (years < 0 || years > 9999) {
        Serial.println("Year entered is invalid, try again!");
        reset();
    }

    /* Check if days entered is valid depending on months */
    // 31 days
    if (months == 1 || months == 3 || months == 5 || months == 7 || months == 8 || months == 10 || months == 12 ) {
      days_reset = 31;
      if (days > 31) {
        Serial.println("Days entered is invalid, try again!");
        reset();
      } 
    }
    // 30 days
    if (months == 4 || months == 6 || months == 9 || months == 11) {
      days_reset = 30;
      if ((days > 30)) {
        Serial.println("Days entered is invalid, try again!");
        reset();
      } 
    }
    // 28 days
    if (months == 2) {
      days_reset = 28;
      if (days > 28 && leap == false) {
        Serial.println("Days entered is invalid, try again!");
        reset();
      }

      if (leap == true) {days_reset = 29;}
      if (days > 29 && leap == true) {
        days_reset = 29;
        Serial.println("Days entered is invalid, try again!");
        reset();
      }

    }

    /* Check if hour entered is valid*/
    if (hours < 0 || hours > 23) {
      Serial.println("Hour entered is invalid, try again!");
      reset();
    }

    /* Check if minutes entered is valid*/
    if (mins < 0 || mins > 59) {
      Serial.println("Minutes entered is invalid, try again!");
      reset();
    }

    /* Check if minutes entered is valid*/
    if (seconds < 0 || seconds > 59) {
      Serial.println("Seconds entered is invalid, try again!");
      reset();
    }

    if (flag == 0) { statement = true; }
  }

  
}

/* function to print date and time*/
void inputPrint() {
 if (statement == true) {

     lcd.setCursor(0, 0);
     lcd.print("Date: ");
     lcd.print(months);
     lcd.print("/");
     lcd.print(days);
     lcd.print("/");
     lcd.print(years);
     lcd.setCursor(0, 1);
     lcd.print("Time: ");
     lcd.print(hours);
     lcd.print(":");
     lcd.print(mins);
     lcd.print(":");
     lcd.print(seconds);

     Serial.print("Date: ");
     Serial.print(months);
     Serial.print("/");
     Serial.print(days);
     Serial.print("/");
     Serial.print(years);
     Serial.print("    Time: ");
     Serial.print(hours);
     Serial.print(":");
     Serial.print(mins);
     Serial.print(":");
     Serial.println(seconds);

//     12 31 2022 23 59 50
//     01 01 2023 00 00 01

     /* changing the time
      *  adding 1 to seconds
      *  if seconds > 59, reset to 0
      *  add 1 to minutes
      *  if minutes > 59, reset to 0
      *  add 1 to hours
      *  if hours > 23, reset to 0
      *  add 1 to days
      *  if days > days_reset+2, reset to 1
      *  add 1 to months
      *  if mothns > 12, reset to 1
      *  add 1 to years
      */
     seconds += 1;
     if (seconds == 60) { seconds = 0; mins += 1; }
     if (mins == 60) { mins = 0; hours += 1; }
     if (hours == 24) { hours = 0; days += 1; }
     if(days > days_reset) { days = 1; months+=1; }
     if(months == 13) { months = 1; years+=1; }
 }
 
}

/* reset values back to 0, called when input is not valid*/
void reset() {
  Serial.println(" ");
  leap = false;
  months = 0; days = 0; years = 0; hours = 0; mins = 0; seconds = 0; flag = 1;
}
