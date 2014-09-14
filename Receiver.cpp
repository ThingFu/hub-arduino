#include "Receiver.h"

Receiver::Receiver() {
	this->rcswitch = RCSwitch();
	this->rcswitch.enableReceive(DEFAULT_RF_RECEIVE_PIN);
}

RCSwitch Receiver::rf() {	
	return this->rcswitch;
}