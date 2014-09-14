#ifndef _Device_h
#define _Device_h

#include "Transmitter.h"

typedef unsigned int (*DeviceStateHandler)(unsigned int sensor);
typedef void (*DeviceSetupHandler)(unsigned int sensor);

class Device {
	public:
    	Device(int serial, int sensors, DeviceStateHandler stateHandler, DeviceSetupHandler setupHandler);
    	void update();
    	void setup();

	private:
		Transmitter transmitter;
		int serial;
		int sensors;
		DeviceStateHandler stateHandler;
		DeviceSetupHandler setupHandler;

};

#endif
