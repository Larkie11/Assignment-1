/******************************************************************************/
/*!
\file GameObject.h
\author Mok Wei Min
\par email:155208U\@mymail.nyp.edu.sg
\brief	Interface class gameobject
*/
/******************************************************************************/
#ifndef GAMEOBJECT
#define GAMEOBJECT
#include <string>

using std::string;

/******************************************************************************/
/*!
Class GameObject:
\brief	Interface/abstract class, count to store the number of objects initialized.
*/
/******************************************************************************/
class GameObject
{
private:
	const string kName;
	static int count_;

protected:
	GameObject(const string& string = "");

public:
	virtual ~GameObject();
	string getName(void);
	static int getCount();
};


#endif