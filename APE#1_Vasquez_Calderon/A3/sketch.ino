// APE 1 - Codigo 1: Blink con la API de Arduino (linea base) 
// Placa: Arduino UNO (ATmega328P @ 16 MHz) - simulacion en Wokwi 
void setup() { 
pinMode(13, OUTPUT);          
// D13 = PB5 (LED integrado "L") 
}
void loop() { 
digitalWrite(13, HIGH); 
delay(500); 
digitalWrite(13, LOW); 
delay(500); 
}