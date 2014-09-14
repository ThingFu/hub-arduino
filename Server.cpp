#include "Server.h"

Server::Server() {
	this->receiver = Receiver();
}


bool Server::gotData() {
  return this->rf().available();
}

void Server::reset() {
  return this->rf().resetAvailable();
}

Payload Server::getPayload() {
  RCSwitch rc = this->receiver.rf();

  return Payload( rc.getReceivedValue(), rc.getReceivedBitlength(), 
                  rc.getReceivedDelay(), rc.getReceivedRawdata(), 
                  rc.getReceivedProtocol());
}

RCSwitch Server::rf() {
	  return this->receiver.rf();
}
