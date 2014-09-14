#ifndef _Transmitter_h
#define _Transmitter_h

#include "RCSwitch.h"

#define DEFAULT_RF_PIN 7
#define PREAMBLE "0110"

class Transmitter {
  public:
    Transmitter();
    void send(unsigned int serial, unsigned int sensor, unsigned int data);

  private:
  	RCSwitch rcswitch;
  	char *createPacket(unsigned int serial, unsigned int sensor, unsigned int data);
};

#endif
