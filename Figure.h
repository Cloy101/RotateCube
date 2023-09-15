//figure.h
#ifndef FIGURE_H
#define FIGURE_H

#include <cmath>
#include <vector>
#include "Screen.h"
#include "Player.h"
#include "Vec3d.h"
#include "Connection.h"


class Vec3d;


class Figure 
{
public:
	//Figure()=default;
	Figure();
		
	unsigned getRFig() { return rFig; };
	unsigned getGFig() { return gFig; };
	unsigned getBFig() { return bFig; };
	unsigned getAlphaFig() { return alphaFig; };
	std::vector<SDL_FPoint> getPoints() { return points; };
	std::vector<Vec3d> getPoints3dVector() { return points3dVector; };
	Vec3d getCentroid() { return centroid; };
	std::vector<Vec3d> & get_P_Points3dVector() { return p_Points3dVector; };
	Vec3d & get_P_Centroid() { return p_Centroid; };
	float get_lengthLine() { return lengthLine; };

	virtual void drawPixel(float x, float y);
	virtual void drawLine(float pointStartX, float pointStartY, float pointEndX, float pointEndY);
	
	void clearPoints();
	void cleanPoints3dVector();


	void setColorFigure(unsigned r, unsigned g, unsigned b, unsigned alpha);
    void setPoints3dVector(Vec3d& source);
	void setConnectionPoints(int a, int b);

	void calculateCentroid();

	void drawFigure(std::vector<Connection>& connections);

	float calculateLengthLine(float pointStartX, float pointStartY, float pointEndX, float pointEndY);

private:
	unsigned rFig;
	unsigned gFig;
	unsigned bFig;
	unsigned alphaFig;
	float lengthLine;

	float distractX;
	float distractY;



	std::vector<SDL_FPoint> points;
	
//	template<typename T>
	std::vector<Vec3d> points3dVector;

	Vec3d centroid;

	std::vector<Vec3d>& p_Points3dVector{ points3dVector };

	Vec3d& p_Centroid{ centroid };

	std::vector<Connection> connectionPoints;

};

#endif 


