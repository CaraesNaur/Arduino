// include the library code:
#include <LiquidCrystal.h>

// pins
const uint8_t pot_pin = 0;
const uint8_t r_pin = 3;
const uint8_t g_pin = 5;
const uint8_t b_pin = 6;
const uint8_t up_pin = 4;
const uint8_t down_pin = 2;
const uint8_t btn_pin = A1;
const uint8_t bl_pin = 13;

// lcd positions
const uint8_t r_pos = 1;
const uint8_t g_pos = 6;
const uint8_t b_pos = 11;
const uint8_t m_pos = 14;

// color values
uint8_t r_val = 255;
uint8_t g_val = 255;
uint8_t b_val = 255;
uint8_t c_val = 255;

const uint8_t numcolors = 64;
const uint8_t colorbytes = 3;

uint8_t current_map[numcolors][colorbytes] = {};

// hue map
uint8_t hue_map[numcolors][colorbytes] = {{255,0,0},{255,26,0},{255,51,0},{255,77,0},{255,102,0},{255,128,0},{255,153,0},{255,179,0},{255,204,0},{255,230,0},{255,255,0},{255,255,0},{227,255,0},{198,255,0},{170,255,0},{142,255,0},{113,255,0},{85,255,0},{57,255,0},{28,255,0},{0,255,0},{0,255,0},{0,255,26},{0,255,51},{0,255,77},{0,255,102},{0,255,128},{0,255,153},{0,255,179},{0,255,204},{0,255,230},{0,255,255},{0,255,255},{0,230,255},{0,204,255},{0,179,255},{0,153,255},{0,128,255},{0,102,255},{0,77,255},{0,51,255},{0,26,255},{0,0,255},{0,0,255},{28,0,255},{57,0,255},{85,0,255},{113,0,255},{142,0,255},{170,0,255},{198,0,255},{227,0,255},{255,0,255},{255,0,255},{255,0,230},{255,0,204},{255,0,179},{255,0,153},{255,0,128},{255,0,102},{255,0,77},{255,0,51},{255,0,26},{255,0,0}};
// orange map
uint8_t orange_map[numcolors][colorbytes] = {{2,0,0},{7,2,0},{12,3,0},{17,4,0},{22,5,0},{27,7,0},{32,8,0},{37,9,0},{42,10,0},{47,12,0},{52,13,0},{56,14,0},{61,15,0},{66,17,0},{71,18,0},{76,19,0},{81,20,0},{86,21,0},{91,23,0},{96,24,0},{101,25,0},{105,26,0},{110,28,0},{115,29,0},{120,30,0},{125,31,0},{130,33,0},{135,34,0},{140,35,0},{145,36,0},{150,38,0},{155,39,0},{159,40,0},{164,41,0},{169,42,0},{174,43,0},{179,45,0},{184,46,0},{189,47,0},{194,48,0},{199,50,0},{203,51,0},{206,53,0},{209,56,0},{211,58,0},{214,61,0},{217,64,0},{219,66,0},{222,69,0},{224,71,0},{227,74,0},{230,77,0},{232,79,0},{235,82,0},{237,84,0},{240,87,0},{242,89,0},{245,92,0},{248,95,0},{250,97,0},{253,100,0},{255,103,0},{255,109,0},{255,116,0},};
// blue map
uint8_t blue_map[numcolors][colorbytes] = {{0,1,3},{0,4,9},{0,8,15},{0,11,21},{0,14,27},{0,17,34},{0,20,40},{0,23,46},{0,26,52},{0,29,59},{0,32,65},{0,35,70},{0,38,76},{0,41,83},{0,44,89},{0,47,95},{0,50,101},{0,53,107},{0,57,114},{0,60,120},{0,63,126},{0,66,131},{0,69,138},{0,72,144},{0,75,150},{0,78,156},{0,81,162},{0,84,169},{0,87,175},{0,90,181},{0,93,187},{0,96,193},{0,99,199},{0,102,205},{0,105,211},{0,108,218},{0,111,224},{0,115,230},{0,118,236},{0,121,242},{0,123,249},{0,127,254},{0,133,255},{0,137,255},{0,143,255},{0,149,255},{0,155,255},{0,161,255},{0,166,255},{0,172,255},{0,178,255},{0,184,255},{0,190,255},{0,195,255},{0,200,255},{0,206,255},{0,212,255},{0,218,255},{0,224,255},{0,229,255},{0,235,255},{0,241,255},{0,247,255},{0,253,255},};
// green map
uint8_t green_map[numcolors][colorbytes] = {{0,2,0},{0,7,0},{0,12,0},{0,16,0},{0,21,0},{0,26,0},{0,31,0},{0,36,0},{0,40,0},{0,44,0},{0,49,0},{0,54,0},{0,58,0},{0,63,0},{0,68,0},{0,73,0},{0,77,0},{0,82,0},{0,87,0},{0,92,0},{0,96,0},{0,101,0},{0,106,0},{0,110,0},{0,114,0},{0,119,0},{0,124,0},{0,129,0},{0,134,0},{0,138,0},{0,143,0},{0,148,0},{0,152,0},{0,157,0},{0,162,0},{0,166,0},{0,171,0},{0,176,0},{0,181,0},{0,186,0},{0,190,0},{0,194,0},{0,199,0},{0,204,0},{0,208,0},{0,213,0},{0,218,0},{0,223,0},{0,227,0},{0,232,0},{0,237,0},{0,242,0},{0,246,0},{0,251,0},{2,255,0},{14,255,0},{28,255,0},{41,255,0},{54,255,0},{67,255,0},{81,255,0},{85,255,0},{107,255,0},{121,255,0},};
// purple map
uint8_t purple_map[numcolors][colorbytes] = {{2,0,2},{6,0,6},{10,0,10},{14,0,14},{18,0,18},{22,0,22},{26,0,26},{30,0,30},{33,0,33},{37,0,37},{41,0,41},{45,0,45},{49,0,49},{53,0,53},{57,0,57},{61,0,61},{66,0,66},{70,0,70},{74,0,74},{78,0,78},{82,0,82},{86,0,86},{90,0,90},{94,0,94},{97,0,97},{101,0,101},{105,0,105},{109,0,109},{113,0,113},{117,0,117},{121,0,121},{125,0,125},{129,1,129},{133,3,133},{137,5,137},{141,7,141},{145,9,145},{149,11,149},{153,13,153},{157,15,157},{161,17,161},{165,19,165},{169,21,169},{173,23,173},{177,25,177},{181,27,181},{185,29,185},{189,31,189},{193,33,193},{197,35,197},{201,37,201},{205,39,205},{209,41,209},{213,43,213},{217,45,217},{221,47,221},{225,49,225},{229,51,229},{233,53,233},{237,55,237},{241,57,241},{245,59,245},{249,61,249},{253,63,253},};

