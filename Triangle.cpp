//Triangle.cpp
#include "Triangle.h"
#include <stdexcept>
#include <iostream>

Triangle::Triangle() :figureRef(*this)
{
	//figureRef = *this;

	Figure::setColorFigure(0, 255, 0, 255); //Yellow
	set_lengthA_side(100);
	set_lengthB_side(100);
	set_lengthC_side(100);
	setConnectionPointsTriangle();
	//draw2dTriangle(500, 500, getLengthLine());
	draw3dTriangle(vec3dTriangle, 500, 100, 600, 500, 800, 100, 500);

}

void Triangle::set_lengthA_side(float value)
{
	this->lengthA_side = value;
}

void Triangle::set_lengthB_side(float value)
{
	this->lengthB_side = value;
}

void Triangle::set_lengthC_side(float value)
{
	this->lengthC_side = value;
}


//void Triangle::setLengthLine(float value)
//{
//	if (value < 1)
//	{
//		throw std::invalid_argument("You entered the value of Triangle length less than 1, the value = 1 now");
//		this->lengthLine = 1;
//	}
//	else { this->lengthLine = value; }
//}

void Triangle::setVec3dTriangle(Vec3d temp)
{
	this->vec3dTriangle = temp;
}



void Triangle::draw3dTriangle(Vec3d& vec3d, float x_A, float y_A, float x_B, float y_B, float x_C, float y_C, float z)
{
	vec3d.setAllPointsVec3d(x_A, y_A, z);
	Figure::setPoints3dVector(vec3d);

	vec3d.setAllPointsVec3d(x_B, y_B, z);
	Figure::setPoints3dVector(vec3d);

	vec3d.setAllPointsVec3d(x_C, y_C, z);
	Figure::setPoints3dVector(vec3d);

	float length_A = Figure::calculateLengthLine(x_B, y_B, x_C, y_C);
	float length_B = Figure::calculateLengthLine(x_C, y_C, x_A, y_A);
	float length_C = Figure::calculateLengthLine(x_A, y_A, x_B, y_B);

	float x = (length_A * x_A + length_B * x_B + length_C * x_C) / (length_A + length_B + length_C);
	float y = (length_A * y_A + length_B * y_B + length_C * y_C) / (length_A + length_B + length_C);

	vec3d.setAllPointsVec3d(x,y, 200 );

	Figure::setPoints3dVector(vec3d);
}

void Triangle::setConnectionPointsTriangle()
{
	connectionPointsTriangle = 
	{
							 {0,1},
							 {0,2},
							 {0,3},
							 {1,2},
							 {1,3},
							 {2,3},
	};
}

//Vec3d Triangle::calculateBisector(float z)
//{
//	float bisector = (std::sqrt(
//								get_lengthA_side() * get_lengthB_side() *
//								(get_lengthA_side() + get_lengthB_side() + get_lengthC_side()) *
//								(get_lengthA_side() + get_lengthB_side() - get_lengthC_side())
//							  ) / (get_lengthA_side() + get_lengthB_side())) / 3;
//    //get_lengthA_side()
//
//	Vec3d temp;
//	
//	float x = ;
//
//	temp.setX();
//	temp.setY();
//	temp.setZ(z);
//	
//	return temp;
//}
