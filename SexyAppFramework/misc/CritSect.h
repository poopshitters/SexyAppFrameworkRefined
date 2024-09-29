#pragma once

#include "Common.h"
#include "include.h"


class CritSync;

namespace Sexy
{

	class CritSect
	{
	private:
		CRITICAL_SECTION mCriticalSection;
		friend class AutoCrit;

	public:
		CritSect(void);
		~CritSect(void);
	};

}