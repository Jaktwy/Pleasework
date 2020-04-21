#include "HelloGL.h"






HelloGL::HelloGL(int argc, char* argv[])
{
	rotation = 0.0f;
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DOUBLE);
	glutInitWindowSize(800, 800);
	glutInitWindowPosition(100, 100);
	glutInitWindowSize(800, 800);
	glutCreateWindow("Simple OpenGL Program");
	glutKeyboardFunc(GLUTCallbacks::Keyboard);
	GLUTCallbacks::Init(this);

	camera = new Camera();
	camera->eye.x = 0.0f; camera->eye.y = 0.0f; camera->eye.z = 1.0f;
	camera->center.x = 0.0f; camera->center.y = 0.0f; camera->center.z = 0.0f;
	camera->up.x = 0.0f; camera->up.y = 1.0f; camera->up.z = 0.0f;
	glutDisplayFunc(GLUTCallbacks::Display);
	glutTimerFunc(REFRESHRATE, GLUTCallbacks::Timer, REFRESHRATE);

	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	// Set the viewport to be the entire window
	glViewport(0, 0, 800, 800);
	// Set the correct perspective
	gluPerspective(45, 1, 0, 1000);
	glMatrixMode(GL_MODELVIEW);
	glEnable(GL_CULL_FACE);
	glCullFace(GL_BACK);

	glutMainLoop();

}





HelloGL::~HelloGL(void)
{
}

/*void HelloGL::DrawPolygon()
{
	glPushMatrix();
	glRotatef(rotation, 0.0f, 0.0f, -1.0f);
	glBegin(GL_POLYGON); //starts to draw a polygon
	{
		glColor4f(1.0f, 0.0f, 0.0f, 0.0f); //Adds Colour to the shape
		glVertex2f(-0.75, 0.5); //define the first point of the polygon, top left
		glVertex2f(0.75, 0.5); //Next point, top right 
		glVertex2f(0.75, -0.5); //bottom right
		glVertex2f(-0.75, 0.5); //last point of the polygon, bottom left
		glEnd(); //defines the end of the draw 
	}
	glPopMatrix();
}
*/
/*void HelloGL::Update()
{
	glLoadIdentity();
	
	glutPostRedisplay();

	gluLookAt(camera->eye.x, camera->eye.y, camera->eye.z, camera->center.x,
		camera->center.y, camera->center.z, camera->up.x, camera->up.y,
		camera->up.z);
	

	if (rotation >= 360.0f)
		rotation = 0.0f;

	Sleep(10);
	glutPostRedisplay();

}
*/
void HelloGL::Keyboard(unsigned char key, int x, int y)
{
	if (key == 'd')
		rotation += 0.5f;


	else if (key == 'a')
		rotation -= 0.5f;

	
	if (key == 'w')
		camera->eye.z += 0.1;

	else if (key == 's')
		camera->eye.x += 0.1;

	else if (key == 'x')
		camera->eye.y += 0.1;
}








