// Menu.h

#ifndef MENU_H
#define MENU_H

#include <vector>
#include "Except.h"
//#include "Setup.h"

class Setup;
class Screen;

template<typename T>
class Menu
{
public:
	Menu(float height, float width);

	
	float get_height_Menu() { return height_Menu; };
	float get_width_Menu() { return width_Menu; };
	
	void set_height_Menu(float height);
	void set_width_Menu(float width);
	
	void set_points_Menu(T value);


private:

	float height_Menu;
	float width_Menu;
	
	std::vector<T> points_Menu;

	std::vector<Screen> screens;

	//Screen & screen = Setup::get_p_Screen();
	
};

#endif // MENU_H
