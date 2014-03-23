#include <SPI.h>
#include <MFRC522.h>

#define SS_PIN 10
#define RST_PIN 9
MFRC522 mfrc522(SS_PIN, RST_PIN);	// Create MFRC522 instance.
byte cardPresent;
String codRFID = "";

void setup() {
  Serial.begin(9600);	// Initialize serial communications with the PC
  SPI.begin();			// Init SPI bus
  mfrc522.PCD_Init();	// Init MFRC522 card
 // Serial.println("Ready!");
 pinMode(5,OUTPUT);
 pinMode(7,OUTPUT);
}

void loop() {
  codRFID="";
   
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
      
        
        if(codRFID.equals("1966540235")){
          Serial.println("Puede Entrar");
          digitalWrite(5,HIGH);
          delay(2000);
          digitalWrite(5,LOW);
        }
        if(codRFID.equals("208027201")){
          Serial.println("Puede irse a tomar por culo");
          digitalWrite(7,HIGH);
          delay(2000);
          digitalWrite(7,LOW);
        }
          
 

        delay(500);
}
