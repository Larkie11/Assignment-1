/******************************************************************************/
/*!
\file Dweller.cpp
\author Mok Wei Min
\par email:155208U\@mymail.nyp.edu.sg
\brief	Defining dweller functions
*/
/******************************************************************************/
#include "Dweller.h"

/*!
\brief
Constructor taking two arguments. Initializes the variables of dweller.
\param name Takes in and passes name of dweller to gameobject.
\param SPECIAL Takes in SPECIAL and passes to SPECIAL_ variable.
*/
Dweller::Dweller(const string& name, const int& SPECIAL) : GameObject(name), SPECIAL_(SPECIAL)
{
	position_ = Vec2D(0, 0);
	health_ = 100;
	radiation_ = 0;
	stimpak_ = 0;
	radaway_ = 0;

	weapon_ = nullptr;
	outfit_ = nullptr;
}

/*!
\brief 
Virtual destructor for dweller.
*/
Dweller::~Dweller()
{

}

/*!
\brief
Takes in position and then set it to position_ variable.
\param pos Position of dweller to set to.
\return Nothing.
*/
void Dweller::setPosition(const Vec2D& pos)
{
	position_ = pos;
}

/*!
\brief
Checks if weapon/outfits are assigned; then call their receiveDamage function.
\param dmg - Damage that weapon/outfit takes.
\return Nothing.
*/
void Dweller::receiveEquipmentDamage(const int& dmg)
{
	//Only if weapon is assigned
	if (weapon_ != nullptr)
	{
		weapon_->receiveDamage(dmg);
	}
	//Only if outfit is assigned
	if (outfit_ != nullptr)
	{
		outfit_->receiveDamage(dmg);
	}
}

/*!
\brief
Takes in dmg that dweller's health is going to take, and minus that dmg from current dweller's health.
\param dmg - Damage that dweller's health takes.
\return Nothing
*/
void Dweller::receiveHealthDamage(const int& dmg)
{
	if (health_ > 0)
	{
		health_ -= dmg;
	}
}

/*!
\brief
Adds radiation damage to variable radiation_ and then checking for maximum health dweller can get since radiation will reduce max health that is healable.
\param rad - Radiaion damage that dweller receives,
\return Nothing
*/
void Dweller::receiveRadDamage(const int& rad)
{
	//increase the amount of radiation dweller has
	radiation_ += rad;

	//if max health - radiation is less than current health
	//assign max health - radiation
	if (100-radiation_ < health_)
	{
		health_ = 100 - radiation_;
	}
}
/*!
\brief
Adds stimpak to dweller stimpak_ variable.
\param stimpak - Amount of stimpak to add to stimpak_ variable.
\return Nothing
*/
void Dweller::addStimpak(const int& stimpak)
{
	stimpak_+=stimpak;
}

/*!
\brief
Adds radaway to dweller radaway_ variable.
\param radaway - Amount of radaway to add to radaway_ variable.
\return Nothing
*/
void Dweller::addRadAway(const int& radaway)
{
	radaway_+= radaway;
}

/*!
\brief
Checks if dweller has stimpak_, minus 1 stimpak, then check for maxhealth, then use stimpak +20 health, only can use until health reaches max health attainable.
\return Nothing
*/
void Dweller::useStimpak()
{
	if (stimpak_ > 0)
	{
		stimpak_--;
		if (health_ < 100)
		{
			if (health_ > 80 - radiation_)
			{
				health_ = 100 - radiation_;
				if (health_ > 100)
				{
					health_ = 100;
				}
			}

			else
			{
				health_ += 20;
				if (health_ > 100)
				{
					health_ = 100;
				}
			}
		}
	}
}

/*!
\brief
Checks if dweller has radaway_, then minus 1 from the radaway_ variable, deducts 10 radiation. 
\return Nothing
*/
void Dweller::useRadAway()
{
	if (radaway_ > 0)
	{
		radaway_--;
		radiation_ -= 10;
	}
	if (radiation_ <= 0)
	{
		radiation_ = 0;
	}
}

