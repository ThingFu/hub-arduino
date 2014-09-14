#include "Server.h"
#include "Receiver.h"

#define BAUD_RATE 9600

Server server = Server();

void setup() {
 Serial.begin(9600);
}

void loop() {
  if (server.gotData()) {
      Payload payload = server.getPayload();      
      char *payloadStr = payload.asJson();
      Serial.println (payloadStr);

      server.reset();
    }
}



