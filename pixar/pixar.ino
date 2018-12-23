#include <boarddefs.h>
#include <IRremote.h>
#include <IRremoteInt.h>
#include <ir_Lego_PF_BitStreamEncoder.h>

//alterar nome
int porta_rele = 12;
int rec = 8;
IRrecv irrecv(rec);

decode_results results;
  
void setup(){
  pinMode(porta_rele, OUTPUT); 
  Serial.begin(9600);
  Serial.println("Enabling IRin");
  irrecv.enableIRIn();
  Serial.println("Enabled IRin");
}
   
void loop()
{ 
  if (irrecv.decode(&results)) {
    Serial.println(results.value, DEC);
    irrecv.resume(); // Receive the next value
  }
  
  delay(100);
  
  if(results.value == 16753245){
    digitalWrite(porta_rele,HIGH);
    }
  if(results.value == 16769565){
    digitalWrite(porta_rele,LOW);
    }
 
  delay(2000);
  
}
