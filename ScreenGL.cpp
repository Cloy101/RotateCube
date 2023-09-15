#include "ScreenGL.h"

ScreenGL::ScreenGL(ScreenResolution sr, float scale) 
{
	//SDL_GL_LoadLibrary(NULL);
	
	
	// Take a window from class Screen
	
	createWindow(sr, scale);

	GLContext = SDL_GL_CreateContext(Screen::getWindow());

	SDL_GL_SetAttribute(SDL_GL_CONTEXT_MAJOR_VERSION, 4);
	SDL_GL_SetAttribute(SDL_GL_CONTEXT_MINOR_VERSION, 6);

	SDL_GL_SetAttribute(SDL_GL_CONTEXT_PROFILE_MASK, SDL_GL_CONTEXT_PROFILE_CORE);
	SDL_GL_SetAttribute(SDL_GL_DOUBLEBUFFER, 1);
	SDL_GL_SetAttribute(SDL_GL_DEPTH_SIZE, 32);
	
	SDL_GL_SetSwapInterval(1);


	if (!gladLoadGLLoader(SDL_GL_GetProcAddress))
	{
		std::cout << "Failed to initialize GLAD" << std::endl;
	}


	//ShaderGL shader;
	//this->p_shader = &shader;


	//shader.createShaderProgram();
	//glGenBuffers(1, &shader.pointsVBO);
	//glGenBuffers(1, &shader.colorsVBO);
	//shader.init_vao(); // need change later
	//shader.bindVBOtoVAO(shader.vao, shader.pointsVBO, shader.pointsGL, 0, 3, GL_FLOAT, GL_FALSE, 3);
	//shader.bindVBOtoVAO(shader.vao, shader.colorsVBO, shader.colorsGL, 0, 4, GL_FLOAT, GL_FALSE, 4);
	
}

//void ScreenGL::init_glad()
//{
//	if(!gladLoadGLLoader(SDL_GL_GetProcAddress))
//	{
//		std::cout << "Failed to initialize GLAD" << std::endl;
//		SDL_Quit();
//	}
//	
//}

void ScreenGL::createWindow(ScreenResolution sr, float scale)
{
	Screen::setScreenResolution(sr);
	Screen::setWindow(SDL_WINDOW_OPENGL);
}

void ScreenGL::showGL(ShaderGL& shader)
{
	//SDL_ClearWin
	//SDL_ShowWindow(Screen::getWindow());

	drawGL(shader);

	// Update the screen
	
}

void ScreenGL::preDraw(ShaderGL& shader)
{
	glDisable(GL_DEPTH_TEST);
	glDisable(GL_CULL_FACE);
	//glViewport(0, 0, Screen::getScreenWidth(), Screen::getScreenHeight());
	drawGL(shader);

}

void ScreenGL::drawGL(ShaderGL& shader)
{
	//ShaderGL& temp = *shader;
	//glDisable(GL_DEPTH_TEST);
	//glDisable(GL_CULL_FACE);

	//glViewport(0, 0, Screen::getScreenWidth(), Screen::getScreenHeight());
	
	//shader.useShader(shader.vao);
}


                             