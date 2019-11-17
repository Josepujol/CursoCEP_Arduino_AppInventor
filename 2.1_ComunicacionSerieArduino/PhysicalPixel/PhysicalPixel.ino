/* 
 *    Physical Pixel

  An example of using the Arduino board to receive data from the computer. In
  this case, the Arduino boards turns on an LED when it receives the character
  'H', and turns off the LED when it receives the character 'L'.

  The data can be sent from the Arduino Serial Monitor, or another program like
  Processing (see code below), Flash (via a serial-net proxy), PD, or Max/MSP.

  The circuit:
  - LED connected from digital pin 13 to ground

  created 2006
  by David A. Mellis
  modified 30 Aug 2011
  by Tom Igoe and Scott Fitzgerald

  This example code is in the public domain.

  http://www.arduino.cc/en/Tutorial/PhysicalPixel
 */

const int ledPin = 9; // pin al que el led esta conectado
int incomingByte;      // variable para leer los bytes de entrada

void setup() {
  // inicializamos la comunicacion serie
  Serial.begin(9600);
  // inicializamos el led como pin digital salida
  pinMode(ledPin, OUTPUT);
}

void loop() {
  // comprobamos si hay datos de entrada
  if (Serial.available() > 0) {
    // lectura del byte mas antiguo del buffer serial
    incomingByte = Serial.read();
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
