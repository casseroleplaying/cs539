/* Potenza, Matthew
 * Lab 8
 * Due 12/3
 * Modular C program to read up to 50 names and adresses from a file into an 
 * array of pointers to structs. Memory for structs to be allocated dynamically 
 * as needed. Data will be sorted in ascending order by zip code and written to  
 * a new file.
 */

/****** "lab8.h" **************************************************************/

#include <stdio.h>

#define MAX 50
#define SLEN 40

struct persdata {
        char name[SLEN];
        char add[SLEN];
        char cst[SLEN];
        int zip;
        };
        
typedef struct persdata DATA;
typedef DATA *DP;

int load(DP *, FILE *, int *);
void sort(DP *, int, int);
void swap(DP *, int, int);
void write(DP *, FILE *, int);
void unload(DP *, int);
