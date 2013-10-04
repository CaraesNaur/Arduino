Knight Rider 7

This is a very configurable Knight Rider (or Cylon) LED chase sketch.

Parts list:

- Arduino (Uno or Mega) (1)
- Breadboard (1)
- Single color LEDs (however many you want/have/your Arduino can accomodate)
- 220 ohm resistors (one for each LED)

Schematic made with Fritzing: http://fritzing.org

The sketch uses no external libraries.

At the top of the sketch, two sets of settings are provided based on which
Arduino board is being used.  I wrote this using a Mega ADK because I wanted
to set up 10 LEDs; an Uno only has 6 PWM pins.  The two breadboard views are
shown in the PNG images.

It operates by tracking the current LED position and applying brightness
values to it and the LEDs before and after (both optional) from an array.  The
current position may be set to range across more or less LEDs than are
actually on the breadboard.

Debug output is sent to serial if enabled by a boolean.
