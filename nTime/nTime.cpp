#include "nTime.h"
#include <Arduino.h>

void nTime::update_each(unsigned long updateDelay){ 
  static bool init = false;
  static unsigned long startMark = 0;

  if(!init){
    this->hour = ((this->timeReference).substring(0,2)).toInt();
    this->minute = ((this->timeReference).substring(3,5)).toInt();
    this->second = ((this->timeReference).substring(7,9)).toInt();
    
    init = true;
  }

  if( millis() - startMark > updateDelay ){
    startMark = millis();
    
    this->second++;
    if(this->second > END_SECOND_MINUTE){
      this->second =0;
      this->minute++;
      if(this->minute > END_SECOND_MINUTE){
        this->minute = 0;
        this->hour++;
        if(this->hour > END_HOUR){
          this->hour = 0;
        }
      }
    }
  } 

  
}

void nTime::printCurrentTime(){
  Serial.print(this->hour);Serial.print(":");
  Serial.print(this->minute);Serial.print(":");
  Serial.print(this->second);   
}

timeState_t nTime::cmpTime(nTime &timeToCmp){
  if(this->hour > timeToCmp.hour){
    return late;
  }else if(this->hour == timeToCmp.hour){
    if(this->minute > timeToCmp.minute){
      return late;
    }else if(this->minute == timeToCmp.minute){
      if(this->second > timeToCmp.second){
        return late;
      }else if(this->second == timeToCmp.second){
        return equal;
      }else{
        return early;
      }
    }else{
      return early;
    }
  }else{
    return early;
  }
}

bool nTime::cmpTimeInterval(nTime &timeStart, nTime &timeEnd){
  if( ((this->cmpTime(timeEnd)  == early) or (this->cmpTime(timeEnd)  == equal))
      and 
      ((this->cmpTime(timeStart) == late) or (this->cmpTime(timeStart) == equal)))
    {
      return true;
    }
    else{
      return false;
    }
}