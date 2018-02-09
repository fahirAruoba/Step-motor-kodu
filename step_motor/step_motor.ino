 
int pos = 0;
#include <Servo.h>  /* Servo kutuphanesi projeye dahil edildi */
Servo servoNesnesi;  /* servo motor nesnesi yaratildi */


int isikSensoru = A0;

int sensorDeger = 0;


void setup() {
 servoNesnesi.attach(11);   
  Serial.begin(4800);

}

void loop() {
  
int yenideger = analogRead(isikSensoru);
int GelenDeger = map(yenideger, 0, 1023,0,50);
delay(30);
 
 

   Serial.println(GelenDeger);
Serial.print(" ");
Serial.print(" ");
Serial.print(" ");

 

if(GelenDeger > 10){
cardakAc();
while(GelenDeger>10){
//servo kodu BURAYA
delay(30);
int yenideger = analogRead(isikSensoru);
int GelenDeger = map(yenideger, 0, 1023,0,50);

   Serial.println(GelenDeger);
Serial.print(" ");
Serial.print(" ");
Serial.print(" ");

if(GelenDeger < 10){
cardakKapa();
break;

  }

 }
 
}
else if(GelenDeger < 10){
cardakKapa();
}

}
void cardakAc(){
 
 servoNesnesi.write(50);  
  delay(10);
}

void cardakKapa(){
 
servoNesnesi.write(10);   /* Motor mili 20. dereceye donuyor */
  delay(10);
}


