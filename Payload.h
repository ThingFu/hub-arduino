#ifndef _Payload_h
#define _Payload_h

#include <Arduino.h>

class Payload {
	public:
    	Payload(unsigned long val, unsigned int bitLength, unsigned int delay,
    			unsigned int *raw, unsigned int protocol);
    	char *asJson();

    private:
    	unsigned long val;
    	unsigned int bitLength;
    	unsigned int delay;
		unsigned int *raw;
		unsigned int protocol;
};

#endif
