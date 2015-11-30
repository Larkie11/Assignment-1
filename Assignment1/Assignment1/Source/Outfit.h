#ifndef OUTFIT_H
#define OUTFIT_H
#include "Item.h"


class Outfit
{
private:
	const int kSPECIAL_;

public:
	Outfit(const string&, const int&, const int&);
	~Outfit();
	const int getSPECIAL();
};

#endif