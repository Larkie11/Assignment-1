/******************************************************************************/
/*!
\file Outfit.cpp
\author Mok Wei Min
\par email:155208U\@mymail.nyp.edu.sg
\brief	Class for outfit, gets SPECIAL, and check for damage outfit takes.
*/
/******************************************************************************/

#include "Outfit.h"

/*!
\brief
Virtual destructor for outfit
*/
Outfit::~Outfit()
{

}

/*!
\brief
Overloaded constructor for outfit that takes in name, durability and special value
and passes on to relative variables.
\param name passes outfit name to item.
\param dura passes outfit durability to item.
\param SPECIAL passes outfit special to kSPECIAL_ variable.
*/
Outfit::Outfit(const string& name, const int& dura, const int& SPECIAL) : Item(name,dura), kSPECIAL_(SPECIAL)
{

}

/*!
\brief
Getter for outfit SPECIAL int.
\return Outfit SPECIAL value.
*/
const int Outfit::getSPECIAL()
{
	return kSPECIAL_;
}

/*!
\brief
This function gets called when equipment takes damage, that function passes in the dmg to minus outfit's durability.
\param dmg Minus the damage from outfit's current durability.
*/
void Outfit::receiveDamage(const int&dmg)
{
	durability_ -= dmg;
}