// Two LEDs are connected to pins 11 and 12
#define RED LED_BUILTIN
#define GREEN 11
#define BLUE 12

void setup() {
	pinMode(RED, OUTPUT);
	pinMode(GREEN, OUTPUT);
	pinMode(BLUE, OUTPUT);
}

void all_off() {
	digitalWrite(LED_BUILTIN, LOW);
	digitalWrite(GREEN, LOW);
	digitalWrite(BLUE, LOW);
}

void all_on() {
	digitalWrite(LED_BUILTIN, HIGH);
	digitalWrite(GREEN, HIGH);
	digitalWrite(BLUE, HIGH);
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
	on(BLUE);
	d();
	
	off(BLUE);
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

void red_green_blink() {
	all_off();
	super_blink(RED);
	delay(100);
	super_blink(GREEN);
	delay(200);
}

void loop() {
    red_green_blink();
}
