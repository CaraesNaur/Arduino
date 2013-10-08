/*
Board options =========================================================
*/

// For an Arduino Uno or similar boards, try these options

// how many LEDs are in the line
//const uint8_t num_leds = 6;

// declare a pin for each LED
//uint8_t pinArray[num_leds] = {3, 5, 6, 9, 10, 11};

// initialize brightness for each LED
//int bright[num_leds] = {0, 0, 0, 0, 0, 0};

//
// ====================================================================
//

//For an Arduino Mega, try these settings

// how many LEDs are in the line
const uint8_t num_leds = 10;

// declare a pin for each LED
// pins 9,10,11 cause conflicts with the timers
uint8_t pinArray[num_leds] = {2, 3, 4, 5, 6, 7, 8, 44, 45, 46};

// initialize brightness for each LED
int bright[num_leds] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0};

/*
End board options =====================================================
*/

// true = ascending, false = descending
bool fade_dir = true;

// the current LED
int8_t curr = 0;

// lower bound of the counter range
int8_t lbound = 0;

// upper bound of the counter range
int8_t ubound = 0;

// delay value
unsigned int del = 100;

// whether to light up the LEDs before current
bool fore = true;

// whether to light up the LEDs after current
bool aft = true;

// how many steps from head to tail
const uint8_t half_range = 3;

// brightness set: first member is the center
uint8_t brange[half_range] = {255, 63, 8};

// brightness value used beyond the brange
uint8_t boor = 0;

// how far the peak of the lit range moves beyond the physical LED range;
// positive values expand beyond, negative retracts
int8_t bounce_outside = 0;

// whether to send debug output to serial
bool debug = false;

void setup() {
	// adjust some values
	lbound = 0 - half_range;
	ubound = (num_leds - 1) + half_range;

	curr = lbound - bounce_outside;

	uint8_t count = 0;

	// initialize the pins
	for (count = 0; count < num_leds; count++) {
		pinMode(pinArray[count], OUTPUT);
		analogWrite(pinArray[count], 0);
	}

	if (debug) {
		Serial.begin(9600);
		Serial.print("outside: ");
		Serial.println(bounce_outside);
		Serial.print("half:    ");
		Serial.println(half_range);
		Serial.print("Range:   ");
		Serial.print(lbound);
		Serial.print(" to ");
		Serial.println(ubound);
		Serial.print("Scan:    ");
		Serial.print(lbound - bounce_outside);
		Serial.print(" to ");
		Serial.println(ubound + bounce_outside);
		Serial.print("curr:    ");
		Serial.println(curr);
		Serial.println("");
		Serial.println("");
		Serial.println("");
	}
}

void loop() {
	int8_t i = 0;
	int8_t o = 0;

	// walk through the range, setting values
	for (i = lbound; i <= ubound; i++) {
		// only sets values on valid LEDs
		if (i >= 0 && i < num_leds) {
			o = abs(i - curr);

			if (
					o < half_range &&
					(
						(
							(
								(fade_dir == true && i > curr)
								||
								(fade_dir == false && i < curr)
							)
							&&
							fore == true
						)
						||
						(
							(
								(fade_dir == true && i < curr)
								||
								(fade_dir == false && i > curr)
							)
							&&
							aft == true
						)
						||
						i == curr
					)
			) {
				bright[i] = brange[o];
			}
			else {
				bright[i] = boor;
			}
		}
	}


	// positive, end of scan
	if ((curr == (ubound + bounce_outside)) && fade_dir) {
		if (debug) {
				Serial.println("back");
		}

		fade_dir = !fade_dir;
		curr--;
	}
	// negative, start of scan
	else if ((curr == (lbound - bounce_outside)) && !fade_dir) {
		if (debug) {
				Serial.println("forward");
		}

		fade_dir = !fade_dir;
		curr++;
	}
	// mid-scan; change current
	else {
		curr += (fade_dir ? 1 : -1);
	}

	if (debug) {
		_debug();
	}

	uint8_t c = 0;

	// send brightness to the pins
	for (c = 0; c < num_leds; c++) {
		analogWrite(pinArray[c], bright[c]);
	}

	delay(del);
}

void _debug() {
	Serial.print(fade_dir ? "UP" : "DN");
	Serial.print(" C: ");
	Serial.print(curr);
	Serial.print("      ");

	uint8_t i = 0;

	for (i = 0; i < num_leds; i++) {
		if(bright[i] < 100) {
			Serial.print(" ");
		}

		if(bright[i] < 10) {
			Serial.print(" ");
		}

		Serial.print(bright[i]);

		if (i < (num_leds - 1)) {
			Serial.print(" ");
		}
		else {
			Serial.println();
		}
	}
}
