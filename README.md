# LED Toggle with Button (AVR)
This code demonstrates toggling an LED using a button on an AVR microcontroller (e.g., Arduino or Freenove).

### Usage
- Connect an LED and a push button to the specified pins on the AVR board.
- Compile and upload the code to the AVR board.
- Press the button to toggle the LED on and off.
### Components
- avr/io.h: AVR Input/Output definitions.
- LED_PIN (Pin 8) and BUTTON_PIN (Pin 9): Pin definitions for LED and button respectively.
### How It Works
- The LED pin is set as an output, and the button pin is set as an input with a pull-up resistor enabled.
- The program continuously checks the state of the button.
- If the button is pressed (the pin reads LOW), the LED state is toggled.
### Note
- Ensure proper connections of LED and button to the AVR board.
- Adjust pin definitions according to the board's pinout if necessary.
### Hardware Setup
- Connect an LED's cathode (short leg) to ground and the anode (long leg) to the specified LED pin.
- Connect one terminal of the push button to ground and the other terminal to the specified button pin. Use a pull-up resistor (e.g., 10kΩ) between the button pin and VCC.
