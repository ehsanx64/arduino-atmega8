/*
 * ATMEGA8 Development using Arduino Framework
 */
#include <Adafruit_NeoPixel.h>
#include <Wire.h>

/*
 * Features
 * 
 * Comment/uncomment each header to enable/disable it
 */
//#include "tone.h"


#define KNOB A0
#define YKNOB A1

#define LED_PIN 12
#define LED_COUNT 1
#define RGB_DELAY 15
Adafruit_NeoPixel rgbLed(LED_COUNT, LED_PIN, NEO_GRB + NEO_KHZ800);
#define RED LED_BUILTIN
#define GREEN 11

#define NEOPIX_PIN 8
#define NEOPIX_COUNT 8
Adafruit_NeoPixel neoPix(NEOPIX_COUNT, NEOPIX_PIN, NEO_GRB + NEO_KHZ800);

int val = 0;
int yval = 0;

void setup() {    
    Wire.begin(8);
    Wire.setClock(100000);
    Wire.onReceive(receiveEvent);
    Serial.begin(9600);
    pinMode(RED, OUTPUT);
    pinMode(GREEN, OUTPUT);
    pinMode(KNOB, INPUT);
    pinMode(YKNOB, INPUT);
    rgbLed.begin();
    rgbLed.setBrightness(8); 
        neoPix.begin();
    neoPix.setBrightness(8); 
    Serial.println("Listening...");

     
     rgbLed.clear();
            rgbLed.show();
            off(GREEN);
            off(RED);

#if TONE_ENABLED
    Tone_Setup();
#endif
}

void loop() {
      val = analogRead(KNOB);  // read the input pin
      yval = analogRead(YKNOB);
//      Serial.print(" KNOB: ");
//      Serial.println(val / 10);          // debug valu
//      Serial.print("YKNOB: ");
//      Serial.println(yval / 100);          // debug valu
//      delay(500);
//neopix_loop();


      int b = (int) ((255 * ((val + 10) / 10)) / 100);
//      Serial.print("Brightness: ");
//      Serial.println(b);
        neoPix.setBrightness(22);
       for (int i = 0; i < 8; i++) {
            if (i < ((int) yval / 100)) {
                neoPix.setPixelColor(i, 0, 255, b);            
            } else {
                neoPix.setPixelColor(i, 0, 0, 0);            
            }
            neoPix.show();
       }
delay(50);

}

void on(int pin) {
    digitalWrite(pin, HIGH);
}

void off(int pin) {
    digitalWrite(pin, LOW);
}
void d() {
    delay(250);
}
void demo1() {
    all_off();
    d();
    
    on(GREEN);
    d();
    
    off(GREEN);
    on(RED);
    d();
}

void red_blink() {
    all_off();
    on(RED);
    delay(100);
    off(RED);
    delay(200);
}

void super_blink(int pin) {
    for (int i = 0; i < 2; i++) {
        on(pin);
        delay(25);
        off(pin);
        delay(100);
    }
}
void all_off() {
    digitalWrite(LED_BUILTIN, LOW);
    digitalWrite(GREEN, LOW);
}

void all_on() {
    digitalWrite(LED_BUILTIN, HIGH);
    digitalWrite(GREEN, HIGH);
}
void red_green_blink() {
    all_off();
    super_blink(RED);
    delay(100);
    super_blink(GREEN);
    delay(200);
}

void rgb_green() {
    rgbLed.setPixelColor(0, 0, 255, 0);
    rgbLed.show();
}

void rgb_blue() {
    rgbLed.setPixelColor(0, 0, 0, 255);
    rgbLed.show();
}

void rgb_red() {
    rgbLed.setPixelColor(0, 255, 0, 0);
    rgbLed.show();
}

void rgb_purple() {
    rgbLed.setPixelColor(0, 255, 0, 255);
    rgbLed.show();
}

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

void rgb_loop() {
    rgbLed.clear();
    rgbLed.show();
  for(int i=0; i<255; i++) {
    rgbLed.setPixelColor(0, 0, 0, i);
    rgbLed.show();
    delay(RGB_DELAY);
  }

  for(int i=0; i<255; i++) {
    rgbLed.setPixelColor(0, i, 0, 255);
    rgbLed.show();
    delay(RGB_DELAY);
  }

  for(int i=0; i<255; i++) {
    rgbLed.setPixelColor(0, 255, i, 255);
    rgbLed.show();
    delay(RGB_DELAY);
  }

  for(int i=255; i>0; i--) {
    rgbLed.setPixelColor(0, 255, 255, i);
    rgbLed.show();
    delay(RGB_DELAY);
  }

  for(int i=255; i>0; i--) {
    rgbLed.setPixelColor(0, i, 255, 0);
    rgbLed.show();
    delay(RGB_DELAY);
  }

  for(int i=255; i>0; i--) {
    rgbLed.setPixelColor(0, 0, i, 0);
    rgbLed.show();
    delay(RGB_DELAY);
  }
}

void receiveEvent(int howMany) {
    if (howMany > 1) {
        Serial.print("Input bytes: ");
        Serial.println(howMany);
        for (int i = 0; i < howMany; i++) {
            int c = Wire.read();
            Serial.print(c);
            if (i < (howMany - 1)) {
                Serial.print(", ");    
            }
        }    
    } else {
        int c = Wire.read();
        Serial.print("Command: ");
        Serial.println(c);        
        switch (c) {
        case 50:
            Serial.println("RED ON");
            on(RED);
            break;

        case 51:
            Serial.println("RED OFF");
            off(RED);
            break;

        case 52:
            Serial.println("GREEN ON");
            on(GREEN);
            break;

        case 53:
            Serial.println("GREEN OFF");
            off(GREEN);
            break;
            
        case 60:
            Serial.println("RGB OFF");
            rgbLed.clear();
            rgbLed.show();
            break;
            
        case 61:
            Serial.println("RGB GREEN");
            rgb_green();
            break;
            
        case 62:
            Serial.println("RGB RED");
            rgb_red();
            break;
            
        case 63:
            Serial.println("RGB BLUE");
            rgb_blue();
            break;
            
        case 64:
            Serial.println("RGB PURPLE");
            rgb_purple();
            break;

        case 65:
            Serial.println("RGB LOOP");
            rgb_loop();
            break;

//        case 70:
//            Serial.println("TONE");
//            play_tone();
//            break;

        default:
            Serial.println("UKNOWN");
            break;
        }
    }
    
//      while (1 < Wire.available()) { // loop through all but the last
//        char c = Wire.read(); // receive byte as a character
//        Serial.print(c);         // print the character
//      }
//      int x = Wire.read();    // receive byte as an integer
//      Serial.println(x);         // print the integer
}
