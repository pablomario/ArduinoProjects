int pulsador=10;
int estadoPulsador=0;
int leds[6] = {1,2,3,4,5,6};
int estadoLed=0;
int pulsado=0;
int led=0;

void setup(){
  pinMode(pulsador,INPUT);
  for(led=0;led<6;led++){
    pinMode(leds[led],OUTPUT);
  }
}

void loop(){
  estadoPulsador=digitalRead(pulsador);
  if(estadoPulsador==HIGH && pulsado==0){
    for(led=0;led<=5;led++){
      digitalWrite(leds[led],HIGH);
      delay(50);
      digitalWrite(leds[led],LOW);
    }
    for(led=5;led>=0;led--){
      digitalWrite(leds[led],HIGH);
      delay(50);
      digitalWrite(leds[led],LOW);
    }
  }
  pulsado=estadoPulsador;
}
