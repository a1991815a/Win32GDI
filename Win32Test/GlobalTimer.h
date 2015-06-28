#ifndef __GLOBALTIMER__
#define __GLOBALTIMER__
#include "SingleInstance.h"

typedef unsigned long long time_type;

#define _globalTimer GlobalTimer::getInstance()

class GlobalTimer: public SingleInstance<GlobalTimer>{
	friend class SingleInstance<GlobalTimer>;
	GlobalTimer();
	~GlobalTimer();
public:
	void refresh();
	int getDT() const;
	int getTimerDT() const;
	void resetTimerDT();

private:
	time_type start_time;
	time_type before_time;
	time_type cur_time;
	int delta_time;
};
#endif