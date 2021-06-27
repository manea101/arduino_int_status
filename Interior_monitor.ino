/
#include <LiquidCrystal.h>
#include <dht.h>

dht DHT;

#define DHT11_PIN 7

int warned = 0;


const int rs = 12, en = 11, d4 = 5, d5 = 4, d6 = 3, d7 = 2;
LiquidCrystal lcd(rs, en, d4, d5, d6, d7);

void setup() {
  lcd.begin(20, 4);
  lcd.setCursor(2, 1);
  lcd.print("STATUS INTERIOR");
  lcd.setCursor(10,2);
  lcd.print("by r0a13x");
  delay(5000);
  lcd.clear();
  delay(500);
  
}

void halt(){
  delay(10000);
  lcd.clear();
  delay(1000);
}

void loop() {
  lcd.setCursor(2, 0);
  lcd.print("STATUS INTERIOR");
  int chk = DHT.read11(DHT11_PIN);
  
    lcd.setCursor(0, 1);
    lcd.print("Temperatura: ");
    lcd.print(DHT.temperature, 0);
    lcd.print((char)223);
    lcd.print("C");
    lcd.setCursor(0,2);
    lcd.print("Umiditate: ");
    lcd.print(DHT.humidity, 0);
    lcd.print("%");
    delay(1500);
    if(DHT.humidity>50){
      warned = 1;
      lcd.setCursor(2, 3);
      lcd.print("Pericol sanatate!"); 
    }
    else if(DHT.humidity<=50 && warned == 1){
       warned = 0;
       lcd.clear();
       
    }
    if(DHT.temperature<-900){
      lcd.clear();
      delay(500);
      lcd.setCursor(5, 1);
      lcd.print("DEFECTIUNE!");
      lcd.setCursor(5, 2);
      lcd.print("REPORNIRE...");
      halt();
    }
    delay(1000);
    

  }
  
