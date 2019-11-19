
 /*
 * Original sourse: https://playground.arduino.cc/Code/Keypad
 * This is the Arduino code for 4x4 keypad.
 * watch the video for details and demo http://youtu.be/qIDzzG2LUtg
 *  * 
 * Written by Ahmad Nejrabi for Robojax Video channel www.Robojax.com
 * Date: Dec 18, 2017, in Ajax, Ontario, Canada
 * Permission granted to share this code given that this
 * note is kept with the code.
 * Disclaimer: this code is "AS IS" and for educational purpose only.
 * this code has been downloaded from http://robojax.com/learn/arduino/
 * 
 */
/* @file HelloKeypad.pde
|| @version 1.0
|| @author Alexander Brevig
|| @contact alexanderbrevig@gmail.com
||
|| @description
|| | Demonstrates the simplest use of the matrix Keypad library.
|| #
*/
#include <Keypad.h>
#include <LiquidCrystal.h>

// initialize the library with the numbers of the interface pins
LiquidCrystal lcd(12, 11, 5, 4, 3, 2);

String input = "";
String password = "12";
boolean authorized = false;
const byte ROWS = 4; //four rows
const byte COLS = 4; //three columns
char keys[ROWS][COLS] = {
  {'1','2','3','A'},
  {'4','5','6','B'},
  {'7','8','9','C'},
  {'*','0','#','D'}
};



byte rowPins[ROWS] = {13, 10, 9, 8}; //connect to the row pinouts of the keypad
byte colPins[COLS] = {7,6,1,0}; //connect to the column pinouts of the keypad

Keypad keypad = Keypad( makeKeymap(keys), rowPins, colPins, ROWS, COLS );



void authorize(){
   lcd.clear();
   lcd.setCursor(0,0);
   lcd.print("Authorized!");
   delay(5000);
   reset();
}

void reset(){
  lcd.clear();
  input = "";
  authorized = false;
   lcd.clear();
   lcd.setCursor(0,0);
   lcd.print("Insert Password");
   lcd.setCursor(0,1);
   lcd.blink();  
}

void backspace(){
  
}


void enter(){
  if(input == password){
    authorize();
    }else{
      lcd.clear();
      lcd.setCursor(0,0);
      lcd.print("Wrong password!");
      delay(5000);
      reset();
      }
 }


void setup(){
  Serial.begin(9600);
   lcd.begin(16, 2);
   lcd.print("Comp Org Project");
   delay(1000);
   lcd.clear();
   lcd.setCursor(0,0);
   lcd.print("By Alex, Nico");
   lcd.setCursor(0,1);
   lcd.print("and Pedro");
   delay(2000);
    reset();
}





  
void loop(){
  char key = keypad.getKey();
  /*
    // just print the pressed key
      if (key =='A'){
    Serial.println("Change Password");
  }

    if (key =='#'){
    Serial.println("Backspace");
  }

  
    if (key =='D'){
    Serial.println("Delete");
  }
  */ 
   if (key){
    if(key == '*'){
      enter();
    }else{
          Serial.println(key);
    input.concat(key);
    lcd.print(key);
      }
    

  } 
  
  // this checkes if 4 is pressed, then do something. Here  we print the text but you can control something.

}
  
