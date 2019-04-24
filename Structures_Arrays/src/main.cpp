#include <Arduino.h>
#include <Adafruit_NeoPixel.h>

#define PIN 2
#define NUMPIXELS 16

Adafruit_NeoPixel pixels(NUMPIXELS, PIN, NEO_GRB + NEO_KHZ800);

struct Array
{
  int Red;
  int Green;
  int Blue;
}Pixel_Array[16];

void Set_Pixel_Array() {
  int Value_Red = 10;
  int Value_Green = 20;
  int Value_Blue = 30;

  for(int i = 0; i < 16; i++) {
    Pixel_Array[i].Red = Value_Red;
    Pixel_Array[i].Green = Value_Green;
    Pixel_Array[i].Blue = Value_Blue;
    
    Value_Red += 1;
    Value_Green += 5;
    Value_Blue += 10;
  }
}

void setup() {
  Serial.begin(9600);
  pixels.begin();
  pixels.clear();
  pixels.show();

  Set_Pixel_Array();
}

void loop() {
  // put your main code here, to run repeatedly:
}