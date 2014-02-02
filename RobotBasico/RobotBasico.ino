// Ultrasonic - Library for HR-SC04 Ultrasonic Ranging Module.
// Rev.4 (06/2012)
// J.Rodrigo ( www.jra.so )
// more info at www.ardublog.com

// ROBOT BASICO
// Rev.1 (02/14)
// Pablo Mario Garcia (@l0stconnection)
// Bytelchus.com

#include <Ultrasonic.h>
Ultrasonic ultrasonic(9,8); // (Trig PIN,Echo PIN)
int aviso = 13;
int derecha[2] = {2,3}; // motor derecho
int izqueirda[2]={5,6}; // motor izqueirdo
int aleatorio;
int distancia;

void setup(){
  pinMode(aviso,OUTPUT);
  pinMode(2,OUTPUT);
  pinMode(3,OUTPUT);
  pinMode(5,OUTPUT);
  pinMode(6,OUTPUT);
  Serial.begin(9600);
}


void loop(){
  Activado(aviso);
 delay(1000); 
  distancia = ultrasonic.Ranging(CM); // CM or INC
  Serial.print(distancia); 
  Serial.println(" cm" );  
 if(distancia <= 10){
     aleatorio = random(0,9);
    if(aleatorio<=4){
      giro(2,3);
    }else{
      giro(5,6);
    }  
 } else{
   anda();
 }
}

void anda(){
  digitalWrite(2,HIGH);
  digitalWrite(3,HIGH);
  digitalWrite(5,HIGH);
  digitalWrite(6,HIGH);
  delay(2000);
  digitalWrite(2,LOW);
  digitalWrite(3,LOW);
  digitalWrite(5,LOW);
  digitalWrite(6,LOW);  
}

void giro(int mot1, int mot2){
  digitalWrite(mot1,HIGH);
  digitalWrite(mot2,HIGH);
  delay(1000);
  digitalWrite(mot1,LOW);
  digitalWrite(mot2,LOW);
}

void Activado(int in){
    digitalWrite(in,HIGH);
    delay(100);
    digitalWrite(in, LOW);
}



