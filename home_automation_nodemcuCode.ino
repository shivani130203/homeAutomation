#include <UbidotsMicroESP8266.h>

#define TOKEN "AlE-fEZr6tGhxt7tq0uvAVKJUiNaHpQULx"
#define ref "5bcdbf9dc03f970bbe05ble4"
#define laser "5bcdbf9dc03f970bbe05bld4"
#define gas "5bcdbf74c03f970b3a083bc8"
#define soil "5bcdbf94c03f970bbe05blel"
#define temp "5bcdbf88c03f970bbe05blde"

#define WIFISSID "madhu1"  
#define PASSWORD "madhuiot"
int vref,vlaser,vgas,vsoil,vtemp;
Ubidots client(TOKEN)

#define S0 D0
#define S1 D1
#define S2 D2
#define S3 D3

#define analogpin 0

void setup() {
Serial.begin(115200);
client.wifiConnection(WIFISSID,PASSWORD);
pinMode(analogpin,INPUT);
pinMode(S0,OUTPUT);
pinMode(S1,OUTPUT);
pinMode(S2,OUTPUT);
pinMode(S3,OUTPUT);

digitalWrite(S0,LOW);
digitalWrite(S1,LOW);
digitalWrite(S2,LOW);
digitalWrite(S3,LOW);

}

void loop() {
digitalWrite(S0,LOW);
digitalWrite(S1,LOW);
digitalWrite(S2,LOW);
digitalWrite(S3,LOW);

delay(100);

vgas=analogRead(analogpin);
client.add(gas,vgas);
client.sendAll(false);
Serial.print("gas");
Serial.println(vgas);

digitalWrite(S0,HIGH);
digitalWrite(S1,LOW);
digitalWrite(S2,LOW);
digitalWrite(S3,LOW);
delay(100);
vlaser=analogRead(analogpin);
client.add(laser,vlaser);
client.sendAll(false);
Serial.print("laser");
Serial.println(vlaser);

digitalWrite(S0,LOW);
digitalWrite(S1,HIGH);
digitalWrite(S2,LOW);
digitalWrite(S3,LOW);
delay(100);
vtemp=analogRead(analogpin);
client.add(temp,vtemp);
client.sendAll(false);
Serial.print("temp");
Serial.println(vtemp);



digitalWrite(S0,HIGH); //FC-28
digitalWrite(S1,HIGH);
digitalWrite(S2,LOW);
digitalWrite(S3,LOW);
delay(100);
vsoil=analogRead(analogpin);
client.add(soil,1024-vsoil);
client.sendAll(false);
Serial.print("soil");
Serial.println(vsoil);


digitalWrite(S0,LOW);
digitalWrite(S1,LOW);
digitalWrite(S2,HIGH);
digitalWrite(S3,LOW);
delay(100);
vtemp=analogRead(analogpin);
client.add(ref,vref);
client.sendAll(false);
Serial.print("ref");
Serial.println(vref);

}
