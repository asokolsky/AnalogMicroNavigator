#include <Arduino.h>
#include "Trace.h"
//#include "AnalogNavigationKeypad.h"
#include "AnalogMicroNavigator.h"

/**
 * A BuiltIn LED
 */

class Led
{
  /** the overheating led pin - use a built-in one */
  uint8_t m_pinLed;
  int8_t m_ons = 0;

public:
  Led(uint8_t pinLed) : m_pinLed(pinLed)
  {
    pinMode(m_pinLed, OUTPUT);
  }

  void turnOn()
  {
    m_ons++;
    if(m_ons > 0) digitalWrite(m_pinLed, HIGH);
  }
  void turnOff()
  {
    m_ons--;
    if(m_ons <= 0) digitalWrite(m_pinLed, LOW);
  }
  
};

/** built-in Arduino led is on pin 13 */
Led g_leg(13);


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

static unsigned long g_ulNow;

bool MyNavKeyPad::onUserInActivity(unsigned long ulNow)
{
  DEBUG_PRINT("MyNavKeyPad::onUserInActivity ulNow="); DEBUG_PRINTDEC(g_ulNow); DEBUG_PRINTLN("");
  return false; 
}

bool MyNavKeyPad::onKeyAutoRepeat(uint8_t vks)
{
  DEBUG_PRINT("MyNavKeyPad::onKeyAutoRepeat vks="); DEBUG_PRINT(getKeyNames(vks)); DEBUG_PRINT(" ulNow="); DEBUG_PRINTDEC(g_ulNow); DEBUG_PRINTLN("");
  return false; 
}

bool MyNavKeyPad::onKeyDown(uint8_t vks)
{
  DEBUG_PRINT("MyNavKeyPad::onKeyDown vks="); DEBUG_PRINT(getKeyNames(vks)); DEBUG_PRINT(" ulNow="); DEBUG_PRINTDEC(g_ulNow); DEBUG_PRINTLN("");
  g_leg.turnOn();
  return false; 
}

bool MyNavKeyPad::onLongKeyDown(uint8_t vks)
{
  DEBUG_PRINT("MyNavKeyPad::onLongKeyDown vks="); DEBUG_PRINT(getKeyNames(vks)); DEBUG_PRINT(" ulNow="); DEBUG_PRINTDEC(g_ulNow); DEBUG_PRINTLN("");
  return false; 
}

bool MyNavKeyPad::onKeyUp(uint8_t vks)
{
  DEBUG_PRINT("MyNavKeyPad::onKeyUp vks="); DEBUG_PRINT(getKeyNames(vks)); DEBUG_PRINT(" ulNow="); DEBUG_PRINTDEC(g_ulNow); DEBUG_PRINTLN("");
  g_leg.turnOff();
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
  //unsigned long ulNow = millis();
  g_kp.getAndDispatchKey(g_ulNow = millis());
 
}

