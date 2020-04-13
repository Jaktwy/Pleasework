#pragma once
#define REFRESHRATE 16
#include <windows.h> //Required for OpenGL on Windows
#include <gl/GL.H> //OpenGL
#include <gl/GLU.H> //OpenGL Utilities
#include "GL\freeglut.h" //freeglut library 
#include "GLUTCallbacks.h"
#include "Structures.h"


class HelloGL
{
public:
	//constructor definition
	HelloGL(int argc, char* argv[]);
	
	//destructor 
	~HelloGL(void);

	void Display();

	void DrawCubeArray();

	void DrawPolygon();

	void Update();

	void Keyboard(unsigned char key, int x, int y);

	

	

	void DrawCube();

	private:
		float rotation;
		Camera* camera;
};

