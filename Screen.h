// Screen.h

#ifndef SCREEN_H
#define SCREEN_H
//#define GLEW_STATIC

//#include <GL/glew.h>
//#include 
#include <chrono>
#include <stdexcept>
#include "SDL.h"
#include "Figure.h"
#include "Menu.h"

class Figure;

template<typename T>
class Menu;


class Screen
{


public:
	enum class ScreenResolution {VGA, HDTV, QHD, UHD };
	//friend class Figure;

	Screen();
	Screen(ScreenResolution sr, float scale);


	void setScale(float value);


	//void input();
	virtual void show() {};
	void show(Figure& figure);

	void showMenu(Menu<float>& figure);


	void show(Figure& figure, Figure& figure2);
	//void drawPixel(float x, float y);
	//void clear();
	
	void setColor(unsigned & color, unsigned value);
	void setR(unsigned value) { setColor(r, value); };
	void setG(unsigned value) { setColor(g, value); };
	void setB(unsigned value) { setColor(b, value); };
	void setAlpha(unsigned value) { setColor(alpha, value); };

	void setAllColors(unsigned r, unsigned g, unsigned b, unsigned alpha);

	unsigned getR() { return r; };
	unsigned getG() { return g; };
	unsigned getB() { return b; };
	unsigned getAlpha() { return alpha; };

	int getScreenWidth() { return screenWidth; };
	int getScreenHeight() { return screenHeight; };

	SDL_Window* getWindow() { return window; };
	SDL_Window* getWindowGL() { return windowGL; };


	//float getScaleWidth() { return scaleWidth; };
	//float getScaleHeight() { return scaleHeight; };

	void setScreenResolution(ScreenResolution sr);

	void createWindowAndRender(ScreenResolution sr, float scale);

	virtual void createWindow(ScreenResolution sr, float scale) {};

	void setWindow(Uint32 flags);

	//friend list


	

private:
	
	SDL_Window* window;
	SDL_Window* windowGL;
	SDL_Renderer* renderer;
	//std::vector<SDL_FPoint> points;

	float scale;

	unsigned r;
	unsigned g;
	unsigned b;
	unsigned alpha;

	int screenWidth;
	int screenHeight;

	//float scaleWidth;
	//float scaleHeight;

};

#endif