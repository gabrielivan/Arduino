#include <LiquidCrystal.h> // Incluímos la libreria externa para poder utilizarla

const int rs = 8, en = 9, d4 = 4, d5 = 5, d6 = 6, d7 = 7;
LiquidCrystal lcd(rs, en, d4, d5, d6, d7);
float tempC; // Variable para almacenar el valor obtenido del sensor (0 a 1023)
//int pinLM35 = 0;// Variable del pin de entrada del sensor (A0)
unsigned long tAnterior;

void setup()
{
  lcd.begin(16,1); //COLUMNAS = 16 FILAS = 1
}

void loop() 
{
  //Obtenemos datos del sensor
  // Con analogRead leemos el sensor, recuerda que es un valor de 0 a 1023
  tempC = analogRead(A4);
  tempC = tempC * (5 / 10.24); 
  // Calculamos la temperatura con la fórmula
  if(millis() - tAnterior > 500)
  {
    tAnterior = millis();  
    
    lcd.setCursor(0, 1);
    lcd.print("Temp. "+String(tempC)+"C");
  }
  
}
