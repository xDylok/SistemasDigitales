// APE 1 - Codigo 2: el mismo Blink, ahora escribiendo registros 
// Placa: Arduino UNO (ATmega328P @ 16 MHz) - simulacion en Wokwi 
// Regla: no se usa pinMode() ni digitalWrite() 
void setup() { 
DDRB |= (1 << DDB5);          
}
void loop() { 
PORTB ^= (1 << PORTB5);       
delay(500);                   
}
// PB5 (D13) como salida; los demás bits no cambian 
// XOR: conmuta solo el bit 5 
// 500 ms encendido / 500 ms apagado 