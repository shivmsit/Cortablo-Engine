// *****************| Cortablo-Engine |*****************
// * Copyright (c) 2019 Cortablo. All rights reserved. *
// *****************************************************

#pragma once

#include <chrono>

class Timer
{
private:
	std::chrono::time_point<std::chrono::high_resolution_clock> m_StartTime, m_EndTime;
public:
	Timer();
	~Timer();

	void Start();
	void Stop();
	void Reset();

	float GetElapsedSeconds();
	float GetElapsedMilliseconds();
	float GetElapsedMicroseconds();
	float GetElapsedNanoseconds();
};