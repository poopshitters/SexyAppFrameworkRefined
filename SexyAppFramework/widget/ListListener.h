#pragma once

namespace Sexy 
{

class ListListener 
{
public:
	virtual void ListClicked(int theId, int theIdx, int theClickCount) = 0;
	virtual void ListClosed(int theId) = 0;
	virtual void ListHiliteChanged(int theId, int theOldIdx, int theNewIdx) = 0;
};

}


