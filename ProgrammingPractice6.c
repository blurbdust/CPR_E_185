/*         Nicholas Losby
        nlosby@iastate.edu
        CPRE 185 Section B
        Programming Practice 6
        <Reflection 1 What were you trying to learn or achieve?>
        Providing enough iterations of the possibilities in tic-tac-to to make a series of conditionals that act like a human when playing the game, including making mistakes. 
        <Reflection 2 Were you successful? Why or Why not?>
        Yes however sometimes the computer plays in the same spot twice and I'm not quite sure how to fix that.
	<Reflection 3 Would you do anything differently if starting this program over?  If so, explain what.>
	Maybe have the comouter read and record past moves from the player to try and determine its strategy.
	<Reflection 4 Think about the most important thing you learned when writing this piece of code.  What was it and explain why it was significant.>
	Testing my code can be the longest part of programming and sometimes the most fun too.
*/

#include <stdio.h>
#include <time.h>
#include <math.h>

void MakeGameBoard(char board[3][3]);

int CheckForWinner(char board[3][3], int* count);
void PrintBoard(char board[3][3]);
int PromptForPlay(char board[3][3], char* turn, int* count);
int PromptForPlayAI(char board[3][3], char* turn, int* count, int* winner);
void AI(char board[3][3], char* turn, int* count, int* winner);
int CheckLegal(int x, int y, char board[3][3]);
int AIS(char board[3][3]);
void AboutPage();


void main (){
	char board[3][3];
	int winner = 0;
	char turn = 'x';
	int i = 0;
	int mode = 0;
	int count = 0;
	
	printf("Enter a gamemode:\n1: Two Player\n2: Against AI [BETA]\n3: About Page\n");
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
	else if (mode == 3) {
		AboutPage();
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
			if ((board[x][y] != '_') && (*count >= 9) && ((winner != 1) || (winner != 2))) {
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
	if ((CheckLegal(x,y, board) == 1)) {
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
			if ((CheckLegal(x,y, board) == 1)) {
				board[x][y] = 'x';
				*turn = 'o';
				*winner = CheckForWinner(board, count);
				AI(board, turn, count, winner);
				++*count;
			}
			else {
				printf("Error.\n");
				}
		}
		else if (*turn == 'o') {
			*winner = CheckForWinner(board, count);
			AI(board, turn, count, winner);
			*turn = 'x';
			++*count;
			}
	
	}
void AI(char board[3][3], char* turn, int* count, int* winner) {
	int i;
		i = AIS(board);
		i = abs(i);
		if ((i==1) && (board[0][0] == '_') && (*turn == 'o')) {
				board[0][0] = 'o';
				*turn = 'x';
				}
		else if ((i==2) && (board[0][2] == '_') && (*turn == 'o')) {
				board[0][2] = 'o';
				*turn = 'x';
				}
		else if ((i==3) && (board[2][0] == '_') && (*turn == 'o')) {
				board[2][0] = 'o';
				*turn = 'x';
				}
		else if ((i==4) && (board[1][1] == '_') && (*turn == 'o')) {
				board[1][1] = 'o';
				*turn = 'x';
				}
		else if ((i==5) && (board[1][0] == '_') && (*turn == 'o')) {
				board[1][0] = 'o';
				*turn = 'x';			
				}
		else if ((i==6) && (board[0][1] == '_') && (*turn == 'o')) {
				board[0][1] = 'o';
				*turn = 'x';
				}
		else if ((i==7) && (board[1][2] == '_') && (*turn == 'o')) {
				board[1][2] = 'o';
				*turn = 'x';
				}
		else if ((i==8) && (board[2][1] == '_') && (*turn == 'o')) {
				board[2][1] = 'o';
				*turn = 'x';
				}
		else if ((i==9) && (board[2][2] == '_') && (*turn == 'o')) {
				board[2][2] = 'o';
				*turn = 'x';
				}
		else if ((i > 9) || (i <= 0))  {
			int x,y;
			for (x=0;x<3;x++) {
				for (y=0;y<3;y++) {
				if ((board[x][y] == '_') && (*turn == 'o')) {
					board[x][y] = 'o';
					*turn = 'x';
					}
					else {
						*winner = 3;
					}
				}
			}
		}
		else {
			*winner = 3;
		}
	}

int AIS(char board[3][3]) {
	int i = 0;
	int tmp;
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
			}
			else if (((board[1][1] == 'x') && (board[2][2] == 'x') && (board[0][0] != 'o'))
				|| ((board[0][1] == 'x') && (board[0][2] == 'x') && (board[0][0] != 'o'))
				|| ((board[1][0] == 'x') && (board[2][0] == 'x') && (board[0][0] != 'o'))) {
				i = 1;
			}
			else {
				tmp = rand();
				srand( time(NULL));
				i = ((rand() * tmp) % 9);
			}
			printf("%d", i );
			return i;
}

int CheckLegal(int x, int y, char board[3][3]) {
	if ((x == 0) || (x == 1) || (x == 2) || (x == '\n') || (x == '_') || (x == 'x') || (x  == 'o') || (x == '|') || (x == 'E') || (x == 'r')) {
		x = 1;
	}
	if ((y == 0) || (y == 1) || (y == 2) || (y == '\n') || (y == '_') || (y == 'x') || (y  == 'o') || (y == '|') || (y == 'E') || (y == 'r')) {
		y = 1;
	}
	if ((board[x][y] != 'x') && (board[x][y] != 'o')) {
		x = 1;
	}
	if ((x == 1) && (y == 1)) {
		return 1;
	}
	else {
		return 0;
	}
}

void AboutPage() {
	printf("Instructions:\nUse 0-2,0-2 for coordinates.\nWritten by Nic Losby.\nDoes anyone actually read the about page?");
}
