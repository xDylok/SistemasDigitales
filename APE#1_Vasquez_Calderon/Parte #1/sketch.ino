// APE 1 - Codigo 1: Blink con la API de Arduino (linea base)
// Placa: Arduino UNO (ATmega328P @ 16 MHz) - simulacion en Wokwi

/* 

void setup() {
 pinMode(13, OUTPUT); // D13 = PB5 (LED integrado "L")
}
void loop() {
 digitalWrite(13, HIGH);
 delay(500);
 digitalWrite(13, LOW);
 delay(500);
}

*/

// APE 1 - Codigo 2: el mismo Blink, ahora escribiendo registros
// Placa: Arduino UNO (ATmega328P @ 16 MHz) - simulacion en Wokwi
// Regla: no se usa pinMode() ni digitalWrite()
void setup() {
 DDRB |= (1 << DDB5); // PB5 (D13) como salida; los demás bits no cambian
}

void loop() {
  PORTB = (1 << PORTB5);     // Asignación directa
  delay(500);
  PORTB = 0;                 // Apaga para mantener el parpadeo
  delay(500);
}
/*
void loop() {
  PINB = (1 << PINB5);       // Conmuta el bit 5
  delay(500);
}*/

/*
void loop() {
  PORTB |= (1 << PORTB5);    // Enciende el LED (pone solo el bit 5 a 1)
  delay(500);
  PORTB &= ~(1 << PORTB5);   // Apaga el LED (pone solo el bit 5 a 0)
  delay(500);
}
*/

/*
void loop() {
 PORTB ^= (1 << PORTB5); // XOR: conmuta solo el bit 5
 delay(500); // 500 ms encendido / 500 ms apagado
}

*/
