#include "nProcess.h"
#include <Arduino.h>

bool nProcess::do_each(unsigned long delay){
  return millis() - this->startMark >= delay ? true,this->startMark = millis()  : false;
}