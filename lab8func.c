/****** "lab8func.c" *******************************************************/
 
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "lab8.h"

/* load:  reads data from file. allocates space for individual structures as
 * needed. assigns addresses of structures to pointer array, and relevant data
 * to members. records number of structures created */
int load(DP *info, FILE *ifp, int *n)
{
        char buffer[81];
        
        while (fgets(buffer, 81, ifp) != NULL && *n < MAX) {
                info[*n] = malloc(sizeof(DATA));
                if (!info[*n])                  /* return error if */
                        return 1;               /* malloc fails */
                else {
                        strcpy(info[*n]->name, buffer);
                        fgets(buffer, 81, ifp);
                        strcpy(info[*n]->add, buffer);
                        fgets(buffer, 81, ifp);
                        strcpy(info[*n]->cst, buffer);
                        fgets(buffer, 81, ifp);
                        info[*n]->zip = atoi(buffer);
                        (*n)++;
                }
        }
        return 0;             
}

/* sort:  modified qsort, rearranges structures held in pointer array in
 * ascending order by zip code. Source: "The C programming Language, Second
 * Edition" p. 87, Authors: Kernighan, Brian W. and Ritchie, Dennis M. */ 
void sort(DP *info, int left, int right)
{
        int i, last;

        if (left >= right)                      /* do nothing if array has */
                return;                         /* fewer than two elements */
        swap(info, left, (left + right) / 2);   /* move partition elem */
        last = left;                            /* to info[0] */
        for (i = left + 1; i <= right; i++)     /* partition */
                if (info[i]->zip < info[left]->zip)
                        swap(info, ++last, i);       
        swap(info, left, last);                /* restore partition elem */
        sort(info, left, last - 1);
        sort(info, last + 1, right);
}

/* swap:  interchange info[i] and info[j] */
void swap(DP *info, int i, int j)
{
        DP temp;
        
        temp = info[i];
        info[i] = info[j];
        info[j] = temp;  
}
 
/* write:  output to file contents of structures held in pointer array */
void write(DP *info, FILE *ofp, int n)
{      
        for (int i = 0; i < n; i++) {
                fprintf(ofp, "%s" "%s" "%s" "%d\n", info[i]->name, 
                        info[i]->add, info[i]->cst, info[i]->zip);
        }
}

/* unload: free memory allocated to structures */
void unload(DP *info, int n)
{
        for (int i = 0; i < n; i++)
                free(info[i]);
}

