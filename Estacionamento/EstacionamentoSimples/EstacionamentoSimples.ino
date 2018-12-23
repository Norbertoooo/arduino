
//carrega a biblioteca ultrasonic.h
 #include <Ultrasonic.h>
//Define os leds
#define led1 9
#define led2 8
//Define os pinos de comunicação do modulo ultrasom
#define TRIGGER_PIN  7
#define ECHO_PIN    6
Ultrasonic ultrasonic(TRIGGER_PIN, ECHO_PIN);
 
void setup()
{
  Serial.begin(9600);
  pinMode(led1,OUTPUT);
  pinMode(led2,OUTPUT);
}
 
void loop()
{
  float cmMsec, inMsec;
  long microsec = ultrasonic.timing();
  cmMsec = ultrasonic.convert(microsec, Ultrasonic::CM);
  Serial.print("CM: ");
  Serial.println(cmMsec);
  delay(600);
  digitalWrite(led2,HIGH);
  if(cmMsec <= 60){
    digitalWrite(led1,HIGH);
    digitalWrite(led2,LOW);
    }else{
      digitalWrite(led1,LOW);
    }
}
