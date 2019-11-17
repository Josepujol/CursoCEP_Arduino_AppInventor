#include <SoftwareSerial.h>
const int rxBTPin=11;  // El RX del módulo BT va al pin 11 del Arduino
const int txBTPin=10;  // El TX del módulo BT va al pin 10 del Arduino
SoftwareSerial I2CBT(txBTPin, rxBTPin);

const int ledPin = 13; // pin al que el led esta conectado
int incomingByte;      // variable para leer los bytes de entrada

void setup() {
  // inicializamos el led como pin digital salida
  pinMode(ledPin, OUTPUT);
  // inicializamos la comunicacion serie BT
  I2CBT.begin(9600);
}

void loop() {
  // comprobamos si hay datos de entrada
  if (I2CBT.available() > 0) {
    // lectura del byte mas antiguo del buffer serial
    incomingByte = I2CBT.read();
    // si el byte es H (ASCII 72) enciende el LED
    if (incomingByte == 'H') {
      digitalWrite(ledPin, HIGH);
    }
    // si el byte es L (ASCII 76) apaga el LED
    if (incomingByte == 'L') {
      digitalWrite(ledPin, LOW);
    }
  }
}
