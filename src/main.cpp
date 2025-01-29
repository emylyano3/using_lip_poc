#include <LittleFS.h>
#include "main.h"
#include <ESPDomotic.h>
#include <Logger.h>

ESPDomotic*  domoticModule  = new ESPDomotic();
Channel*     outputChannel  = new Channel("oc1", "out_channel_1", 1, OUTPUT, false, CHANNEL_NO_TIMER);
Channel*     inputChannel   = new Channel("ic1", "in_channel_1", 2, INPUT, true, CHANNEL_NO_TIMER);

void setup() {
  Serial.begin(115200);
  log(F("Switch example setup"));
  outputChannel->setState(LOW);
  outputChannel->setTimer(2000);
  inputChannel->setTimer(3000);
  domoticModule->setModuleType("switch");
  domoticModule->setWifiConnectTimeout(20);
  domoticModule->setConfigPortalTimeout(120);
  domoticModule->setPortalSSID("proeza-domotics-demo");
  domoticModule->addChannel(outputChannel);
  domoticModule->addChannel(inputChannel);
  domoticModule->init();

  log("Output channel name", outputChannel->getName());
  log("Output channel is analog", outputChannel->isAnalog());
  log("Output channel is output", outputChannel->isOutput());
  log("Output channel is enabled", outputChannel->isEnabled());
  log("Output channel timer", outputChannel->getTimer());
  
  log("Input channel name", inputChannel->getName());
  log("Input channel is analog", inputChannel->isAnalog());
  log("Input channel is output", inputChannel->isOutput());
  log("Input channel is enabled", inputChannel->isEnabled());
  log("Input channel timer", inputChannel->getTimer());

  log("Module location", domoticModule->getConfig()->getModuleLocation());
  log("Module name", domoticModule->getConfig()->getModuleName());
}

void loop() {
  domoticModule->cycle();
  delay(100);
}