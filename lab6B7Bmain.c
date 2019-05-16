/****** "lab6B7Bmain.c" *******************************************************/

#include <stdio.h>
#include "lab6B7B.h"

int main(void)
{       
        int n = 0;
        DP info[MAX];                   /* array of pointers to structs */
        
        if (load(info, &n) == 1) {      /* read data */
                printf("Error, insufficient memory.\n");
                return 1;               /* quit if malloc fails */
        }
        if (n != 0) {                   /* proceed if data found, else quit */
                sort(info, 0, n-1);     /* sort data */
                write(info, n);         /* output sorted data */
                unload(info, n);        /* free allocated memory */
        }   
        return 0;
}
