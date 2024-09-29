#ifndef __SEXY_PERFTIMER_H__
#define __SEXY_PERFTIMER_H__

#include "Common.h"

namespace Sexy
{

///////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////
class PerfTimer 
{
protected:
	LARGE_INTEGER mStart;
	double mDuration;
	bool mRunning;

	void CalcDuration();

public:
	PerfTimer();
	void Start();
	void Stop();

	double GetDuration();

	static __int64 GetCPUSpeed(); // in Hz
	static int GetCPUSpeedMHz(); 
};

///////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////
class SexyPerf
{
public:
	static void BeginPerf(bool measurePerfOverhead = false);
	static void EndPerf();
	static bool IsPerfOn();

	static void StartTiming(const char *theName);
	static void StopTiming(const char *theName);

	static std::string GetResults();
};

///////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////
class SexyAutoPerf
{
public:
	const char *mName;
	bool mIsStarted;

	SexyAutoPerf(const char *theName) : mName(theName), mIsStarted(true) { SexyPerf::StartTiming(theName); }
	SexyAutoPerf(const char *theName, bool doStart) : mIsStarted(doStart), mName(theName) 
	{ 
		if(doStart) 
			SexyPerf::StartTiming(theName);
	}

	~SexyAutoPerf() { Stop(); }

	void Start()
	{
		if(!mIsStarted)
		{
			mIsStarted = true;
			SexyPerf::StartTiming(mName);
		}
	}

	void Stop() 
	{ 
		if(mIsStarted) 
		{ 
			SexyPerf::StopTiming(mName);
			mIsStarted = false;
		}
	}
};

///////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////
//#define SEXY_PERF_ENABLED
#ifdef SEXY_PERF_ENABLED

#define SEXY_PERF_BEGIN(theName) SexyPerf::StartTiming(theName)
#define SEXY_PERF_END(theName) SexyPerf::StopTiming(theName)
#define SEXY_AUTO_PERF_MULTI(theName,theSuffix) SexyAutoPerf anAutoPerf##theSuffix(theName)
#define SEXY_AUTO_PERF(theName) SEXY_AUTO_PERF_MULTI(theName,1)

#define SEXY_PERF_BEGIN_COND(theName,theCond) if(theCond) SexyPerf::StartTiming(theName)
#define SEXY_PERF_END_COND(theName,theCond) if(theCond) SexyPerf::StopTiming(theName)
#define SEXY_AUTO_PERF_MULTI_COND(theName,theSuffix,theCond) SexyAutoPerf anAutoPerf##theSuffix(theName,theCond); 
#define SEXY_AUTO_PERF_COND(theName) SEXY_AUTO_PERF_MULTI_COND(theName,1,theCond)

#else

#define SEXY_PERF_BEGIN(theName) 
#define SEXY_PERF_END(theName) 
#define SEXY_AUTO_PERF_MULTI(theName,theSuffix)
#define SEXY_AUTO_PERF(theName) 

#define SEXY_PERF_BEGIN_COND(theName,theCond) 
#define SEXY_PERF_END_COND(theName,theCond) 
#define SEXY_AUTO_PERF_MULTI_COND(theName,theSuffix,theCond) 
#define SEXY_AUTO_PERF_COND(theName) 

#endif

} // namespace Sexy
#endif