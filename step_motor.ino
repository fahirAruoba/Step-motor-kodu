



#include <dht.h>

dht DHT;

#define DHT11_PIN 7

#include <Stepper.h>

#define STEPS 100

Stepper stepper(STEPS, 8, 9, 10, 11);

void setup(){
  Serial.begin(9600);
    stepper.setSpeed(30);

}

void loop()
{
  int chk = DHT.read11(DHT11_PIN);
  

  if(DHT.humidity > 92){
    
  stepper.step(-50);
  delay(1000);
  stepper.step(50);
delay(15000);
  while(DHT.humidity > 92 ){
    int chk = DHT.read11(DHT11_PIN);
  Serial.print("Humidity = ");
  Serial.println(DHT.humidity);
  delay(1000);
  }
  }
  else if(DHT.humidity < 92 && DHT.humidity > 0){
      
  Serial.print("Humidity = ");
  Serial.println(DHT.humidity);
  }
}

