//Triangle.h
#ifndef TRIANGLE_H
#define TRIANGLE_H

#include "Except.h"
#include "Figure.h"
#include "Connection.h"


class Triangle :public Figure
{
public:
	Triangle();

	void set_lengthA_side(float value);
	void set_lengthB_side(float value);
	void set_lengthC_side(float value);
	void setVec3dTriangle(Vec3d temp);


	float get_lengthA_side() { return lengthA_side; };
	float get_lengthB_side() { return lengthB_side; };
	float get_lengthC_side() { return lengthC_side; };



	Figure& getFigureRef() { return figureRef; };


	Vec3d vec3dTriangle;

	Vec3d getVec3dTriangle() { return this->vec3dTriangle; };

	std::vector<Connection> getConnectionPointsTriangle() { return connectionPointsTriangle; };
	std::vector<Connection>& get_P_ConnectionPointsTriangle() { return p_ConnectionPointsTriangle; };

	//virtual std::vector<Figure::Vec3d> setVectors() override;

private:

	float lengthA_side;
	float lengthB_side;
	float lengthC_side;
	//void draw2dTriangle(float xStart, float yStart, float lengthLine);
	void draw3dTriangle(Vec3d& vec3d, float x_A, float y_A, float x_B, float y_B, float x_C, float y_C, float z);
	void setConnectionPointsTriangle();

	//Vec3d calculateBisector(float x, float y, float z);

	Figure& figureRef;

	std::vector<Connection> connectionPointsTriangle;
	std::vector<Connection>& p_ConnectionPointsTriangle{ connectionPointsTriangle };


};

#endif 
