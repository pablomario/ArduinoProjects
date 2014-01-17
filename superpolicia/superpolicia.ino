
int estado = 0;
int estadoanterior = 0;
int salida = 0;

void setup(){
  pinMode(8,INPUT);
  pinMode(3,OUTPUT);
  pinMode(5,OUTPUT);
  pinMode(6,OUTPUT); 
  pinMode(9,OUTPUT); 
  pinMode(10,OUTPUT); 
  pinMode(11,OUTPUT); 
}

void loop(){
 estado = digitalRead(8); 
 
 if((estado == HIGH)&&(estadoanterior==0)){ 
   salida = 1 - salida;
   delay(20);
 }
 estadoanterior = estado; //guardo el estado en el que esta
 
  if(salida == 1){
    for(int j=0; j<50; j++){
       for(int i=0; i<3;i++){
        digitalWrite(3, HIGH); 
        digitalWrite(5, HIGH); 
        digitalWrite(6, HIGH);
        delay(60);
        digitalWrite(3,LOW);
        digitalWrite(5,LOW);
        digitalWrite(6,LOW);
        delay(60);
      }
      for(int i=0; i<3; i++){
        digitalWrite(9, HIGH); 
        digitalWrite(10, HIGH); 
        digitalWrite(11, HIGH);
        delay(60);
        digitalWrite(9,LOW);
        digitalWrite(10,LOW);
        digitalWrite(11,LOW);
        delay(60);
      }
    }  
  salida =0 ;  
  }else{
    digitalWrite(3, LOW); 
    digitalWrite(5, LOW); 
    digitalWrite(6, LOW); 
    digitalWrite(9, LOW);
    digitalWrite(10, LOW); 
    digitalWrite(11, LOW);   
  }
}
