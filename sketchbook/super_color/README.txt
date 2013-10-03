Super Color

This is a somewhat complex breadboard setup and sketch to manipulate a single
RGB LED.  It is the result of one of my learning exercises for my first
Arduino based project.

Parts list:

- Arduino Uno R3 (1)
- Breadboard (1)
- Hitachi HD44780 16x2 character LCD screen (1)
- Common anode RGB LED (1)
- Force sensitive resistors (FSR) or momentary buttons (2)
- Mini SPST button (1)
- 8 pin female headers (2)
- 10k ohm resistor (1)
- 150 ohm resistors (3)
- 10k ohm trimpot (1)
- Toothpaste cap, white (1) (optional)
- Bic pen (1) (optional)

I built this using a MakerShield, which has several of these parts built in,
plus a mini breadboard.  On the MakerShield, POT1 and BTN1 are used.

Schematic made with Fritzing: http://fritzing.org

The sketch uses the standard Arduino LCD library, LiquidCrystal.h.

The sketch sets up 15 modes to operate the LED.  During setup(), the LED is
blinked and basic instructions are output to the LCD.  After setup, the LCD
shows the current red, green, and blue values (0 to 255) on the first line
and a mode indicator on the second line.  In some modes, arrow indicators
are shown below the color values. 

Mode is selected with the trimpot.

- "W?": White fader
- "Y?": Yellow fader
- "C?": Cyan fader
- "M?": Magenta fader
- "H?": Hue map cycle
- "WF": White flame
- "OF": Orange flame
- "BF": Blue flame
- "GF": Green flame
- "PF": Purple flame
- "HF": Hue flame
- "XX": Random
- "R?": Red fader
- "G?": Green fader
- "B?": Blue fader

Modes ending with "?" indicate the user may change the emitted color in some
way.  Arrow indicators show which channel(s) will change when either (but not
both) FSRs are pressed (or momentary buttons, if substituted in).  If pressed
long enough, about 1 second, the color change will happen at an increased
rate, which triggers "*" to display beside the arrow(s).  When both FSRs are
pressed, the arrows are replaced with "!".  When the minimum or maximum value
is reached, the arrow characters become inverted.

Modes ending with "F" are "flame modes"; these cause the LED flicker like a
candle using predefined arrays of colors.  "Orange Flame" was the genesis of
this entire sketch.

The last three modes can be used to set the LED to any of 16.7 million
possible colors.

The final button is used to toggle the LCD backlight.

Optional: I made a diffuser for the LED using a toothpaste cap and a 1 inch
piece of the white body tube of a Bic pen.
