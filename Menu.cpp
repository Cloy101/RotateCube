// Menu.cpp

#include "Menu.h"

template<typename T>
Menu<T>::Menu(float height, float width)
{
	try
	{
		set_height_Menu(height);
	}
	catch (const std::underflow_error& ex)
	{
		std::cout << "Menu::set_height_Menu(height) - " << ex.what() << std::endl;
	}

	try
	{
		set_width_Menu(width);
	}
	catch (const std::underflow_error& ex)
	{
		std::cout << "Menu::set_width_Menu(width) - " << ex.what() << std::endl;
	}

	set_points_Menu(0.0f);

}

template<typename T>
void Menu<T>::set_height_Menu(float height)
{
	Except except;
	if (except.exception_less_1<float>(height))
	{
		this->height_Menu = 200.0f;
	}
	else { this->height_Menu = height; }
}

template<typename T>
void Menu<T>::set_width_Menu(float width)
{
	Except except;
	if (except.exception_less_1<float>(width))
	{
		this->width_Menu = 50.0f;
	}
	else { this->width_Menu = width; }
}

template<typename T>
void Menu<T>::set_points_Menu(T value)
{
	this->points_Menu.emplace_back(value);
}
