/* Version Final*/

int leds[10]={0,1,2,4,5,6,7,8,9,10};
int const potenciometro = 0;
int entradaPotenciometro=0;
int cacho = 1023/10;
int posicion = 0;

void setup(){
  for(int i = 0; i<10;i++){
    pinMode(leds[i],OUTPUT);
  }
}

void loop(){
  entradaPotenciometro = analogRead(potenciometro);
  posicion = entradaPotenciometro/cacho;
  if(posicion>=1)digitalWrite(0,HIGH);
  else digitalWrite(0,LOW);
  if(posicion>=2)digitalWrite(1,HIGH);
  else digitalWrite(1,LOW);
  if(posicion>=3)digitalWrite(2,HIGH);
  else digitalWrite(2,LOW);
  if(posicion>=4)digitalWrite(4,HIGH);
  else digitalWrite(4,LOW);
  if(posicion>=5)digitalWrite(5,HIGH);
  else digitalWrite(5,LOW);
  if(posicion>=6)digitalWrite(6,HIGH);
  else digitalWrite(6,LOW);
  if(posicion>=7)digitalWrite(7,HIGH);
  else digitalWrite(7,LOW);
  if(posicion>=8)digitalWrite(8,HIGH);
  else digitalWrite(8,LOW);
  if(posicion>=9)digitalWrite(9,HIGH);
  else digitalWrite(9,LOW);
  if(posicion>=10)digitalWrite(10,HIGH);
  else digitalWrite(10,LOW);
  
}
