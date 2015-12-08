/******************************************************************************/
/*!
\file Vec2D.h
\author Mok Wei Min
\par email:155208U\@mymail.nyp.edu.sg
\brief	Struct to define a 2D Vector
*/
/******************************************************************************/

#ifndef VEC2D_H
#define VEC2D_H

/******************************************************************************/
/*!
Class Vec2D:
\brief	Struct class for storing dweller 2d position x and y.
*/
/******************************************************************************/

struct Vec2D
{
	double x;
	double y;
	Vec2D();
	Vec2D(double vx, double vy);
};

#endif