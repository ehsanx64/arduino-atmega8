/*
 * ATMEGA8 Development using Arduino Framework
 */
#include <Wire.h>
/*
 * Features
 * 
 * Comment/uncomment each header to enable/disable it
 */
//#include "tone.h"
#include "neopixel.h"

#define KNOB A0
#define YKNOB A1

#define RED LED_BUILTIN
#define GREEN 11
int val = 0;
//int yval = 0;

void setup() {    
//    Wire.begin(8);
//    Wire.setClock(100000);
//    Wire.onReceive(receiveEvent);
    Serial.begin(9600);
    pinMode(RED, OUTPUT);
    pinMode(GREEN, OUTPUT);
    pinMode(KNOB, INPUT);
    pinMode(YKNOB, INPUT);
    
    Serial.println("Listening...");
//            off(GREEN);
//            off(RED);

#if TONE_ENABLED
    Tone_Setup();
#endif

//#if NEOPIXEL_ENABLED
NeoPixel_Setup();
//#endif
}

void loop() {
      val = analogRead(KNOB);  // read the input pin
//      yval = analogRead(YKNOB);
//      Serial.print(" KNOB: ");
//      Serial.println(val / 10);          // debug valu
      
//      Serial.print("YKNOB: ");
//      Serial.println(yval / 100);          // debug valu
//      delay(500);
//neopix_loop();


      int b = (int) ((54 * ((val + 10) / 10)) / 100);
//      Serial.print("Brightness: ");
//      Serial.println(b);
        set_brightness(b);

delay(100);

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
            

//#if NEOPIXEL_ENABLED
//#if NEOPIXEL_WS2812B_ENABLED
//        case 60:
//            Serial.println("RGB OFF");
//            rgb_off();
//            break;
//            
//        case 61:
//            Serial.println("RGB GREEN");
//            rgb_green();
//            break;
//            
//        case 62:
//            Serial.println("RGB RED");
//            rgb_red();
//            break;
//            
//        case 63:
//            Serial.println("RGB BLUE");
//            rgb_blue();
//            break;
//            
//        case 64:
//            Serial.println("RGB PURPLE");
//            rgb_purple();
//            break;
//
//        case 65:
//            Serial.println("RGB LOOP");
//            rgb_loop();
//            break;
//#endif
//#endif
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
