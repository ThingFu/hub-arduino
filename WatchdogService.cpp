#include "WatchdogService.h"
#include "Narcoleptic.h"

WatchdogService::WatchdogService() {
	this->watchdogDelay = 8000;
}

void WatchdogService::configure(int delay) {
	this->watchdogDelay = delay;
}

void WatchdogService::delay(long ms) { 
 while(ms > 0) {
 	  int wdDelay = this->watchdogDelay;
      if(ms > wdDelay) {
        ms -= wdDelay;
        Narcoleptic.delay(wdDelay);
      } else {
        Narcoleptic.delay(ms);
        break;
      }
   }
}
