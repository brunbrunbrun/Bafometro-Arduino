#include <Arduino.h>
#include <LiquidCrystal.h>

const int rs = 12, en = 11, d4 = 5, d5 = 4, d6 = 3, d7 = 2;
LiquidCrystal lcd(rs, en, d4, d5, d6, d7);

int mq3_pino_analogico = A0;


void setup() 
{
  lcd.begin(16,2); 
  
  //buzzer no pino 10
  pinMode(10,OUTPUT); 
  
  //led verde no pino 9
  pinMode(9, OUTPUT);

  //led vermelho no pino 8
  pinMode(8, OUTPUT);
}

void loop() 
{
  lcd.clear();
  lcd.setCursor(3,0);
  int valor_mq3 = analogRead(mq3_pino_analogico);

  if(valor_mq3 < 200)
  {
    lcd.print("Sobriozin");
    lcd.setCursor(5,1);
    lcd.print(valor_mq3);
    digitalWrite(9, HIGH);
    digitalWrite(8, LOW);
  }
  else
  {
    lcd.print("Bebaaasso");
    lcd.setCursor(5,1);
    lcd.print(valor_mq3);
    tone(10, 250, 250);
    digitalWrite(9, LOW);
    digitalWrite(8, HIGH);
    
  }

  delay(500);
}
