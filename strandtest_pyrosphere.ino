// strandtest_pyrosphere
// sfranzyshen
// idea fab labs chico
// 6/13/2017

#include <Adafruit_NeoPixel.h>
#ifdef __AVR__
  #include <avr/power.h>
#endif

#define NEO_PIN 3
#define NEO_PIXELS 385

long randNumber;

uint16_t Led_Map0[] = {0,1,2,3,4,5,6,7,8,9,10,11,12,13,14,16,21,25,30,34,38,43,47,51,56,61,65,70,74,79,84,89,94,99,103,108,114,119,124,129,134,139,144,149,154,159,164,170,175,180,184,189,194,199,204,209,214,219,224,229,234,238,242,247,252,256,261,266,270,275,280,284,288,293,298,303,308,313,318,323,328,334,338,344,349,354,359,364,370,375,380,384};
uint16_t Led_Map1[] = {252,247,318,256,180,175,170,242,313,364,323,261,184,103,99,94,89,164,238,308,359,384,370,328,266,189,108,34,30,25,21,84,159,234,303,354,380,375,334,270,194,114,38,7,6,16,14,79,154,229,298,349,344,338,275,199,119,43,8,1,5,4,13,74,149,224,293,288,284,280,204,124,47,9,2,0,3,12,70,144,219,214,209,129,51,10,11,65,139,134,56,61};
uint16_t Led_Map2[] = {238,303,308,242,164,234,229,298,354,359,313,247,170,89,159,154,149,224,293,349,380,384,364,318,252,175,94,21,84,79,74,70,144,219,288,344,375,370,323,256,180,99,25,16,14,13,12,65,139,214,284,338,334,328,261,184,103,30,6,5,4,3,11,61,134,209,280,275,270,266,189,108,4,7,1,0,2,10,56,129,204,199,194,114,38,8,9,51,124,119,43,47};
uint16_t Led_Map3[] = {293,288,349,298,224,219,214,284,344,380,354,303,229,149,144,139,134,209,280,338,375,384,359,308,238,234,180,74,70,65,61,56,129,204  ,275,334,370,364,313,242,164,159,79,13,12,11,10,51,124,199,270  ,328,323,318,247,170,89,84,14,4,3,2,9,47,119,194,266,261,256,252,175,94,21,16,5,0,1,8,43,114,189,184,180,99,25,6,7,38,108,103,30,34};
uint16_t Led_Map4[] = {280,275,338,284,209,204,199,270,334,375,344,288,214,134,129,124,119,194,266,328,370,384,380,349,293,219,139,61,56,51,47,43,114,189,261,323,364,359,354,298,224,144,65,11,10,9,8,38,108,184,256,318,313,308,303,229,149,70,12,3,2,1,7,34,103,180,252,247,242,238,234,154,74,13,4,0,5,6,30,99,175,170,164,159,79,14,16,25,94,89,84,21};
uint16_t Led_Map5[] = {266,261,328,270,194,189,184,256,323,370,334,275,199,119,114,108,103,180,252,318,364,384,375,338,280,204,124,47,43,38,34,30,99,175,247,313,359,380,344,284,209,129,51,9,8,7,6,25,94,170,242,308,354,349,288,214,134,56,10,2,1,5,16,21,89,164,238,303,298,293,219,139,61,11,3,0,4,14,84,159,234,229,224,144,65,12,13,79,154,149,70,74};
uint16_t Led_Map6[] = {74,70,149,154,79,13,12,65,144,224,229,234,159,84,14,4,0,3,11,61,139,219,293,298,303,238,164,89,21,16,5,1,2,10,56,134,214,288,349,354,308,242,170,94,25,6,7,8,9,51,129,209,284,344,380,359,313,247,175,99,30,34,38,43,47,124,204,280,338,375,384,364,318,252,180,103,108,114,119,199,275,334,370,323,256,184,189,194,270,328,261,266};
uint16_t Led_Map7[] = {21,84,89,94,25,16,14,79,159,164,170,175,99,30,6,5,0,4,13,74,154,234,238,242,247,252,180,103,34,7,1,2,3,12,70,149,229,303,308,313,318,256,184,108,38,8,9,10,11,65,144,224,298,354,359,364,323,261,189,114,43,47,51,56,61,139,219,293,349,380,384,370,328,266,194,119,124,129,134,214,288,344,375,334,270,199,204,209,284,338,275,280};
uint16_t Led_Map8[] = {34,30,103,108,38,7,6,25,99,180,184,189,114,43,8,1,0,5,16,21,94,175,252,256,261,266,194,119,47,9,2,3,4,14,84,89,170,247,318,323,328,270,199,124,51,10,11,12,13,79,159,164,242,313,364,370,334,275,204,129,56,61,65,70,74,180,234,238,308,359,384,375,338,280,209,134,139,144,149,229,303,354,380,344,284,214,219,224,298,349,288,293};
uint16_t Led_Map9[] = {47,43,119,124,51,9,8,38,114,194,199,204,129,56,10,2,0,1,7,4,108,189,266,270,275,280,209,134,61,11,3,4,5,6,30,103,184,261,328,334,338,284,214,139,65,12,13,14,16,25,99,180,256,323,370,375,344,288,219,144,70,74,79,84,21,94,175,252,318,364,384,380,349,293,224,149,154,159,89,170,247,313,359,354,298,229,234,164,242,308,303,238};
uint16_t Led_Map10[] = {61,56,134,139,65,11,10,51,129,209,214,219,144,70,12,3,0,2,9,47,124,204,280,284,288,293,224,149,74,13,4,5,1,8,43,119,199,275,338,344,349,298,229,154,79,14,16,6,7,38,114,194,270,334,375,380,354,303,234,159,84,21,25,30,34,108,189,266,328,370,384,359,308,238,164,89,94,99,103,184,261,323,364,313,242,170,175,180,256,318,247,252};
uint16_t Led_Map11[] = {384,380,375,370,364,359,354,349,344,338,334,328,323,318,313,308,303,298,293,288,284,280,275,270,266,261,256,252,247,242,238,234,229,224,219,214,209,204,199,194,189,184,180,175,170,164,159,154,149,144,139,134,129,124,119,114,108,103,99,94,89,84,79,74,70,65,61,56,51,47,43,38,34,30,25,21,16,14,13,12,11,10,9,8,7,6,5,4,3,2,1,0};

