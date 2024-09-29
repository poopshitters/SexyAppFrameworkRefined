#pragma once

namespace Sexy
{

class DialogListener
{
public:
	virtual void			DialogButtonPress(int theDialogId, int theButtonId) = 0;
	virtual void			DialogButtonDepress(int theDialogId, int theButtonId) = 0;
};

}
