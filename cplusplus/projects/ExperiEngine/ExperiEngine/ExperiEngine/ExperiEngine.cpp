#include "olcConsoleGameEngine.h"

using namespace std;


// Create our own structs
// for the management of vectors and such

struct vec3d {
	float x, y, z;
};

struct triangle {
	// 
	vec3d p[3];
};

struct mesh {
	// Seemingly using the std vector. 
	// Dock, vi har inte specificerat storleken
	// på tris. . .
	vector<triangle> tris;
};



// Create our own iteration of the olcConsoleGameEngine
// class for the project
// Override the olcConsoleGameEngine 
class olcEngine3d : public olcConsoleGameEngine {
public:
	olcEngine3d() {
		m_sAppName = L"3D Demo";
	}


private:
	// Det som sker inside private, kommer att 
	// bara vara accessible i klassen? 
	// antar jag . . .
	// För att meshCube kommer att kallas i en public 
	// del av klassen nedan
	mesh meshCube;

public:
	bool OnUserCreate() override {
		// Cube med nedre vänstra corner är i 
		// origin (0,0,0). Samt att det är en 
		// unit cube, med sida = 1
		//
		// NOTE! the cube mesh needs to be constituted
		// by triangles. 
		//
		// Därför kommer varje face av the cube att konstitueras
		// av två trianglar!
		meshCube.tris = {
			// SOUTH
			{0.0f, 0.0f, 0.0f,         0.0f, 1.0f, 0.0f,       1.0f, 1.0f, 0.0f},
			{0.0f, 0.0f, 0.0f,         1.0f, 1.0f, 0.0f,       1.0f, 0.0f, 0.0f },

		};
		return true;
	}
	
	bool OnUserUpdate(float fElapsedTime) override {
	
	}
		
};

int main()
{
	olcEngine3d demo;
	if (demo.ConstructConsole(256, 240, 4, 4)) {
		demo.Start();
	}
    return 0;
}

