#include "LED.h"
#include <Arduino.h>

LED::LED(int pin){
    this->pin = pin;
    pinMode(pin, OUTPUT);
}

void LED::turn(led_status_t required_status){
    if(this->state == required_status) return;
    digitalWrite(this->pin, required_status);
}

void LED::blink(unsigned long timeOFF, unsigned long timeON){
  
  switch (this->state) {
    
    case OFF:
        if ( millis() - this->startMarkForBlink >= timeOFF ){
            digitalWrite(this->pin, HIGH);
            this->state = ON;
            this->startMarkForBlink = millis();
            return;
        }
        
        return;

    case ON:
        if ( millis() - this->startMarkForBlink >= timeON ){
            digitalWrite(this->pin, LOW);
            this->state = OFF;
            this->startMarkForBlink = millis();
            return;
        }
        
        return;
  }  
}