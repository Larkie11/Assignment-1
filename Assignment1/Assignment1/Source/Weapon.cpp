#include "Weapon.h"

Weapon::Weapon(const string& wName, const int& dura, const int& kAttackDmg) : kAttackDmg(kAttackDmg)
{
	if (kAttackDmg < 0)
	{
		//kAttackDmg = 0;
	}
}

const int Weapon::getAttackDmg()
{
	return kAttackDmg;
}