char* c_label = "";
char* o_label = "";

boolean up_act = false;
boolean down_act = false;
boolean fast = false;

long press_millis = 0;
long ms = 0;
long pmc = 0;

unsigned int pval = 0;
unsigned long last_btn = 0;
unsigned int btn_delay = 200; // millis


// initialize the library with the numbers of the interface pins
LiquidCrystal lcd(12, 11, 10, 9, 8, 7);

// up arrow
// __#__
// _###_
// #####
// __#__
// __#__
// __#__
// _____
byte up_arr[8] = {B00100,B01110,B11111,B00100,B00100,B00100,B00000};

// down arrow
// _____
// __#__
// __#__
// __#__
// #####
// _###_
// __#__
byte dn_arr[8] = {B00000,B00100,B00100,B00100,B11111,B01110,B00100};

// wait arrow
// __#__
// _###_
// #####
// __#__
// #####
// _###_
// __#__
byte wt_arr[8] = {B00100,B01110,B11111,B00100,B11111,B01110,B00100};

// minimum arrow
// #####
// ##_##
// ##_##
// ##_##
// _____
// #___#
// ##_##
byte mn_arr[8] = {B11111,B11011,B11011,B11011,B00000,B10001,B11011};

// maximum arrow
// ##_##
// #___#
// _____
// ##_##
// ##_##
// ##_##
// #####
byte mx_arr[8] = {B11011,B10001,B00000,B11011,B11011,B11011,B11111};

