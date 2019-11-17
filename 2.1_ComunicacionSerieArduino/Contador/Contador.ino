/*
 * Programa de ejemplo del uso del monitor serie
 * Realiza un contador de segundos
 * Jose Pujol
 * Noviembre de 2017
 */
 
int contador = 0;  // variable para almacenar el valor del contador

void setup() {
 // abre el puerto serie
 // y establece la velocidad de conexion en baudios
 Serial.begin(9600);
 Serial.println("Iniciamos la cuenta");  // Imprime texto
}

void loop() {
 Serial.print("CONTADOR=");  // Imprime texto
 Serial.println(contador);  // Imprime el valor de la variable contador
 delay(1000);   // tiempo de espera de 1s              
 contador ++; // se incrementa el valor del contador en 1
}
