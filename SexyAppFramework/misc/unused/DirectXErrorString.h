#pragma once
#include <string>
#include <ddraw.h>

namespace Sexy
{
	std::string GetDirectXErrorString(HRESULT theResult);
} // namespace 

#endif