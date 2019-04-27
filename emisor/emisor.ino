#include <ESP8266WiFi.h>

//Constants

const int pResistor = A0; // Photoresistor at Arduino analog pin A0
const int ledPin=14;       // Led pin at Arduino pin 9
const int ledPin2=4;       // Led pin at Arduino pin 9

//Variables
int value,value2;          // Store value from photoresistor (0-1023)

void setup(){
  delay(1000);
  Serial.begin(115200);
 pinMode(ledPin, OUTPUT); 
  pinMode(ledPin2, INPUT);// Set lepPin - 9 pin as an output
 pinMode(pResistor, INPUT);// Set pResistor - A0 pin as an input (optional)
 Serial.println(WiFi.softAP("PruebaWifi") ? "Listo" : "Falló!");

}

void loop(){
  value = analogRead(pResistor);
  Serial.print(value+" ");

  String ssid="PruebaWifi-"+String(value);
  Serial.println(ssid);
  Serial.println(WiFi.softAP(ssid) ? "Listo" : "Falló!");
  
  /*//You can change value "25"
  if (value > 400){
    digitalWrite(ledPin, LOW);  //Turn led off
    value2=digitalRead(ledPin2);
    Serial.print("LOW, ");
    Serial.println(value2);
  }
  else{
    digitalWrite(ledPin, HIGH); //Turn led on
    value2=digitalRead(ledPin2);
    Serial.print("HIGH, ");
    Serial.println(value2);
  }
*/
  delay(1000); //Small delay
}
