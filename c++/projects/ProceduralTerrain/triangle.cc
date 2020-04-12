/*
`g++ triangle.cc -lglut -lGL -o triangle`
will supposedly on Debian 7 produce compile it
correctly. 

*/




#include "GL/freeglut.h"
#include "GL/gl.h"

void drawTriangle(){

	glClearColor(0.4, 0.4, 0.4, 0.4);
	glClear(GL_COLOR_BUFFER_BIT);
	
	glColor3f(1.0, 2.0, 1.0);

	// Multiply current matrix with orthographic
	// matrix. 
	// void glOrtho(GLdouble left, GLdouble right, GLdouble bottom,
 	//		GLdouble top, GLdouble nearVal, GLdouble farVal);
 	// The question is what the 'current matrix' is. 
	glOrtho(-1.0, 2.0, -1.0, 1.0, -1.0, 1.0);

		
		glBegin(GL_TRIANGLES);
			glVertex3f(-0.7, 0.7, 0);
			glVertex3f(0.7, 0.7, 0);
			glVertex3f(0, -1, 0);
		glEnd();

	glFlush();

}

int main(int argc, char **argv)
{
    
    glutInit(&argc, argv);
    
    glutInitDisplayMode(GLUT_SINGLE);
    
    glutInitWindowSize(500, 500);
    
    glutInitWindowPosition(100, 100);
    
    glutCreateWindow("OpenGL - Creating a triangle");
    
    // Callback functions. 
    glutDisplayFunc(drawTriangle);
    
    glutMainLoop();
    return 0;
}
