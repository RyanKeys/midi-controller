#include <Arduino.h>
#include "Adafruit_Keypad.h"




const int pot1 = A0;
const int pot2 = A1;
const int pot3 = A2;
const int pot4 = A3;
const int pot5 = A4;
const int pot6 = A5;
const int pot7 = A6;
const int pot8 = A7;




//initialize an instance of class NewKeypad
const byte ROWS = 4; // rows
const byte COLS = 4; // columns
//define the symbols on the buttons of the keypads
char keys[ROWS][COLS] = {
  {'1','2','3','A'},
  {'4','5','6','B'},
  {'7','8','9','C'},
  {'*','0','#','D'}
};
byte rowPins[ROWS] = {9,8,7,6}; //connect to the row pinouts of the keypad
byte colPins[COLS] = {2,3,4,5}; //connect to the column pinouts of the keypad
Adafruit_Keypad customKeypad = Adafruit_Keypad( makeKeymap(keys), rowPins, colPins, ROWS, COLS);



void setup() {
  Serial.begin(31250);
  customKeypad.begin();
  //Inits push buttons


}

void noteOn(int cmd, int pitch, int velocity) {
  Serial.write(cmd);
  Serial.write(pitch);
  Serial.write(velocity);
}

void loop() {
  customKeypad.tick();

  while(customKeypad.available()){
    keypadEvent e = customKeypad.read();
    if((char)e.bit.KEY == int(65)) noteOn(0x90, 0x1E, 0x45);
    noteOn(0x90, 0x1E, 0x00);

  }
  
  int potValue1 = analogRead(pot1);
  int potMIDI1 = map(potValue1,0,1023,0,127);
  
  int potValue2 = analogRead(pot2);
  int potMIDI2 = map(potValue2,0,1023,0,127);
  
  int potValue3 = analogRead(pot3);
  int potMIDI3 = map(potValue3,0,1023,0,127);
  
  int potValue4 = analogRead(pot4);
  int potMIDI4 = map(potValue4,0,1023,0,127);
  
  int potValue5 = analogRead(pot5);
  int potMIDI5 = map(potValue5,0,1023,0,127);
  
  int potValue6 = analogRead(pot6);
  int potMIDI6 = map(potValue6,0,1023,0,127);

  int potValue7 = analogRead(pot7);
  int potMIDI7 = map(potValue7,0,1023,0,127);
  
  int potValue8 = analogRead(pot8);
  int potMIDI8 = map(potValue8,0,1023,0,127);
  

}
