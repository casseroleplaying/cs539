/* Potenza, Matthew
 * Lab 4B
 * Due 11/5
 * C program to filter a randomly generated string of 40 uppercase letters for
 * elements of a user defined string of 2-20 uppercase letters and replace them
 * with a charachter specified by the user. Program uses array notation.
 */ 
   
#include<stdio.h>
#include<stdlib.h>

int charinput();
void strgenerate(char []);
void strinput(char []);
void strfilter(char [], char [], char[], int);
 
int main(void)
{
	char s1[41], s2[22], s3[41];
	int ans, c;
        
        strgenerate(s1);                    	        /* generate string */
        
        printf("\nThis program will filter a randomly generated string of 40");
        printf("\nuppercase letters for elements of a user defined string of");
        printf("\n2-20 uppercase letters and replace them with a charachter");
        printf("\nspecified by the user.\n");
        
        do {    
                strinput(s2);		                /* get user string */
                c = charinput();                        /* get user char */
                strfilter(s1, s2, s3, c); 	        /* filter string */
                
                printf("\nGenerated string: ");         /* output results */
                puts(s1);
                printf("\nFiltered string : ");
                puts(s3);
                
                printf("\nContinue(Y/N)? ");
                ans = getchar();  
                while ((getchar()) != '\n');            /* clear input buffer */
        
        } while (ans == 'Y' || ans == 'y');  	        /* re-run program */
        
        return 0;
}

/****** gets replacement charachter ******************************************/
int charinput()
{
	printf("\nEnter a replacement charachter: ");
        int c = getchar();
        while ((getchar()) != '\n');                    /* clear input buffer */
        return c;
}

/****** generates random string of 40 uppercase letters ***********************/
void strgenerate(char s1[])
{
	for (int i = 0; i < 40; i++)
		s1[i] = rand() % 26 + 'A';              /* populate string */
	s1[40] = '\0';                                  /* null terminate */
}

/****** gets user string of 2-20 uppercase letters ****************************/
void strinput(char s2[])
{	
        for(int i = 0; i < 22; i++)                     /* clear string */
                s2[i] = '\0';
                
	printf("\nEnter string of 2-20 uppercase letters: ");
	fgets(s2, 22, stdin);                           /* get user string */
	
	for(int i = 21; i >= 0; i--) {
	        if (s2[i] == '\n')
	                s2[i] = '\0';                   /* null terminate */
	        if (i < 2 && s2[i] == '\0') {
	                printf("Error: Input too short, retry.\n");
	                strinput(s2);                   /* recur if error */
	        }
	        if (i == 20 && s2[i] != '\0') {
	                printf("Error: Input too long, retry.\n");
	                while ((getchar()) != '\n');    /* clear input buffer */
	                strinput(s2);                   /* recur if error */
	        }
	        if ((s2[i] < 'A' || s2[i] > 'Z') && s2[i] != '\0') {
	                printf("Error: Invalid input, retry.\n");
	                strinput(s2);                   /* recur if error */
	        }
	}
}               

/****** filters generated string, copies to new string ************************/
void strfilter(char s1[], char s2[], char s3[], int c)
{
	for (int i = 0; i <= 40; i++) {
	        s3[i] = s1[i];                          /* copy string */
	        for(int j = 0; s2[j] != '\0'; j++) {
			if (s1[i] == s2[j])             /* elements match */
				s3[i] = c;              /* replace */
		}
	}
}
