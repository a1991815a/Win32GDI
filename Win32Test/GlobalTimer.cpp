#include "GlobalTimer.h"
#include "stdafx.h"

GlobalTimer::GlobalTimer()
	:delta_time(0)
{
	start_time = before_time = cur_time = GetTickCount();
}

GlobalTimer::~GlobalTimer()
{

}

void GlobalTimer::refresh()
{
	before_time = cur_time;
	cur_time = GetTickCount();
	delta_time += getDT();
}

int GlobalTimer::getDT() const
{
	return cur_time - before_time;
}

int GlobalTimer::getTimerDT() const
{
	return delta_time;
}

void GlobalTimer::resetTimerDT()
{
	delta_time = 0;
}
