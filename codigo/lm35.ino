#include <LiquidCrystal.h>
int Motor = 6;
int analogpin = A0;
float tempC;
float tempF;
int tempDigital;

LiquidCrystal lcd(12, 11, 5, 4, 3, 2);

void setup() {
  pinMode(Motor, OUTPUT);
  Serial.begin(9600);
  lcd.begin(16,2);
}

void loop() {
  tempDigital = analogRead(analogpin);      //lectura digital
  tempC = (tempDigital * 5.0)*100.0/1023.0;  //lectura analogica
  tempF = tempC * 9.0/5.0 + 32.0;             //temp en grados F
  //
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("Temp");
  lcd.setCursor(6, 0);
  lcd.print(tempC);
  
  if(tempC >= 20){
   digitalWrite(Motor, HIGH);
   lcd.setCursor(0,1); 
   lcd.print("motor ON");
  }
  else{
    digitalWrite(Motor, LOW);
    lcd.setCursor(0,1);
    lcd.print("motor OF");
  }
  
  Serial.println("Temperatura");
  Serial.println(tempC);
  delay(1000);

  
}
