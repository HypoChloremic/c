// gcc animation.cpp -lGL -lGLU -lglut -lm -o animation

#include <GL/glut.h>
#include <math.h>
#include <stdio.h>





// Global declaration

int x,y;
float i,j;


// Initialization function
void init(void){
	// Reset background color with black
	// since all three arguments are 0.0
	glClearColor(
		0.0, 
		0.0, 
		0.0, 
		1.0);

	// Picture color
	glColor3f(
		0.0,
		1.0,
		0.0);

	// Width of point
	glPointSize(1.0);
	glMatrixMode(GL_PROJECTION);

	// Resetting transformation matrix. 
	glLoadIdentity();

	// Set window size in X- and Y- direction 
    gluOrtho2D(-780, 780, -420, 420); 

}



// function to display the animation
void display(void){
	
    // Outer loop to make figure moving 
    // loop variable j iterated up to 10000, 
    // indicating that figure will be in motion for large amount of time 
    // around 10000/6.29 = 1590 time it will revolve 
    // j is incremented by small value to make motion smoother 

    // I really dislike this method however.  
    for (j = 0; j < 10000; j += 0.01) 
    { 
		/*
		`glClear(GL_COLOR_BUFFER_BIT)` has the task to 
		clear the screen with a default value, after a
		certain time (usually 1/30th second or 1/60th second)
		therefore, if there is a change to the coordinates
		the display will change, therefore animating. 
		*/

		glClear(GL_COLOR_BUFFER_BIT);

		// delimit the vertices of a primitive or group of like primitives
		// the parameter specifies the primitives that will be created from the 
		// vertices presented. 
		// ALSO: glBein and glEnd are paired. 
		glBegin(GL_POINTS);

			// Looping over the global variable
			// this creates the outer circle
			for (i = 0; i < 6.29; i+=0.001)
			{
				/* This works mathematically when
				we start considering the unit circle
				that (cos i, sin i) for (x,y), generates
				a circle.

				Creating vertices that will be represented 
				by dots. */
				x = 200 * cos(i);
				y = 200 * sin(i);
				glVertex2i(x,y);
				
				// I guess generates a smaller circle
				// with a given offset
				glVertex2i(x / 2 - 600 * cos(j), 
						   y / 2 - 100 * sin(j));
			}

			// 7 loops to draw parallel latitude 
	        for (i = 1.17; i < 1.97; i += 0.001) 
	        { 
	            x = 400 * cos(i); 
	            y = -150 + 300 * sin(i); 
	            glVertex2i(x, y); 
	            glVertex2i(x / 2 - 600 * cos(j), y / 2 - 100 * sin(j)); 
	        } 
	        // Loop to make orbit of revolution 
	        for (i = 0; i < 6.29; i += 0.001) 
	        { 
	            x = 600 * cos(i); 
	            y = 100 * sin(i); 
	            glVertex2i(x, y); 
	        } 

		glEnd();
		glFlush();
	}
}

int main(int argc, char** argv)
{
    glutInit(&argc, argv); 
      
    // Display mode which is of RGB (Red Green Blue) type 
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB); 
      
    // Declares window size 
    glutInitWindowSize(1360, 768); 
      
    // Declares window position which is (0, 0) 
    // means lower left corner will indicate position (0, 0) 
    glutInitWindowPosition(0, 0); 
  
    // Name to window 
    glutCreateWindow("Revolution"); 
  
    // Call to myInit() 
    init();

    // Callback functions
    // Remember that the callback functions are setup in a way
    // that they repaint the window upon callback. Situations which
    // induces the callback can be window-resizing for instance. 
    glutDisplayFunc(display); 
    glutMainLoop(); 
	return 0;
}