#include <Wire.h>
#include <SSD1306.h>

SSD1306 display(0x3c, 4,5);
 
#define DISPLAY_WIDTH 127
#define DISPLAY_HEIGHT 63

#define LOGO_WIDTH 50
#define LOGO_HEIGHT 50

//format xbm, covert from
//http://www.online-utility.org/image_converter.jsp?outputType=XBM 

const char Logo[] PROGMEM ={
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
  0x00, 0x00, 0x00, 0x00, 0xF0, 0xFF, 0x33, 0x3F, 0xFF, 0x3F, 0x00, 0xF0, 
  0xFF, 0x33, 0x3F, 0xFF, 0x3F, 0x00, 0x30, 0x00, 0x03, 0x0F, 0x03, 0x30, 
  0x00, 0x30, 0x00, 0x03, 0x0F, 0x03, 0x30, 0x00, 0x30, 0x3F, 0xF3, 0x0C, 
  0xF3, 0x33, 0x00, 0x30, 0x3F, 0xF3, 0x0C, 0xF3, 0x33, 0x00, 0x30, 0x3F, 
  0xF3, 0x30, 0xF3, 0x33, 0x00, 0x30, 0x3F, 0xF3, 0x30, 0xF3, 0x33, 0x00, 
  0x30, 0x3F, 0x33, 0x0C, 0xF3, 0x33, 0x00, 0x30, 0x3F, 0x33, 0x0C, 0xF3, 
  0x33, 0x00, 0x30, 0x00, 0xC3, 0x3F, 0x03, 0x30, 0x00, 0x30, 0x00, 0xC3, 
  0x3F, 0x03, 0x30, 0x00, 0xF0, 0xFF, 0x33, 0x33, 0xFF, 0x3F, 0x00, 0xF0, 
  0xFF, 0x33, 0x33, 0xFF, 0x3F, 0x00, 0x00, 0x00, 0x00, 0x3C, 0x00, 0x00, 
  0x00, 0x00, 0x00, 0x00, 0x3C, 0x00, 0x00, 0x00, 0xF0, 0x0F, 0xF3, 0xFF, 
  0xF0, 0x33, 0x00, 0xF0, 0x0F, 0xF3, 0xFF, 0xF0, 0x33, 0x00, 0xC0, 0xF0, 
  0xCC, 0xFC, 0xFF, 0x33, 0x00, 0xC0, 0xF0, 0xCC, 0xFC, 0xFF, 0x33, 0x00, 
  0x00, 0xCF, 0xF3, 0xCF, 0x0C, 0x3C, 0x00, 0x00, 0xCF, 0xF3, 0xCF, 0x0C, 
  0x3C, 0x00, 0xF0, 0x3C, 0x3C, 0x0F, 0xCC, 0x0C, 0x00, 0xF0, 0x3C, 0x3C, 
  0x0F, 0xCC, 0x0C, 0x00, 0x00, 0x33, 0xC3, 0xF0, 0x03, 0x30, 0x00, 0x00, 
  0x33, 0xC3, 0xF0, 0x03, 0x30, 0x00, 0x00, 0x00, 0x30, 0x0C, 0x3F, 0x33, 
  0x00, 0x00, 0x00, 0x30, 0x0C, 0x3F, 0x33, 0x00, 0xF0, 0xFF, 0x03, 0xFF, 
  0x3F, 0x00, 0x00, 0xF0, 0xFF, 0x03, 0xFF, 0x3F, 0x00, 0x00, 0x30, 0x00, 
  0xC3, 0xC3, 0xCC, 0x3F, 0x00, 0x30, 0x00, 0xC3, 0xC3, 0xCC, 0x3F, 0x00, 
  0x30, 0x3F, 0xC3, 0x33, 0xC0, 0x03, 0x00, 0x30, 0x3F, 0xC3, 0x33, 0xC0, 
  0x03, 0x00, 0x30, 0x3F, 0xF3, 0x00, 0xC3, 0x0F, 0x00, 0x30, 0x3F, 0xF3, 
  0x00, 0xC3, 0x0F, 0x00, 0x30, 0x3F, 0x33, 0x33, 0x0C, 0x03, 0x00, 0x30, 
  0x3F, 0x33, 0x33, 0x0C, 0x03, 0x00, 0x30, 0x00, 0x33, 0xCF, 0x3F, 0x30, 
  0x00, 0x30, 0x00, 0x33, 0xCF, 0x3F, 0x30, 0x00, 0xF0, 0xFF, 0xF3, 0xCF, 
  0x0F, 0x03, 0x00, 0xF0, 0xFF, 0xF3, 0xCF, 0x0F, 0x03, 0x00, 0x00, 0x00, 
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
  0x00, 0x00,0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
  0x00, 0x00, 0x00, 0x00, 0xF0, 0xFF, 0x33, 0x3F, 0xFF, 0x3F, 0x00, 0xF0, 
  0xFF, 0x33, 0x3F, 0xFF, 0x3F, 0x00, 0x30, 0x00, 0x03, 0x0F, 0x03, 0x30, 
  0x00, 0x30, 0x00, 0x03, 0x0F, 0x03, 0x30, 0x00, 0x30, 0x3F, 0xF3, 0x0C, 
  0xF3, 0x33, 0x00, 0x30, 0x3F, 0xF3, 0x0C, 0xF3, 0x33, 0x00, 0x30, 0x3F, 
  0xF3, 0x30, 0xF3, 0x33, 0x00, 0x30, 0x3F, 0xF3, 0x30, 0xF3, 0x33, 0x00, 
  0x30, 0x3F, 0x33, 0x0C, 0xF3, 0x33, 0x00, 0x30, 0x3F, 0x33, 0x0C, 0xF3, 
  0x33, 0x00, 0x30, 0x00, 0xC3, 0x3F, 0x03, 0x30, 0x00, 0x30, 0x00, 0xC3, 
  0x3F, 0x03, 0x30, 0x00, 0xF0, 0xFF, 0x33, 0x33, 0xFF, 0x3F, 0x00, 0xF0, 
  0xFF, 0x33, 0x33, 0xFF, 0x3F, 0x00, 0x00, 0x00, 0x00, 0x3C, 0x00, 0x00, 
  0x00, 0x00, 0x00, 0x00, 0x3C, 0x00, 0x00, 0x00, 0xF0, 0x0F, 0xF3, 0xFF, 
  0xF0, 0x33, 0x00, 0xF0, 0x0F, 0xF3, 0xFF, 0xF0, 0x33, 0x00, 0xC0, 0xF0, 
  0xCC, 0xFC, 0xFF, 0x33, 0x00, 0xC0, 0xF0, 0xCC, 0xFC, 0xFF, 0x33, 0x00, 
  0x00, 0xCF, 0xF3, 0xCF, 0x0C, 0x3C, 0x00, 0x00, 0xCF, 0xF3, 0xCF, 0x0C, 
  0x3C, 0x00, 0xF0, 0x3C, 0x3C, 0x0F, 0xCC, 0x0C, 0x00, 0xF0, 0x3C, 0x3C, 
  0x0F, 0xCC, 0x0C, 0x00, 0x00, 0x33, 0xC3, 0xF0, 0x03, 0x30, 0x00, 0x00, 
  0x33, 0xC3, 0xF0, 0x03, 0x30, 0x00, 0x00, 0x00, 0x30, 0x0C, 0x3F, 0x33, 
  0x00, 0x00, 0x00, 0x30, 0x0C, 0x3F, 0x33, 0x00, 0xF0, 0xFF, 0x03, 0xFF, 
  0x3F, 0x00, 0x00, 0xF0, 0xFF, 0x03, 0xFF, 0x3F, 0x00, 0x00, 0x30, 0x00, 
  0xC3, 0xC3, 0xCC, 0x3F, 0x00, 0x30, 0x00, 0xC3, 0xC3, 0xCC, 0x3F, 0x00, 
  0x30, 0x3F, 0xC3, 0x33, 0xC0, 0x03, 0x00, 0x30, 0x3F, 0xC3, 0x33, 0xC0, 
  0x03, 0x00, 0x30, 0x3F, 0xF3, 0x00, 0xC3, 0x0F, 0x00, 0x30, 0x3F, 0xF3, 
  0x00, 0xC3, 0x0F, 0x00, 0x30, 0x3F, 0x33, 0x33, 0x0C, 0x03, 0x00, 0x30, 
  0x3F, 0x33, 0x33, 0x0C, 0x03, 0x00, 0x30, 0x00, 0x33, 0xCF, 0x3F, 0x30, 
  0x00, 0x30, 0x00, 0x33, 0xCF, 0x3F, 0x30, 0x00, 0xF0, 0xFF, 0xF3, 0xCF, 
  0x0F, 0x03, 0x00, 0xF0, 0xFF, 0xF3, 0xCF, 0x0F, 0x03, 0x00, 0x00, 0x00, 
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
  0x00, 0x00, 
  };


void setup() {
  
  // put your setup code here, to run once:
    display.init();
    display.setColor(WHITE);
    display.drawXbm(10,15,LOGO_WIDTH,LOGO_HEIGHT,Logo);
    display.display();
    delay(5000);
    display.clear();
    

}

void loop() {
  // put your main code here, to run repeatedly:

}
