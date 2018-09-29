const int ledPin = 13; 
int piscando = 500; 
void setup() {
  Serial.begin(9600);
  pinMode(ledPin, OUTPUT);
  Serial.println("testando");
}

void loop()
{
  
if (Serial.available() > 0) { // Verificar se há caracteres disponíveis
  char caractere = Serial.read(); // Armazena caractere lido
  if(caractere == 'b'){
    Serial.println(caractere);
    pisca();
  }
}

}


void pisca()
{
 digitalWrite(ledPin, HIGH);
 delay(piscando);
 digitalWrite(ledPin, LOW);
 delay(piscando);
}
