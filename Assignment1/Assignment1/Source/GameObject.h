#ifndef GAMEOBJECT
#define GAMEOBJECT
#include <string>

using std::string;

class GameObject
{
private:
	const string kName;
	static int count_;

protected:
	GameObject(const string&);

public:
	GameObject();
	~GameObject();
	string getName(void);
	static int getCount();
};


#endif