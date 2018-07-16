
/*setup for LCD*/

#include <Wire.h>
#include "rgb_lcd.h"

rgb_lcd lcd;

/*temperature data variables*/

int t;
String temp;

/* NeoPixel strup setup*/
#include <Adafruit_NeoPixel.h>

#define PIN 3 //digital pin output

#define NUM_LEDS 8  // numbers of led in the strip

#define BRIGHTNESS 50 //set the brightness to 50

Adafruit_NeoPixel strip = Adafruit_NeoPixel(NUM_LEDS, PIN, NEO_GRB + NEO_KHZ800);

int startingValue; // starting value of the noise level input


int refresh;

void setup() {
  // set up the LCD's number of columns and rows:
  lcd.begin(16, 2);
  // initialize the serial communications:
  Serial.begin(9600);
  t = 0;

  strip.begin();
  strip.show();//initial all pixels to 'off'

  startingValue = 100;
  int refresh = 0; //refresh
}

void loop()
{
  if (refresh == 10) {
  refresh = 0;
 }
  // when characters arrive over the serial port...
 /* if (Serial.available())
  {
    // wait a bit for the entire message to arrive
    delay(100);
    // clear the screen
    lcd.clear();
    // read all the available characters
    while (Serial.available() > 0)
    {
      // display each character to the LCD
      lcd.write(Serial.read());
    }
  }*/
  t = analogRead(A2);
  Serial.println(t);
  //String space = "  ";
  // Serial.print(space);
  if (refresh == 0) {
    lcd.clear();
    temp = String(t);
    // Serial.println(temp);
    lcd.print("Noise Level:" + temp);
    lcd.setCursor(0,1);
    lcd.print("SHUT UP!");
    if (t <= 350) {
      lcd.setRGB(0, 255, 0);
    } else if (t > 350 && t <= 450) {
      lcd.setRGB(255, 255, 0);
    } else if (t > 450) {
      lcd.setRGB(255, 0, 0);
    }
lcd.display();
    setLEDs(t);
}
  refresh = refresh+1;
  
  delay(30);


}

/*********************************************************************************************************
  END FILE
*********************************************************************************************************/
