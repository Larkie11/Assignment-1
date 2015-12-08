/******************************************************************************/
/*!
\file GameObject.cpp
\author Mok Wei Min
\par email:155208U\@mymail.nyp.edu.sg
\brief	Gameobject function definitions
*/
/******************************************************************************/

#include "GameObject.h"

int GameObject::count_ = 0;

/*!
\brief
Virtual destructor for gameobject.
*/
GameObject::~GameObject()
{

}

/*!
\brief
Overloaded constructor taking one argument. Also + count everytime objects of this type are instantiated.
\param name Takes in the name of the object.
*/
GameObject::GameObject(const string& name): kName(name)
{
	count_++;
}

/*!
\brief
Getter for object name.
\return name of the object.
*/
string GameObject::getName()
{
	return kName;
}

/*!
\brief
Getter for count for every object instantiated by derived classes.
\return count of objects of this type instantiated.
*/
int GameObject::getCount()
{
	return count_;
}