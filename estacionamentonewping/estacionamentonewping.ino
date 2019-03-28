#include <NewPing.h>
 
#define TRIGGER_PIN  26
#define ECHO_PIN     25
#define MAX_DISTANCE 200
#define vermelho 12
#define verde 13

int distancia = 0;
 
NewPing sonar(TRIGGER_PIN, ECHO_PIN, MAX_DISTANCE);
 
void setup() {
  Serial.begin(115200);
  pinMode(vermelho,OUTPUT);
  pinMode(verde,OUTPUT);
}
 
void loop() {
  
  distancia = sonar.ping_cm();
  digitalWrite(verde,HIGH);
  digitalWrite(vermelho,LOW);
  Serial.print("Ping: ");
  Serial.print(distancia);
  Serial.println("cm");
  if( ( distancia <= 30 ) && ( distancia != 0 ) ){
    digitalWrite(verde,LOW);
    digitalWrite(vermelho,HIGH);
    }
    
  delay(700);
}
