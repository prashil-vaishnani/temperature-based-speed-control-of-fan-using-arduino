#include <LiquidCrystal.h>


#include<DHT.h>      // Including library for dht
#include<LiquidCrystal.h>
#define dht_dpin 12
#define pwm 9
DHT dht(dht_dpin,DHT11);

LiquidCrystal lcd(7,6, 5, 4, 3, 11);
byte degree[8] = {0b00011,0b00011,0b00000,0b00000,0b00000,0b00000,0b00000,0b00000};

void setup()
{
 lcd.begin(16, 2);
 dht.begin();
 lcd.createChar(1, degree);
 lcd.clear();
 lcd.print("   Fan Speed  ");
 lcd.setCursor(0,1);
 lcd.print("  Controlling ");
 delay(2000);
 analogWrite(pwm, 255);
 lcd.clear();
 lcd.print("Circuit Digest ");
 delay(2000);
 Serial.begin(9600);
}

void loop()
{
  //DHT.read11(dht_dpin);
  int temp=dht.readTemperature();
  Serial.print(temp);
  lcd.setCursor(0,0);
  lcd.print("Temperature:");
  lcd.print(temp);   // Printing temperature on LCD
  lcd.write(1);
  lcd.print("C");
  lcd.setCursor(0,1);
  if(temp <26 )
    { 
      analogWrite(9,0);
      lcd.print("Fan OFF            ");
      delay(100);
    }
    
    else if(temp==26)
    {
      analogWrite(pwm, 51);
      lcd.print("Fan Speed: 20%   ");
      delay(100);
    }
    
     else if(temp==27)
    {
      analogWrite(pwm, 102);
      lcd.print("Fan Speed: 40%   ");
      delay(100);
    }
    
     else if(temp==28)
    {
      analogWrite(pwm, 153);
      lcd.print("Fan Speed: 60%   ");
      delay(100);
    }
    
    else if(temp==29)
    {
      analogWrite(pwm, 204);
      lcd.print("Fan Speed: 80%    ");
      delay(100);
    }
     else if(temp>29)
    {
      analogWrite(pwm, 255);
      lcd.print("Fan Speed: 100%   ");
      delay(100);
    } 
  delay(3000);
}
