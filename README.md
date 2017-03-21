# Analog Micro Navigator

Tiny analog keypad designed to recognize simultaneous button presses.
Has a 5-way joystick and nothing else.

## Hardware

[Schematics and PCB] (https://easyeda.com/asokolsky/Analog_Micro_Navigator-fc0d88dfa3bf496bb906f65b6c270cef)

### PinOut

| Pin | Name | Description |
| --- | -----| -----|
|1|VCC| Voltage supply.  Connect to VCC of your controller.|	
|2|A1| Connect to analog input of your controller.|
|3|A2| Connect to another analog input of your controller.|
|4|AGND| Analog Ground or just Ground|

## Software Samples

AnalogMicroNavigator.ino

## Sequence of CallBacks 

### Single Button presses

~~~~
MyNavKeyPad::onKeyDown vks=VK_LEFT 
MyNavKeyPad::onKeyUp vks=VK_LEFT 
~~~~

### First one then another button being pressed

~~~~
MyNavKeyPad::onKeyDown vks=VK_LEFT 
MyNavKeyPad::onKeyAutoRepeat vks=VK_LEFT 
MyNavKeyPad::onKeyAutoRepeat vks=VK_LEFT 
MyNavKeyPad::onKeyAutoRepeat vks=VK_LEFT 
MyNavKeyPad::onKeyDown vks=VK_LEFT VK_SOFTB 
MyNavKeyPad::onKeyAutoRepeat vks=VK_LEFT VK_UP 
MyNavKeyPad::onKeyAutoRepeat vks=VK_LEFT VK_UP 
MyNavKeyPad::onKeyAutoRepeat vks=VK_LEFT VK_UP 
MyNavKeyPad::onKeyAutoRepeat vks=VK_LEFT VK_UP 
MyNavKeyPad::onKeyAutoRepeat vks=VK_LEFT VK_UP 
MyNavKeyPad::onKeyAutoRepeat vks=VK_LEFT VK_UP 
MyNavKeyPad::onKeyAutoRepeat vks=VK_LEFT VK_UP 
MyNavKeyPad::onKeyAutoRepeat vks=VK_LEFT VK_UP 
MyNavKeyPad::onKeyAutoRepeat vks=VK_LEFT VK_UP 
MyNavKeyPad::onLongKeyDown vks=VK_LEFT VK_UP 
MyNavKeyPad::onKeyAutoRepeat vks=VK_LEFT VK_UP 
MyNavKeyPad::onKeyUp vks=VK_LEFT VK_UP 
MyNavKeyPad::onKeyUp vks=VK_UP 
~~~~