unsigned int pcol = 0;

// previous colors
uint8_t p_r = 0;
uint8_t p_g = 0;
uint8_t p_b = 0;
uint8_t p_i = 0;

// current colors
uint8_t c_r = 0;
uint8_t c_g = 0;
uint8_t c_b = 0;
uint8_t c_i = 0;

// display values
uint8_t d_r = 0;
uint8_t d_g = 0;
uint8_t d_b = 0;

uint8_t flare = 0;
uint8_t icol = 0;
uint8_t coldelta = 0;
uint8_t scmode = 0;
uint8_t bstate = 0;
bool blstate = false;

void setup() {
	randomSeed(analogRead(1));
	// set pin modes
	pinMode(pot_pin, OUTPUT);
	pinMode(r_pin, OUTPUT);
	pinMode(g_pin, OUTPUT);
	pinMode(b_pin, OUTPUT);
	pinMode(up_pin, INPUT_PULLUP);
	pinMode(down_pin, INPUT_PULLUP);

	pinMode(btn_pin, INPUT);
	pinMode(bl_pin, OUTPUT);


	// start lcd
	lcd.begin(16, 2);

	// assign arrows to lcd custom characters
	lcd.createChar(1, up_arr);
	lcd.createChar(2, dn_arr);
	lcd.createChar(3, wt_arr);
	lcd.createChar(4, mn_arr);
	lcd.createChar(5, mx_arr);

	setColor(0, 0, 0);

	lcd.clear();

	lcd.setCursor(0,0);
	lcd.print("Knob: set mode");
	lcd.setCursor(0,1);
	lcd.print("Buttons: ");
	lcd.write(byte(1));
	lcd.print("/");
	lcd.write(byte(2));

	delay(3000);

	// blink white 4 times fast
	setColor(0, 0, 0);
	delay(200);
	setColor(255, 255, 255);
	delay(200);
	setColor(0, 0, 0);
	delay(200);
	setColor(255, 255, 255);
	delay(200);
	setColor(0, 0, 0);
	delay(200);
	setColor(255, 255, 255);
	delay(200);
	setColor(0, 0, 0);
	delay(200);
	setColor(255, 255, 255);

	pcol = random(numcolors);

	lcd.clear();
	lcd.setCursor(r_pos - 1, 0);
	lcd.print("r???");

	lcd.setCursor(g_pos - 1, 0);
	lcd.print("g???");

	lcd.setCursor(b_pos - 1, 0);
	lcd.print("b???");
	lcd.setCursor(0,1);
	lcd.print("                ");

	// done
}
/*

Mode Map
0	"W?"	white fader
1	"Y?"	yellow fader
2	"C?"	cyan fader
3	"M?"	magenta fader
4	"H?"	hue map cycle
5	"WF"	white flame
6	"OF"	orange flame
7	"BF"	blue flame
8	"GF"	green flame
9	"PF"	purple flame
10	"HF"	hue flame
11	"XX"	random
12	"R?"	red fader
13	"G?"	green fader
14	"B?"	blue fader
15	unused

*/

