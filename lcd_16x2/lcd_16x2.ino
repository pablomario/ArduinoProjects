/*
Este programa permite escribir en un display de 16x2 compatible con el driver HD 44780 de Hitachi
*/

// Llamanos a la libreria Liquid Cristal
#include <LiquidCrystal.h>

// Inicializamos el display con los pines a utilizar en el siguiente orden: rs, enable, d4, d5, d6, d7
LiquidCrystal lcd(6, 7, 8, 9, 10, 11);


void setup() {
 lcd.begin(16, 2); // Definimos el tamaño de la pantalla en 16 caracteres y 2 lineas
}

void loop() {
 lcd.clear(); // borramos lo que hay el display
 lcd.setCursor(3, 0); // Nos posicionamos en el tercer caracter de la primer linea 0,0
 lcd.print("Hola Mundo");// Escribimos en la primera linea el display

 lcd.setCursor(0, 1); // Nos posicionamos en el primer caracter de la segunda linea 0,1
 lcd.print("BY CESAR GAMARRA"); // Escribimos en la segunda linea del display

 delay(250); // retardamos la ejecucion del programa 250 milisegundos

}
