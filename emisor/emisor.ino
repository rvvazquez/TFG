#include <ESP8266WiFi.h>
#include "xxtea-iot-crypt.h"//https://github.com/boseji/xxtea-lib

//Constants

const int analogico = A0; // PIN analogico
const char *password = "";
int canal = 2;

//Variables
int value;    // Valor recogido en el puerto analógico

//funcion de configuración
void setup(){
  
  delay(1000);
  Serial.begin(115200);               //Frecuencia serial
  pinMode(analogico, INPUT);         //Configuración puerto analógico como entrada
  xxtea.setKey("8K0DANJuGUawTuSv");  //Configurar la contraseña de encriptado

}

void loop(){
  
  value = analogRead(analogico);             
  value = map(value, 0, 1024, 0, 100);        
  
  String ssid="LDR-"+String(value);
  String result = xxtea.encrypt(ssid);
  
  Serial.println(WiFi.softAP(result,password,canal) ? "Listo" : "Falló!");
  delay(100); 
  
}
