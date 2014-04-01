#include <SPI.h>
#include <MFRC522.h>
#include <LiquidCrystal.h>

#define SS_PIN 10
#define RST_PIN 9
MFRC522 mfrc522(SS_PIN, RST_PIN);	// Create MFRC522 instance.
byte cardPresent;
LiquidCrystal lcd(2,3,4,5,6,7);
String codRFID="";

void setup() {
  Serial.begin(9600);	// Initialize serial communications with the PC
  SPI.begin();			// Init SPI bus
  mfrc522.PCD_Init();	// Init MFRC522 card
 // Serial.println("Ready!");
 lcd.begin(16, 2);
}

void loop() {
  codRFID="";
  
 lcd.setCursor(3, 0); // Nos posicionamos en el tercer caracter de la primer linea 0,0
 lcd.print("<< RFID >>");// Escribimos en la primera linea el display
 lcd.setCursor(0, 1); // Nos posicionamos en el primer caracter de la segunda linea 0,1
 lcd.print(" Bytelchus.com"); // Escribimos en la segunda linea del display   
  // Look for new cards
        if ( ! mfrc522.PICC_IsNewCardPresent()) {
          return;
        }

// Select one of the cards
        if ( ! mfrc522.PICC_ReadCardSerial()) {
          return;
        }
//Serial.print("Card UID:");
        for (byte i = 0; i < mfrc522.uid.size; i++) {
                //Serial.print(mfrc522.uid.uidByte[i] < 0x10 ? " 0" : " ");
                Serial.print(mfrc522.uid.uidByte[i], HEX);
                codRFID = codRFID+mfrc522.uid.uidByte[i];
        } 
        Serial.println();
      
        
        if(codRFID.equals("1966540235") || codRFID.equals("208027201")){
          Serial.println("Puede Entrar");
          lcd.setCursor(3, 0); // Nos posicionamos en el tercer caracter de la primer linea 0,0
           lcd.print("<< RFID >>");// Escribimos en la primera linea el display
           lcd.setCursor(0, 1); // Nos posicionamos en el primer caracter de la segunda linea 0,1
           lcd.print("ACCESO PERMITIDO"); // Escribimos en la segunda linea del display 
           delay(900);   
            lcd.clear(); // borramos lo que hay el display       
        }else{          
           lcd.setCursor(3, 0); // Nos posicionamos en el tercer caracter de la primer linea 0,0
           lcd.print("<< RFID >>");// Escribimos en la primera linea el display
           lcd.setCursor(0, 1); // Nos posicionamos en el primer caracter de la segunda linea 0,1
           lcd.print("ACCESO DENEGADO!"); // Escribimos en la segunda linea del display 
           delay(900);
           lcd.clear(); // borramos lo que hay el display
        }
          
 

        delay(500);
}
