/*  Servo Arm Mover With Keypad And I2C LCD 16x2
 * 
 *  GitHub URL - https://github.com/narayanvyas/Arduino-Ultrasonic-Distance-Sensor-HC-SR04-With-Servo-Motor-And-LCD
 * 
 *  Developed By Web Dev Fusion
 *  URL - https://www.webdevfusion.com
 *  
 * Components
 * ----------
 *  - Arduino Uno
 *  - I2C LCD
 *  - Keypad (4*4)
 *  - Jumper Wires
 *  - Breadboard / PCB
 *  
 *  Libraries
 *  ---------
 *  - NewLiquidCrystal - https://bitbucket.org/fmalpartida/new-liquidcrystal/downloads/
 *  - Keypad - http://playground.arduino.cc/Code/Keypad
 *  
 */

#include <Wire.h>
#include <LCD.h>
#include <LiquidCrystal_I2C.h>
#include <Keypad.h>
#include <Servo.h>
 
LiquidCrystal_I2C  lcd(0x27,2,1,0,4,5,6,7); // 0x27 is the I2C bus address for an unmodified backpack
int servoPin = 10;       // Servo Pin
Servo Servo1;            // creating servo object

const byte ROWS = 4;     //four rows 
const byte COLS = 4;     //four columns

char hexaKeys[ROWS][COLS] = {    
  {'1','2','3','A'},             
  {'4','5','6','B'},
  {'7','8','9','C'},
  {'*','0','#','D'}
};

byte rowPins[ROWS] = {6, 7, 8, 9};    //connect to the row pinouts of the keypad
byte colPins[COLS] = {2, 3, 4, 5};    //connect to the column pinouts of the keypad
/* ------------------------------ */

Keypad customKeypad = Keypad( makeKeymap(hexaKeys), rowPins, colPins, ROWS, COLS);

void setup()
{
  Servo1.attach(servoPin);
  Serial.begin(9600);
  lcd.begin (16,2);
  lcd.setBacklightPin(3,POSITIVE);
  lcd.setBacklight(HIGH);
  lcd.home ();    // set cursor to 0,0
  lcd.print("Servo Robot");
  lcd.setCursor(0, 1);
}
 
void loop()
{
  char customKey = customKeypad.getKey();
  if (customKey != NO_KEY){
    switch(customKey) {
      case '1': 
        Serial.println("Hel");
        Servo1.write(20);
        lcd.setCursor(0,1);
        lcd.print("Arm Moved 20*");
        break;
      case '2': 
        Servo1.write(40);
        lcd.setCursor(0,1);
        lcd.print("Arm Moved 40*");
        break;
      case '3': 
        Servo1.write(60);
        lcd.setCursor(0,1);
        lcd.print("Arm Moved 60*");
        break; 
      case '4': 
        Servo1.write(80);
        lcd.setCursor(0,1);
        lcd.print("Arm Moved 80*");
        break; 
      case '5': 
        Servo1.write(100);
        lcd.setCursor(0,1);
        lcd.print("Arm Moved 100*");
        break; 
      case '6': 
        Servo1.write(120);
        lcd.setCursor(0,1);
        lcd.print("Arm Moved 120*");
        break; 
      case '7': 
        Servo1.write(140);
        lcd.setCursor(0,1);
        lcd.print("Arm Moved 140*");
        break; 
      case '8': 
        Servo1.write(160);
        lcd.setCursor(0,1);
        lcd.print("Arm Moved 160*");
        break; 
      case '9': 
        Servo1.write(180);
        lcd.setCursor(0,1);
        lcd.print("Arm Moved 180*");
        break; 
      case '0':
        Servo1.write(0);
        lcd.setCursor(0,1);
        lcd.print("Arm Moved 0*");
        break;
      default:
        lcd.setCursor(0,1);
        lcd.print("                ");
        lcd.setCursor(0,1);
        lcd.print("Wrong Key");
    }
  }
}
