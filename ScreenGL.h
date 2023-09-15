// ScreenGL.h

#ifndef SCREENGL_H
#define SCREENGL_H

//#define GLEW_STATIC

//#include <GL/glew.h>
#include "ShaderGL.h"
#include "Screen.h"
#include <glad/glad.h>

//#include "Figure.h"
//#include "Menu.h"

//using enum Screen::ScreenResolution;

class ScreenGL :public Screen
{
public:

	ScreenGL(ScreenResolution sr, float scale);

	//void init_glew();
	void createWindow(ScreenResolution sr, float scale) override;

	void showGL(ShaderGL& shader);
	void preDraw(ShaderGL& shader);
	void drawGL(ShaderGL& shader);
	
	//ShaderGL get_shader() { return shader; };
	//ShaderGL* get_p_shader() { return p_shader; };
	

	//ShaderGL* p_ShaderGL;
//	ShaderGL& ref_ShaderGL = temp;


private:

	SDL_GLContext GLContext;

	//ShaderGL* p_shader;
	//ShaderGL& ref_shader = shader;
	

};

#endif // !SCREENGL_H