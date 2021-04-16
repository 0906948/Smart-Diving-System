// import libraries / declarations / definitions
#include <duikhoepel.h>

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);  // begin serial communication
  irrecv.enableIRIn();              // Start the receiver

  // Starten LCD
  lcd.init();                      
  lcd.backlight();
  // Testprint op LCD
  lcd.clear();                      // maakt het scherm leeg
  lcd.setCursor(0,0);               // selecteer de positie waar de tekst moet starten
  lcd.print("Starting: ");          // de tekst die getoond moet worden
  delay(500);                       // wacht 500ms 
  for(int i = 1; i <= 16; i++){     // telt tot 100$
  lcd.setCursor(10,0);
  lcd.print((i*100)/16);
  lcd.print("%");
  lcd.setCursor(i-1,1);             // toont % visueel
  lcd.print("=");
  delay(100);
  }

    // Start LED strip
  strip.begin();                    // INITIALIZE NeoPixel strip object (REQUIRED)
  colorWipe(strip.Color(255,128,0), 50); // oranje
  strip.show();                     // Update strip with new contents
  strip.setBrightness(50);          // Set BRIGHTNESS to about 1/5 (max = 255)

  lcd.clear();
  lcd.setCursor(0,0);               // selecteer de positie waar de tekst moet starten
  lcd.print("Selecteer");          // de tekst die getoond moet worden
  lcd.setCursor(0,1);               // selecteer de positie waar de tekst moet starten
  lcd.print("programma");          // de tekst die getoond moet worden
}
void loop() 
{
 if (IrReceiver.decode()) 
   {
    Serial.println(IrReceiver.decodedIRData.decodedRawData, DEC); // Print the Serial 'results.value'
    irrecv.resume();   // Receive the next value
   }

   // 1
   if (IrReceiver.decodedIRData.decodedRawData == 3125149440)  // change according to your IR remote button number
    {
      strip.show(); 
      lcd.clear();                      // maakt het scherm leeg
      lcd.setCursor(0,0);               // selecteer de positie waar de tekst moet starten
      lcd.print("Rainbow");             // de tekst die getoond moet worden
      rainbow(1);
      delay(15);
    }

    // 2
    if (IrReceiver.decodedIRData.decodedRawData == 3108437760)  // change according  to your IR remote button number
    {
      strip.show(); 
      lcd.clear();                      // maakt het scherm leeg
      lcd.setCursor(0,0);               // selecteer de positie waar de tekst moet starten
      lcd.print("Oranje");          // de tekst die getoond moet worden
      colorWipe(strip.Color(255,128,0), 50);
    delay(15);
    }

    // 3
    if (IrReceiver.decodedIRData.decodedRawData == 3091726080)  // change according  to your IR remote button number
    {
      strip.show(); 
      lcd.clear();                      // maakt het scherm leeg
      lcd.setCursor(0,0);               // selecteer de positie waar de tekst moet starten
      lcd.print("Groen");          // de tekst die getoond moet worden
      strip.fill(strip.Color(0, 255, 0, 50));
      strip.show();
    delay(15);
    }
    
    // 4
    if (IrReceiver.decodedIRData.decodedRawData == 3141861120)  // change according  to your IR remote button number
    {
      strip.fill(strip.Color(0, 0, 0, 25));
      strip.show(); 
      lcd.clear();                      // maakt het scherm leeg
      lcd.setCursor(0,0);               // selecteer de positie waar de tekst moet starten
      lcd.print("Succes");          // de tekst die getoond moet worden
      strip.show(); 
      strip.fill(strip.Color(0, 255, 0, 50));
      strip.show();
      delay(1);
      strip.show(); 
      strip.fill(strip.Color(255,255,255, 50));
      strip.show();
      delay(1);
      strip.show(); 
      strip.fill(strip.Color(0, 255, 0, 50));
      strip.show();
      delay(1);
      strip.show(); 
      strip.fill(strip.Color(255,255,255, 50));
      strip.show();
      delay(1);
      strip.show(); 
      strip.fill(strip.Color(0, 255, 0, 50));
      strip.show();
      delay(1);
      strip.show(); 
      strip.fill(strip.Color(255,255,255, 50));
      strip.show();
      delay(1);
    delay(15);
    }
    
    // 5
    if (IrReceiver.decodedIRData.decodedRawData == 3208707840)  // change according  to your IR remote button number
    {
      strip.fill(strip.Color(0, 0, 0, 50));
      strip.show();  
      lcd.clear();                      // maakt het scherm leeg
      lcd.setCursor(0,0);               // selecteer de positie waar de tekst moet starten
      lcd.print("Faal");          // de tekst die getoond moet worden
      colorWipe(strip.Color(255,0,0), 50);
      strip.show();
      colorWipe(strip.Color(255,255,255), 50);
      strip.show();
      colorWipe(strip.Color(255,0,0), 50);
      strip.show();
      colorWipe(strip.Color(255,255,255), 50);
      strip.show();
      colorWipe(strip.Color(255,0,0), 50);
      strip.show();
    delay(15);
    }

    // #
    if (IrReceiver.decodedIRData.decodedRawData == 4061003520)  // change according  to your IR remote button number
    {
      strip.fill(strip.Color(0, 0, 0, 0));
      strip.show();  
      lcd.clear();                      // maakt het scherm leeg
      lcd.setCursor(0,0);               // selecteer de positie waar de tekst moet starten
      lcd.print("Selecteer");          // de tekst die getoond moet worden
      lcd.setCursor(0,1);               // selecteer de positie waar de tekst moet starten
      lcd.print("programma");          // de tekst die getoond moet worden
    delay(15);
    }
}     

// 1 = 3125149440 = wit / regenbood gloei
// 2 = 3108437760 = oranje -> groengeel
// 3 = 3091726080 = groen
// 4 = 3141861120 = groen knipperend
// 5 = 3208707840 = rood knipperend
// # = 4061003520 = uit
