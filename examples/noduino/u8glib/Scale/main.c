/*
  Example code for the 2x2 scale function.
  
  Universal 8bit Graphics Library, http://code.google.com/p/u8glib/
  
  Copyright (c) 2012, olikraus@gmail.com
  All rights reserved.

  Redistribution and use in source and binary forms, with or without modification, 
  are permitted provided that the following conditions are met:

  * Redistributions of source code must retain the above copyright notice, this list 
    of conditions and the following disclaimer.
    
  * Redistributions in binary form must reproduce the above copyright notice, this 
    list of conditions and the following disclaimer in the documentation and/or other 
    materials provided with the distribution.

  THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND 
  CONTRIBUTORS "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, 
  INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES OF 
  MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE 
  DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR 
  CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, 
  SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT 
  NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; 
  LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER 
  CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, 
  STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) 
  ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF 
  ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.  
*/

#include "noduino.h"
#include "U8glib.h"

U8GLIB_SSD1306_128X64 u8g(U8G_I2C_OPT_NONE);	// I2C / TWI 

void draw(void)
{
	// graphic commands to redraw the complete screen should be placed here  
	u8g.setFont(u8g_font_unifont);
	u8g.setFontPosTop();
	u8g.drawStr(0, 1, "Hello");
	u8g.drawHLine(0, 1 + 14, 40);
	u8g.setScale2x2();	// Scale up all draw procedures
	u8g.drawStr(0, 12, "Hello");	// actual display position is (0,24)
	u8g.drawHLine(0, 12 + 14, 40);	// All other procedures are also affected
	u8g.undoScale();	// IMPORTANT: Switch back to normal mode
}

void setup(void)
{
	// flip screen, if required
	//u8g.setRot180();

	// assign default color value
	if (u8g.getMode() == U8G_MODE_R3G3B2)
		u8g.setColorIndex(255);	// white
	else if (u8g.getMode() == U8G_MODE_GRAY2BIT)
		u8g.setColorIndex(3);	// max intensity
	else if (u8g.getMode() == U8G_MODE_BW)
		u8g.setColorIndex(1);	// pixel on
}

void loop(void)
{
	// picture loop
	u8g.firstPage();
	do {
		draw();
	} while (u8g.nextPage());

	// rebuild the picture after some delay
	delay(500);
}
