#pragma once

namespace Sexy
{

class ButtonListener
{
public:
	virtual void			ButtonPress(int theId) {};
	virtual void			ButtonDepress(int theId) {};
	virtual void			ButtonDownTick(int theId) {};
	virtual void			ButtonMouseEnter(int theId) {};
	virtual void			ButtonMouseLeave(int theId) {};
	virtual void			ButtonMouseMove(int theId, int theX, int theY) {};
};

}


