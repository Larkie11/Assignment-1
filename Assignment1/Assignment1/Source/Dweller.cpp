#include "Dweller.h"

Dweller::Dweller(const string& name, const int& SPECIAL) : GameObject(name), SPECIAL_(SPECIAL)
{
	position_ = Vec2D(0, 0);
	health_ = 100;
	radiation_ = 0;
	stimpak_ = 0;
	radaway_ = 0;

	weapon_ = nullptr;
	outfit_ = nullptr;

	if (SPECIAL_> 9999999)
	{
		SPECIAL_ = 9999999; //cap at 9999999
	}
}

Dweller::~Dweller()
{

}
void Dweller::setPosition(const Vec2D& pos)
{
	position_ = pos;
}
void Dweller::receiveEquipmentDamage(const int& dmg)
{
	if (weapon_ != nullptr)
	{
		weapon_->receiveDamage(dmg);
	}
	if (outfit_ != nullptr)
	{
		outfit_->receiveDamage(dmg);
	}
}
void Dweller::receiveHealthDamage(const int& dmg)
{
	health_ -= dmg;
}
void Dweller::receiveRadDamage(const int& rad)
{
	//increase the amount of radiation dweller has
	radiation_ += rad;

	if (100-radiation_ < health_)
	{
		health_ = 100 - radiation_;
	}
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
	if (health_ > 80 - radiation_)
	{
		health_ = 100 - radiation_;
	}
	stimpak_--;
	health_ += 20;
}
void Dweller::useRadAway()
{
	if (radaway_ > 1)
	{
		radaway_--;
		radiation_ -= 10;
	}
	if (radiation_ <= 0)
	{
		radiation_ = 0;
	}
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
	if (weapon_ != nullptr)
	{
		if (weapon_->getDurability() > 0)
		{
			return weapon_->getAttackDmg();
		}

		else
		{
			return 1;
		}
	}
	if (weapon_ == nullptr)
	{
		return 1;
	}
}
const Vec2D& Dweller::getPosition()
{
	return position_;
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
Outfit* Dweller::assignOutfit(Outfit* outfit)
{
	outfit_ = outfit;
	return outfit_;
}
Weapon* Dweller::assignWeapon(Weapon* weapon)
{
	weapon_ = weapon;
	return weapon_;
}