void loop() {
	ms = millis();

	lcd.setCursor(0, 1);
	bstate = analogRead(btn_pin);

	// check the button
	if (!bstate > 0 && (ms - last_btn >= btn_delay)) {
		// turn LED on:
		blstate = !blstate;
		lcd.print((blstate ? "+" : "-"));
		digitalWrite(bl_pin, (blstate ? HIGH : LOW));
		last_btn = ms;
	}

	pval = analogRead(pot_pin);
	up_act = !digitalRead(up_pin);
	down_act = !digitalRead(down_pin);

	scmode = constrain(map(pval, 0, 1023, 14, -1), 0, 14);

	switch (scmode) {
		case 0: // buttons control RGB
			c_label = "W?";

			break;
		case 1: // buttons control RG, B=0
			c_label = "Y?";

			if (b_val != 0) {
				b_val = 0;
			}
			if (r_val != g_val) {
				c_val = uint8_t((r_val + g_val) / 2);
			}

			break;
		case 2: // buttons control GB, R=0
			c_label = "C?";

			if (r_val != 0) {
				r_val = 0;
			}
			if (g_val != b_val) {
				c_val = uint8_t((g_val + b_val) / 2);
			}
			break;
		case 3: // buttons control RB, G=0
			c_label = "M?";

			if (g_val != 0) {
				g_val = 0;
			}
			if (r_val != b_val) {
				c_val = uint8_t((r_val + b_val) / 2);
			}

			break;
		case 4: // buttons loop through hue map
			c_label = "H?";

			if (current_map != hue_map) {
				memcpy(current_map, hue_map, sizeof(current_map)); //current_map = hue_map;
				//*current_map = hue_map;
			}

			break;
		case 5: // RGB flicker
			c_label = "WF";

			if (r_val != g_val || g_val != b_val) {
				c_val = uint8_t((r_val + g_val + b_val) / 3);
			}
			break;
		case 6: // orange map
			c_label = "OF";
			if (current_map != orange_map) {
				memcpy(current_map, orange_map, sizeof(current_map)); //current_map = orange_map;
			}
			break;
		case 7: // blue map
			c_label = "BF";
			if (current_map != blue_map) {
				memcpy(current_map, blue_map, sizeof(current_map)); //current_map = blue_map;
				//current_map = blue_map;
			}
			break;
		case 8: //	green map
			c_label = "GF";
			if (current_map != green_map) {
				memcpy(current_map, green_map, sizeof(current_map)); //current_map = green_map;
				//current_map = green_map;
			}
			break;
		case 9: // purple map
			c_label = "PF";
			if (current_map != purple_map) {
				memcpy(current_map, purple_map, sizeof(current_map)); //current_map = purple_map;
				//current_map = purple_map;
			}
			break;
		case 10: // hue map
			c_label = "HF";
			if (current_map != hue_map) {
				memcpy(current_map, hue_map, sizeof(current_map)); //current_map = hue_map;
				//current_map = hue_map;
			}
			break;
		case 11: // random
			c_label = "XX";
			break;
		case 12: // Set R
			c_label = "R?";
			c_val = r_val;
			break;
		case 13: // Set G
			c_label = "G?";
			c_val = g_val;
			break;
		case 14: // Set B
			c_label = "B?";
			c_val = b_val;
			break;
	}

	lcd.setCursor(m_pos, 1);
	lcd.print(c_label);

	// one button pressed
	if ((up_act == true && down_act == false) || (down_act == true && up_act == false)) {
		pmc++;

		if (press_millis == 0) {
			press_millis = ms;
		}

		if (press_millis > 0 && ms - press_millis >= 1000) {
			fast = true;
		}

		// up button pressed
		if (up_act == true && (scmode == 4 || c_val < 255)) {
			c_val++;
		}

		// down button pressed
		if (down_act == true && (scmode == 4 || c_val > 0)) {
			c_val--;
		}
	}

	// neither button pressed
	if (up_act == false && down_act == false) {
		press_millis = 0;
		pmc = 0;
		fast = false;
	}

	// flame modes: 5, 6, 7, 8, 9, 10
	if (c_label[1] == 'F') {
		if (c_label == "WF") {
			coldelta = random(1,4) * random(3,12);
			flare = random(64);
		}
		else {
			coldelta = random(1,3) * random(0, 8);
			flare = random(16);
		}

		if (random(6) < 3) {
			if (c_label == "WF") {
				c_val += coldelta;
			}
			else {
				icol = pcol + coldelta;
			}
		}
		else {
			if (c_label == "WF") {
				c_val -= coldelta;
			}
			else {
				icol = pcol - coldelta;
			}
		}

		if (random(16) == 0) {
			if (c_label == "WF") {
				c_val += flare * 4;
			}
			else {
				icol += flare;
			}
		}

		if (c_label == "WF") {
			r_val = constrain(c_val, 0, 255);
			g_val = r_val; 
			b_val = r_val; 
		}
		else if (c_label == "HF") {
			if (icol < 0) {
				icol += numcolors;
			}
			if (icol >= numcolors) {
				icol -= numcolors;
			}
		}
		else {
			icol = constrain(icol, 0, numcolors - 1);
		}
	}

	if (scmode == 0) { // "W?"
		r_val = c_val;
		g_val = c_val;
		b_val = c_val;
		setColor(r_val, g_val, b_val);
	}
	else if (scmode == 1) { // "Y?"
		r_val = c_val;
		g_val = c_val;
		b_val = 0;
		setColor(r_val, g_val, b_val);
	}
	else if (scmode == 2) { // "C?"
		r_val = 0;
		g_val = c_val;
		b_val = c_val;
		setColor(r_val, g_val, b_val);
	}
	else if (scmode == 3) { // "M?"
		r_val = c_val;
		g_val = 0;
		b_val = c_val;
		setColor(r_val, g_val, b_val);
	}
	else if (scmode == 4) { // "H?"
		if (c_val > 255) {
			c_val -= 255;
		}
		else if (c_val < 0) {
			c_val += 255;
		}

		icol = map(c_val, 0, 255, 0, numcolors - 1);
	}
	else if (scmode == 5) {
		setColor(r_val, g_val, b_val);
	}

	// mapped modes
	if (scmode == 4 || scmode == 6 || scmode == 7 || scmode == 8 || scmode == 9 || scmode == 10) {
		setColorI(icol);
		r_val = current_map[icol][0];
		g_val = current_map[icol][1];
		b_val = current_map[icol][2];
	}
	else if (scmode == 11) { // random
		r_val = random(255);
		g_val = random(255);
		b_val = random(255);
		setColor(r_val, g_val, b_val);
	}
	else if (scmode == 12) { // "R?"
		r_val = c_val;
		setColor(c_val, g_val, b_val);
	}
	else if (scmode == 13) { // "G?"
		g_val = c_val;
		setColor(r_val, c_val, b_val);
	}
	else if (scmode == 14) { // "B?"
		b_val = c_val;
		setColor(r_val, g_val, c_val);
	}

	d_r = r_val;
	d_g = g_val;
	d_b = b_val;

	pcol = icol;

	// draw r value
	lcd.setCursor(r_pos, 0);
	if (d_r < 100) {
		lcd.print("_");
	}
	if (d_r < 10) {
		lcd.print("_");
	}
	lcd.print(d_r);

	// draw g value
	lcd.setCursor(g_pos, 0);
	if (d_g < 100) {
		lcd.print("_");
	}
	if (d_g < 10) {
		lcd.print("_");
	}
	lcd.print(d_g);

	// draw b value
	lcd.setCursor(b_pos, 0);
	if (d_b < 100) {
		lcd.print("_");
	}
	if (d_b < 10) {
		lcd.print("_");
	}
	lcd.print(d_b);

	//lcd.setCursor(0,1);

	// draw red indicator
	lcd.setCursor(r_pos, 1);

	if (c_label == "R?" || c_label == "W?" || c_label == "Y?" || c_label == "M?") {
		lcd.print((fast && ((up_act && c_val < 255) || (down_act && c_val > 0))) ? "*" : " ");

		if (up_act && !down_act) {
			lcd.write(byte(c_val < 255 ? 1 : 5)); // up_arr or mx_arr
		}
		else if (!up_act && down_act) {
			lcd.write(byte(c_val > 0 ? 2 : 4)); // dn_arr or mn_arr
		}
		else if (!up_act && !down_act) {
		 lcd.write(byte(3)); // wt_arr
		}
		else {
			lcd.print("!");
		}

		lcd.print((fast && ((up_act && c_val < 255) || (down_act && c_val > 0))) ? "*" : " ");
	}
	else if (c_label == "H?") {
		lcd.print((fast && ((up_act && c_val < 255) || (down_act && c_val > 0))) ? "*" : " ");

		if (up_act && !down_act) {
			lcd.write(byte(1)); // up_arr
		}
		else if (!up_act && down_act) {
			lcd.write(byte(2)); // dn_arr
		}
		else if (!up_act && !down_act) {
		 lcd.write(byte(3)); // wt_arr
		}
		else {
			lcd.print("!");
		}

		lcd.print((fast && ((up_act && c_val < 255) || (down_act && c_val > 0))) ? "*" : " ");
	}
	else {
		lcd.print("   ");
	}

	// draw green indicator
	lcd.setCursor(g_pos, 1);

	if (c_label == "G?" || c_label == "W?" || c_label == "Y?" || c_label == "C?") {
		lcd.print((fast && ((up_act && c_val < 255) || (down_act && c_val > 0))) ? "*" : " ");

		if (up_act && !down_act) {
			lcd.write(byte(c_val < 255 ? 1 : 5)); // up_arr or mx_arr
		}
		else if (!up_act && down_act) {
			lcd.write(byte(c_val > 0 ? 2 : 4)); // dn_arr or mn_arr
		}
		else if (!up_act && !down_act) {
		 lcd.write(byte(3)); // wt_arr
		}
		else {
			lcd.print("!");
		}

		lcd.print((fast && ((up_act && c_val < 255) || (down_act && c_val > 0))) ? "*" : " ");
	}
	else if (c_label == "H?") {
		lcd.print((fast && ((up_act && c_val < 255) || (down_act && c_val > 0))) ? "*" : " ");

		if (up_act && !down_act) {
			lcd.write(byte(1)); // up_arr
		}
		else if (!up_act && down_act) {
			lcd.write(byte(2)); // dn_arr
		}
		else if (!up_act && !down_act) {
		 lcd.write(byte(3)); // wt_arr
		}
		else {
			lcd.print("!");
		}

		lcd.print((fast && ((up_act && c_val < 255) || (down_act && c_val > 0))) ? "*" : " ");
	}
	else {
		lcd.print("   ");
	}

	// draw blue indicator
	lcd.setCursor(b_pos, 1);

	if (c_label == "B?" || c_label == "W?" || c_label == "M?" || c_label == "C?") {
		lcd.print((fast && ((up_act && c_val < 255) || (down_act && c_val > 0))) ? "*" : " ");

		if (up_act && !down_act) {
			lcd.write(byte(c_val < 255 ? 1 : 5)); // up_arr or mx_arr
		}
		else if (!up_act && down_act) {
			lcd.write(byte(c_val > 0 ? 2 : 4)); // dn_arr or mn_arr
		}
		else if (!up_act && !down_act) {
		 lcd.write(byte(3)); // wt_arr
		}
		else {
			lcd.print("!");
		}

		lcd.print((fast && ((up_act && c_val < 255) || (down_act && c_val > 0))) ? "*" : " ");
	}
	else if (c_label == "H?") {
		lcd.print((fast && ((up_act && c_val < 255) || (down_act && c_val > 0))) ? "*" : " ");

		if (up_act && !down_act) {
			lcd.write(byte(1)); // up_arr
		}
		else if (!up_act && down_act) {
			lcd.write(byte(2)); // dn_arr
		}
		else if (!up_act && !down_act) {
		 lcd.write(byte(3)); // wt_arr
		}
		else {
			lcd.print("!");
		}

		lcd.print((fast && ((up_act && c_val < 255) || (down_act && c_val > 0))) ? "*" : " ");
	}
	else {
		lcd.print("   ");
	}

	if (c_label[1] != '?' || fast == false) {
		delay(100);
	}
	else {
		delay(5);
	}
}

void setColor(int rv, int gv, int bv) {
	analogWrite(r_pin, 255 - rv);
	analogWrite(g_pin, 255 - gv);
	analogWrite(b_pin, 255 - bv);
}

void setColorI(int i) {
	analogWrite(r_pin, 255 - current_map[i][0]);
	analogWrite(g_pin, 255 - current_map[i][1]);
	analogWrite(b_pin, 255 - current_map[i][2]);
}

