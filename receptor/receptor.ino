#include "ESP8266WiFi.h"
String ssid="";
int pinD6=12;
void setup()
{
  Serial.begin(115200);
  Serial.println();
  pinMode(pinD6,OUTPUT);

  WiFi.mode(WIFI_STA);
  WiFi.disconnect();
  delay(100);
}

void loop()
{
  
  int n = WiFi.scanNetworks();

  for (int i = 0; i < n; i++)
  {
    ssid=WiFi.SSID(i);
    String cabeza=ssid.substring(0,11);
    String dato=ssid.substring(11);
    if(cabeza=="PruebaWifi-"){

       if (dato.toInt() > 900){
        
    digitalWrite(pinD6, LOW);  //Turn led off
    
  }
  else{
           

    digitalWrite(pinD6, HIGH); //Turn led on
    
  }
    }
    Serial.println(cabeza);
    
    Serial.println(dato);

  }
  Serial.println();

  //delay(1000);
}
