#define GL_GLEXT_PROTOTYPES
#include <GL/glut.h>
#include <math.h>
#include <iostream>


// This way we seemingly globally accessible
// variables that we can manipulate. 

// Rotate X
double rX=0;
// Rotate Y
double rY=0;

// The coordinates for the vertices of the cube
double x = 0.6;
double y = 0.6;
double z = 0.6;

double count = 0;

void drawCube()
{
        // Set Background Color
    glClearColor(0.4, 0.4, 0.4, 1.0);

        // Clear screen
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    // Reset transformations
    glLoadIdentity();

    // Rotate when user changes rX and rY
    glRotatef( rX, 1.0, 0.0, 0.0 );
    glRotatef( count, 0.0, 1.0, 0.0 );

    // BACK
        glBegin(GL_TRIANGLES);
            glColor3f(0.4, 0.3, 0.5);
                glVertex3f(x, y, z);
                glVertex3f(x, -y, z);
                glVertex3f(-x, y, z);
        glEnd();

        glBegin(GL_TRIANGLES);
            glColor3f(0.5, 0.3, 0.2);
                glVertex3f(-x, -y, z);
                glVertex3f(x, -y, z);
                glVertex3f(-x, y, z);
        glEnd();

        // FRONT
        // Using 4 trianges!
        glBegin(GL_TRIANGLES);
            glColor3f(0.1, 0.5, 0.3);
                glVertex3f(-x, y, -z);
                glVertex3f(0, 0, -z);
                glVertex3f(-x, -y, -z);
        glEnd();

        glBegin(GL_TRIANGLES);
                glColor3f(0.0, 0.5, 0.0);
                glVertex3f(-x, -y, -z);
                glVertex3f(0, 0, -z);
                glVertex3f(x, -y, -z);
        glEnd();

        glBegin(GL_TRIANGLES);
            glColor3f(0.1, 0.3, 0.3);
                glVertex3f(-x, y, -z);
                glVertex3f(x, y, -z);
                glVertex3f(0, 0, -z);
        glEnd();

        glBegin(GL_TRIANGLES);
                glColor3f(0.2, 0.2, 0.2);
                glVertex3f(0, 0, -z);
                glVertex3f(x, y, -z);
                glVertex3f(x, -y, -z);
        glEnd();

        // LEFT
        glBegin(GL_TRIANGLES);
        glColor3f(0.3, 0.5, 0.6);
                glVertex3f(-x, -y, -z);
                glVertex3f(-x, -y, z);
                glVertex3f(-x, y, -z);
        glEnd();

        glBegin(GL_TRIANGLES);
                glColor3f(0.5, 0.5, 0.5);
                glVertex3f(-x, y, z);
                glVertex3f(-x, -y, z);
                glVertex3f(-x, y, -z);
        glEnd();

        // RIGHT
        glBegin(GL_TRIANGLES);
        glColor3f(0.2, 0.2, 0.2);
                glVertex3f(x, y, z);
                glVertex3f(x, y, -z);
                glVertex3f(x, -y, z);
        glEnd();

        glBegin(GL_TRIANGLES);
        glColor3f(0.0, 0.0, 0.0);
                glVertex3f(x, -y, -z);
                glVertex3f(x, y, -z);
                glVertex3f(x, -y, z);
        glEnd();

        // TOP
        glBegin(GL_TRIANGLES);
        glColor3f(0.6, 0.0, 0.0);
                glVertex3f(x, y, z);
                glVertex3f(x, y, -z);
                glVertex3f(-x, y, -z);
        glEnd();

        glBegin(GL_TRIANGLES);
        glColor3f(0.6, 0.1, 0.2);
                glVertex3f(-x, y, z);
                glVertex3f(x, y, z);
                glVertex3f(-x, y, -z);
        glEnd();

        // BOTTOM
        glBegin(GL_TRIANGLES);
        glColor3f(0.4, 0.0, 0.4);
                glVertex3f(-x, -y, -z);
                glVertex3f(-x, -y, z);
                glVertex3f(x, -y, z);
        glEnd();

        glBegin(GL_TRIANGLES);
                glColor3f(0.3, 0.0, 0.3);
                glVertex3f(x, -y, -z);
                glVertex3f(-x, -y, -z);
                glVertex3f(x, -y, z);
        glEnd();

    count++;
    std::cout << count;

    if (count>30)
    {
        /* code */
        std::cout << count;
        count = 0;
    }
    glFlush();
    glutSwapBuffers();
}


// Initializes 3D rendering
void initRendering()
{
        glEnable(GL_DEPTH_TEST);
        glEnable(GL_COLOR_MATERIAL);

        // Set the color of the background
        glClearColor(0.7f, 0.8f, 1.0f, 1.0f);
        glEnable(GL_LIGHTING);
        glEnable(GL_LIGHT0);
        glEnable(GL_NORMALIZE);
}

int main(int argc, char **argv)
{
        // Initialize GLUT and process user parameters
        glutInit(&argc, argv);

        // Request double buffered true color window with Z-buffer
        glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);

        glutInitWindowSize(700,700);
        glutInitWindowPosition(100, 100);

        // Create window
        glutCreateWindow("Linux Journal OpenGL Cube");
        initRendering();

        // Enable Z-buffer depth test
        glEnable(GL_DEPTH_TEST);

        // Callback functions
        glutDisplayFunc(drawCube);
        // Pass control to GLUT for events
        glutMainLoop();

        return 0;
}