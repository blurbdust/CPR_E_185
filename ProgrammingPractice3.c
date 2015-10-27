/*      Nicholas Losby

        nlosby@iastate.edu

        CPRE 185 Section B

		Programming Practice 3

         <Reflection 1 What were you trying to learn or achieve?>
I am trying to become more familiar with the do-while loop.
        <Reflection 2 Were you successful? Why or Why not?>
Yes. Both are working just fine.
<Reflection 3 Would you do anything differently if starting this program over?  If so, explain what.>
I orignally started with the idea of the computer guessing the number that the user input however I ultimately decided not to.
<Reflection 4 Think about the most important thing you learned when writing this piece of code.  What was it and explain why it was significant.>
Make sure you go into a program with a clear idea on how and what you want to achieve otherwise it is more likely there will be bugs.

*/

#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

int randomNumber(int lowerBound, int higherBound);
int guess(int NumToGuess);

int main(void) {
	
	int count, lowerBound, higherBound, numToGuess;
	
	printf("Enter the boundaries. Ex.0-100\n");
	scanf("%d-%d", &lowerBound, &higherBound);
	
	numToGuess = randomNumber(lowerBound, higherBound);
	
	count = guess(numToGuess);
	
	printf("It took you %d guesses!\n", count);
	return 0;
}

int randomNumber(int lowerBound, int higherBound) {
	int x, numToGuess;
	do {
		
		numToGuess = (rand() % higherBound);
		if (lowerBound > 1) {
			x = lowerBound - 1;
			numToGuess = numToGuess + x;
		}
		else if ((numToGuess == 0) && (lowerBound != 0)) {
			numToGuess = lowerBound;
		}
		return numToGuess;
	}
	while (numToGuess > higherBound);
}

int guess(int numToGuess) {
	
	bool guessed = false;
	int numGuessed;
	int count = 0;
	
	do {
		printf("Enter a guess:\n");
		scanf("%d", &numGuessed);
		
		++count;
		if (numGuessed == numToGuess) {
			guessed = true;
			return count;
		}
		else {
		if (numGuessed > numToGuess) {
		printf("Lower, ");
		}
		else if (numGuessed < numToGuess) {
		printf("Higher, ");
		}
		printf("Try again!\n");
		}
		
	}
	while (guessed == false);
}