/*!
\brief
Get each digit in dweller and outfit special int, then add them together, maximum for each digit is 9, if no outfit/outfit no durability, 
only return dweller special
\return Nothing
*/
const int Dweller::getSPECIAL()
{
	int a = SPECIAL_ % 10;
	int b = SPECIAL_ / 10 % 10;
	int c = SPECIAL_ / 100 % 10;
	int d = SPECIAL_ / 1000 % 10;
	int e = SPECIAL_ / 10000 % 10;
	int f = SPECIAL_ / 100000 % 10;
	int g = SPECIAL_ / 1000000 % 10;
	
	//If no outfit assigned, give back dweller special
	if (outfit_ == nullptr)
	{
		return SPECIAL_;
	}
	//If outfit is assigned
	else
	{
		//Get outfit special
		int kSPE = outfit_->getSPECIAL();
		//if outfit has no durability
		if (outfit_->getDurability() <= 0)
		{
			return SPECIAL_;
		}

		//if outfit has durability
		else
		{
			int ka = kSPE % 10;
			int kb = kSPE / 10 % 10;
			int kc = kSPE / 100 % 10;
			int kd = kSPE / 1000 % 10;
			int ke = kSPE / 10000 % 10;
			int kf = kSPE / 100000 % 10;
			int kg = kSPE / 1000000 % 10;

			if (kg + g > 9)
			{
				kg = 9000000;
			}
			else
			{
				kg = (kg + g)*1000000;
			}
			if (kf +f > 9)
			{
				kf = 900000;
			}
			else
			{
				kf = (kf + f)*100000;
			}
			if (ke +e > 9)
			{
				ke = 90000;
			}
			else
			{
				ke = (ke + e)*10000;
			}
			if (kd +d > 9)
			{
				kd = 9000;
			}
			else
			{
				kd = (kd + d)*1000;
			}
			if (kc + c > 9)
			{
				kc = 900;
			}
			else
			{
				kc = (kc + c)*100;
			}
			if (kb +b > 9)
			{
				kb = 90;
			}
			else
			{
				kb = (kb + b)*10;
			}
			if (ka +a > 9)
			{
				ka = 9;
			}
			else
			{
				ka += a;
			}

			return kg + kf + ke + kd + kc + kb + ka;
		}
	}
}
/*!
\brief
Getter for dweller health.
\return Current health point for dweller.
*/
const int Dweller::getCurrentHealth()
{
	return health_;
}

/*!
\brief
Getter for radiation damage.
\return Current radiation damage for dweller.
*/
const int Dweller::getCurrentRadDamage()
{
	return radiation_;
}

/*!
\brief
Checks if a weapon is assigned, if it is, use the weapons attack damage,
if it is not assigned/has no durability, int 1 as damage.
\return Dweller's attack damage either with or without weapon attack damage.
*/
const int Dweller::getAttackDmg()
{
	if (weapon_ == nullptr)
	{
		return 1;
	}

	else
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
}

/*!
\brief
Getter for dweller position.
\return Vec2D for position.
*/
const Vec2D& Dweller::getPosition()
{
	return position_;
}

/*!
\brief
Boolean method to check if dweller is dead, health lesser than 1 means dweller is dead,
health more than 1 means dweller is alive.
\return Dweller dead = true/false
*/
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

/*!
\brief
Takes in outfit pointer parameter and passes to dweller outfit_ variable.
\param outfit - to pass on to dweller outfit_ variable.
\return Outfit pointer
*/
Outfit* Dweller::assignOutfit(Outfit* outfit)
{
	Outfit* oldOutfit = outfit;
	outfit_ = outfit;
	return oldOutfit;
}

/*!
\brief
Takes in weapon pointer parameter and passes to dweller weapon_ variable.
\param weapon - to pass on to dweller weapon_ variable.
\return Weapon pointer
*/
Weapon* Dweller::assignWeapon(Weapon* weapon)
{
	Weapon* oldWeapon = weapon;
	weapon_ = weapon;
	return oldWeapon;
}