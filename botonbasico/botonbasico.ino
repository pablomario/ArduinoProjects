
int estado = 0;
int estadoanterior = 0;
int salida = 0;
int miDelay = 50;
int cont = 0;

void setup(){
  pinMode(8,INPUT);
  pinMode(11,OUTPUT);
pinMode(10,OUTPUT); 
pinMode(9,OUTPUT); 
pinMode(6,OUTPUT); 
}

void loop(){
 estado = digitalRead(8); 
 
 if((estado == HIGH)&&(estadoanterior==0)){ 
   salida = 1 - salida;
   delay(20);
 }
 estadoanterior = estado; //guardo el estado en el que esta
 
  if(salida == 1){
    digitalWrite(11, HIGH); 
    digitalWrite(10, HIGH); 
    digitalWrite(9, LOW); 
    digitalWrite(6, LOW);
  }else{
     digitalWrite(9, HIGH); 
     digitalWrite(6, HIGH); 
     digitalWrite(11, LOW); 
    digitalWrite(10, LOW);    
  }
}
