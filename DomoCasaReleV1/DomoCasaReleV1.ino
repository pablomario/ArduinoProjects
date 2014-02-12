

#include <SPI.h>
#include <Ethernet.h>

//Declaración de la direcciones MAC e IP. También del puerto 80
byte mac[]={0xDE,0xAD,0xBE,0xEF,0xFE,0xED}; //MAC
IPAddress ip(192,168,1,100); //IP
EthernetServer servidor(80);

int rele = 7;
String readString=String(30);
String stateE=String(3);
void setup(){
  Ethernet.begin(mac, ip); //Inicializamos con las direcciones asignadas
  servidor.begin();
  pinMode(rele,OUTPUT);
  stateE="OFF";
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
          if (readString.substring(LEC,LEC+6)=="LEC=ET"){
            digitalWrite(rele,LOW);
            stateE="OFF";
          }else if (readString.substring(LEC,LEC+6)=="LEC=EF"){
            digitalWrite(rele,HIGH);
            stateE="ON";
          }
          
          
          //Cabecera HTTP estándar
          cliente.println("HTTP/1.1 200 OK");
          cliente.println("Content-Type: text/html");
          cliente.println();
          //Página Web en HTML
          
cliente.print("<!DOCTYPE html><html><head><title>DomoCasa - Bytelchus</title></head><body style='margin:0; padding:0;'><header style='background: url(http://bytelchus.com/wp-content/uploads/2014/01/bg-main-block-short.jpg); margin: 0 auto 20px auto;'><center><img src='http://bytelchus.com/wp-content/uploads/2014/01/cropped-logo1.png'></center></header><article style='margin: 0 auto; width: 90%; text-aling: center;'>");

cliente.print("<section>Luz de la <span style='font-weight: bold;'>RELE:");
cliente.print(stateE);
cliente.print("</span><br><br><center><input type=submit value=OFF style=width:200px;height:75px onClick=location.href='./?LEC=ET\'><input type=submit value=ON style=width:200px;height:75px onClick=location.href='./?LEC=EF\'></center></section>");
cliente.print("</center></section></article></body></html>");
     
    cliente.stop();//Cierro conexión con el cliente
          readString="";
        }
      }
    }
  }
}
