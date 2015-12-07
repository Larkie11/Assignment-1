#include "Outfit.h"


Outfit::~Outfit()
{

}

Outfit::Outfit(const string& name, const int& dura, const int& SPECIAL) : Item(name,dura), kSPECIAL_(SPECIAL)
{

}

const int Outfit::getSPECIAL()
{
	return kSPECIAL_;
}

void Outfit::receiveDamage(const int&dmg)
{
	durability_ -= dmg;
}