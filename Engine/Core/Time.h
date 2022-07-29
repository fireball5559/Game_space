#pragma once
#include <chrono>
namespace anvilHM 
{
	class Time 
	{
	private:
		using clock = std::chrono::high_resolution_clock;
		using clock_duration = clock::duration;
		using clock_rep = clock::rep;
	public:
		Time()
			: m_startTimePoint{ clock::now() },
			m_frameTimePoint{ clock::now() }{};
		void Tick();
		void reset() { m_startTimePoint = clock::now(); }
	public:
			float deltaTime;
			float time = 0;
	private:
		
		clock::time_point m_startTimePoint;//timepoint at start of application
		clock::time_point m_frameTimePoint;//timepoint at start of frame

	};
}
