#include <avr/io.h>

#define LED_PIN 0 // Pin 8 på Arduino/Freenove
#define BUTTON_PIN 1 // Pin 9 på Arduino/Freenove

int main() {
  DDRB |= (1 << LED_PIN); // Sätt LED-pin som utgång
  DDRB &= ~(1 << BUTTON_PIN); // Sätt knapp-pin som ingång
  PORTB |= (1 << BUTTON_PIN); // Aktivera den interna pull-up motståndet för knappen

  bool ledState = false; // Initialt är LED:n släckt

  while (1) {
    // Läs knappens status
    bool buttonState = !(PINB & (1 << BUTTON_PIN)); // Om knappen är nedtryckt, läsning ger 0 (false)

    // Om knappen är nedtryckt, ändra LED:ens tillstånd
    if (buttonState) {
      ledState = !ledState; // Toggle LED:ens tillstånd
      if (ledState) {
        PORTB |= (1 << LED_PIN); // Tänd LED:n
      } else {
        PORTB &= ~(1 << LED_PIN); // Släck LED:n
      }
      while (buttonState) {
        buttonState = !(PINB & (1 << BUTTON_PIN)); // Vänta på att knappen släpps
      }
    }
  }
  return 0;
}
