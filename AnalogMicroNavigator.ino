#include <Arduino.h>
#include "Trace.h"
//#include "AnalogNavigationKeypad.h"
#include "AnalogMicroNavigator.h"

class MyNavKeyPad: public /*AnalogNavigationKeypad*/ AnalogMicroNavigator
{
public:  
  /** this test if for a keyboard connected to A0 and A1 */
  MyNavKeyPad() : /* AnalogNavigationKeypad(A1, A2) */ AnalogMicroNavigator(A0, A1)
  {
    
  }
  bool onUserInActivity(unsigned long ulNow);
  bool onKeyAutoRepeat(uint8_t vks);
  bool onKeyDown(uint8_t vks);
  bool onLongKeyDown(uint8_t vks);
  bool onKeyUp(uint8_t vks);
};

bool MyNavKeyPad::onUserInActivity(unsigned long ulNow)
{
  DEBUG_PRINT("MyNavKeyPad::onUserInActivity ulNow="); DEBUG_PRINTDEC(ulNow); DEBUG_PRINTLN("");
  return false; 
}

bool MyNavKeyPad::onKeyAutoRepeat(uint8_t vks)
{
  DEBUG_PRINT("MyNavKeyPad::onKeyAutoRepeat vks="); DEBUG_PRINTLN(getKeyNames(vks));
  return false; 
}

bool MyNavKeyPad::onKeyDown(uint8_t vks)
{
  DEBUG_PRINT("MyNavKeyPad::onKeyDown vks="); DEBUG_PRINTLN(getKeyNames(vks));
  return false; 
}

bool MyNavKeyPad::onLongKeyDown(uint8_t vks)
{
  DEBUG_PRINT("MyNavKeyPad::onLongKeyDown vks="); DEBUG_PRINTLN(getKeyNames(vks));
  return false; 
}

bool MyNavKeyPad::onKeyUp(uint8_t vks)
{
  DEBUG_PRINT("MyNavKeyPad::onKeyUp vks="); DEBUG_PRINTLN(getKeyNames(vks));
  return false; 
}




MyNavKeyPad g_kp;

void setup()
{  
  Serial.begin(115200);
  
  delay(1000);   
  //while(!Serial)  ; // wait for serial port to connect. Needed for Leonardo only
  DEBUG_PRINTLN("AnalogNavigationKeypad test!");
    
  //g_kp.setup();
  
}

void loop()
{
  unsigned long ulNow = millis();
  g_kp.getAndDispatchKey(ulNow);
 
}

