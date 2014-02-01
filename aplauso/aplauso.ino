boolean estado = false;
boolean encendido = false;
boolean anterior= false;

void setup(){
  pinMode(2,OUTPUT);
  pinMode(3,OUTPUT);
  pinMode(4,OUTPUT);
  pinMode(8,INPUT);
    digitalWrite(2,LOW);
    digitalWrite(3,LOW);
    digitalWrite(4,LOW);
    Serial.begin(9600);
}


void loop(){
  
    estado = digitalRead(8);
    Serial.println(estado);
    delay(60);
    
 
 if(anterior==false && estado == HIGH){   
   if(encendido == false){
       digitalWrite(2,HIGH);
       digitalWrite(3,HIGH);
       digitalWrite(4,HIGH);
       encendido = true;
   }else if(encendido == true){
      digitalWrite(2,LOW);
      digitalWrite(3,LOW);
      digitalWrite(4,LOW);
      encendido = false;
  }  
 }
 anterior = estado;
}

