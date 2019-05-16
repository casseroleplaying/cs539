/****** "lab8main.c" **********************************************************/

#include <stdio.h>
#include <stdlib.h>
#include "lab8.h"

int main(int argc, char *argv[])
{       
        FILE *ifp, *ofp; 
        int n = 0;
        DP info[MAX];                           /* pointers to structs array */
                
        if (argc != 3) {                        /* ensure proper usage */
                printf("Error: usage: ./lab8 <input file> <output file>\n");
                return 1;
        }
        if ((ifp = fopen(argv[1], "r")) == NULL) {
                printf("Error: cannot open input file.\n");
                return 2;
        }
        if ((ofp = fopen(argv[2], "w")) == NULL) {
                printf("Error: cannot open output file.\n");
                return 3;
        }       
        if (load(info, ifp, &n) == 1) {         /* read data from file */
                printf("Error: insufficient memory.\n");
                return 4;                       /* quit if malloc fails */
        }
        if (n == 0)                     
                return 0;                       /* quit if file is empty */
                
        sort(info, 0, n-1);                     /* sort data */
        write(info, ofp, n);                    /* output sorted data */
        unload(info, n);                        /* free allocated memory */  
        fclose(ifp);                            /* close files */
        fclose(ofp);
        
        return 0;
}
