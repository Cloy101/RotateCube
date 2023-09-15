//Vec3d.cpp
#include "Vec3d.h"

Vec3d::Vec3d()
{
	setX(0);
	setY(0);
	setZ(0);
}

void Vec3d::setX(float x)
{
	except(this->x, x);
}

void Vec3d::setY(float y)
{
	except(this->y, y);
}

void Vec3d::setZ(float z)
{
	except(this->z, z);
}

void Vec3d::setAllPointsVec3d(float x, float y, float z)
{
	setX(x);
	setY(y);
	setZ(z);
}

bool Vec3d::operator!=(const Vec3d& source) const
{
	if (this->x != source.x && this->y != source.y && this->z != source.z) { return true; }
	return false;
}

bool Vec3d::operator==(const Vec3d& source) const
{
	if (this->x == source.x && this->y == source.y && this->z == source.z) { return true; }
	return false;
}

Vec3d::Vec3d(const Vec3d& copy)
{
	if (copy != *this)
	{
		setAllPointsVec3d(copy.x, copy.y, copy.z);
	}
}

void Vec3d::except(float & value, float value2)
{
	//if (exception<float, Vec3d>(value2, *this)) { value = 1; }
	//else { value = value2; }
	value = value2;

}



