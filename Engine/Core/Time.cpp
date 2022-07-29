#include "Time.h"
namespace anvilHM {
	
	void anvilHM::Time::Tick()
	{
		clock_duration duration = clock::now() - m_startTimePoint;
		time = duration.count()/(float)clock_duration::period::den;//den is 1 trillion :D

		duration = clock::now() - m_frameTimePoint;
		deltaTime = duration.count() / (float)clock_duration::period::den;
		
		m_frameTimePoint = clock::now();
	}
}
