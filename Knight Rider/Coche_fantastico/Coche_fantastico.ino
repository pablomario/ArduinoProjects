int estado=0;
int leds[6] = {1,2,3,4,5,6};
int estadoLed=0;
int led=0;
int programa = 0;
int anterior=0;

void setup(){
  pinMode(10,INPUT);
  for(led=0;led<6;led++){
    pinMode(leds[led],OUTPUT);
  }
}

void loop(){
  estado=digitalRead(10);
   if(estado == HIGH){ 
     programa++;
     delay(20);
   }
   if(programa==1 && anterior == 0){
     programa1();
     anterior = 1;
   }else if(programa==2 && anterior == 1){
     programa2();
     anterior = 2;
   }else if(programa == 3 && anterior == 2){
     programa3();
     anterior=3;
   }else if(programa == 4 && anterior ==3){
     programa4();
     programa=0;
     anterior=0;
   }
 
}

void programa1(){
  for(int i=0; i<5;i++){
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
}

void programa2(){
   for(int j = 0; j<6; j++){
      digitalWrite(leds[j],HIGH);
      delay(50);
   }
}

void programa3(){
  for(int j = 0; j<6; j++){
      digitalWrite(leds[j],LOW);
      delay(50);
    }
 }
 
 
void programa4(){
  for(int j =0; j<6;j++){
      for(int i=1; i<3;i++){
        digitalWrite(1,HIGH);
        digitalWrite(2,HIGH);
        digitalWrite(3,HIGH);
        delay(50);
        digitalWrite(1,LOW);
        digitalWrite(2,LOW);
        digitalWrite(3,LOW);
        delay(50); 
      }
      for(int i=1; i<3;i++){
        digitalWrite(4,HIGH);
        digitalWrite(5,HIGH);
        digitalWrite(6,HIGH);
        delay(50);
        digitalWrite(4,LOW);
        digitalWrite(5,LOW);
        digitalWrite(6,LOW);
        delay(50); 
      }
   }  
}
