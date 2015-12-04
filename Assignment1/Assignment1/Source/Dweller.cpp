#include "Dweller.h"

Dweller::Dweller(const string& name, const int& SPECIAL) : GameObject(name), SPECIAL_(SPECIAL)
{
	position(0, 0);
	health_ = 100;
	radiation_ = 0;
	stimpak_ = 0;
	radaway_ = 0;

	weapon_ = nullptr;
	outfit_ = nullptr;

	if (SPECIAL_ > 9999999)
	{
		SPECIAL_ = 9999999; //cap at 9999999
	}
	this->SPECIAL_ = SPECIAL;
}

Dweller::~Dweller()
{

}
//void Dweller::receiveEquipmentDamage(const int& dmg)
//{
//
//}
void Dweller::recieveHealthDamage(const int& dmg)
{

}
void Dweller::receiveRadDamage(const int& rad)
{
	//increase the amount of radiation dweller has
	radiation_ += rad;

	//Rad values = 0 to 100
	if (radiation_ >0 && radiation_< 100 )
	{
		health_ -= radiation_;
	}
}
void Dweller::receiveEquipmentDamage(const int&)
{

}
void Dweller::addStimpak(const int& stimpak)
{
	stimpak_+=stimpak;
}
void Dweller::addRadAway(const int& radaway)
{
	radaway_+= radaway;
}
void Dweller::useStimpak()
{
	stimpak_--;
	health_ += 20;
}
void Dweller::useRadAway()
{
	radaway_--;
	radiation_ -= 10;
}

const int Dweller::getSPECIAL()
{
	return SPECIAL_;
}
const int Dweller::getCurrentHealth()
{
	return health_;
}
const int Dweller::getCurrentRadDamage()
{
	return radiation_;
}
const int Dweller::getAttackDmg()
{
	//return kAttackDmg??
	return 0;
}
const Vec2D& Dweller::getPosition(void)
{
	//return position(x,y);
}

bool Dweller::isDead()
{
	if (health_ < 1) //lesser than 1 dweller dies
	{
		return true;
	}
	else
	{
		return false;
	}
}