#include <stdio.h>
#include <math.h>
/* Nicholas Losby
nlosby@iastate.edu
CPRE 185 Section ?? //FIXME
Programming Practice 1

<Reflection 1 What were you trying to learn or achieve?>
<Reflection 2 Were you successful? Why or Why not?>
<Reflection 3 Would you do anything differently if starting this program over?
If so, explain what.>
<Reflection 4 Think about the most important thing you learned when writing this
piece of code.  What was it and explain why it was significant.>
*/
/*int findLargestPower(int numChange, int numBase, int exp) {
	for ( exp = 0, (((pow(numBase, exp) / numChange) > numBase)), exp = exp + 1)
	{
		int a;
		printf("\n%d", a);
		}
	return exp;
}
*/
/*int divideForFirstPlace(){
	
}
*/
#include <stdio.h>
#include <math.h>

int main(void) {
	int numChange, numBase, largestPower, a, b;
	int exp = 0;
	printf("Enter number in base 10: \n");
	scanf("%d,%d", &numChange, &numBase);
	//scanf("Enter base number to chnage to: %d\n", &numBase);
	
	for (exp = 0; ((numChange / (pow(numBase, exp))) >= numBase); exp = exp + 1 )
	{
		a = pow(numBase, exp);
		largestPower = exp;
	//	printf("%d", exp);
		}
	for (exp; (numChange % (a) >= 0); exp = exp - 1)
	{
		if (exp == 0) {
			return 0;
		} else 
		a = pow(numBase, exp);
		b = (numChange / pow(numBase, exp));
		printf("%d", b);
		numChange = (numChange % a);
		}
		
	return 0;
}
