#include <Arduino.h>
#include <Adafruit_NeoPixel.h>

#define PIN 2
#define NUMPIXELS 12

Adafruit_NeoPixel pixels(NUMPIXELS, PIN, NEO_GRB + NEO_KHZ800);

struct Array
{
  int Red;
  int Green;
  int Blue;
}Pixel_Array[12];

void Set_Pixel_Array() {
  int Value_Red = 10;
  int Value_Green = 0;
  int Value_Blue = 120;

  for(int i = 0; i < 12; i++) {
    Pixel_Array[i].Red = Value_Red;
    Pixel_Array[i].Green = Value_Green;
    Pixel_Array[i].Blue = Value_Blue;
    
    Value_Red += 10;
    //Value_Green += 5;
    Value_Blue -= 10;
  }
}

void Show_Pixel_Array() {
  for(int i = 0; i < 12; i++) {
    pixels.setPixelColor(i, pixels.Color(Pixel_Array[i].Red, Pixel_Array[i].Green, Pixel_Array[i].Blue));
    pixels.show();
  }
}

void Print_Data_Pixel_Array() {
  Serial.println(".:Informacion del Arreglo:.");
  for(int i = 0; i < 12; i++) {
    Serial.print("Pixel ");
    Serial.print(i+1);
    Serial.print(" ");
    Serial.print(Pixel_Array[i].Red);
    Serial.print(" ");
    Serial.print(Pixel_Array[i].Green);
    Serial.print(" ");
    Serial.println(Pixel_Array[i].Blue);
  }
}

void setup() {
  Serial.begin(9600);
  pixels.begin();
  pixels.clear();
  pixels.show();

  Set_Pixel_Array();
  Show_Pixel_Array();
  Print_Data_Pixel_Array();
}

void loop() {
  // put your main code here, to run repeatedly:
}