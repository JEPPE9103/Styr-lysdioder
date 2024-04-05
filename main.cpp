#include <Arduino.h>

// Definiera pin-nummer för LED och knapp
#define LED_PIN 8
#define BUTTON_PIN 9

void setup() {
  // Konfigurera LED-pin som utgång
  DDRB |= (1 << DDB0); 

  // Konfigurera knapp-pin som ingång
  DDRB &= ~(1 << DDB1); 

  // Aktivera den interna pull-up motståndet för knappen
  PORTB |= (1 << PORTB1); 
}

void loop() {
  // Läs knappens status
  bool buttonState = bit_is_clear(PINB, BUTTON_PIN);

  // Om knappen är nedtryckt, tänd LED:n, annars släck den
  if (buttonState) {
    PORTB |= (1 << PORTB0); 
  } else {
    PORTB &= ~(1 << PORTB0); 
  }
}
