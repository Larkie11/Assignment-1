/*!
\file Vec2D.cpp
\author Mok Wei Min
\par email:155208U\@mymail.nyp.edu.sg
\brief	Struct to define a 2D Vector
*/
/******************************************************************************/

#include "Vec2D.h"

/*!
\brief
Default constructor vec2d
*/
Vec2D::Vec2D()
{

}

/*!
\brief
Overloaded constructor storing dweller x and y position
\param vx passes x value to variable x.
\param vy passes y value to variable y.
*/
Vec2D::Vec2D(double vx, double vy) : x(vx), y(vy)
{

}