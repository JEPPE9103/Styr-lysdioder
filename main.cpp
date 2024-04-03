#include <Arduino.h>

// Definiera pin-nummer för LED och knapp
#define LED_PIN 8
#define BUTTON_PIN 9

void setup() {
  // Konfigurera LED-pin som utgång
  DDRB |= (1 << DDB0); // Sätt bit 0 i DDRB till 1 för att göra den till en utgång (LED på pin 8)

  // Konfigurera knapp-pin som ingång
  DDRB &= ~(1 << DDB1); // Rensa bit 1 i DDRB för att göra den till en ingång (knapp på pin 9)

  // Aktivera den interna pull-up motståndet för knappen
  PORTB |= (1 << PORTB1); // Sätt bit 1 i PORTB till 1 för att aktivera pull-up motstånd (knapp på pin 9)
}

void loop() {
  // Läs knappens status
  bool buttonState = bit_is_clear(PINB, BUTTON_PIN);

  // Om knappen är nedtryckt, tänd LED:n, annars släck den
  if (buttonState) {
    PORTB |= (1 << PORTB0); // Sätt bit 0 i PORTB till 1 för att tända LED:n
  } else {
    PORTB &= ~(1 << PORTB0); // Rensa bit 0 i PORTB för att släcka LED:n
  }
}
