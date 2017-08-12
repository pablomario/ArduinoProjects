/*
Este programa permite escribir en un display de 16x2 compatible con el driver HD 44780 de Hitachi
*/

// Llamanos a la libreria Liquid Cristal
#include <LiquidCrystal.h>

// Inicializamos el display con los pines a utilizar en el siguiente orden: rs, enable, d4, d5, d6, d7
LiquidCrystal lcd(6, 7, 8, 9, 10, 11);

void setup() {
 lcd.begin(16, 2); // Definimos el tamaño de la pantalla en 16 caracteres y 2 lineas
 Serial.begin(9600); // Iniciamos el puerto serial a 9600 baudios
}

void loop() {
 lcd.clear(); // borramos lo que hay el display
 
  if (Serial.available()) {
    char c = Serial.read();
    if ( c == 'H' ) {
       lcd.setCursor(0, 0); 
       lcd.print("ACCESO  ACTIVADO");
       lcd.setCursor(0, 1);
       lcd.print("----------------");
    } else if ( c == 'L' ) {
        lcd.setCursor(0, 0); 
        lcd.print("ACCESO  DENEGADO");
        lcd.setCursor(0, 1);
        lcd.print("----------------");
    }
  }
  delay(5000); // retardamos la ejecucion del programa 250 milisegundos
}



