#include "Device.h"

Device::Device(int serial, int sensors, DeviceStateHandler stateHandler, DeviceSetupHandler setupHandler) {
	this->transmitter = Transmitter();
	this->serial = serial;
	this->stateHandler = stateHandler;
	this->setupHandler = setupHandler;
	this->sensors = sensors;
}

void Device::update() {
	for (int i=0; i < this->sensors; i++) {
		this->transmitter.send(this->serial, i, this->stateHandler(i));
	}
}

void Device::setup() {
	for (int i=0; i < this->sensors; i++) {
		this->setupHandler(i);
	}
}

