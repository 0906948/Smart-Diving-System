// import libraries / declarations / definitions
// import libraries / declarations / definitions

// Neopixel
#include <Adafruit_NeoPixel.h>
#ifdef __AVR__
 #include <avr/power.h>            // Required for 16 MHz Adafruit Trinket
#endif

Adafruit_NeoPixel strip(56, 6, NEO_GRB + NEO_KHZ800); //#leds, pin, driver

//IR remote
#include <IRremote.h>

int IRpin = 11;
IRrecv irrecv(IRpin);
decode_results results;

//LCD display
#include <Wire.h>
#include <LiquidCrystal_I2C.h>

const int i2c_addr = 0x27;         //Hier zet je het I2C addres neer. Deze moet je eerst uitzoeken voordat je begint.
const int Kolommen = 16;           //Hier zet je het aantal kolommen neer
const int Rijen = 2;               //Hier zet je het aantal rijden van je display neer

LiquidCrystal_I2C lcd = LiquidCrystal_I2C(i2c_addr,Kolommen,Rijen); //Hier maken we een LCD die de eigenschappen die je net geschreven hebt aan

// DECLARE FUNCTIONS //
void regenboog(int wait){
  // Hue of first pixel runs 5 complete loops through the color wheel.
  // Color wheel has a range of 65536 but it's OK if we roll over, so
  // just count from 0 to 5*65536. Adding 256 to firstPixelHue each time
  // means we'll make 5*65536/256 = 1280 passes through this outer loop:
  for(long firstPixelHue = 0; firstPixelHue < 1*65536; firstPixelHue += 256) {
    for(int i=0; i<strip.numPixels(); i++) { // For each pixel in strip...
      // Offset pixel hue by an amount to make one full revolution of the
      // color wheel (range of 65536) along the length of the strip
      // (strip.numPixels() steps):
      int pixelHue = firstPixelHue + (i * 65536L / strip.numPixels());
      // strip.ColorHSV() can take 1 or 3 arguments: a hue (0 to 65535) or
      // optionally add saturation and value (brightness) (each 0 to 255).
      // Here we're using just the single-argument hue variant. The result
      // is passed through strip.gamma32() to provide 'truer' colors
      // before assigning to each pixel:
      strip.setPixelColor(i, strip.gamma32(strip.ColorHSV(pixelHue)));
    }
    strip.show(); // Update strip with new contents
    lcd.clear();                      // maakt het scherm leeg
    lcd.setCursor(0,0);               // selecteer de positie waar de tekst moet starten
    lcd.print("regenboog");          // de tekst die getoond moet worden
    delay(wait);  // Pause for a moment
  }
}

void oranje(int wait){
  strip.fill(strip.Color(255, 128, 0, 50)); // oranje
  strip.show();                           // Update strip with new contents
  lcd.clear();                      // maakt het scherm leeg
  lcd.setCursor(0,0);               // selecteer de positie waar de tekst moet starten
  lcd.print("oranje");          // de tekst die getoond moet worden
  delay(wait);  // Pause for a moment
}

void groen(int wait){
  strip.fill(strip.Color(0, 255, 0, 50)); // groen
  strip.show();                           // Update strip with new contents
  lcd.clear();                      // maakt het scherm leeg
  lcd.setCursor(0,0);               // selecteer de positie waar de tekst moet starten
  lcd.print("groen");          // de tekst die getoond moet worden
  delay(wait);  // Pause for a moment
}

void wit(int wait){
  strip.fill(strip.Color(255, 255, 255, 25)); // wit
  strip.show();                           // Update strip with new contents
  lcd.clear();                      // maakt het scherm leeg
  lcd.setCursor(0,0);               // selecteer de positie waar de tekst moet starten
  lcd.print("wit");          // de tekst die getoond moet worden
  delay(wait);  // Pause for a moment
}

void rood(int wait){
  strip.fill(strip.Color(255, 0, 0, 50)); // wit
  strip.show();                           // Update strip with new contents
  lcd.clear();                      // maakt het scherm leeg
  lcd.setCursor(0,0);               // selecteer de positie waar de tekst moet starten
  lcd.print("rood");          // de tekst die getoond moet worden
  delay(wait);  // Pause for a moment
}

void reset(){
  oranje(0);
  lcd.clear();
  lcd.setCursor(0,0);                     // selecteer de positie waar de tekst moet starten
  lcd.print("Selecteer");                 // de tekst die getoond moet worden
  lcd.setCursor(0,1);                     // selecteer de positie waar de tekst moet starten
  lcd.print("programma");                 // de tekst die getoond moet worden
 }

// RUN CODE //
void setup() {                            // put your setup code here, to run once:
  Serial.begin(9600);                     // begin serial communication
  irrecv.enableIRIn();                    // Start the IR receiver

  // Start LCD
  lcd.init();                             // initieert LCD                     
  lcd.backlight();                        // Schakelt backlight LCD aan

  // Start LED strip
  strip.begin();                          // INITIALIZE NeoPixel strip object (REQUIRED)
  oranje(0);
  strip.setBrightness(50);                // Set BRIGHTNESS to about 1/5 (max = 255)

  // Kies programma
  reset();
}

void loop(){
  if (IrReceiver.decode()) 
   {
    Serial.println(IrReceiver.decodedIRData.decodedRawData, DEC); // Print the Serial 'results.value'
    irrecv.resume();   // Receive the next value
   }
  if (IrReceiver.decodedIRData.decodedRawData == 3125149440){ //1
    regenboog(0);
    }
  if (IrReceiver.decodedIRData.decodedRawData == 3108437760) //2
  {
    oranje(1);
  }
  if (IrReceiver.decodedIRData.decodedRawData == 3141861120) //4
  {
    groen(1);
  }
  if (IrReceiver.decodedIRData.decodedRawData == 3208707840) //5
  {
    wit(1);
  }
  if (IrReceiver.decodedIRData.decodedRawData == 4161273600) //7
  {
    rood(1);
  }
  if (IrReceiver.decodedIRData.decodedRawData == 3927310080) //8
  {
    wit(1);
  }
  if (IrReceiver.decodedIRData.decodedRawData == 4061003520) //#
  {
    reset();
  }
}
