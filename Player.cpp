#include "Player.h"

Player::Player()
{
	this->rotateX = 0.001f;
	this->rotateY = 0.002f;
	this->rotateZ = 0.001f;
}

void Player::rotate(Vec3d& point, float x, float y, float z)
{
	float radius{};

	radius = x;
	point.setY(std::cos(radius) * point.getY() - std::sin(radius) * point.getZ());
	point.setZ(std::sin(radius) * point.getY() + std::cos(radius) * point.getZ());

	radius = y;
	point.setX(std::cos(radius) * point.getX() + std::sin(radius) * point.getZ());
	point.setZ(-std::sin(radius) * point.getX() + std::cos(radius) * point.getZ());

	radius = z;
	point.setX(std::cos(radius) * point.getX() - std::sin(radius) * point.getY());
	point.setY(std::sin(radius) * point.getX() + std::cos(radius) * point.getY());
}

std::vector<Vec3d> Player::rotateWithCentroid(Vec3d& centroid, std::vector<Vec3d>& containerOfPoints)
{
	std::vector<Vec3d> temp;

	for (auto& temp : containerOfPoints)
	{
		temp.setX(temp.getX() - centroid.getX());
		temp.setY(temp.getY() - centroid.getY());
		temp.setZ(temp.getZ() - centroid.getZ());
		rotate(temp, rotateX, rotateY, rotateZ);
		temp.setX(temp.getX() + centroid.getX());
		temp.setY(temp.getY() + centroid.getY());
		temp.setZ(temp.getZ() + centroid.getZ());
	}
	return temp;
}


