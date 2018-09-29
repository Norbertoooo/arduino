int armazenavalor = 0;  
int pinorele1 = 8; //Pino do Arduino ligado ao IN1 da placa de relés  
int estadorele1 = LOW; //Armazena o estado do relé 1   
 
void setup()  
{  
  pinMode(pinorele1, OUTPUT);  //Define os pino dos reles como saída  
  Serial.begin(9600); //Inicializa a serial 
  Serial.println("teste de rele"); 
}  
   
void loop()  
{  
  digitalWrite(pinorele1,LOW); 


if (Serial.available() > 0) { // Verificar se há caracteres disponíveis
  char caractere = Serial.read(); // Armazena caractere lido
  if(caractere == 'b'){ 
    digitalWrite(pinorele1,HIGH);  
  }
}
  
} 
