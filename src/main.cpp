#include <LittleFS.h>
#include "main.h"
#include <ESP32Domotic.h>
#include <Logger.h>

ESP32Domotic  domoticModule;
Channel       channel("c1", "channel_1", 1, OUTPUT, false, true);

void setup() {
  Serial.begin(115200);
  log("Switch example setup");
  channel.setState(LOW);
  channel.setTimer(20);
  domoticModule.setModuleType("switch");
  domoticModule.setWifiConnectTimeout(20);
  domoticModule.setConfigPortalTimeout(120);
  domoticModule.setPortalSSID("proeza-domotics-demo");
  domoticModule.addChannel(&channel);
  domoticModule.init();

  log("Channel is analog", channel.isAnalog());
  log("Channel is output", channel.isOutput());
  log("Module location", domoticModule.getConfig()->getModuleLocation());
  log("Module name", domoticModule.getConfig()->getModuleName());
}

void loop() {
  // domoticModule.cycle();
  // log("Channel previous state", channel.getPrevState());
  // log("Channel current raw state", channel.getRawState());
  // log("Channel current mapped state", channel.getMappedState());
  domoticModule.cycle();
  delay(1000);
}