#include <stdio.h>
#include <math.h>
#include <stdlib.h>

void GenerateDungeon(char map[96][160]);
void GenerateRooms(char map[96][160]);
void GenerateHallways(char map[96][160],int x, int y, int s1, int s2, int r, int rx[], int ry[]);
void PrintDungeon(char map[96][160]);
int sign(int x);

void main (){
	
	char map[96][160];
	GenerateDungeon(map);
	GenerateRooms(map);
	PrintDungeon(map);
	
}

void GenerateDungeon(char map[96][160]) {
	int x,y;
	for (y=0;y<96;y++) {
		for (x=0;x<160;x++) {
			map[y][x] = '#';
			}
		}

}

void GenerateRooms(char map[96][160]) {
	int i,j,r,x,y,s1,s2,t;
	int room = 9;
	int rx[(room-1)];
	int ry[(room-1)];
	
	for (r=0;r<room;r++) {
		//wait a secondish
		/* for (t=0;t<666;t++) {
			t = t;
		} */
	srand(666+r);
	//srand(time(NULL) + r);
	x = (rand() % 158) + 1;
	y = (rand() % 94) + 3;
	s1 = (rand() % 9) + 8;
	s2 = ((rand() % 18)/2) + 5;
	//printf("%d,%d,%d,%d", x,y,s1,s2);
	
	rx[r] = x;
	ry[r] = y;
	
	if ((x+s1) >= 159) {
		x = (x+s1) - 160;
		}
	if ((y+s2) >= 95) {
		y = (y+s2) - 96;
		}
	
	for (i=0;i<=s1;i++) {
		for (j=0;j<=s2;j++) {
			map[y+j][x+i] = '.';
				
				}
			}
			GenerateHallways(map,x,y,s1,s2,r,rx,ry);
		}
	}

int sign(int x){
	if (x>0) {
		return 1;
		}
	else if (x<0){
		return -1;
	}
	else {
	return 0;
	}
}


void GenerateHallways(char map[96][160], int x, int y, int s1, int s2, int r, int rx[], int ry[]) {
	int m1,m2,x1,y1,x2,y2,t;
	double deltaX, deltaY, error, deltaError;
		if (r <= 0) {
		x2 = rx[0];
		y2 = ry[0];
		}
		if (r % 2) {
		t = rand() % 8;
		x2 = rx[t];
		y2 = ry[t];
		}
		else if (r >= 1) {
		x2 = rx[r-1];
		y2 = ry[r-1];
		}
		printf("%d, %d; %d     %d, %d\n", x2, y2, r, x, y);
		m1 = s1/2.0;
		m2 = s2/2.0;
		
		/*
		//wall middles
		map[y][x+m1] = 'm';
		map[y+m2][x] = 'm';
		
		
		//room middle
		*/
		y = y+m2;
		x = x+m1;
		map[y][x] = '.';


        x1 = x;
        y1 = y;
        deltaX = x2 - x1;
        deltaY = y2 - y1;
        error = 0;
		if (y2 == y1) {
		for (y=y1; y!=y2; y = y + sign(y2-y1)) {
			map[y][x] = '.';
			}	
		}
	
	deltaError = abs(deltaY/deltaX);
	for (x = x1; x<x2; x = x + sign(x2-x1)) {
		map[y][x] = '.';
		error = error + deltaError;
		while (error >= 0.01){
			y = y + sign(y2-y1);
            map[y][x] = '.';
			error = error - 1.0;
			}
		}

	}

void PrintDungeon(char map[96][160]) {
	int x,y;
	for (y=0;y<96;y++) {
		for (x=0;x<160;x++) {
			printf("%c", map[y][x]);
			}
		}
}

