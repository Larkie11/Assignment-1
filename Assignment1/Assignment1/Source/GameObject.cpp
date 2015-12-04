#include "GameObject.h"

GameObject::GameObject(const string& name): kName(name)
{
	count_++;
}

string GameObject::getName()
{
	return kName;
}

int GameObject::getCount()
{
	return count_;
}