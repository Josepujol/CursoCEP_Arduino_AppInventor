/*
  Nombre proyecto:  Configuración de modulo Bluetooth HC-06
  URL proyecto:     http://giltesa.com/?p=11738
  Fecha:        09/08/2012
  Licencia:    (CC) BY-NC-SA: giltesa.com

  El siguiente código permite configurar el modulo Bluetooth HC-06 desde Arduino.
  Se puede ajustar el nombre, la contraseña y los baudios a usar con el puerto serie.
  La configuración Bluetooth se guarda en el modulo, así que solo es necesario configurarlo una vez.
  
  Después de grabar el programa en el Arduino se dispone de 10 segundos de tiempo para conectar el
  modulo, una vez se apague el led comenzara el proceso de configuración y al terminar el led comenzara
  a parpadear.
  
  ** La configuración se ha de hacer con el modulo sin emparejar (sin conectar con nada) **
*/


// Opciones de configuración:
  char ssid[10]   = "Arduino1"; // Nombre para el modulo Bluetooth.
  char baudios     = '4';      // 1=>1200 baudios, 2=>2400, 3=>4800, 4=>9600 (por defecto), 5=>19200, 6=>38400, 7=>57600, 8=>115200
  char password[10] = "1234";   // Contraseña para el emparejamiento del modulo.


void setup()
{
  Serial.begin(9600);
  
  // Tiempo de espera:
    pinMode(13,OUTPUT);
    digitalWrite(13,HIGH);
    delay(10000);
    digitalWrite(13,LOW);
  
  // Ahora se procede a la configuración del modulo:
  
    // Se inicia la configuración:
      Serial.print("AT"); delay(1000);

    // Se ajusta el nombre del Bluetooth:
      Serial.print("AT+NAME"); Serial.print(ssid); delay(1000);

    // Se ajustan los baudios:
      Serial.print("AT+BAUD"); Serial.print(baudios); delay(1000);

    // Se ajusta la contraseña:
      Serial.print("AT+PIN"); Serial.print(password); delay(1000);  
}

void loop()
{
  // Al parpadear el led se habrá terminado la configuración:
  digitalWrite(13, !digitalRead(13));
  delay(500);
}
