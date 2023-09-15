//figure.cpp
#include "Figure.h"


Figure::Figure()
{
	setColorFigure(255, 0, 0, 255);
	this->centroid.setAllPointsVec3d(0,0,0);

	
	this->p_Points3dVector = points3dVector ;
	this->p_Centroid = centroid;

}


void Figure::setColorFigure(unsigned r, unsigned g, unsigned b, unsigned alpha)
{
	if (r > 255 || g > 255 || b > 255 || alpha > 255) 
	{
		throw std::invalid_argument("The range of Figure colors more then 255");
		this->rFig = 255;
		this->gFig = 0;
		this->bFig = 0;
		this->alphaFig = 255;
	}
	else
	{
		this->rFig = r;
		this->gFig = g;
		this->bFig = b;
		this->alphaFig = alpha;
	}
}


void Figure::drawLine(float pointStartX, float pointStartY, float pointEndX, float pointEndY)
{
	
	this->lengthLine = calculateLengthLine(pointStartX, pointStartY, pointEndX, pointEndY);

	//Definition of angle between the cathetes
	float angle = std::atan2(distractY, distractX);

	for (float i{}; i < lengthLine; i++)
	{
		drawPixel(pointStartX + std::cos(angle) * i, pointStartY + std::sin(angle) * i);
		//SDL_Delay(3);
	}
}



void Figure::drawPixel(float x, float y)
{
	points.emplace_back(SDL_FPoint(x, y));
}


void Figure::clearPoints()
{
	points.clear();
}


void Figure::setPoints3dVector(Vec3d& source)
{
	this->points3dVector.emplace_back(source);
}

void Figure::setConnectionPoints(int a, int b)
{
	this->connectionPoints.emplace_back(Connection(a, b));
}

void Figure::cleanPoints3dVector()
{
	this->points3dVector.clear();
}

void Figure::calculateCentroid()
{
	for (auto& temp : this->points3dVector)
	{
		centroid.setX(centroid.getX() + temp.getX());
		centroid.setY(centroid.getY() + temp.getY());
		centroid.setZ(centroid.getZ() + temp.getZ());
	}

	centroid.setX(centroid.getX() / points3dVector.size());
	centroid.setY(centroid.getY() / points3dVector.size());
	centroid.setZ(centroid.getZ() / points3dVector.size());

}

void Figure::drawFigure(std::vector<Connection>& connections)
{
	for (auto& conn : connections)
	{
		drawLine(
			getPoints3dVector().at(conn.getA()).getX(),
			getPoints3dVector().at(conn.getA()).getY(),
			getPoints3dVector().at(conn.getB()).getX(),
			getPoints3dVector().at(conn.getB()).getY()
			);
	}
}

float Figure::calculateLengthLine(float pointStartX, float pointStartY, float pointEndX, float pointEndY)
{
	//Definition of triangle cathetes
	this->distractX = pointEndX - pointStartX;
	this->distractY = pointEndY - pointStartY;

	//Definition of triangle hypotenuse
	return std::sqrt(pow(distractX, 2.0f) + pow(distractY, 2.0f));
}

