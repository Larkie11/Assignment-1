#ifndef GAMEOBJECT
#define GAMEOBJECT
#include <string>

using std::string;

class GameObject
{
private:
	const string kName;
	int count_;

protected:
	GameObject(const string&);

public:
	~GameObject();
	string getName(void);
	int getCount();
};


#endif