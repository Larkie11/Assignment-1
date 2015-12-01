#ifndef DWELLER_H
#define DWELLER_H
#include "Vec2D.h"
#include "Outfit.h"
#include "Weapon.h"

class Dweller
{
private:
	Vec2D position;
	int SPECIAL_;
	int health_;
	int radiation_;
	int stimpak_;
	int radaway_;
	const Outfit* outfit;

public:
	Dweller(const string&, const int&);
	~Dweller();
	const int getSPECIAL();
	const int getCurrentHealth();
	const int getCurrentRadDamage();
	const int getAttackDmg();
	const Vec2D& getPosition(void);
	void recieveHealthDamage(const int&);
	void receiveRadDamage(const int&);
	void receiveEquipmentDamage(const int&);
	void addStimpak(const int&);
	void addRadAway(const int&);
	void useStimpak();
	void useRadAway();
	const Outfit* assignOutfit(Outfit*);
	const Weapon* assignWeapon(Weapon*);
	bool isDead();
};

#endif