int brillo;
int potenciometro = 0; //conectado a A0

// la entrada del potenciometro no hay que declararla pues por defecto es entrada


void setup(){
  pinMode(8, OUTPUT);
}

void loop(){
  brillo = analogRead(potenciometro) / 4;
  /* leo el valor del potenciometro y lo divido entre 4 para
  poder usarlo en analogWrite que el maximo es 254 */
  analogWrite(8, brillo);
}
