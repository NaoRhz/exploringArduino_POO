#ifndef PROCESS_H
#define PROCESS_H

#define WATCHDOG_DURATION 1000

class nProcess{ 
    private:
        unsigned long startMark = 0;

    public:    
        bool do_each(unsigned long delay); 
};

#endif /* PROCESS_H */
