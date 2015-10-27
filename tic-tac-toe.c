#include <stdio.h>

void MakeGameBoard(char board[3][3]);

int CheckForWinner(char board[3][3], int* count);
void PrintBoard(char board[3][3]);
int PromptForPlay(char board[3][3], char* turn, int* count);
int PromptForPlayAI(char board[3][3], char* turn, int* count, int* winner);
void AI(char board[3][3], char* turn, int* count, int* winner);
int CheckLegal(int x, int y);



void main (){
	char board[3][3];
	int winner = 0;
	char turn = 'x';
	int i = 0;
	int mode = 0;
	int count = 0;
	
	printf("Enter a gamemode:\n1: Two Player\n2: Against AI [BETA]\n");
	scanf("%d", &mode);
	
	if (mode == 1) {
		MakeGameBoard(board);
		while (winner == 0) {
			PrintBoard(board);
			PromptForPlay(board, &turn, &count);
			PrintBoard(board);
			winner = CheckForWinner(board, &count);
			}
	}
	else if (mode == 2) {
		MakeGameBoard(board);
		while (winner == 0) {
			PrintBoard(board);
			PromptForPlayAI(board, &turn, &count, &winner);
			PrintBoard(board);
			winner = CheckForWinner(board, &count);
			}
	
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

int CheckForWinner(char board[3][3], int* count) {
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
	
	//Check Cats Game
	for (x=0;x<3;x++) {
		for (y=0;y<3;y++) {
			if ((board[x][y] != '_') && ((winner != 1) || (winner != 2)) && (*count >= 9)) {
				winner = 3;
			}
		}
	}
	
	//Print Win
	if (winner == 1) {
		printf("X won!");
	}
	else if (winner == 2) {
		printf("O won!");
	}
	else if (winner == 3) {
		printf("Cats game!");
	}
	return winner;
}

void PrintBoard(char board[3][3]) {
	int i;
	for (i=0;i<19;i++) {
		printf("\n");
	}
	int x,y;
	printf("  0 1 2\n");
	for (x=0;x<3;x++) {
		for (y=0;y<3;y++) {
			if (y == 0) {
				printf("%d %c|", x, board[x][y]);
			}
			else if (y == 1) {
				printf("%c|", board[x][y]);
			}
			else {
			printf("%c", board[x][y]);
			}
		}
		printf("\n");
	}
}

int PromptForPlay(char board[3][3], char* turn, int* count) {
	int x,y;
	printf("%c, Enter coordinates where you wish to play:\n", *turn);
	scanf("%d,%d", &x, &y);
	if ((CheckLegal(x,y) == 1)) {
		if (*turn == 'o') {
			board[x][y] = 'o';
			*turn = 'x';
			++*count;
		}
		else {
			board[x][y] = 'x';
			*turn = 'o';
			++*count;
			}
		}
	else {
		printf("Error\n");
		return 0;
	}
}

int PromptForPlayAI(char board[3][3], char* turn, int* count, int* winner) {
	int x,y;
		if (*turn == 'x') {
			printf("Enter coordinates where you wish to play:\n");
			scanf("%d,%d", &x, &y);
			if ((CheckLegal(x,y) == 1)) {
				board[x][y] = 'x';
				*turn = 'o';
				AI(board, turn, count, winner);
				++*count;
			}
			else {
				printf("Error\n");
				//PromptForPlay(board, turn);
				}
		}
		else if (*turn == 'o') {
			AI(board, turn, count, winner);
			*turn = 'x';
			++*count;
			}
		/*else {
			printf("I suck.");
		} */
	
	}
void AI(char board[3][3], char* turn, int* count, int* winner) {
	int i;
	int o = 0;
	if ((*turn == 'o') && (o<=1)) {
	for (i=1;i<=9;i++) {
		printf("%d %c",i, *turn);
		/*if (((board[1][2] == '_') && (board[2][1] == '_')) || ((board[2][1] == '_') && (board[1][2] == '_'))) {
			board[1][2] = 'o';
			*turn = 'x';
		} */
			if (((board[0][0] == 'x') && (board[1][1] == 'x') && (board[2][2] != 'o'))
				|| ((board[2][0] == 'x') && (board[2][1] == 'x') && (board[2][2] != 'o'))) {
				i = 9;
			}
			else if (((board[1][1] == 'x') && (board[2][1] == 'x') && (board[0][1] != 'o'))
				|| ((board[0][0] == 'x') && (board[0][2] == 'x') && (board[0][1] != 'o'))) {
				i = 6;
			}
			else if (((board[0][1] == 'x') && (board[1][1] == 'x') && (board[2][1] != 'o')) 
				|| ((board[2][0] == 'x') && (board[2][2] == 'x') && (board[2][1] != 'o'))) {
				i = 8;
			}
			else if (((board[1][0] == 'x') && (board[1][1] == 'x') && (board[1][2] != 'o')) 
				|| ((board[2][2] == 'x') && (board[0][2] == 'x') && (board[1][2] != 'o'))) {
				i = 7;
			}
			else if (((board[0][0] == 'x') && (board[2][0] == 'x') && (board[1][0] != 'o'))
				|| ((board[1][2] == 'x') && (board[1][1] == 'x') && (board[1][0] != 'o')))	{
				i = 5;
			} /*
			else if ((board[2][0] == 'x') && (board[2][1] == 'x') && (board[2][2] != 'o')) {
				i = 9;
			}
			else if ((board[2][2] == 'x') && (board[0][2] == 'x') && (board[1][2] != 'o')) {
				i = 7;
			}
			else if ((board[2][0] == 'x') && (board[2][2] == 'x') && (board[2][1] != 'o')) {
				i = 8;
			}
			else if ((board[1][2] == 'x') && (board[1][1] == 'x') && (board[1][0] != 'o')) {
				i = 5;
			}
			else if ((board[0][0] == 'x') && (board[0][2] == 'x') && (board[0][1] != 'o')) {
				i = 6;
			} */
		if ((i==1) && (board[0][0] == '_') && (*turn == 'o')) {
				board[0][0] = 'o';
				*turn = 'x';
				//return 0;
				}
		else if ((i==2) && (board[0][2] == '_') && (*turn == 'o')) {
				board[0][2] = 'o';
				*turn = 'x';
				//return 0;
				}
		else if ((i==3) && (board[2][0] == '_') && (*turn == 'o')) {
				board[2][0] = 'o';
				*turn = 'x';
				//return 0;
				}
		else if ((i==4) && (board[1][1] == '_') && (*turn == 'o')) {
				board[1][1] = 'o';
				*turn = 'x';
				//return 0;
				}
		else if ((i==5) && (board[1][0] == '_') && (*turn == 'o')) {
				board[1][0] = 'o';
				*turn = 'x';
				//return 0;				
				}
		else if ((i==6) && (board[0][1] == '_') && (*turn == 'o')) {
				board[0][1] = 'o';
				*turn = 'x';
				//return 0;
				}
		else if ((i==7) && (board[1][2] == '_') && (*turn == 'o')) {
				board[1][2] = 'o';
				*turn = 'x';
				//return 0;
				}
		else if ((i==8) && (board[2][1] == '_') && (*turn == 'o')) {
				board[2][1] = 'o';
				*turn = 'x';
				//return 0;
				}
		else if ((i==9) && (board[2][2] == '_') && (*turn == 'o')) {
				board[2][2] = 'o';
				*turn = 'x';
				//return 0;
				}
		else if (i > 9)  {
			int x,y;
			for (x=0;x<3;x++) {
				for (y=0;y<3;y++) {
				if (board[x][y] == '_') {
					board[x][y] = 'o';
					*turn = 'x';
						}
				else {
					*winner = 3;
					printf("%d", i);
				}
					}
				}
		}
	} 
	}
	++o;
}

int CheckLegal(int x, int y) {
	if ((x == 0) || (x == 1) || (x == 2) || (x == '\n') || (x == '_') || (x == 'x') || (x  == 'o') || (x == '|') || (x == 'E') || (x == 'r')) {
		x = 1;
	}
	if ((y == 0) || (y == 1) || (y == 2) || (y == '\n') || (y == '_') || (y == 'x') || (y  == 'o') || (y == '|') || (y == 'E') || (y == 'r')) {
		y = 1;
	}
	if ((x == 1) && (y == 1)) {
		return 1;
	}
	else {
		return 0;
	}
}

void AboutPage() {
	printf("I'm tinkeirng, ignore me.");
}
