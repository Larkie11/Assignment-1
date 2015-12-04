#include "Outfit.h"

Outfit::Outfit(const string& name, const int& dura, const int& SPECIAL) : kSPECIAL_(SPECIAL)
{

}

const int Outfit::getSPECIAL()
{
	return kSPECIAL_;
}