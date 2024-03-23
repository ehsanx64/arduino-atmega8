#include <Adafruit_NeoPixel.h>
#include <Wire.h>

//#define NOTE_B0  31
//#define NOTE_C1  33
//#define NOTE_CS1 35
//#define NOTE_D1  37
//#define NOTE_DS1 39
//#define NOTE_E1  41
//#define NOTE_F1  44
//#define NOTE_FS1 46
//#define NOTE_G1  49
//#define NOTE_GS1 52
//#define NOTE_A1  55
//#define NOTE_AS1 58
//#define NOTE_B1  62
//#define NOTE_C2  65
//#define NOTE_CS2 69
//#define NOTE_D2  73
//#define NOTE_DS2 78
//#define NOTE_E2  82
//#define NOTE_F2  87
//#define NOTE_FS2 93
//#define NOTE_G2  98
//#define NOTE_GS2 104
//#define NOTE_A2  110
//#define NOTE_AS2 117
//#define NOTE_B2  123
//#define NOTE_C3  131
//#define NOTE_CS3 139
//#define NOTE_D3  147
//#define NOTE_DS3 156
//#define NOTE_E3  165
//#define NOTE_F3  175
//#define NOTE_FS3 185
//#define NOTE_G3  196
//#define NOTE_GS3 208
//#define NOTE_A3  220
//#define NOTE_AS3 233
//#define NOTE_B3  247
//#define NOTE_C4  262
//#define NOTE_CS4 277
//#define NOTE_D4  294
//#define NOTE_DS4 311
//#define NOTE_E4  330
//#define NOTE_F4  349
//#define NOTE_FS4 370
//#define NOTE_G4  392
//#define NOTE_GS4 415
//#define NOTE_A4  440
//#define NOTE_AS4 466
//#define NOTE_B4  494
//#define NOTE_C5  523
//#define NOTE_CS5 554
//#define NOTE_D5  587
//#define NOTE_DS5 622
//#define NOTE_E5  659
//#define NOTE_F5  698
//#define NOTE_FS5 740
//#define NOTE_G5  784
//#define NOTE_GS5 831
//#define NOTE_A5  880
//#define NOTE_AS5 932
//#define NOTE_B5  988
//#define NOTE_C6  1047
//#define NOTE_CS6 1109
//#define NOTE_D6  1175
//#define NOTE_DS6 1245
//#define NOTE_E6  1319
//#define NOTE_F6  1397
//#define NOTE_FS6 1480
//#define NOTE_G6  1568
//#define NOTE_GS6 1661
//#define NOTE_A6  1760
//#define NOTE_AS6 1865
//#define NOTE_B6  1976
//#define NOTE_C7  2093
//#define NOTE_CS7 2217
//#define NOTE_D7  2349
//#define NOTE_DS7 2489
//#define NOTE_E7  2637
//#define NOTE_F7  2794
//#define NOTE_FS7 2960
//#define NOTE_G7  3136
//#define NOTE_GS7 3322
//#define NOTE_A7  3520
//#define NOTE_AS7 3729
//#define NOTE_B7  3951
//#define NOTE_C8  4186
//#define NOTE_CS8 4435
//#define NOTE_D8  4699
//#define NOTE_DS8 4978

#define BUZZER 5
// notes in the melody:
//int melody[] = {

//  NOTE_C4, NOTE_G3, NOTE_G3, NOTE_A3, NOTE_G3, 0, NOTE_B3, NOTE_C4
//};

// note durations: 4 = quarter note, 8 = eighth note, etc.:
//int noteDurations[] = {
//
//  4, 8, 8, 4, 4, 4, 4, 4
//};

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
//            noTone(BUZZER);

//            play_tone();

tone(BUZZER, 262, 1000);
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
        neoPix.setBrightness(b);
       for (int i = 0; i < 8; i++) {
            if (i < ((int) yval / 100)) {
                neoPix.setPixelColor(i, 0, 255, 0);            
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

//void play_tone() {
//
//  // iterate over the notes of the melody:
//
//  for (int thisNote = 0; thisNote < 8; thisNote++) {
//
//    // to calculate the note duration, take one second divided by the note type.
//
//    //e.g. quarter note = 1000 / 4, eighth note = 1000/8, etc.
//
//    int noteDuration = 1000 / noteDurations[thisNote];
//
//    tone(BUZZER, melody[thisNote], noteDuration);
//
//    // to distinguish the notes, set a minimum time between them.
//
//    // the note's duration + 30% seems to work well:
//
//    int pauseBetweenNotes = noteDuration * 1.30;
//
//    delay(pauseBetweenNotes);
//
//    // stop the tone playing:
//
//    noTone(BUZZER);
//
//  }
//}
