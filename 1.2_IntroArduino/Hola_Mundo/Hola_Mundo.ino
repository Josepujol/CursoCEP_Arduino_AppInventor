/* 
 Titilar 
 Enciende y apaga LED por espacio de un segundo de forma repetitiva 
 LED pin 13
 
 Jose Pujol
 Octubre 2017
 Programa basado en Blink- https://www.arduino.cc/en/Tutorial/Blink
 */

// declaracion de variables 
int ledPin=13; // LED asociado al pin 13      

// la funcion setup se ejecuta una sola vez 
void setup() { 
  pinMode(ledPin, OUTPUT); // inicializa el pin 13 como una salida digital 
} 

// la funcion loop se ejecuta repetidamente de forma infinita 
void loop() { 
  digitalWrite(ledPin, HIGH); // establece 5v en el pin del LED 
  delay(1000); // espera un segundo 
  digitalWrite(ledPin, LOW); // establece 0v en el pin del LED 
  delay(1000); // espera un segundo 
}
