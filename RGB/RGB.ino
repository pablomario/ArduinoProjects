int ledRojo = 11;
int ledVerde = 10;
int ledAzul = 9;

void setup(){
  pinMode(ledRojo, OUTPUT);
  pinMode(ledVerde, OUTPUT);
  pinMode(ledAzul,OUTPUT);
}

void loop(){
  color(255,0,0);
  delay(1000);
  color(0,255,0);
  delay(1000);
  color(0,0,255);
  delay(1000);
}

void color(int rojo, int verde, int azul){ 
  analogWrite(ledRojo, 255-rojo);
  analogWrite(ledVerde, 255-verde);
  analogWrite(ledAzul, 255-azul);  
}
