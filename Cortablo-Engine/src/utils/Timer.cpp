// *****************| Cortablo-Engine |*****************
// * Copyright (c) 2019 Cortablo. All rights reserved. *
// *****************************************************

#include "Timer.h"

Timer::Timer()
{
	Start();
}

Timer::~Timer()
{
	Stop();
}

void Timer::Start()
{
	m_StartTime = std::chrono::high_resolution_clock::now();
}

void Timer::Stop()
{
	m_EndTime = std::chrono::high_resolution_clock::now();
}

void Timer::Reset()
{
	Start();
}

float Timer::GetElapsedSeconds()
{
	Stop();
	return std::chrono::duration_cast<std::chrono::seconds>(m_EndTime - m_StartTime).count();
}

float Timer::GetElapsedMilliseconds()
{
	Stop();
	return std::chrono::duration_cast<std::chrono::milliseconds>(m_EndTime - m_StartTime).count();
}

float Timer::GetElapsedMicroseconds()
{
	Stop();
	return std::chrono::duration_cast<std::chrono::microseconds>(m_EndTime - m_StartTime).count();
}

float Timer::GetElapsedNanoseconds()
{
	Stop();
	return std::chrono::duration_cast<std::chrono::nanoseconds>(m_EndTime - m_StartTime).count();
}
