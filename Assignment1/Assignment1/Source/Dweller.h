/******************************************************************************/
/*!
\file Dweller.h
\author Mok Wei Min
\par email:155208U\@mymail.nyp.edu.sg
\brief	Class to define dweller
*/
/******************************************************************************/

#ifndef DWELLER_H
#define DWELLER_H
#include "Vec2D.h"
#include "Outfit.h"
#include "Weapon.h"

/******************************************************************************/
/*!
Class Dweller:
\brief	Defines the dweller class variables and methods
*/
/******************************************************************************/

class Dweller : public GameObject
{
private:
	Vec2D position_;
	int SPECIAL_;
	int health_;
	int radiation_;
	int stimpak_;
	int radaway_;
	Outfit* outfit_;
	Weapon* weapon_;

public:
	Dweller(const string&, const int&);
	virtual ~Dweller();
	const int getSPECIAL();
	const int getCurrentHealth();
	const int getCurrentRadDamage();
	const int getAttackDmg();
	const Vec2D& getPosition();
	void setPosition(const Vec2D&);
	void receiveHealthDamage(const int&);
	void receiveRadDamage(const int&);
	void receiveEquipmentDamage(const int&);
	void addStimpak(const int&);
	void addRadAway(const int&);
	void useStimpak();
	void useRadAway();
	Outfit* assignOutfit(Outfit*);
	Weapon* assignWeapon(Weapon*);
	bool isDead();
};

#endif