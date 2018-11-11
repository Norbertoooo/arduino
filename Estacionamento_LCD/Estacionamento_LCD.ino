

//Programa: Teste de Display LCD 16 x 2
//Autor: FILIPEFLOP
//carrega a biblioteca ultrasonic.h
 #include <Ultrasonic.h>
//Carrega a biblioteca LiquidCrystal
#include <LiquidCrystal.h>
//Define os leds
#define led1 9
#define led2 8
//Define os pinos de comunicação do modulo ultrasom
#define TRIGGER_PIN  7
#define ECHO_PIN    6
//instanciando objeto ultrasonic
Ultrasonic ultrasonic(TRIGGER_PIN, ECHO_PIN);
 
//Define os pinos que serão utilizados para ligação ao display
LiquidCrystal lcd(12, 11, 5, 4, 3, 2);
 
void setup()
{
  //Define o número de colunas e linhas do LCD
  lcd.begin(16, 2);
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
  delay(1500);
   //Limpa a tela
  lcd.clear();
  //Posiciona o cursor na coluna 3, linha 0;
  lcd.setCursor(2, 0);
  //Envia o texto entre aspas para o LCD
  lcd.print(" Distancia: ");
  lcd.setCursor(3, 1);
  lcd.print(cmMsec);
  delay(1500);
  
  digitalWrite(led2,HIGH);
  if(cmMsec <= 60){
    digitalWrite(led1,HIGH);
    digitalWrite(led2,LOW);
    }else{
      digitalWrite(led1,LOW);
    }
 













  
  /*
  //Rolagem para a esquerda
  for (int posicao = 0; posicao < 3; posicao++)
  {
    lcd.scrollDisplayLeft();
    delay(200);
  }
   
  //Rolagem para a direita
  for (int posicao = 0; posicao < 6; posicao++)
  {
    lcd.scrollDisplayRight();
    delay(200);
  }
  */
}
