#ifndef _Server_h
#define _Server_h

#include "RCSwitch.h"
#include "Payload.h"
#include "Receiver.h"

class Server {
	public:
    	Server();
    	bool gotData();
    	void reset();
    	Payload getPayload();

    private:
    	Receiver receiver;
    	RCSwitch rf();
};

#endif
