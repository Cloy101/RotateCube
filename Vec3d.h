//Vec3d.h
#ifndef VEC3D_H
#define VEC3D_H

#include "Except.cpp"



class Vec3d
{
public:
	Vec3d();

	void setX(float x);
	void setY(float y);
	void setZ(float z);

	float getX() { return x; };
	float getY() { return y; };
	float getZ() { return z; };

	void setAllPointsVec3d(float x, float y, float z);

	bool operator != (const Vec3d& source) const;

	bool operator == (const Vec3d& source) const;



	Vec3d(const Vec3d& copy);

	
	Vec3d operator = (Vec3d& moved) noexcept
	{
		if (moved != *this)
		{
			setAllPointsVec3d(moved.x, moved.y, moved.z);
			return moved;
		}	else
			{
				return *this;
			}
	}

private:

	void except(float & value, float value2);

	float x, y, z;
};

#endif // Vec3d.h