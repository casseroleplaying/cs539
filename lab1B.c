/* Potenza, Matthew
 * Lab 1B
 * Due 9/17
 * C program to accept as input 3 positive integers and determine if
 * they make a valid triangle. If so, output the type of triangle and its area.
 */

#include<stdio.h>
#include<math.h>

int main(void)
{
	/* declare variables */
	int side1, side2, side3;
	float s, area;
	char answer;
	
	/* output program description (one time only) */
	printf("\nThis program will accept three positive integers\n");
	printf("and determine if they can make a valid triangle.\n");
	printf("If so, the type of triangle and its area will be displayed.\n");
	
	do
	{
		do
		{
			/* prompt user and read input */
			printf("\nPlease enter the lengths of 3 sides: ");
			scanf("%d %d %d", &side1, &side2, &side3);

			/* ensure proper usage */
			if (side1 <= 0 || side2 <= 0 || side3 <= 0)
			{
				printf("Error. All sides must be positive integers.\n");
			}

		}
		while (side1 <= 0 || side2 <= 0 || side3 <= 0);    /*re-prompt if input error*/ 
	

		/* check to see if a valid triangle can be made */
		if (side1 + side2 <= side3 || side1 + side3 <= side2 || side2 + side3 <= side1)
		{
			printf("These lengths do not make a valid triangle.\n");
			printf("The sum of any two sides must be greater than the third.\n");
		}

		/* lengths make a valid triangle, proceed with program */
		else
		{
			/* determine triangle type */
			if (side1 == side2 && side2 == side3)
			{
				printf("These lengths make an equilateral triangle.\n");
			}
			else if (side1 == side2 || side2 == side3 || side1 == side3)
			{
				printf("These lengths make an isoceles triangle.\n");
			}
			else 
			{
				printf("These lengths make a scalene triangle.\n");
			}

			/* calculate triangle area using Heron's formula */
			s = (side1 + side2 + side3) / 2.0;
			area = sqrt(s * (s - side1) * (s - side2) * (s - side3));

			printf("The area of the triangle is %6.2f.\n", area);
		}

		/* prompt user */
		printf("Do you want to continue (Y/N)? ");
		scanf(" %c", &answer);
	}
	while (answer == 'Y' || answer == 'y');    /* re-run program based on user input */

	return 0;

}
