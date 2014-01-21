int leds[10]={0,1,2,4,5,6,7,8,9,10};

void setup(){
  for(int i = 0; i<10;i++){
    pinMode(leds[i],OUTPUT);
  }
}

void loop(){
  for(int i=0;i<10;i++){
    digitalWrite(leds[i],HIGH);
    delay(50);
  }
  
}
