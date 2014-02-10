

#include <SPI.h>
#include <Ethernet.h>

//Declaración de la direcciones MAC e IP. También del puerto 80
byte mac[]={0xDE,0xAD,0xBE,0xEF,0xFE,0xED}; //MAC
IPAddress ip(192,168,1,100); //IP
EthernetServer servidor(80);

int SALON=5;
int ENTRADA=6;
int PASILLO=7;
String readString=String(30);
String stateS=String(3);
String stateE=String(3);
String stateP=String(3);

void setup()
{
  Ethernet.begin(mac, ip); //Inicializamos con las direcciones asignadas
  servidor.begin();
  pinMode(SALON,OUTPUT);
  pinMode(ENTRADA, OUTPUT);
  pinMode(PASILLO,OUTPUT);
  digitalWrite(SALON,LOW);
  digitalWrite(ENTRADA,LOW);
  digitalWrite(PASILLO,LOW);
  stateS="OFF";
  stateE="OFF";
  stateP="OFF";
}

void loop(){
  EthernetClient cliente= servidor.available();  
  if(cliente){
    boolean lineaenblanco=true;
    while(cliente.connected())//Cliente conectado
    {
      if(cliente.available()){
        char c=cliente.read();
        if(readString.length()<30){//Leemos petición HTTP caracter a caracter        
          readString.concat(c); //Almacenar los caracteres en la variable readString
        }
        if(c=='\n' && lineaenblanco){//Si la petición HTTP ha finalizado        
          int LEC = readString.indexOf("LEC=");
          if(readString.substring(LEC,LEC+6)=="LEC=ST"){
            digitalWrite(SALON,LOW);
            stateS="OFF";
          }else if (readString.substring(LEC,LEC+6)=="LEC=SF"){
            digitalWrite(SALON,HIGH);
            stateS="ON";
          }else if (readString.substring(LEC,LEC+6)=="LEC=ET"){
            digitalWrite(ENTRADA,LOW);
            stateE="OFF";
          }else if (readString.substring(LEC,LEC+6)=="LEC=EF"){
            digitalWrite(ENTRADA,HIGH);
            stateE="ON";
          }else if (readString.substring(LEC,LEC+6)=="LEC=PT"){
            digitalWrite(PASILLO,LOW);
            stateP="OFF";
          }else if (readString.substring(LEC,LEC+6)=="LEC=PF"){
            digitalWrite(PASILLO,HIGH);
            stateP="ON";
          }
          
          
          //Cabecera HTTP estándar
          cliente.println("HTTP/1.1 200 OK");
          cliente.println("Content-Type: text/html");
          cliente.println();
          //Página Web en HTML
          
cliente.print("<!DOCTYPE html><html><head><title>DomoCasa - Bytelchus</title></head><body style='margin:0; padding:0;'><header style='background: url(http://bytelchus.com/wp-content/uploads/2014/01/bg-main-block-short.jpg); margin: 0 auto 20px auto;'><center><img src='http://bytelchus.com/wp-content/uploads/2014/01/cropped-logo1.png'></center></header><article style='margin: 0 auto; width: 90%; text-aling: center;'><section>Estado del <span style='font-weight: bold;'>ENTRADA:");
cliente.print(stateE);
cliente.print("</span><br><br><input type=submit value=OFF style=width:200px;height:75px onClick=location.href='./?LEC=ET\'><input type=submit value=ON style=width:200px;height:75px onClick=location.href='./?LEC=EF\'></section>");

cliente.print("<section><hr/> Estado del <span style='font-weight: bold;'>SALON: ");
cliente.print(stateS);
cliente.print("</span><br><br><input type=submit value=OFF style=width:200px;height:75px onClick=location.href='./?LEC=ST\'><input type=submit value=ON style=width:200px;height:75px onClick=location.href='./?LEC=SF\'></section>");

cliente.print("<section><hr/>Estado del <span style='font-weight: bold;'>PASILLO: ");
cliente.print(stateP);
cliente.print("</span><br><br><input type=submit value=OFF style=width:200px;height:75px onClick=location.href='./?LEC=PT\'><input type=submit value=ON style=width:200px;height:75px onClick=location.href='./?LEC=PF\'></section></article></body></html>");
     
    cliente.stop();//Cierro conexión con el cliente
          readString="";
        }
      }
    }
  }
}
