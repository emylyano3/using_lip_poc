#include "main.h"

ESP32Domotic _domoticModule;

void setup() {
  _domoticModule.init();
}

void loop() {
  _domoticModule.loop();
}