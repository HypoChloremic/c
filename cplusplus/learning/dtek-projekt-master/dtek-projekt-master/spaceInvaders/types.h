#ifndef TYPES_H_
#define TYPES_H_

// The player struct
/*
y - The player y location coordinate. The player lacks an x coordinate, as they cannot move on that axis.
speed - The pixels/frame movement modifier
score - Unused score tracker
*/
typedef struct{
	int y;
	int speed;
	int score;
} Player;

// The alien struct
/*
x - The alien x location coordinate.
y - The alien y location coordinate.
speed - The pixels/frame movement modifier
direction - A value to store whether the alien is currently headed right or left. 0 = right, 1 = left.
health - The alien health count. Used to ensure aliens are killable.
*/
typedef struct alien{
	int x;
	int y;
	int speed;
	int direction;
	int health;
} Alien;

// The laser struct
/*
x - The laser x location coordinate.
y - The laser y location coordinate
speed - The pixels/frame movement modifier
isVisible - The value used to determine whether the laser is currently in use and should be drawn, or not.
*/
typedef struct lazor{
	int x;
	int y;
	int speed;
	int isVisible;
} Lazor;

#endif