uint16_t *Led_Map;

uint16_t Ring0[] = {0};
uint16_t Ring1[] = {1,2,3,4,5};
uint16_t Ring2[] = {6,7,8,9,10,11,12,13,14,15};
uint16_t Ring3[] = {16,17,18,19,20,21,22,23,24,25,26,27,28,29,30};
uint16_t Ring4[] = {31,32,33,34,35,36,37,38,39,40,41,42,43,44,45};
uint16_t Ring5[] = {46,47,48,49,50,51,52,53,54,55,56,57,58,59,60};
uint16_t Ring6[] = {61,62,63,64,65,66,67,68,69,70,71,72,73,74,75};
uint16_t Ring7[] = {76,77,78,79,80,81,82,83,84,85};
uint16_t Ring8[] = {86,87,88,89,90};
uint16_t Ring9[] = {91};

Adafruit_NeoPixel strip = Adafruit_NeoPixel(NEO_PIXELS, NEO_PIN, NEO_GRB + NEO_KHZ800);

void setup() {
  // This is for Trinket 5V 16MHz, you can remove these three lines if you are not using a Trinket
  #if defined (__AVR_ATtiny85__)
    if (F_CPU == 16000000) clock_prescale_set(clock_div_1);
  #endif
  // End of trinket special code

  strip.begin();
  strip.show(); // Initialize all pixels to 'off'
  randomSeed(analogRead(0));
}

void loop() {

  randomMap(); // randomly set a mapping ...
  
  wipe(strip.Color(255, 255, 255), 50); // White
  wipe(strip.Color(0, 0, 0), 50); // Black
  trace(strip.Color(255, 255, 255), 50); // White
  chase(strip.Color(255, 255, 255), 50); // White
  pulse(strip.Color(255, 255, 255), 25); // White
  pulse(strip.Color(255, 255, 255), 50); // White
  pulse(strip.Color(255, 255, 255), 100); // White

  //rainbow(10);

}

