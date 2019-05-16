/* Potenza, Matthew
 * Lab 3B
 * Due 10/15
 * C program to perform simple arithmetic calculations.
 * Accepts an expression from user input that must consist of two positive 
 * integers surrounding a single binary arithmetic operator and may include any 
 * amount of whitespace. Input will be echoed to output 1:1
 * along with a re-formatted expression and its solution if valid.
 */

#include<stdio.h>

int convert (int c, int sum);
int dec_remainder (int term1, int term2);
void modulus (int term1, int opr, int term2);
void multiply (int term1, int opr, int term2);
void divide (int term1, int opr, int term2);
void add (int term1, int opr, int term2);
void subtract (int term1, int opr, int term2);
void output (int term1, int opr, int term2, long eval);
void printd (int n);

int main (void)
{
	int answer, c;
	
	printf("\nEnter an arithmetic expression of the form\n");
	printf("<positive integer> <binary operator> <positive integer>\n");
	printf("to calculate it's solution.\n");			 

	do {
		int err = 0, echo = 0, num = 0, opr = 0, 
		    spc = 0, term1 = 0, term2 = 0;      /* reset when re-run */

                printf("\nExpression : ");
		
		while ((c = getchar()) != '\n') {		/* read input */
			
			if (echo == 0) {				
				printf("\nYou entered: ");	/* print 1x */
				echo = 1;
			}
                        
                        putchar(c);				/* echo input */
			
			switch (c) {    /* validate and assign input values */
			
			/* process operands of expression */
			case '0': case '1': case '2': case '3': case '4':
			case '5': case '6': case '7': case '8': case '9':
				
				if ((num == 1 && opr == 0 && spc == 0) || 
				    num == 0) { 
					term1 = convert(c, term1);
					num = 1;
				} 
				else if ((num == 1 && opr != 0 && spc != 2) || 
				         (num == 2 && spc < 2)) {
					term2 = convert(c, term2);
					num = 2;
				} 
				else
					err = 1;
				break;
			
			/* process operator(s) */
			case '%': case '*': case '/': case '+': case '-':
			        if (num == 1 && opr == 0)
					opr = c;
				else
					err = 1;
				break;
			
			case ' ':               /* process blank space */
				if (num == 1)
			                spc = 1;
				else if (num == 2)
				        spc = 2;
				break;

			default:                /* all other input invalid */
				err = 1;
				break;
			} 
		}
	        
		if (err == 1 || opr == 0 || num == 1)   /* error handling */
			printf("\nInput error, retry.\n");	
                else {
			
			switch(opr) {	        /* call arithmetic functions */
			
			case '%':					
				modulus (term1, opr, term2);
				break;
			case '*':					
				multiply (term1, opr, term2);	
				break;
			case '/':					
				divide (term1, opr, term2);			
				break;
			case '+':			
				add (term1, opr, term2);
				break;
			case '-':          			
				subtract (term1, opr, term2);
				break;
			}
		}

		printf("Continue (Y/N)? ");		/* prompt user */
		answer = getchar();
                
                while ((getchar()) != '\n');		/* clear input buffer */

	} while (answer == 'Y' || answer == 'y');	/* re-run program */	

	return 0;
}

/******************************************************************************/
/* converts a stream of charachters, processed one at a time to an integer.
 * source: C by Discovery 2nd Edition, p. 316 author: Foster, L.S. */
int convert (int c, int sum)
{
	sum = sum * 10 + (c - '0');	
	return(sum);
}

/******************************************************************************/
/* returns as an int the decimal remainder of floating-point division */
int dec_remainder(int term1, int term2)
{
	int dec;
	float rem;

	rem = (term1 % term2 / (float)term2);	
	dec = rem * 100;			
	return(dec);
}

/******************************************************************************/
/* prints re-formatted arithmetic expression and its solution */
void output(int term1, int opr, int term2, long eval)
{
	printf("\nSolution   : ");
	printd(term1);
	putchar(' ');
	putchar(opr);
	putchar(' ');
	printd(term2);
	putchar(' ');
	putchar('=');
	putchar(' ');
	if (opr == '/' && term1 % term2 != 0) {         /* division produces */
		printd(eval);                           /* floating-point    */
		putchar('.');                           /* quotient          */     
		printd(dec_remainder(term1, term2));
	} 
	else
		printd(eval);
	putchar('\n');
}

/******************************************************************************/
/* recursive function to print n in decimal using putchar()
 * source: The C Programming Language, second edition p.87
 * authors: Kernighan, Brian W. and Ritchie, Dennis M. */
void printd(int n)
{
	if (n < 0) { 			/* if negative */
	  	putchar('-');		/* print sign */
	  	n = -n;			/* change to positive */
	}
	
	if (n/10)			/* remove the last digit */
		printd(n/10);		/* recur */

	putchar(n % 10 + '0');		/* print last digit */
}

/******************************************************************************/
/* performs modulus */
void modulus (int term1, int opr, int term2) 
{
	long eval;
	eval = term1 % term2;
	output(term1, opr, term2, eval);
}

/******************************************************************************/
/* performs multiplication */
void multiply (int term1, int opr, int term2) 
{
	long eval;
	eval = term1 * term2;
	output(term1, opr, term2, eval);
}

/******************************************************************************/
/* performs division */
void divide (int term1, int opr, int term2) 
{
	long eval;
	if (term2 == 0) {
		printf("\nDivision by zero is undefined.\n");
	} 
	else {
	eval = term1 / term2;
	output(term1, opr, term2, eval);
	}
}

/******************************************************************************/
/* performs addition */
void add (int term1, int opr, int term2) 
{
	long eval;
	eval = term1 + term2;
	output(term1, opr, term2, eval);
}

/******************************************************************************/
/* performs subtraction */
void subtract (int term1, int opr, int term2) 
{
	long eval;
	eval = term1 - term2;
	output(term1, opr, term2, eval);
}
