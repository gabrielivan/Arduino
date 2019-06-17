#include <LiquidCrystal.h>
int flagUp=0;
int flagDown=0;
int flagLeft=0;
int flagRight=0;
int flagReset=0;

// initialize the library by associating any needed LCD interface pin
// with the arduino pin number it is connected to
const int rs = 8, en = 9, d4 = 4, d5 = 5, d6 = 6, d7 = 7;
LiquidCrystal lcd(rs, en, d4, d5, d6, d7);
int variableMcLovin=0;

void setup() 
{
  // set up the LCD's number of columns and rows:
  lcd.begin(16, 2);
  // Print a message to the LCD.
  lcd.print("McLovin'");
}

void loop() 
{
  // set the cursor to column 0, line 1
  // (note: line 1 is the second row, since counting begins with 0):
 variableMcLovin = analogRead(A0);
 
 if(variableMcLovin<100 && variableMcLovin >= 0)
 {
  if(flagRight==0)
  {
    flagRight=1; 
  }
  else
  {flagRight=0;}
  
  flagUp=0;
  flagDown=0;
  flagLeft=0;
 }
 else if(variableMcLovin<180 && variableMcLovin >110)
 {
  if(flagUp==0)
  {
    flagUp=1; 
  }
  else
  {flagUp=0;}
  
  flagDown=0;
  flagLeft=0;
  flagRight=0;
 }
 else if(variableMcLovin<400 && variableMcLovin >300)
 {
   if(flagDown==0)
  {
    flagDown=1; 
  }
  else
  {flagDown=0;}

  flagUp=0;
  flagLeft=0;
  flagRight=0;
 }
 else if(variableMcLovin<620 && variableMcLovin >450)
 {
  if(flagLeft==0)
  {
    flagLeft=1; 
  }
  else
  {flagLeft=0;}
  
  flagUp=0;
  flagDown=0;
  flagRight=0;
 }
 else if(variableMcLovin<1000 && variableMcLovin >680)
 {
    flagUp=0;
    flagDown=0;
    flagLeft=0;
    flagRight=0;
    lcd.setCursor(0, 1);
    lcd.print("     ");
 }
 if(flagRight==1)
  {
    lcd.setCursor(0, 1);
    lcd.print("Right  ");
  }
 if(flagLeft==1)
  {
    lcd.setCursor(0, 1);
    lcd.print("Left  ");
  }
 if(flagDown==1)
  {
    lcd.setCursor(0, 1);
    lcd.print("Down  ");
  }
 if(flagUp==1)
  {
    lcd.setCursor(0, 1);
    lcd.print("Up    ");
  }
 
}
