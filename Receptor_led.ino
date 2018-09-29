#include <IRremote.h>

int RECV_PIN = 11;
int led = 8;
IRrecv irrecv(RECV_PIN);

decode_results results;

void setup()
{
  pinMode(led,OUTPUT);
  Serial.begin(9600);
  // In case the interrupt driver crashes on setup, give a clue
  // to the user what's going on.
  Serial.println("Enabling IRin");
  irrecv.enableIRIn(); // Start the receiver
  Serial.println("Enabled IRin");
}

void loop() {
  if (irrecv.decode(&results)) {
    Serial.println(results.value, DEC);
    if(results.value == 16728255){
      digitalWrite(led,HIGH);
      }else{
        digitalWrite(led,LOW);
        }
    irrecv.resume(); // Receive the next value
    
  }
  delay(100);
}
