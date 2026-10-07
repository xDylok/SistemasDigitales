/*
 * GccApplication1.c
 *
 * Created: 4/10/2026 15:10:46
 * Author : MiguelV
 */ 

#include <avr/io.h>


/* 
 * APE 1 - Codigo 5: Microchip Studio (C puro, sin Arduino) 
 * Dispositivo: ATmega328P | Toolchain: AVR/GNU C Compiler (avr-gcc) 
 */ 
#include <avr/io.h> 
  
int main(void) 
{ 
    DDRB  |=  (1 << DDB5) | (1 << DDB0);   // PB5 y PB0 como salidas 
    DDRD  &= ~(1 << DDD2);                 // PD2 como entrada 
    PORTD |=  (1 << PORTD2);               // pull-up interna en PD2 
  
    while (1) 
    { 
        if (PIND & (1 << PIND2)) {         // pulsador suelto (lee 1) 
            PORTB &= ~(1 << PORTB5);       // apaga PB5 
        } else {                           // pulsador presionado (lee 0) 
            PORTB |=  (1 << PORTB5);       // enciende PB5 
        } 
        PORTB ^= (1 << PORTB0);            // conmuta PB0 en cada vuelta
	}
}

