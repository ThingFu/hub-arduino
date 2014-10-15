#include <RCSwitch.h>

#define BAUD_RATE 9600
#define RECEIVER_PIN    0   // Interrupt Pin
#define TRANSMITTER_PIN 10

RCSwitch receiver = RCSwitch();
RCSwitch transmitter = RCSwitch();

void setup() {
 Serial.begin(BAUD_RATE);
 receiver.enableReceive(RECEIVER_PIN);
 transmitter.enableTransmit(TRANSMITTER_PIN);  
}

String incomingViaSerial;

void loop() {
  if (receiver.available()) {   
    char buf[24];
    sprintf(buf, "TF|%d|%lu|E0", receiver.getReceivedProtocol(), receiver.getReceivedValue());
    Serial.println (buf);
    
    receiver.resetAvailable();
  }
  
  while (Serial.available()) {
      delay(3); 
      if (Serial.available() > 0) {      
        char c = Serial.read();         
        incomingViaSerial += c;        
      }      
  }
  
  if (incomingViaSerial.length() > 0) {
    char charBuf[incomingViaSerial.length()+1];
    incomingViaSerial.toCharArray(charBuf, incomingViaSerial.length()+1);        
    transmitter.send(charBuf);
    incomingViaSerial = "";
  }  
}



