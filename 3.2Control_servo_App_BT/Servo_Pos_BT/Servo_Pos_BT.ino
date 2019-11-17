/*
 * Programa para controlar la posición de un servo desde App Inventor mediante
 * un slider y via Bluetooth usando el HC06
 * Jose Pujol
 * Noviembre de 2019
 */


#include <Servo.h> // incluimos la libreria Servo.h
Servo myservo;  // Creamos el objeto tipo servo de nombre myservo

// Variables para recibir y almacenar datos
int incomingByte;      // variable para leer los bytes de entrada
int value = 0;  // variable para almacenar el valor numerico
int angle = 0; // variable para enviar los grados al servomotor

void setup() {
  // inicializamos el led como pin digital salida
  Serial.begin(9600);;
  myservo.attach(9);  // attaches the servo on pin 9 to the servo object
}

void loop() {
  // comprobamos si hay datos de entrada
  if (Serial.available() > 0) {
    // lectura del byte mas antiguo del buffer serial
    incomingByte = Serial.read();
    if (incomingByte >= '0' && incomingByte <= '9') {
      //Acumula los datos numericos multiplicando por 10 el valor acumulado
      value = (value * 10) + (incomingByte - '0'); // Resta 48 que es el valor decimal del 0 ASCII
    }
    else if (incomingByte == '>') // uso > como finalizador
    {
      angle = value;   // Guarda el valor en la variable angle
      Serial.println(angle);     // imprime angle por monitor serie
      value = 0;  // Dejamos lista la variable para volver a escribir en ella
    }
  }
  myservo.write(angle);   // Escribimos el valor angle en el servo
  delay(15);              // damos tiempo al servo a posicionarse
}



