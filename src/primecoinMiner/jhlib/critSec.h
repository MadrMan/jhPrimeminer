#pragma once

class JHCritSec
{
public:
	JHCritSec()
#ifndef _WIN32
		: mutex(PTHREAD_RECURSIVE_MUTEX_INITIALIZER_NP)
#endif
	{
#ifdef _WIN32
		InitializeCriticalSection(&cs);
#endif
	}

	~JHCritSec()
	{
#ifdef _WIN32
		DeleteCriticalSection(&cs);
#endif
	}

	void lock()
	{
#ifdef _WIN32
		EnterCriticalSection(&cs);
#else
		pthread_mutex_lock(&mutex);
#endif
	}

	inline void unlock()
	{
#ifdef _WIN32
		LeaveCriticalSection(&cs);	
#else
		pthread_mutex_unlock(&mutex);
#endif
	}

private:
#ifdef _WIN32
	CRITICAL_SECTION cs;
#else
	pthread_mutex_t mutex;	
#endif
};

