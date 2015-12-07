#include "GameObject.h"

int GameObject::count_ = 0;

GameObject::~GameObject()
{

}

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