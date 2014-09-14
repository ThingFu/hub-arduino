#include "Transmitter.h"
#include "Util.h"

Transmitter::Transmitter() {
	this->rcswitch = RCSwitch();
	this->rcswitch.enableTransmit(DEFAULT_RF_PIN);
}

void Transmitter::send(unsigned int serial, unsigned int sensor, unsigned int data) {
	this->rcswitch.send(createPacket(serial, sensor, data));
}

char *Transmitter::createPacket(unsigned int serial, unsigned int sensor, unsigned int data) {
	char *buf = new char[25];
	char *_serial = new char[7];
	char *_sensor = new char[3];
	char *_data = new char[13];

	dec_to_bin(_serial, serial, 6);	
	dec_to_bin(_sensor, sensor, 2);
	dec_to_bin(_data, data, 12);

	sprintf(buf, "%s%s%s%s", PREAMBLE, _serial, _sensor, _data);
	
	return buf;
}
