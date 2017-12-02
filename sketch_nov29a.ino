#include <Adafruit_NeoPixel.h>
#ifdef __AVR__
  #include <avr/power.h>
#endif

#define PIN 6

int numPixels = 30;
float radius=M_PI*1.5;



Adafruit_NeoPixel strip = Adafruit_NeoPixel(numPixels, PIN, NEO_GRB + NEO_KHZ800);

int r=0;
int g=255;
int b=255;

//int switchPin =4;

void setup() {
  // put your setup code here, to run once:
  #if defined (__AVR_ATtiny85__)
    if (F_CPU == 16000000) clock_prescale_set(clock_div_1);
  #endif

  Serial.begin(9600);

  strip.begin();
  strip.show();
  strip.clear();

}

void loop() {
  // put your main code here, to run repeatedly:
//  if (digitalRead(switchPin)==true)
//    allOff();
//  else
  activate();

//  delay(500);
}

void activate(){
  for (int i=0; i < numPixels; i++)
    strip.setPixelColor(i,r,g,b);

  // Convert (-1, 1) to (0, 255)
  int brightness=127.5+127.5*sin(radius);
  strip.setBrightness(brightness);
  // Move the radius forward, you can try// out different number. The smaller the// step, the slower the light "breath".
  radius=radius+0.002;
  strip.show();

//  adjustBrightness();
  
}

//void allOff(){
//  strip.clear();
//  strip.show();
//}

//void adjustBrightness(){
//  strip.setBrightness(brightness);
//  radius=radius+0.002;
//  Serial.println(brightness);
//}


