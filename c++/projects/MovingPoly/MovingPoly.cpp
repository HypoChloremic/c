// gcc MovingPoly.cpp -lGL -lGLU -lglut -lm -o MovingPoly

#include <GL/glut.h>
#include <math.h>
#include <stdio.h>
#include <iostream>


// These are very important parameters to take
// into consideration
#define SCREEN_WIDTH 600
#define SCREEN_HEIGHT 600

// Global declaration
float i,j;
double x,y;

// Aug went aspergers on me about the placement
// of the star. I have created a pointer
// to a double value, the actual type of the 
// the thing is a double pointer. 


void Pol(double matrix[][2]){

	// `sizeof matrix` is the size of the matrix as a whole
	// in memory. And the size of `sizeof matrix[0]` is the 
	// size of the 'row-array'
	//int rows = sizeof matrix / sizeof matrix[0];  
	
	// `sizeof double` is the size of the element
	//int cols = sizeof matrix[0] / sizeof(double);

	glBegin(GL_TRIANGLES);

	glColor3i(100, 23, 2);
	
	/*
	std::cout << "Running Loop \n";
	std::cout << cols <<"  "<< rows << "\n";
	*/
	std::cout << matrix[0][0] << "\n";

	for (int i = 0; i < 3; ++i){
			std::cout << "\n" << i;
			glVertex2i(matrix[i][0], matrix[i][1]);
	}

	glEnd();

}


void Pol2(double* matrix){

	// `sizeof matrix` is the size of the matrix as a whole
	// in memory. And the size of `sizeof matrix[0]` is the 
	// size of the 'row-array'
	//int rows = sizeof matrix / sizeof matrix[0];  
	
	// `sizeof double` is the size of the element
	//int cols = sizeof matrix[0] / sizeof(double);

	glBegin(GL_TRIANGLES);

	glColor3i(100, 23, 2);
	
	/*
	std::cout << "Running Loop \n";
	std::cout << cols <<"  "<< rows << "\n";
	*/

	// std::cout << matrix[0][0] << "\n";

	for (int i = 0; i < 3; ++i){
			glVertex2i(*(matrix + i*2), *((matrix + i*2) + 1));
	}

	glEnd();

}

void Circle(double j){
	glBegin(GL_POINTS);
		for (i = 0; i < 6.29; i+=0.001)
		{
		
			/* This works mathematically when
			we start considering the unit circle
			that (cos i, sin i) for (x,y), generates
			a circle.

			Creating vertices that will be represented 
			by dots. */
			x = (double)SCREEN_WIDTH/2 * cos(i);
			y = (double)SCREEN_HEIGHT/2 * sin(i);
			glVertex2i(x,y);
		}
	glEnd();
}

void Axis(){

	glBegin(GL_LINES);
    	glVertex2f(0, -SCREEN_HEIGHT);
    	glVertex2f(0, SCREEN_HEIGHT);
	glEnd();

	glBegin(GL_LINES);
    	glVertex2f(SCREEN_WIDTH, 0);
    	glVertex2f(-SCREEN_WIDTH, 0);
	glEnd();

}


void VertexMatrix(){

}


// Initialization function
void init(void){
	// Reset background color with black
	// since all three arguments are 0.0

    glEnable(GL_COLOR_MATERIAL);

    glClearColor(0.7f, 0.8f, 1.0f, 1.0f);

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
	std::cout << "Running triangleMatrix";
	//double** TriangleMatrix;

	double TriangleMatrix[][2] = {{ 100.0, 0.0},
								   {-100.0, 0.0},
								   { 0.0,  100.0}};
	
    // Outer loop to make figure moving 
    // loop variable j iterated up to 10000, 
    // indicating that figure will be in motion for large amount of time 
    // around 10000/6.29 = 1590 time it will revolve 
    // j is incremented by small value to make motion smoother 

    // I really dislike this method however.  
    for (j = 0; j < 10000; j += 0.01) { 
		/*
		`glClear(GL_COLOR_BUFFER_BIT)` has the task to 
		clear the screen with a default value, after a
		certain time (usually 1/30th second or 1/60th second)
		therefore, if there is a change to the coordinates
		the display will change, therefore animating. 
		*/

		glClear(GL_COLOR_BUFFER_BIT);

		// Drawing Circle
		Circle(j);

		// Drawing axis
		Axis();

		
		// #######################
		// ### CHANGING MATRIX ###
		// #######################
		for (int i = 0; i < 3; ++i){
			TriangleMatrix[i][0] += sin(j);
		} 
		// Creating the polygon
		// Pol(TriangleMatrix);
		
		// The parenthesis here is casting, i.e the `(double*)`
		// which tells the compiler to treat `TriangleMatrix` as 
		// double pointer. 
		Pol2((double*) TriangleMatrix);
		
		// One can also use 'address of' with the `&` operand
		// in front of the matrix object
		// Pol2(&TriangleMatrix[0][0])

		glFlush();
	}
}

int main(int argc, char** argv)
{
    glutInit(&argc, argv); 
      
    // Display mode which is of RGB (Red Green Blue).
    // we are specifying what the frame-buffer should 
    // be. It is a kind of buffer that saves a frame. 
    // Buffer is some block of memory (used alot for io operations
    // makes them faster by prepping memory in some way) that 
    // where we can save data for later use somehow. 

    // GLUT_RGB and GLUT_SINGLE actually changes stuff, versus using 
    // GLUT_DOUBLE. 
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB); 
      
    // Declares window size 
    glutInitWindowSize(1360, 768); 
      
    // Declares window position which is (0, 0) 
    // means lower left corner will indicate position (0, 0) 
    glutInitWindowPosition(0, 0); 
  
    // Name to window  and creates it
    glutCreateWindow("Moving Polygon"); 

    // idlefunc is acallback that continuously updates
    // the fade factor between two images over time. 
    // (how to fade into the subsequent image)
    // glutIdleFunc(&update_fade_factor)
  
    // Call to myInit() 
    init();

    // Callback functions
    // Remember that the callback functions are setup in a way
    // that they repaint the window upon callback. Situations which
    // induces the callback can be window-resizing for instance. 
    //
    // Furthermore, the glutDisplayFunc renders our image, when 
    // the window needs displaying. 
    glutDisplayFunc(display); 
    glutMainLoop(); 
	return 0;
}