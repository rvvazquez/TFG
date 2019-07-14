#include "ESP8266WiFi.h"
#include "xxtea-iot-crypt.h"//https://github.com/boseji/xxtea-lib

//constantes
const int canal=2;
int pinD6=12;
scan_config scan = {
          NULL,                         //SSID
          NULL,                         //bssid
          canal,                         //channel
          false                         //hide channels
      };
   
//variables
String ssid="";

void setup()
{
  Serial.begin(115200);             //Frecuencia Serial
  pinMode(pinD6,OUTPUT);            //Configuración como puerto de salida
  WiFi.mode(WIFI_STA);              //Configuramos wifi como estación
  WiFi.disconnect();                //Desconexión de cualquier red conectada
  delay(100);                   
  xxtea.setKey("8K0DANJuGUawTuSv"); //Clave desencriptación
}

//callback llamado tras cada escaneo
static  void  ICACHE_FLASH_ATTR scan_done(void *arg, STATUS  status){

    struct  bss_info  *bss_link = (struct bss_info  *)arg;
    ssid="";
    if(bss_link!=NULL){
        
        while (bss_link != NULL) {

          String value((char*)bss_link->ssid);
          if(xxtea.decrypt(value)!="-FAIL-"){
            ssid=xxtea.decrypt(value);
            if(ssid.startsWith("LDR")){
                break;
             }
           }
           bss_link = bss_link->next.stqe_next;
       } 
    }
}



void loop()
{
    wifi_station_scan(&scan, scan_done); //función de escaneo con las propiedades de configuración del struct scan, al finalizar llama a la función scan_done

    if(!ssid.equals("")){

      int datoInt =  ssid.substring(4).toInt();

      if (datoInt > 70){
        
        digitalWrite(pinD6, LOW);  
    
      }else{
          digitalWrite(pinD6, HIGH); 
        }
        
    }
  
  delay(100);
  

 
}


