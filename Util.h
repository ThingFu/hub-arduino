#ifndef _Util_h
#define _Util_h

inline void dec_to_bin(char* bin, unsigned long long Dec, unsigned int bitLength) {
  unsigned int i=0;

  while (Dec > 0)  {
    bin[32+i++] = ((Dec & 1) > 0) ? '1' : '0';
    Dec = Dec >> 1;
  }

  for (unsigned int j = 0; j< bitLength; j++)  {
    if (j >= bitLength - i) {
      bin[j] = bin[ 31 + i - (j - (bitLength - i)) ];
    } else  {
      bin[j] = '0';
    }
  }
  bin[bitLength] = '\0';
  
  return;
}

inline char *bin_to_tristate(char *bin) {
  char returnValue[50];
  
  int pos = 0;
  int pos2 = 0;
  while (bin[pos]!='\0' && bin[pos+1]!='\0') {
    if (bin[pos]=='0' && bin[pos+1]=='0') {
      returnValue[pos2] = '0';
    } else if (bin[pos]=='1' && bin[pos+1]=='1') {
      returnValue[pos2] = '1';
    } else if (bin[pos]=='0' && bin[pos+1]=='1') {
      returnValue[pos2] = 'F';
    } else {
      return "not applicable";
    }
    pos = pos+2;
    pos2++;
  }
  returnValue[pos2] = '\0';

  return returnValue;  
}

#endif
