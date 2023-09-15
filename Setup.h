//setup.h

#ifndef SETUP_H
#define SETUP_H

#include <iostream>
#include <stdexcept>


#include "Triangle.h"
#include "Screen.h"
#include "Cube.h"
#include "Player.h"
#include "ShaderGL.h"

using enum Screen::ScreenResolution;

class Setup
{
public:
	Setup();

	template<typename T>
	void input(T& value);

	Setup* get_p_Setup() { return this; };
	std::shared_ptr<Screen> get_p_Screen() { return p_Screen; };
	std::shared_ptr<Cube> get_p_Cube() { return p_Cube; };
	std::shared_ptr<Triangle> get_p_Triangle() { return p_Triangle; };
	std::shared_ptr<Player> get_p_Player() { return p_Player; };


	bool changeScreen;

private:

	bool stop();

	SDL_Event event;
	SDL_GLContext GLContext;

	std::shared_ptr<Screen> p_Screen;
	std::shared_ptr<Cube> p_Cube;
	std::shared_ptr<Triangle> p_Triangle;
	std::shared_ptr<Player> p_Player;

};

#endif 