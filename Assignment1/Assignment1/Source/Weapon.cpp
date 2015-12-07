#include "Weapon.h"

Weapon::~Weapon()
{

}

Weapon::Weapon(const string& name, const int& dura, const int& dmg) : Item(name,dura),kAttackDmg(dmg)
{

}

const int Weapon::getAttackDmg()
{
	return kAttackDmg;
}

void Weapon::receiveDamage(const int& dmg)
{
	durability_ -= (dmg / 2);
}