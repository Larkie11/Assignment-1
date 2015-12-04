#ifndef ITEM_H
#define ITEM_H
#include "GameObject.h"

class Item : public GameObject
{
protected:
	int durability_;

public:
	Item(const string&, const int&);
	Item();
	~Item();
	void receiveDamage(const int&); //virtual function??
	const int getDurability();
};

#endif