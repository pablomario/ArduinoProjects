
int estado = 0;
int estadoanterior = 0;
int salida = 0;

void setup(){
  pinMode(8,INPUT);
  pinMode(11,OUTPUT);
  pinMode(10,OUTPUT); 
  pinMode(6,OUTPUT); 
  pinMode(5,OUTPUT); 
}

void loop(){
 estado = digitalRead(8); 
 
 if((estado == HIGH)&&(estadoanterior==0)){ 
   salida = 1 - salida;
   delay(50);
 }
 estadoanterior = estado; //guardo el estado en el que esta
 
  if(salida == 1){
    for(int j=0; j<20;j++){
      for(int i = 0; i<3; i++){ 
       digitalWrite(11, HIGH); 
       digitalWrite(10, HIGH); 
       delay(50);   
       digitalWrite(11, LOW); 
       digitalWrite(10, LOW);
       delay(50); 
     }
     for(int i = 0; i<3; i++){       
       digitalWrite(6, HIGH); 
       digitalWrite(5, HIGH); 
       delay(50);   
       digitalWrite(6, LOW); 
       digitalWrite(5, LOW);
       delay(50); 
     }
    }
    salida=0;
  }
}
