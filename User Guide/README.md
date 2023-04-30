## GlowDuino Boards User Guide
This user guide covers the usage of the new features of the Atmega328PB.

### Feature Summary
Compared to a general Arduino board, the GlowDuino Uno has the following added 
features:
- Four additional GPIO pins, two of which can be used as analog inputs (A6, A7, 22, 23)
- Three additional PWM pins, totaling nine
- One additional Serial port
- One additional I²C interface
- One additional SPI interface
- Two additional internal 16-bit timers (TC3, TC4)
- Higher current rating: 1A for both 5V and 3.3V power line

On top of these features, the Uno board supports two output voltage options, 3.3V and 
5V. You can switch between these with the toggle switch on the side of the board.

In conclusion, the Uno board has the following features:
- Atmeg 328PB microcontroller
	- 32KB Flash memory
	- 2KB SRAM
	- 1KB EEPROM
	- 16MHz external crystal oscillator
	- 5 Internal timers
	- Preloaded Arduino IDE-compatible bootloader
- 24 GPIO pins
	- 40mA GPIO current
	- 8 Analog inputs (A0-7)
	- 9 PWM outputs	(0,1,2,3,5,6,9,10,11)
	- 2 Serial ports (0,1, 11,12)
	- 2 I²C interfaces (A5,A4, 22,23)
	- 2 SPI interfaces (10,11,12,13, A0,A1,A6,A7)
- Switchable GPIO voltage (5V, 3.3V)
- High power 5V and 3.3V rail
	- 1A Max
- 20 GPIO indicator LEDs
	- 665K MAX input resistance
- CH340 USB- Serial converter (Serial 0)
- 6pin ICSP header for direct programming
- USB Type-C connector (for programming)
- Power jack (for additional power)
	- Recommended voltage range: 7-12V
	- Maximum voltage range: 6-20V

### Using the new features
Follow the instructions in the **Software and Installation** folder in order to be 
able to use the board with the Arduino IDE software.

To use the **additional four pins**, you can refer to them in the program by their name 
written on the board (22,23,A6,A7). The `digitalRead` and `digitalWrite` function 
works on these pins as well.

**Using both serial ports** in Arduino IDE works by referring to them as `Serial` and 
`Serial1` (for serial 0 and serial 1).

To **use the second I²C interface**, update the IDE package version to 2.0.3 or higher.
After that, you can include the **Wire1.h** library into your sketch and address it as `Wire1`.
Similarly, you can **use the second SPI interface** as well. Include the **SPI1.h** library into
your sketch and address it as `SPI1`.

In case you do not wish to use any of the new features and want to run your board in 328P mode,
you can upload a generic Arduino Uno bootloader to your GlowDuino Uno via the ICSP header.
When uploading, make sure to use the -f option in avrdude to disregard the IC signature
mismatch. Once uploaded, the microcontroller will behave just like an Arduino Uno would. The
voltage level changer switch will still work but none of the other added features will be accessible.

### Pin differences
Every pin with an indicator LED has a pull-down resistor with a value of **665 kilo ohms**.
This means these pins are not floating pins. In our testing, this does not interfere
with analog or digital measurements and causes no disturbance when using capacitive touch 
sensing. However, you will not be able to use such an analog pin for nondeterministic operations,
such as random number generation. For these purposes, you can substitute these pins with either
the **A6** or **A7** analog pins, which do not have pull-down resistors and as such are considered
floating pins. If you need more than just two pins, you can cut the jumper pads next to the other
analog pins to disconnect the pull-down resistor of that particular pin.
