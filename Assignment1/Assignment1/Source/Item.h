/******************************************************************************/
/*!
\file Item.h
\author Mok Wei Min
\par email:155208U\@mymail.nyp.edu.sg
\brief	Interface class item for outfits and weapons
*/
/******************************************************************************/
#ifndef ITEM_H
#define ITEM_H
#include "GameObject.h"

/******************************************************************************/
/*!
Class GameObject:
\brief	Interface class for outfits and weapons that stores their durability.
*/
/******************************************************************************/
class Item : public GameObject
{
protected:
	int durability_;

public:
	Item(const string& string = "", const int& no = 0);
	virtual ~Item();
	virtual void receiveDamage(const int&) = 0;
	const int getDurability();
};

#endif