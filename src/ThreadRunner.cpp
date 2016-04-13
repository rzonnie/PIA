/* 
 * File:   ThreadRunner.cpp
 * Author: remi
 * 
 * Created on April 10, 2016, 1:38 PM
 */

#include "../include/ThreadRunner.h"

ThreadRunner::ThreadRunner() {
}

ThreadRunner::ThreadRunner(Settings* settings)
: settings(settings) {
}


ThreadRunner::~ThreadRunner() {
}

void ThreadRunner::setQuit(bool quit) {
    this->quit = quit;
}
