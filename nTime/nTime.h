#ifndef N_TIME_H
#define N_TIME_H

#include <Arduino.h>

#define END_SECOND_MINUTE       59
#define END_HOUR                23

#define _1_SECONDS              1000    /*  milliseconds    */
#define _5_SECONDS              5000    /*  milliseconds    */
#define _10_SECONDS             10000   /*  milliseconds    */
#define _15_SECONDS             15000   /*  milliseconds    */
#define _30_SECONDS             30000   /*  milliseconds    */
#define _1_MINUTES              60000   /*  milliseconds    */
#define _5_MINUTES              300000  /*  milliseconds    */
#define _10_MINUTES             600000  /*  milliseconds    */
#define _15_MINUTES             900000  /*  milliseconds    */

enum timeState_t{
                  equal, 
                  early, 
                  late
                };

class nTime{
    private:
        String timeReference;
        unsigned short int hour;
        unsigned short int minute;
        unsigned short int second;

    public:
    
        nTime(const String ref){
            this->timeReference = ref;
        }

        void update_each(unsigned long updateDelay); 
        void printCurrentTime();
        timeState_t cmpTime(nTime &timeToCmp);
        bool cmpTimeInterval(nTime &timeStart, nTime &timeEnd);
};

#endif /*   TIME_H      */