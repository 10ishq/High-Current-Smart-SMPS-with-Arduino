// This code is the part of the project of DIY powersupply authored by Tanishq Jaiswal
// This code comes without any kind of warrenty or gurantee
// Any one is free to share and edit this program
// Email- tanishq.jaiswal97@gmail.com
// Youtube video -- https://www.youtube.com/watch?v=-bsHym1Tiho&feature=youtu.be
// MOST IMPORTANT- Have Fun :)


#include "Adafruit_GFX.h"
#include "Adafruit_PCD8544.h"
 
int VoltageValue; 
int CurrentValue;
float voltage;
float current;

// pin 6 - Serial clock out (SCLK)
// pin 5 - Serial data out (DIN)
// pin 4 - Data/Command select (D/C)
// pin 3 - LCD chip select (CS)
// pin 2 - LCD reset (RST)
Adafruit_PCD8544 display = Adafruit_PCD8544(6, 5, 4, 3, 2);
  

  
void setup()  
{
  

  while (!Serial);
 
  Serial.begin(9600);
  
  display.begin();
  
  display.setContrast(40);
  
  delay(1000);
  
  display.clearDisplay();     // clears the screen and buffer
  
  display.setTextSize(1.5);     // set text size
  
  display.setTextColor(BLACK);
  
  delay(1000);
}
  
void loop() {
  
  VoltageValue = analogRead(A1);
  
  CurrentValue = analogRead(A0);
  
  voltage = VoltageValue * (5.0 / 1023.0) * 6.97;    // voltage calculation
  
  current = ((512-CurrentValue)*27.03/1023);   // current calculation
  

  
  Serial.print("AMPS= ");
 
  Serial.print(current);
  
  Serial.print("  ");

  
  
  Serial.print("VOLTS= ");
  
  Serial.print(voltage);

  Serial.print("  ");

  
  
  Serial.print("POWER= ");
 
  Serial.print(current*voltage);

  Serial.print("  ");
  
  Serial.println();
    
  
 
  display.clearDisplay();              // clears the screen and buffer
  
  display.setCursor(0,0);
    
  
  display.print("VOLTS=");
  
  display.print(voltage);
  
  display.print("V");
  
  display.println();
  
  display.println();
  
    
  
  display.print("AMPS=");
  
  display.print(current);
  
  display.print("A");

  display.println();
  
  display.println();
  
    
    
  display.print("POWER=");
  
  display.print(current * voltage);  // power calculation
  
  display.print("W"); 
  
  display.println();  
   
  display.display();
    
  delay(500);
}
