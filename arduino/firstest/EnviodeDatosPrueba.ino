#include <Servo.h>
#define PIN_LED 7
#define PIN_MOT 5

Servo mot;

void setup() {
  Serial.begin(9600);
  delay(30);  
  pinMode(PIN_LED, OUTPUT);
  digitalWrite(PIN_LED,0);
  mot.attach(PIN_MOT);
  mot.write(0);  
}

int vmot=0,vled=0,pos;
String cad,cad1,cad2;

void loop() {
  if(Serial.available()){
    cad = Serial.readString(); 
    pos = cad.indexOf(',');
    cad1= cad.substring(0,pos);
    cad2= cad.substring(pos+1); 
    if(vled != cad1.toInt()){
      vled = cad1.toInt();  
      digitalWrite(PIN_LED,vled); 
    }
    if(vmot != cad2.toInt()){
      vmot = cad2.toInt();  
      mot.write(vmot);  
    }
             
    Serial.println(cad1);
    Serial.println(cad2);
    
      
  }
  
}
