//cube.cpp
#include "Cube.h"
#include <stdexcept>
#include <iostream>

Cube::Cube() :figureRef(*this)
{
	Figure::setColorFigure(255, 255, 0, 255); //Yellow
	setLengthLine(200);
	setConnectionPointsCube();
	//draw2dCube(500, 500, getLengthLine());
	draw3dCube(vec3dCube, 200, 200, 200, getLengthLine());

}


void Cube::setLengthLine(float value)
{
	if (value < 1)
	{
		throw std::invalid_argument("You entered the value of Cube length less than 1, the value = 1 now");
		this->lengthLine = 1;
	}
	else { this->lengthLine = value; }
}

void Cube::setVec3dCube(Vec3d temp)
{
	this->vec3dCube = temp;
}

void Cube::draw2dCube(float xStart, float yStart, float lengthLine)
{
	Figure::drawLine(xStart, yStart, xStart+lengthLine, yStart);
	Figure::drawLine(xStart + lengthLine, yStart, xStart + lengthLine, yStart + lengthLine);
	Figure::drawLine(xStart + lengthLine, yStart + lengthLine, xStart, yStart + lengthLine);
	Figure::drawLine(xStart, yStart + lengthLine, xStart, yStart);
}

void Cube::draw3dCube(Vec3d& vec3d, float xStart, float yStart, float zStart, float lengthLine)
{
	vec3d.setAllPointsVec3d(xStart, yStart, zStart);
	Figure::setPoints3dVector(vec3d);

	vec3d.setAllPointsVec3d(xStart + lengthLine, yStart, zStart);
	Figure::setPoints3dVector(vec3d);

	vec3d.setAllPointsVec3d(xStart + lengthLine, yStart + lengthLine, zStart);
	Figure::setPoints3dVector(vec3d);

	vec3d.setAllPointsVec3d(xStart, yStart + lengthLine, zStart);
	Figure::setPoints3dVector(vec3d);

	vec3d.setAllPointsVec3d(xStart, yStart, zStart + lengthLine);
	Figure::setPoints3dVector(vec3d);

	vec3d.setAllPointsVec3d(xStart + lengthLine, yStart, zStart + lengthLine);
	Figure::setPoints3dVector(vec3d);

	vec3d.setAllPointsVec3d(xStart + lengthLine, yStart + lengthLine, zStart + lengthLine);
	Figure::setPoints3dVector(vec3d);

	vec3d.setAllPointsVec3d(xStart, yStart + lengthLine, zStart + lengthLine);
	Figure::setPoints3dVector(vec3d);
}

void Cube::setConnectionPointsCube()
{
	connectionPointsCube = { 
							 {0,1},
							 {0,3},
							 {0,4},
							 {1,2},
							 {1,5},
							 {2,6},
							 {2,3},
							 {3,7},
							 {4,5},
							 {4,7},
							 {5,6},
							 {6,7},
						   };
}


