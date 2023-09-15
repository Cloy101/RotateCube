//cube.h
#ifndef CUBE_H
#define CUBE_H

#include <stdexcept>
#include "Figure.h"
#include "Connection.h"


class Cube :public Figure
{
public:
	Cube();

	void setLengthLine(float value);
	float getLengthLine() { return lengthLine; };

	Figure& getFigureRef() { return figureRef; };

	void setVec3dCube(Vec3d temp);

	Vec3d vec3dCube;
	
	Vec3d getVec3dCube() { return this->vec3dCube; };

	std::vector<Connection> getConnectionPointsCube() { return connectionPointsCube; };
	std::vector<Connection> & get_P_ConnectionPointsCube() { return p_ConnectionPointsCube; };

	//virtual std::vector<Figure::Vec3d> setVectors() override;

private:

	float lengthLine;
	void draw2dCube(float xStart, float yStart, float lengthLine);
	void draw3dCube(Vec3d& vec3d, float xStart, float yStart, float zStart, float lengthLine);
	void setConnectionPointsCube();

	
	Figure& figureRef;
	
	std::vector<Connection> connectionPointsCube;
	std::vector<Connection>& p_ConnectionPointsCube{ connectionPointsCube };


};

#endif 
