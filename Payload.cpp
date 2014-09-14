#include "Payload.h"
#include "Util.h"

Payload::Payload(unsigned long val, unsigned int bitLength, unsigned int delay,
                 unsigned int *raw, unsigned int protocol) {
  this->val = val;
  this->bitLength = bitLength;
  this->delay = delay;
  this->raw = raw;
  this->protocol = protocol;
}

char *Payload::asJson() {
  char buf[256];
  char binary[this->bitLength+1];
  dec_to_bin(binary, this->val, this->bitLength);

  // use snprintf
  sprintf(buf,
    "S|%d|%s|%lu|E",
    this->protocol,
    binary, 
    val
  );

  return buf;  
}
