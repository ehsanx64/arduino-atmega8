//#if NEOPIXEL_DEFINED
#include <Arduino.h>
#include <Adafruit_NeoPixel.h>
#include "neopixel.h"
//#define RGB_DELAY 15
//#define LED_PIN 12
//#define LED_COUNT 1

//#if NEOPIXEL_WS2812B_ENABLED
//Adafruit_NeoPixel rgbLed(LED_COUNT, LED_PIN, NEO_GRB + NEO_KHZ800);
//#endif

Adafruit_NeoPixel neoPix(NEOPIX_COUNT, NEOPIX_PIN, NEO_GRB + NEO_KHZ800);
void NeoPixel_Setup() {
//#if NEOPIXEL_WS2812B_ENABLED
//    rgbLed.begin();
//    rgbLed.setBrightness(8);
//    rgbLed.clear();
//    rgbLed.show();
//#endif
 pinMode(NEOPIX_PIN, OUTPUT);
    neoPix.begin();
    neoPix.setBrightness(39);
//    neoPix.clear();
//    neoPix.show();

delay(500);
neoPix.setPixelColor(0, 255, 0, 0);
neoPix.setPixelColor(1, 0, 255, 0);
neoPix.setPixelColor(2, 0, 0, 255);
neoPix.setPixelColor(3, 255, 255, 255);
neoPix.setPixelColor(4, 255, 255, 0);
neoPix.setPixelColor(5, 255, 0, 255);
neoPix.setPixelColor(6, 0, 255, 255);
neoPix.setPixelColor(7, 64, 0, 0);
neoPix.show();
//for (int i = 0; i < 254; i++) {
//    neoPix.setPixelColor(7, i, 0, 0);
//    neoPix.show();
//    delay(8);
//}
//for (int i = 254; i > 0; i--) {
//    neoPix.setPixelColor(7, i, 0, 0);
//    neoPix.show();
//    delay(8);
//}

//    set_neopixel(5);
//neopix_loop();
}

void NeoPixel_Loop() {
}

//#if NEOPIXEL_WS2812B_ENABLED
//void rgb_off() {
//    rgbLed.clear();
//    rgbLed.show();
//}
//
//void rgb_purple() {
//    rgbLed.setPixelColor(0, 255, 0, 255);
//    rgbLed.show();
//}
//
//void rgb_green() {
//    rgbLed.setPixelColor(0, 0, 255, 0);
//    rgbLed.show();
//}
//
//void rgb_blue() {
//    rgbLed.setPixelColor(0, 0, 0, 255);
//    rgbLed.show();
//}
//
//void rgb_red() {
//    rgbLed.setPixelColor(0, 255, 0, 0);
//    rgbLed.show();
//}
//
//void rgb_loop() {
//    rgbLed.clear();
//    rgbLed.show();
//  for(int i=0; i<255; i++) {
//    rgbLed.setPixelColor(0, 0, 0, i);
//    rgbLed.show();
//    delay(RGB_DELAY);
//  }
//
//  for(int i=0; i<255; i++) {
//    rgbLed.setPixelColor(0, i, 0, 255);
//    rgbLed.show();
//    delay(RGB_DELAY);
//  }
//
//  for(int i=0; i<255; i++) {
//    rgbLed.setPixelColor(0, 255, i, 255);
//    rgbLed.show();
//    delay(RGB_DELAY);
//  }
//
//  for(int i=255; i>0; i--) {
//    rgbLed.setPixelColor(0, 255, 255, i);
//    rgbLed.show();
//    delay(RGB_DELAY);
//  }
//
//  for(int i=255; i>0; i--) {
//    rgbLed.setPixelColor(0, i, 255, 0);
//    rgbLed.show();
//    delay(RGB_DELAY);
//  }
//
//  for(int i=255; i>0; i--) {
//    rgbLed.setPixelColor(0, 0, i, 0);
//    rgbLed.show();
//    delay(RGB_DELAY);
//  }
//}
//#endif

#define NEOPIX_UP_DELAY 100
#define NEOPIX_DOWN_DELAY 200
void neopix_loop() {
    neoPix.clear();
    neoPix.show();
    
    for (int c = 0; c < 3; c++) {
        for (int i = 0; i < NEOPIX_COUNT; i++) {
            switch (c) {
                case 0:
                    neoPix.setPixelColor(i, 0, 255, 0);
                    break;
                case 1:
                    neoPix.setPixelColor(i, 255, 0, 0);
                    break;
                case 2:
                    neoPix.setPixelColor(i, 0, 0, 255);
                    break;
                 default:
                    break;
            }
            
            neoPix.show();
            delay(NEOPIX_UP_DELAY);
        }

        for (int i = NEOPIX_COUNT; i >= 0; i--) {
            neoPix.setPixelColor(i, 0, 0, 0);
            neoPix.show();
            delay(NEOPIX_DOWN_DELAY);
        }
    }
    
}

void set_neopixel(int val) {
       for (int i = 0; i < 8; i++) {
            if (i <= val) {
                neoPix.setPixelColor(i, 0, 255, 10);            
            } else {
                neoPix.setPixelColor(i, 0, 0, 0);            
            }
            neoPix.show();
       }
}

void set_brightness(int val) {
//    neoPix.clear();
    if (val > 0) {
    neoPix.setBrightness(val);
    neoPix.show();
    }
    
}
//#endif
