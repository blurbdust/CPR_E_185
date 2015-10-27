/*         Nicholas Losby

        nlosby@iastate.edu

        CPRE 185 Section B

Programming Practice 4

         <Reflection 1 What were you trying to learn or achieve?>

                I am trying to work a little more with pointers and arrays.

        <Reflection 2 Were you successful? Why or Why not?>

        Partially, the program only works sometimes while other times it has a runtime error.

<Reflection 3 Would you do anything differently if starting this program over?  If so, explain what.>

        No, everything is layed out logically and efficiently.

<Reflection 4 Think about the most important thing you learned when writing this piece of code.  What was it and explain why it was significant.>

        I need to really remember when and when not to use asterisks and ampersands.
*/


#include <stdio.h>

int PopulateArray (int* array, int arrSize, int increment);
void FlipFirstAndLast(int* array, int arrSize);
void PrintArray(int* array, int arrSize);

int main(void) {
	
	int array[20];
	int arrSize, increment;
	
	printf("Enter the first number:\n");
	scanf("%d", &array[0]);
	printf("Enter desired length of array:\n");
	scanf("%d", &arrSize);
	printf("Enter desired increment:\n");
	scanf("%d", &increment);
	
	PopulateArray(array, arrSize, increment);
	FlipFirstAndLast(array, arrSize);
	PrintArray(array, arrSize);
	
	return 0;
}

int PopulateArray (int* array, int arrSize, int increment) {

	int i;
	for (i=2;i<arrSize;i++) {
	array[i] = array[i-1] + increment;
	return array;
	}

}

void FlipFirstAndLast(int* array, int arrSize) {
	int a;
	a = array[0];
	array[0] = array[arrSize-1];
	array[arrSize-1] = a;
	return;
}

void PrintArray(int* array, int arrSize) {
	int i;
	for (i=0;i<arrSize;i++) {
		printf("%d ", array[i]);
		return;
	}
}
