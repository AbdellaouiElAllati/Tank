#include <SoftwareSerial.h>
SoftwareSerial hc06(12,11);
String cmd="";

//-- MOTEUR A -- 
int ENA=9; //Connecté à Arduino pin 9(sortie PWM) 
int IN1=4; //Connecté à Arduino pin 4 
int IN2=5; //Connecté à Arduino pin 5 
//-- MOTEUR B -- 
int ENB=10; //Connecté à Arduino pin 10(Sortie PWM) 
int IN3=6; //Connecté à Arduino pin 6 
int IN4=7; //Connecté à Arduino pin 7 

void setup() { 
  Serial.begin(9600);
  delay(500);
  pinMode(ENA,OUTPUT); // Configurer 
  pinMode(ENB,OUTPUT); // les broches 
  pinMode(IN1,OUTPUT); // comme sortie 
  pinMode(IN2,OUTPUT); 
  pinMode(IN3,OUTPUT); 
  pinMode(IN4,OUTPUT); 
  digitalWrite(ENA,LOW);// Moteur A - Ne pas tourner 
  digitalWrite(ENB,LOW);// Moteur B - Ne pas tourner 
  
  // Direction du Moteur A 
  digitalWrite(IN1,LOW); 
  digitalWrite(IN2,HIGH);
  
  // Direction du Moteur B 
  // NB: en sens inverse du moteur A 
  digitalWrite(IN3,HIGH); 
  digitalWrite(IN4,LOW); 

}

void loop() { 
  while(hc06.available()>0){
  cmd+=(char)hc06.read();
  }
  if(cmd=="avant"){
    analogWrite(ENA,255);
    analogWrite(ENB,255);   
  }
    if(cmd=="arriere"){
    analogWrite(ENA,-255);
    analogWrite(ENB,-255); 
    
  }
    if(cmd=="gauche"){
    analogWrite(ENA,128);
    analogWrite(ENB,255); 
    
  }
    if(cmd=="droite"){
    analogWrite(ENA,255);
    analogWrite(ENB,128); 
    
  }
    if(cmd=="stop"){
    analogWrite(ENA,0);
    analogWrite(ENB,0); 
    
  }
}
