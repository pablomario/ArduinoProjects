/* Sketch medidor ultrasonico */
/* Creado por Josemanu        */
/* para Ardumania.es          */


// necesitamos una variable para medir el pulso
unsigned long pulso;
// otra para calcular la distancia
float distancia;
// y otra para el pin
int pin = 8;  

void setup()  
{
  // inicializamos el puerto serie
  Serial.begin(9600);
}
void loop()
{
  // ponemos el pin como salida
  pinMode(pin, OUTPUT);
  // lo activamos
  digitalWrite(pin, HIGH);
  // esperamos 10 microsegundos
  delayMicroseconds(10);
  // lo desactivamos
  digitalWrite(pin, LOW);
  // cambiamos el pin como entrada
  pinMode(pin, INPUT);
  // medimos el pulso de salida del sensor
  pulso = pulseIn(pin, HIGH);
  // lo pasamos a milisegundos y lo sacamos por el puerto serie
  Serial.print("tiempo = ");
  Serial.print(float(pulso/1000.0));
  // ahora calculamos la distancia en cm y al puerto serie
  Serial.print("ms, distancia = ");
  distancia = ((float(pulso/1000.0))*34.32)/2;
  Serial.print(distancia);
  Serial.println("cm");
  // esperamos un segundo antes de hacer una nueva medida
  delay(1000);
}
