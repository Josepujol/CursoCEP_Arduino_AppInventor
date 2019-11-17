
int incomingByte;      // variable para leer los bytes de entrada
// variables temperatura
const int LM35Pin = A0; // pin conexion
float temperature = 0; // variable almacenar lectura

void setup() {
  // inicializamos la comunicacion serie
  Serial.begin(9600);
}

void loop() {
  // leemos el sensor
  int lectura = analogRead(LM35Pin); // Valor entre 0 y 1023
  // convertimos el sensor a ºC
  temperature = (5.0 * lectura * 100.0) / 1024.0;
  // comprobamos si hay datos de entrada
  if (Serial.available() > 0) {
    // lectura del byte mas antiguo del buffer serial
    incomingByte = Serial.read();
    // si el byte es T envia dato de temperatura
    if (incomingByte == 'T') {
      Serial.print(temperature);
    }
  }
  delay(100);
}


