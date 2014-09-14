#ifndef _WatchdogService_h
#define _WatchdogService_h

class WatchdogService {
	public:
    	WatchdogService();
    	void configure(int delay);
    	void delay(long ms);

	private:
		int watchdogDelay;
};

#endif
