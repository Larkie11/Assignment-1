#include "Weapon.h"

Weapon::Weapon(const string& wName, const int& dura, const int& dmg) : kAttackDmg(dmg)
{

}

const int Weapon::getAttackDmg()
{
	return kAttackDmg;
}