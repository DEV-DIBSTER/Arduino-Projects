/*
SparkFun Inventor’s Kit
Circuit 1C-Photoresistor

Use a photoresistor to monitor how bright a room is, and turn an LED on when it gets dark.

This sketch was written by SparkFun Electronics, with lots of help from the Arduino community.
This code is completely free for any use.

View circuit diagram and instructions at: https://learn.sparkfun.com/tutorials/sparkfun-inventors-kit-experiment-guide---v40
Download drawings and code at: https://github.com/sparkfun/SIK-Guide-Code
*/

const int photoresistor = A0;              //this variable will hold a value based on the position of the knob
int threshold = 750;  
#include <Wire.h>
#include <Adafruit_GFX.h>
#include "Adafruit_LEDBackpack.h"

Adafruit_BicolorMatrix matrix = Adafruit_BicolorMatrix();//if the photoresistor reading is below this value the the light will turn on

void setup()
{
  Serial.begin(9600);
  Serial.println("8x8 LED Matrix Test");
  
  matrix.begin(0x70);//start a serial connection with the computer
  pinMode(photoresistor, INPUT);             //set pin 13 as an output that can be set to HIGH or LOW
}
static const uint8_t PROGMEM
  smile_bmp[] =
  { B00111100,
    B01000010,
    B10100101,
    B10000001,
    B10100101,
    B10011001,
    B01000010,
    B00111100 },
  neutral_bmp[] =
  { B00111100,
    B01000010,
    B10100101,
    B10000001,
    B10111101,
    B10000001,
    B01000010,
    B00111100 },
  frown_bmp[] =
  { B00111100,
    B01000010,
    B10100101,
    B10000001,
    B10011001,
    B10100101,
    B01000010,
    B00111100 };

void loop()
{
  //read the position of the knob
  int photoresistor = analogRead(A0);   //set photoresistor to a number between 0 and 1023 based on how far the knob is turned    //print the value of photoresistor in the serial monitor on the computer

  //if the photoresistor value is below the threshold turn the light on, otherwise turn it off
  if (photoresistor < 300){
    matrix.clear();
    matrix.drawBitmap(0, 0, frown_bmp, 8, 8, LED_RED);
    Serial.println("Lights Off"); 
    matrix.writeDisplay();
    delay(500);
      
           // Turn on the LED  
  } else{
    matrix.clear();
    matrix.drawBitmap(0, 0, smile_bmp, 8, 8, LED_GREEN);
    Serial.println("Lights Off"); 
    matrix.writeDisplay();
    Serial.println("Lights on"); 
            // Turn off the LED
  }

  delay(100);                       //short delay to make the printout easier to read
}
