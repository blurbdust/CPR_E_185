/*         Nicholas Losby

        nlosby@iastate.edu

        CPRE 185 Section B

Programming Practice 2

         <Reflection 1 What were you trying to learn or achieve?>

		I am trying to practice using booleans. It is actually harder than I anticipated.

        <Reflection 2 Were you successful? Why or Why not?>
        
		I belive I was, the code compiles and runs succesfully.

		<Reflection 3 Would you do anything differently if starting this program over?  If so, explain what.>

		I would make sure that when I run a separate function to assign a variable to the return of the function.
		For example, I forgot to make pos = determine(userNum).

		<Reflection 4 Think about the most important thing you learned when writing this piece of code.  What was it and explain why it was significant.>
		
		Even though I can error check other's programs, it doesn't mean I don't make mistakes myself.

*/

#include <stdio.h>
#include <stdbool.h>

#define true 1
#define false 0

int determine(int userNum);
int zero(void);

int main(void) {
	int userNum;
	bool pos = false;
	
	printf("Enter a number: ");
	scanf("%d", &userNum);
	
	if (userNum == 0) { 
	zero();
	}
	else {
		pos = determine(userNum);
			if (pos == 1) {
			printf("\n%d is a positve number.", userNum);
			}
			else if (pos != 1) {
			printf("\n%d is a negative number.", userNum);
			}
		}
	return 0;
}

int determine(int userNum) {
	bool pos;
	//printf("%d", userNum);
	if (userNum > 0) {
		pos = true;
	}
	else {
		pos = false;
	}
	return pos;
}

int zero(void) {
	printf("\nThat is zero, nice try.");
	return;
}
