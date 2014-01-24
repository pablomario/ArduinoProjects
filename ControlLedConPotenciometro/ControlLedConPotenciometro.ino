/* Version Final*/

int leds[10]={2,3,4,6,7,8,9,10,11,12};
int const potenciometro = 0;
int entradaPotenciometro=0;
int cacho = 1023/10;
int posicion = 0;

void setup(){
  for(int i = 0; i<10;i++){
    pinMode(leds[i],OUTPUT);
    digitalWrite(leds[i],LOW);
  }  
  Serial.begin(115200);
}

void loop(){
  entradaPotenciometro = analogRead(potenciometro);
  posicion = entradaPotenciometro/cacho;
  Serial.println(posicion); 
  if(posicion>=1)digitalWrite(2,HIGH);
  else digitalWrite(2,LOW);
  if(posicion>=2)digitalWrite(3,HIGH);
  else digitalWrite(3,LOW);
  if(posicion>=3)digitalWrite(4,HIGH);
  else digitalWrite(4,LOW);
  if(posicion>=4)digitalWrite(6,HIGH);
  else digitalWrite(6,LOW);
  if(posicion>=5)digitalWrite(7,HIGH);
  else digitalWrite(7,LOW);
  if(posicion>=6)digitalWrite(8,HIGH);
  else digitalWrite(8,LOW);
  if(posicion>=7)digitalWrite(9,HIGH);
  else digitalWrite(9,LOW);
  if(posicion>=8)digitalWrite(10,HIGH);
  else digitalWrite(10,LOW);
  if(posicion>=9)digitalWrite(11,HIGH);
  else digitalWrite(11,LOW);
  if(posicion>=10)digitalWrite(12,HIGH);
  else digitalWrite(12,LOW);
  
}
