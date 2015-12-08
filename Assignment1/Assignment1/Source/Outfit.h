/******************************************************************************/
/*!
\file Outfit.h
\author Mok Wei Min
\par email:155208U\@mymail.nyp.edu.sg
\brief	Class for outfit object
*/
/******************************************************************************/

#ifndef OUTFIT_H
#define OUTFIT_H
#include "Item.h"

/******************************************************************************/
/*!
Class GameObject:
\brief	Class for outfit, gets SPECIAL, and check for damage outfit takes.
*/
/******************************************************************************/

class Outfit : public Item
{
private:
	const int kSPECIAL_;

public:
	Outfit(const string&, const int&, const int&);
	virtual ~Outfit();
	virtual void receiveDamage(const int&);
	const int getSPECIAL();
};

#endif