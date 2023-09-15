// Screen.cpp
#include "Screen.h"


Screen::Screen()
{

	setScreenResolution(ScreenResolution::VGA);
	setScale(1.0);
	this->window = nullptr;
	this->windowGL = nullptr;
	//this->renderer = nullptr;

	setAllColors(0, 0, 0, 0);
}

Screen::Screen(ScreenResolution sr, float scale)
{

	setScreenResolution(sr);
	setScale(scale);
	this->window = nullptr;
	this->windowGL = nullptr;
	//this->renderer = nullptr;

	setAllColors(20, 20, 20, 255);
}



void Screen::setScale(float value)
{
	this->scale = value;
}


void Screen::show(Figure & figure)
{
	SDL_SetRenderDrawColor(renderer, r, g, b, alpha);
	//SDL_RenderClear(renderer);

	SDL_SetRenderDrawColor(renderer, figure.getRFig(), figure.getGFig(), figure.getBFig(), figure.getAlphaFig());
	for (auto& point : figure.getPoints())
	{
		SDL_RenderDrawPointF(renderer, point.x, point.y);
		
	}
	SDL_RenderPresent(renderer);

}

void showMenu(Menu<float>& figure)
{

}

void Screen::show(Figure& figure, Figure& figure2)
{
	SDL_SetRenderDrawColor(renderer, r, g, b, alpha);
	SDL_RenderClear(renderer);

	SDL_SetRenderDrawColor(renderer, figure.getRFig(), figure.getGFig(), figure.getBFig(), figure.getAlphaFig());
	for (auto& point : figure.getPoints())
	{
		SDL_RenderDrawPointF(renderer, point.x, point.y);
	}
	//SDL_RenderPresent(renderer);

	SDL_SetRenderDrawColor(renderer, figure2.getRFig(), figure2.getGFig(), figure2.getBFig(), figure2.getAlphaFig());
	for (auto& point : figure2.getPoints())
	{
		SDL_RenderDrawPointF(renderer, point.x, point.y);

	}
	
	SDL_RenderPresent(renderer);

	SDL_Delay(7);

}



//void Screen::input()
//{
//	while (SDL_PollEvent(&event))
//	{
//		if (event.type == SDL_QUIT)
//		{
//			SDL_Quit();
//			exit(0);
//		}
//	}
//}



void Screen::setColor(unsigned & color,  unsigned value)
{
	if (value > 255)
	{
		throw std::invalid_argument("The Argument for color can't be more than 255, your argument have been returned to 0");
		color = 0;
	}
	else { color = value; }
}


void Screen::setAllColors(unsigned r, unsigned g, unsigned b, unsigned alpha)
{
	setR(r);
	setG(g);
	setB(b);
	setAlpha(alpha);
}


void Screen::setScreenResolution(ScreenResolution sr)
{
	switch (sr)
	{
	case ScreenResolution::VGA:
		this->screenWidth = 640;
		this->screenHeight = 480;
		break;
	case ScreenResolution::HDTV:
		this->screenWidth = 1920;
		this->screenHeight = 1080;
		break;
	case ScreenResolution::QHD:
		this->screenWidth = 2560;
		this->screenHeight = 1440;
		break;
	case ScreenResolution::UHD:
		this->screenWidth = 3840;
		this->screenHeight = 2160;
		break;
	}

}

void Screen::setWindow(Uint32 flags)
{
	this->window = SDL_CreateWindow("SDL_Window", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, getScreenWidth(), getScreenHeight(), flags | SDL_WINDOW_SHOWN);
}



void Screen::createWindowAndRender(ScreenResolution sr, float scale)
{
	setScreenResolution(sr);
	setScale(scale);
	//SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
	SDL_CreateWindowAndRenderer(getScreenWidth(), getScreenHeight(), 0, &window, &renderer);
	SDL_RenderSetScale(renderer, scale, scale);


}







