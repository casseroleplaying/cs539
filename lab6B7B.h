/* Potenza, Matthew
 * Lab 6B, 7B
 * Due 11/26
 * Modular C program to read up to 50 names and adresses from standard input
 * into an array of pointers to structs. Memory for structs to be allocated
 * dynamically as needed. Data will be sorted in ascending order by zip code 
 * and written to standard output.
 */

/****** "lab6B7B.h" ***********************************************************/

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

int load(DP *, int *);
void sort(DP *, int, int);
void swap(DP *, int, int);
void write(DP *, int);
void unload(DP *, int);
