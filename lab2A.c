/* Potenza, Matthew
 * Lab 2A
 * Due 10/8
 * C program to echo input one word per line, parse the parsnip.
 */

#include<stdio.h>

int main (void)
{
	int c, inWord = 0;

	/* read charachter from input, repeat until end of file */
	while ((c = getchar()) != EOF)
	
		/* charachter is alphabetic */
		if ((c >= 65 &&  c <= 90) || (c >= 97 && c <= 122))
		{
			putchar(c);	/* send charachter to output */
			inWord = 1;	/* set state to processing a word */
		}
		else			/* charachter is not alphabetic */
		{
			if (inWord == 1)	/* word has been processed */
			{	
				putchar('\n');	/* send newline to output */
				inWord = 0;	/* reset state */
			}
		}

	return 0;
}
