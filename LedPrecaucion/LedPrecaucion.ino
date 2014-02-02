
int aviso = 13;

void setup(){
  pinMode(aviso,OUTPUT);
}


void loop(){
  Activado(aviso);
  delay(600);
  
}

void Activado(int in){
  for(int i= 0; i<3; i++){
    digitalWrite(in,HIGH);
    delay(60);
    digitalWrite(in, LOW);
    delay(60);
  }
}

