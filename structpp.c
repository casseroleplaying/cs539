#include <stdio.h>
#include <stdlib.h>

#define MAX 4

struct item {
        int id;
        int qs;
        int qe;
};
typedef struct item ITEM;
typedef ITEM *IP;

void pmatch(IP *);

int main (void)
{

        IP x[MAX];
        
        x[0] = malloc(sizeof(ITEM));
        x[1] = malloc(sizeof(ITEM));
        x[2] = malloc(sizeof(ITEM));
        x[3] = malloc(sizeof(ITEM));
        
        x[0]->id = 1;
        x[0]->qs = 10;
        x[0]->qe = 20;
        
        x[1]->id = 2;
        x[1]->qs = 5;
        x[1]->qe = 5;
        
        x[2]->id = 3;
        x[2]->qs = 30;
        x[2]->qe = 40;
        
        x[3]->id = 4;
        x[3]->qs = 50;
        x[3]->qe = 50;
        
        pmatch(x);
        
        return 0;
}

void pmatch(IP *x)
{
        IP xp = x;
        for (int i = 0; i < MAX; i++) {
                if (xp->qs == xp->qe) {
                        printf("%d" "\n", xp->id);
                }
                xp++;
        }
}
