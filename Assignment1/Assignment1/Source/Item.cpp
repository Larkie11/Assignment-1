/******************************************************************************/
/*!
\file Item.cpp
\author Mok Wei Min
\par email:155208U\@mymail.nyp.edu.sg
\brief	Interface class item for outfits and weapons
*/
/******************************************************************************/

#include "Item.h"

/*!
\brief
Virtual destructor for item.
*/
Item::~Item()
{

}

/*!
\brief
Overloaded constructor taking two argument, and passing them to the variables.
\param name Takes in name of gameobject and passes it to the overloaded contructor for gameobject name.
\param initialdura Takes in initial durability and passes it to durability_ variable.
*/
Item::Item(const string& name, const int& initialdura) : GameObject(name),durability_(initialdura)
{
}

/*!
\brief
Getter for item durability
\return Durability for outfit or weapon.
*/
const int Item::getDurability()
{
	return durability_;
}
