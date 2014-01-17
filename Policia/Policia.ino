
int led1 = 11;
int led2 = 10;
int led4 = 5;
int led5 = 3;
int miDelay = 50;

void setup() {                
  pinMode(led1, OUTPUT);  
  pinMode(led2, OUTPUT); 

  pinMode(led4, OUTPUT); 
  pinMode(led5, OUTPUT);  
}
void loop() {
    digitalWrite(led1, HIGH); 
    digitalWrite(led2, HIGH); 
  delay(miDelay);   
    digitalWrite(led1, LOW); 
    digitalWrite(led2, LOW);
  delay(miDelay); 
    digitalWrite(led1, HIGH); 
    digitalWrite(led2, HIGH); 
  delay(miDelay);   
    digitalWrite(led1, LOW); 
    digitalWrite(led2, LOW); 
  delay(miDelay); 
   digitalWrite(led1, HIGH); 
    digitalWrite(led2, HIGH); 
  delay(miDelay);   
    digitalWrite(led1, LOW); 
    digitalWrite(led2, LOW);  
  delay(80); 
    digitalWrite(led4, HIGH); 
    digitalWrite(led5, HIGH); 
  delay(miDelay);   
    digitalWrite(led4, LOW); 
    digitalWrite(led5, LOW);
  delay(miDelay); 
    digitalWrite(led4, HIGH); 
    digitalWrite(led5, HIGH); 
  delay(miDelay);   
    digitalWrite(led4, LOW); 
    digitalWrite(led5, LOW); 
  delay(miDelay); 
   digitalWrite(led4, HIGH); 
    digitalWrite(led5, HIGH); 
  delay(miDelay);   
    digitalWrite(led4, LOW); 
    digitalWrite(led5, LOW);
   delay(80); 
  
}
