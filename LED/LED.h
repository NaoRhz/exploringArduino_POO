#ifndef LED_H
#define LED_H

enum led_status_t{OFF, ON};

class LED{
    private:
        int pin;
        led_status_t state = OFF;
        unsigned long startMarkForBlink = 0;

    public:
        LED(int pin);   /*  Constructor */
        
        void turn(led_status_t required_status);
        void blink(unsigned long timeOff, unsigned long timeOn);
};

#endif /*   LED_H   */

