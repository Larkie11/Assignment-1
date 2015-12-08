/*!
\file Weapon.h
\author Mok Wei Min
\par email:155208U\@mymail.nyp.edu.sg
\brief	Class for weapon object
*/
/******************************************************************************/

#ifndef WEAPON_H
#define WEAPON_H
#include "Item.h"

/******************************************************************************/
/*!
Class GameObject:
\brief	Class for weapon, sets/gets weapon name, durability and atack damage.
*/
/******************************************************************************/

class Weapon : public Item
{
private:
	const int kAttackDmg;

public:
	Weapon(const string&, const int&, const int&);
	virtual ~Weapon();
	virtual void receiveDamage(const int&);
	const int getAttackDmg();
};
#endif