// APE 1 - Codigo 3: Laboratorio de bits en los puertos B y D
// Placa: Arduino UNO (ATmega328P @ 16 MHz) - simulacion en Wokwi
// Libs : ninguna (avr/io.h llega incluido por Arduino.h)
// Pines: PB0..PB3 (D8..D11) = LEDs | PD2 (D2) = pulsador a GND | PB5 (D13) = LED L
// Regla: NO se usa pinMode(), digitalWrite() ni digitalRead()

const uint8_t MASK_LEDS = 0x0F; // 0b00001111 -> PB0..PB3
const uint8_t NUM_MODOS = 3;
const uint8_t PATRON_INICIAL[NUM_MODOS] = {0b0000, 0b0001, 0b0101};
const unsigned long PERIODO_MS = 300;

uint8_t modo = 0;
uint8_t patron = PATRON_INICIAL[0];
uint8_t btnAnterior = 1; // con pull-up, en reposo se lee 1
unsigned long tAnterior = 0;

void imprimirBin8(const char* etiqueta, uint8_t v) {
  Serial.print(etiqueta);
  for (int8_t i = 7; i >= 0; i--) { // extrae el bit i
    Serial.print((v >> i) & 1);
  }
  Serial.println();
}

void escribirLeds(uint8_t valor) {
  // leer-modificar-escribir: solo cambian PB0..PB3; PB4..PB7 se conservan
  PORTB = (PORTB & ~MASK_LEDS) | (valor & MASK_LEDS);
}

void demoOperaciones() {
  uint8_t a = 0b11001100;
  uint8_t b = 0b10101010;
  imprimirBin8("a      = ", a);
  imprimirBin8("b      = ", b);
  imprimirBin8("a & b  = ", a & b);
  imprimirBin8("a | b  = ", a | b);
  imprimirBin8("a ^ b  = ", a ^ b);
  imprimirBin8("~a     = ", (uint8_t)~a);
  imprimirBin8("a << 1 = ", (uint8_t)(a << 1));
  imprimirBin8("a >> 2 = ", a >> 2);
  Serial.print("~a sin cast, en BIN: ");
  Serial.println(~a, BIN); // ver pregunta de control 6
}

void setup() {
  DDRD &= ~(1 << DDD2);            // PD2 entrada (bit DDR = 0)
  PORTD |= (1 << PORTD2);          // pull-up interna (bit PORT = 1)
  DDRB |= MASK_LEDS | (1 << DDB5); // salidas: PB0..PB3 y PB5
  
  Serial.begin(9600);
  Serial.println(F("APE 1 - Laboratorio de bits"));
  demoOperaciones();
  escribirLeds(patron);
}

void loop() {
  // 1) Pulsador: se aisla el bit 2 de PIND (activo en bajo)
  uint8_t btn = (PIND >> PIND2) & 1;
  
  if (btnAnterior == 1 && btn == 0) { // flanco de bajada
    modo = (modo + 1) % NUM_MODOS;
    patron = PATRON_INICIAL[modo];
    Serial.print(F("Modo: "));
    Serial.println(modo);
  }
  btnAnterior = btn;

  // 2) Actualizacion periodica sin bloquear el programa
  if (millis() - tAnterior > PERIODO_MS) {
    tAnterior = millis();
    switch (modo) {
      case 0:
        patron = (patron + 1) & MASK_LEDS; // contador binario de 4 bits
        break;
      case 1:
        patron = ((patron << 1) | (patron >> 3)) & MASK_LEDS; // rotacion circular a la izquierda
        break;
      case 2:
        patron = ~patron & MASK_LEDS; // alternancia
        break;
    }
    escribirLeds(patron);
    PINB = (1 << PINB5); // escribir 1 en PINB5 conmuta PB5
    imprimirBin8("PORTB = ", PORTB);
  }
}