// Fill the dots one after the other with a color
void wipe(uint32_t c, uint8_t wait) {
  //for(uint16_t i=0; i<strip.numPixels(); i++) {
  for(uint16_t i=0; i < (sizeof(Led_Map0)/sizeof(uint16_t)); i++) {
    strip.setPixelColor(Led_Map[i], c);
    strip.show();
    delay(wait);
  }
}

// Randomly set a mappping
void randomMap() {
    randNumber = random(11);

    switch (randNumber) {
      case 1:
        Led_Map = Led_Map1;
      break;
      case 2:
        Led_Map = Led_Map2;
      break;
      case 3:
        Led_Map = Led_Map3;
      break;
      case 4:
        Led_Map = Led_Map4;
      break;
      case 5:
        Led_Map = Led_Map5;
      break;
      case 6:
        Led_Map = Led_Map6;
      break;
      case 7:
        Led_Map = Led_Map7;
      break;
      case 8:
        Led_Map = Led_Map8;
      break;
      case 9:
        Led_Map = Led_Map9;
      break;
      case 10:
        Led_Map = Led_Map10;
      break;
      case 11:
        Led_Map = Led_Map11;
      break;
      
      default:
        Led_Map = Led_Map0;
      break;
    }  
}

// Show the dots one after the other with a color
void trace(uint32_t c, uint8_t wait) {
  for(uint16_t i=0; i < (sizeof(Led_Map0)/sizeof(uint16_t)); i++) {
    strip.setPixelColor(Led_Map[i], c);
    strip.show();
    delay(wait);
    strip.setPixelColor(Led_Map[i], strip.Color(0, 0, 0));
    strip.show();
  }
}

// Pulse the rings one after the other with a color
void pulse(uint32_t c, uint8_t wait) {
  
  for(uint16_t i=0; i < (sizeof(Ring0)/sizeof(uint16_t)); i++) {
    strip.setPixelColor(Led_Map[Ring0[i]], c);
  }
  
  strip.show(); // Ring0 On
  delay(wait);
  
  for(uint16_t i=0; i < (sizeof(Ring0)/sizeof(uint16_t)); i++) {
    strip.setPixelColor(Led_Map[Ring0[i]], strip.Color(0, 0, 0));
  }
  
  for(uint16_t i=0; i < (sizeof(Ring1)/sizeof(uint16_t)); i++) {
    strip.setPixelColor(Led_Map[Ring1[i]], c);
  }
  
  strip.show();// Ring0 Off & Ring1 On
  delay(wait);
  
  for(uint16_t i=0; i < (sizeof(Ring1)/sizeof(uint16_t)); i++) {
    strip.setPixelColor(Led_Map[Ring1[i]], strip.Color(0, 0, 0));
  }
  for(uint16_t i=0; i < (sizeof(Ring2)/sizeof(uint16_t)); i++) {
    strip.setPixelColor(Led_Map[Ring2[i]], c);
  }
  
  strip.show();// Ring1 Off & Ring2 On
  delay(wait);
  
  for(uint16_t i=0; i < (sizeof(Ring2)/sizeof(uint16_t)); i++) {
    strip.setPixelColor(Led_Map[Ring2[i]], strip.Color(0, 0, 0));
  }

  for(uint16_t i=0; i < (sizeof(Ring3)/sizeof(uint16_t)); i++) {
    strip.setPixelColor(Led_Map[Ring3[i]], c);
  }
  
  strip.show();// Ring2 Off & Ring3 On
  delay(wait);
  
  for(uint16_t i=0; i < (sizeof(Ring3)/sizeof(uint16_t)); i++) {
    strip.setPixelColor(Led_Map[Ring3[i]], strip.Color(0, 0, 0));
  }
  
  for(uint16_t i=0; i < (sizeof(Ring4)/sizeof(uint16_t)); i++) {
    strip.setPixelColor(Led_Map[Ring4[i]], c);
  }
  
  strip.show();// Ring3 Off & Ring4 On
  delay(wait);
  
  for(uint16_t i=0; i < (sizeof(Ring4)/sizeof(uint16_t)); i++) {
    strip.setPixelColor(Led_Map[Ring4[i]], strip.Color(0, 0, 0));
  }
  
  for(uint16_t i=0; i < (sizeof(Ring5)/sizeof(uint16_t)); i++) {
    strip.setPixelColor(Led_Map[Ring5[i]], c);
  }
  
  strip.show();// Ring4 Off & Ring5 On
  delay(wait);
  
  for(uint16_t i=0; i < (sizeof(Ring5)/sizeof(uint16_t)); i++) {
    strip.setPixelColor(Led_Map[Ring5[i]], strip.Color(0, 0, 0));
  }
  
  for(uint16_t i=0; i < (sizeof(Ring6)/sizeof(uint16_t)); i++) {
    strip.setPixelColor(Led_Map[Ring6[i]], c);
  }
  
  strip.show();// Ring5 Off & Ring6 On
  delay(wait);
  
  for(uint16_t i=0; i < (sizeof(Ring6)/sizeof(uint16_t)); i++) {
    strip.setPixelColor(Led_Map[Ring6[i]], strip.Color(0, 0, 0));
  }
  
  for(uint16_t i=0; i < (sizeof(Ring7)/sizeof(uint16_t)); i++) {
    strip.setPixelColor(Led_Map[Ring7[i]], c);
  }
  
  strip.show();// Ring6 Off & Ring7 On
  delay(wait);
  
  for(uint16_t i=0; i < (sizeof(Ring7)/sizeof(uint16_t)); i++) {
    strip.setPixelColor(Led_Map[Ring7[i]], strip.Color(0, 0, 0));
  }
  
  for(uint16_t i=0; i < (sizeof(Ring8)/sizeof(uint16_t)); i++) {
    strip.setPixelColor(Led_Map[Ring8[i]], c);
  }
  
  strip.show();// Ring7 Off & Ring8 On
  delay(wait);
  
  for(uint16_t i=0; i < (sizeof(Ring8)/sizeof(uint16_t)); i++) {
    strip.setPixelColor(Led_Map[Ring8[i]], strip.Color(0, 0, 0));
  }
  
  for(uint16_t i=0; i < (sizeof(Ring9)/sizeof(uint16_t)); i++) {
    strip.setPixelColor(Led_Map[Ring9[i]], c);
  }
  
  strip.show();// Ring8 Off & Ring9 On
  delay(wait);
  
  for(uint16_t i=0; i < (sizeof(Ring9)/sizeof(uint16_t)); i++) {
    strip.setPixelColor(Led_Map[Ring9[i]], strip.Color(0, 0, 0));
  }
 
  strip.show();// Ring9 Off
}

