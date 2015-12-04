#ifndef WEAPON_H
#define WEAPON_H
#include "Item.h"

class Weapon : public Item
{
private:
	const int kAttackDmg;

public:
	Weapon(const string&, const int&, const int&);
	~Weapon();
	const int getAttackDmg();
};
#endif