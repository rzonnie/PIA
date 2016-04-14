/* 
 * File:   ThreadRunner.h
 * Author: remi
 *
 * Created on April 10, 2016, 1:38 PM
 */

#ifndef THREADRUNNER_H
#define THREADRUNNER_H

#include "Settings.h"

class ThreadRunner {
public:
    ThreadRunner();
    ThreadRunner(Settings* settings);
    virtual ~ThreadRunner();
    
    /**
     * Every subclass should implement its own thread runner. This run function will
     * run during the entire thread life span.
     */
    virtual void run() = 0;
    void setQuit(bool quit);
    bool getQuit() const;
protected:
    /**
     * Pointer to the settings
     */
    Settings *settings;
    
    /**
     * On true, exit thread
     */
    bool quit = false;
};

#endif /* THREADRUNNER_H */