//Theatre-style crawling lights.
void chase(uint32_t c, uint8_t wait) {
  for (int j=0; j<10; j++) {  //do 10 cycles of chasing
    for (int q=0; q < 3; q++) {
      for (uint16_t i=0; i < (sizeof(Led_Map0)/sizeof(uint16_t)); i=i+3) {
        strip.setPixelColor(Led_Map[i+q], c);    //turn every third pixel on
      }
      strip.show();

      delay(wait);

      for (uint16_t i=0; i < (sizeof(Led_Map0)/sizeof(uint16_t)); i=i+3) {
        strip.setPixelColor(Led_Map[i+q], 0);        //turn every third pixel off
      }
    }
  }
}

// Slightly different, this makes the rainbow equally distributed throughout
void rainbow(uint8_t wait) {
  uint16_t i, j;

  for(j=0; j<256*5; j++) { // 5 cycles of all colors on wheel
    for(i=0; i < strip.numPixels(); i++) {
      strip.setPixelColor(i, Wheel(((i * 256 / strip.numPixels()) + j) & 255));
    }
    strip.show();
    delay(wait);
  }
  
  for(i=0; i < strip.numPixels(); i++) {
    strip.setPixelColor(i, strip.Color(0, 0, 0));
    strip.show();
    delay(wait);
  }
}

// Input a value 0 to 255 to get a color value.
// The colours are a transition r - g - b - back to r.
uint32_t Wheel(byte WheelPos) {
  WheelPos = 255 - WheelPos;
  if(WheelPos < 85) {
    return strip.Color(255 - WheelPos * 3, 0, WheelPos * 3);
  }
  if(WheelPos < 170) {
    WheelPos -= 85;
    return strip.Color(0, WheelPos * 3, 255 - WheelPos * 3);
  }
  WheelPos -= 170;
  return strip.Color(WheelPos * 3, 255 - WheelPos * 3, 0);
}

