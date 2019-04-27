#include <ESP8266WiFi.h>

//Constants

const int pResistor = A0; // Photoresistor at Arduino analog pin A0
const int ledPin=14;       // Led pin at Arduino pin 9
const int ledPin2=4;       // Led pin at Arduino pin 9
const char *password = "";
int canal = 2;

//Variables
int value;          // Store value from photoresistor (0-1023)

void setup(){
  delay(1000);
  Serial.begin(115200);
 pinMode(ledPin, OUTPUT); 
  pinMode(ledPin2, INPUT);// Set lepPin - 9 pin as an output
 pinMode(pResistor, INPUT);// Set pResistor - A0 pin as an input (optional)

}

void loop(){
  value = analogRead(pResistor);

  String ssid="PruebaWifi-"+String(value);
  Serial.println(ssid);
  Serial.println(WiFi.softAP(ssid,password,canal) ? "Listo" : "Falló!");
  delay(1000); //Small delay
}
