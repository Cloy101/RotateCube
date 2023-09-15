//Player.h

#ifndef PLAYER_H 
#define PLAYER_H

#include <cmath>
#include <map>
#include "Figure.h"

class Vec3d;




class Player
{
public:
	Player();

	std::map<int, bool> keys;

	void rotate(Vec3d& point, float x, float y, float z);
	std::vector<Vec3d> rotateWithCentroid(Vec3d& vec3d, std::vector<Vec3d>& vector);
	
	float rotateX;
	float rotateY;
	float rotateZ;

private:


};

#endif
