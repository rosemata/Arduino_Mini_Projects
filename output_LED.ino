// 1- Roselle Mata - 664124994
// 2- Lab 3 - Scrolling Output
// 3- The code is supposed to display my first name and last name in row 1, and a scrolling output of my favorite qoute in row 2
// 4- I expected the lab to be easy, but simple mistakes can make everything not work.
// 5- References - I found inspiration and code snippets at https://docs.arduino.cc/learn/electronics/lcd-displays specifically in code scroll example
// 6- Demo: https://youtu.be/Bc3dZp7lrvY

// include the library code:
#include <LiquidCrystal.h>

// initialize the library by associating any needed LCD interface pin
// with the arduino pin number it is connected to

const int rs = 12, en = 11, d4 = 5, d5 = 4, d6 = 3, d7 = 2;

LiquidCrystal lcd(rs, en, d4, d5, d6, d7);

char const *qoute = "Try and try until you succeed.  ";

int line = 1; // line number to show your string 0 or 1
int iCursor = 0;
void setup() {
  lcd.begin(16,2); // set up column and row
  lcd.setCursor (1,0); // set cursor to column 1 and row 0
  lcd.print("Roselle T Mata");
}

void loop() {
  scrolling_display(); // function generate for scrolling text
  delay(550);
}

void scrolling_display() {
  int size = strlen(qoute); // LEN OF STRING
  
  if(iCursor == (size)-1) { // RESET
    iCursor = 0;
  }

  lcd.setCursor(0, 1); // set cursor to column 0 and row 1
  
  if (iCursor < size - 16) { // print the whole sentence
    for (int i = iCursor; i < iCursor + 16; i++) {
      lcd.print(qoute[i]); // print letter by letter
    }
  }

  else {
    //  code takes care of printing characters
    for (int i = iCursor; i < (size-1); i++) {
      lcd.print(qoute[i]);
    }

    // remaining characters are printed
    for (int i = 0; i <= 16 - (size-iCursor); i++) {
      lcd.print(qoute[i]);
    }
  }

  iCursor++;
}
