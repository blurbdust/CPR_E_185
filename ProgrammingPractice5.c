#include <stdio.h>

void MakeGameBoard(char board[3][3]);

int CheckForWinner(char board[3][3]);
void PrintBoard(char board[3][3]);
int PromptForPlay(char board[3][3], char* turn);



void main (){
	char board[3][3];
	int winner = 0;
	char turn = 'x';
	
	MakeGameBoard(board);
	while (winner == 0) {
	PrintBoard(board);
	PromptForPlay(board, &turn);
	winner = CheckForWinner(board);
	PrintBoard(board);
	}
	
}

void MakeGameBoard(char board[3][3]) {
	int x,y;
	for (x=0;x<3;x++) {
		for (y=0;y<3;y++) {
			board[x][y] = '_';
		}
	}
}

int CheckForWinner(char board[3][3]) {
	int winner = 0;
	int x,y;
	//Horizontal Win
	for (x=0;x<3;x++) {
		if ((board[x][0] == 'x') && (board[x][1] == 'x') && (board[x][2] == 'x')) {
			winner = 1;
		}
		else if ((board[x][0] == 'o') && (board[x][1] == 'o') && (board[x][2] == 'o')){
			winner = 2;
		}
	}

	//Vertical Win
	for (y=0;y<3;y++){
		if ((board[0][y] == 'x') && (board[1][y] == 'x') && (board[2][y] == 'x')) {
			winner = 1;
		}
		else if ((board[0][y] == 'o') && (board[1][y] == 'o') && (board[2][y] == 'o')) {
			winner = 2;
		}
	}
	
	//Diagonal Win (Ugh) Wasn't that bad
	if (((board[0][0] == 'x') && (board[1][1] == 'x') && (board[2][2] == 'x')) || ((board[0][2] == 'x') && (board[1][1] == 'x') && (board[2][0] == 'x'))) {
		winner = 1;
	}
	else if (((board[0][0] == 'o') && (board[1][1] == 'o') && (board[2][2] == 'o')) || ((board[0][2] == 'o') && (board[1][1] == 'o') && (board[2][0] == 'o'))) {
		winner = 2;
	}
	//Print Win
	if (winner == 1) {
		printf("X won!");
	}
	else if (winner == 2) {
		printf("O won!");
	}
	return winner;
}

void PrintBoard(char board[3][3]) {
	int i;
	for (i=0;i<19;i++) {
		printf("\n");
	}
	int x,y;
	for (x=0;x<3;x++) {
		for (y=0;y<3;y++) {
			printf("%c", board[x][y]);
		}
		printf("\n");
	}
}

int PromptForPlay(char board[3][3], char* turn) {
	int x,y;
	printf("%c, Enter coordinates where you wish to play:\n", *turn);
	scanf("%d,%d", &x, &y);
	if (*turn == 'o') {
		board[x][y] = 'o';
		*turn = 'x';
	}
	else {
		board[x][y] = 'x';
		*turn = 'o';
	}
}
