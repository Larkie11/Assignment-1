#include "Item.h"

Item::~Item()
{

}

Item::Item(const string& name, const int& initialdura) : GameObject(name),durability_(initialdura)
{
}

const int Item::getDurability()
{
	return durability_;
}
