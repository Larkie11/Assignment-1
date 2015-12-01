#ifndef ITEM_H
#define ITEM_H
#include "GameObject.h"

class Item
{
protected:
	int durability_;

public:
	Item(const string&, const int&);
	~Item();
	void receiveDamage(const int&);
	const int getDurability();
};

#endif