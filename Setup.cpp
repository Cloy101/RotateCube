//setup.cpp
#include "Setup.h"

Setup::Setup()
{
	// 1. Initializing the SDL library
	SDL_Init(SDL_INIT_VIDEO);

	// 2. Creating the window;
	Screen screen(HDTV, 1.0f);// (HDTV, 1.0f);

	/////////////////
    // IF YOU WANT TO WATCH THE COLOR TRIANGLE THAT IS DROWN BY OPENGL YOU HAVE TO COMMENT THE STRING BELOW
	screen.createWindowAndRender(HDTV, 1.0f); // Create window for drawing the figures with CPU

	
	/////////////////
	// IF YOU WANT TO WATCH THE COLOR TRIANGLE THAT IS DROWN BY OPENGL YOU HAVE TO UNCOMMENT THE CODE BELOW
	/*
	//------------------------------------------------------------------------------
	// Initialization of OpenGL
	
	screen.setWindow(SDL_WINDOW_OPENGL);


	
	// 3. Making the OpenGL contex and GLsetup
	GLContext = SDL_GL_CreateContext(screen.getWindow());

	SDL_GL_SetAttribute(SDL_GL_CONTEXT_MAJOR_VERSION, 4);
	SDL_GL_SetAttribute(SDL_GL_CONTEXT_MINOR_VERSION, 6);

	SDL_GL_SetAttribute(SDL_GL_CONTEXT_PROFILE_MASK, SDL_GL_CONTEXT_PROFILE_CORE);
	SDL_GL_SetAttribute(SDL_GL_DOUBLEBUFFER, 1);
	SDL_GL_SetAttribute(SDL_GL_DEPTH_SIZE, 32);

	SDL_GL_SetSwapInterval(1);

	// 4. Initialization of GLAD

	if (!gladLoadGLLoader(SDL_GL_GetProcAddress))
	{
		std::cout << "Failed to initialize GLAD" << std::endl;
	}

	
	// 5. Making the shader program
	ShaderGL shader("Shaders/Vertex.vs","Shaders/Fragment.frag");


	// 6. Making vertexes and colors
	GLfloat vertices[] = {
						-0.5f, -0.5f, 0.0f,
						 0.5f, -0.5f, 0.0f,
						 0.0f,  0.5f, 0.0f
	};

	GLfloat colors[] = {
					 	 1.0f, 0.0f, 0.0f,
						 0.0f, 1.0f, 0.0f,
						 0.0f, 0.0f, 1.0f
	};

	// 7. Makin VBO and VAO
	GLuint VAO, verticesVBO, colorsVBO;
	glGenVertexArrays(1, &VAO);
	glGenBuffers(1, &verticesVBO);
	glGenBuffers(1, &colorsVBO);

	// 8.  Bind the Vertex Array Object first, then bind and set vertex buffer(s) and attribute pointer(s).
	glBindVertexArray(VAO);

	glBindBuffer(GL_ARRAY_BUFFER, verticesVBO);
	glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);

	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(GLfloat), nullptr);
	glEnableVertexAttribArray(0);

	glBindBuffer(GL_ARRAY_BUFFER, colorsVBO);
	glBufferData(GL_ARRAY_BUFFER, sizeof(colors), colors, GL_STATIC_DRAW);

	glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(GLfloat), nullptr);
	glEnableVertexAttribArray(1);
	
	

	//-----------------------------------------------------------------------
	// The initialization ends with destroying the window because to rewrite the code without this step too long for simple demonstration of skills
	// Below the code, that producing the image of rotated figures by CPU
	*/


	Cube cube;
	Triangle triangle;
	Player player;

	p_Screen = std::make_shared<Screen>(screen);
	p_Cube = std::make_shared<Cube>(cube);
	p_Triangle = std::make_shared<Triangle>(triangle);
	p_Player = std::make_shared<Player>(player);
	
	cube.Figure::calculateCentroid(); // this function set the Figure::Vec3d centroid  (x,y,z)
	triangle.Figure::calculateCentroid(); // this function set the Figure::Vec3d centroid  (x,y,z)
	cube.drawFigure(cube.get_P_ConnectionPointsCube());
	triangle.drawFigure(triangle.get_P_ConnectionPointsTriangle());




	while (true)
	{
		/////////////////
		// IF YOU WANT TO WATCH THE COLOR TRIANGLE THAT IS DROWN BY OPENGL YOU HAVE TO UNCOMMENT THE CODE BELOW
		/*
		glClearColor(0.5f, 0.5f, 0.5f, 1.0f);
		glClear(GL_COLOR_BUFFER_BIT);

		shader.useShaderGL();
		glBindVertexArray(VAO);
		glDrawArrays(GL_TRIANGLES, 0, 3);

		glBindVertexArray(0);

		input<Player>(player);
		SDL_GL_SwapWindow(screen.getWindow());
		*/
		
		/////////////////
		// IF YOU WANT TO WATCH THE COLOR TRIANGLE THAT IS DROWN BY OPENGL YOU HAVE TO COMMENT THE STRING BELOW
		screen.show(cube, triangle);
				
		player.rotateWithCentroid(cube.get_P_Centroid(), cube.Figure::get_P_Points3dVector());
		player.rotateWithCentroid(triangle.get_P_Centroid(), triangle.Figure::get_P_Points3dVector());

		cube.Figure::clearPoints();
		triangle.Figure::clearPoints();

		cube.drawFigure(cube.get_P_ConnectionPointsCube());
		triangle.drawFigure(triangle.get_P_ConnectionPointsTriangle());

		input<Player>(player);



	}
}


template<typename T>
void Setup::input(T& value)
{
	while (SDL_PollEvent(&event))
	{
		switch (event.type)
		{
		case SDL_QUIT:
			//SDL_Quit();
			exit(0);
			break;

		case SDL_KEYDOWN:
			value.keys[event.key.keysym.sym] = true;
			if (value.keys[SDLK_ESCAPE])
			{
				//SDL_Quit();
				exit(0);
			}
			if (value.keys[SDLK_SPACE])
			{
				if (changeScreen != true)
				{
					changeScreen = true;
				}	else 
					{
						changeScreen = false;
					}
			}
			break;

		case SDL_KEYUP:
			value.keys[event.key.keysym.sym] = false;
			break;

		default:
			break;
		}

	}
}

bool Setup::stop()
{
	return false;
}

