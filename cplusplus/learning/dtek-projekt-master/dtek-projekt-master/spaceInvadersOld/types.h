#ifndef TYPES_H_
#define TYPES_H_

typedef struct{
	int y;
	int speed;
	int score;
} Player;

typedef struct{
	int x;
	int y;
	int speed;
	int direction;
} Alien;

typedef struct{
	int x;
	int y;
	int speed;
} Lazor;

#endif
