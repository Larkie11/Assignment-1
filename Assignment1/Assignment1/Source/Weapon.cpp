/*!
\file Weapon.cpp
\author Mok Wei Min
\par email:155208U\@mymail.nyp.edu.sg
\brief	Defining weapon functions
*/
/******************************************************************************/

#include "Weapon.h"

/*!
\brief
Virtual destructor for weapon
*/
Weapon::~Weapon()
{

}

/*!
\brief
Overloaded constructor taking in weapon name, durability and attack damage and passing on to relavant variables.
\param name Takes in and passes weapon name to item.
\param dura Takes in and passes weapon durability to item.
\param dmg Takes in weapon damage and passes to kAttackDmg.
*/
Weapon::Weapon(const string& name, const int& dura, const int& dmg) : Item(name,dura),kAttackDmg(dmg)
{

}

/*!
\brief
Getter for weapon attack damage.
\return Weapon attack damage.
*/
const int Weapon::getAttackDmg()
{
	return kAttackDmg;
}

/*!
\brief
This function gets called when equipment takes damage, that function passes in the dmg to minus weapon's durability (only half damage).
\param dmg Minus the damage by half from weapon's current durability.
*/
void Weapon::receiveDamage(const int& dmg)
{
	durability_ -= (dmg / 2);
}