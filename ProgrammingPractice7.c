/*         Nicholas Losby
        nlosby@iastate.edu
        CPRE 185 Section B
Programming Practice 7
         <Reflection 1 What were you trying to learn or achieve?>
                Working with strings and to pass the time while the internet is down.
        <Reflection 2 Were you successful? Why or Why not?>
        Yes, however the internet isn't back up yet.
<Reflection 3 Would you do anything differently if starting this program over?  If so, explain what.>
        I would want to make it do something more than just print out the string length and hardcoded string that overwrites user input but I did not have any ideas.
<Reflection 4 Think about the most important thing you learned when writing this piece of code.  What was it and explain why it was significant.>
      I should compile incrementally in larger programs instead of typing everything out first and then checking for bugs.
*/

#include <stdio.h>
#include <string.h>

void main () {
	char internetDown[] = "Error. No internet connection!";
	char userInput[] = " ";
	char userApp[] = " ";
	int length = 0;
	
	//Internet went down in Friley but I still had to do programming practice...
	printf("Enter a string:\n");
	scanf("%s", &userInput);
	length = strlen(userInput);
	
	printf("Congratulations, you input a string of %d characters long.\n", length);
	
	printf("What should I append your string?\n");
	scanf("%s", &userApp);
	
	strcat(userInput, userApp);
	length = strlen(userInput);
	
	printf("Your (new) string is: %s with a length of %d characters.\n", userInput, length);

	strcpy(userInput, internetDown);
	printf("Your (newest) string is: %s\n", userInput);
}
