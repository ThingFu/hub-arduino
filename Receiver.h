#ifndef _Receiver_h
#define _Receiver_h

#include "RCSwitch.h"

#define DEFAULT_RF_RECEIVE_PIN 0

class Receiver {

  public:
    Receiver();
    RCSwitch rf();

  private:
  	RCSwitch rcswitch;
};

#endif
