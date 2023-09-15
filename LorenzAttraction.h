//LorenzAttraction.h
#ifndef LORENZATTRACTION_H
#define LORENZATTRACTION_H

#include "Except.h"
#include "Figure.h"
#include "Connection.h"



class LorenzAttraction :public Figure
{

	public:

		const float S = 10.0f;
		const float R = 28.0f;
		const float B = 8.0f / 3.0f;

		LorenzAttraction();

		void set_lengthA_side(float value);
		void set_lengthB_side(float value);
		void set_lengthC_side(float value);
		void setVec3dLorenz(Vec3d temp);


	/*	float get_lengthA_side() { return lengthA_side; };
		float get_lengthB_side() { return lengthB_side; };
		float get_lengthC_side() { return lengthC_side; };*/



		Figure& getFigureRef() { return figureRef; };


		Vec3d vec3dLorenz;

		Vec3d getVec3dLorenz() { return this->vec3dLorenz; };

		std::vector<Connection> getConnectionPointsLorenz() { return connectionPointsLorenz; };
		std::vector<Connection>& get_P_ConnectionPointsLorenz() { return p_ConnectionPointsLorenz; };

		//virtual std::vector<Figure::Vec3d> setVectors() override;

	private:

		float dt;

		//void draw2dLorenz(float xStart, float yStart, float lengthLine);
		void draw3dLorenz(Vec3d& vec3d, float x_A, float y_A, float x_B, float y_B, float x_C, float y_C, float z);
		void setConnectionPointsLorenz();

		//Vec3d calculateBisector(float x, float y, float z);

		Figure& figureRef;

		std::vector<Connection> connectionPointsLorenz;
		std::vector<Connection>& p_ConnectionPointsLorenz{ connectionPointsLorenz };


};

#endif // LORENZATTRACTION_H