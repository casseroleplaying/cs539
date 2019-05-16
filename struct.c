#include <stdio.h>

#define MAX 4

struct item {
        int id;
        int qs;
        int qe;
};
typedef struct item ITEM;

void pmatch(ITEM []);

int main (void)
{

        ITEM x[MAX];
        
        x[0].id = 1;
        x[0].qs = 10;
        x[0].qe = 20;
        
        x[1].id = 2;
        x[1].qs = 5;
        x[1].qe = 5;
        
        x[2].id = 3;
        x[2].qs = 30;
        x[2].qe = 40;
        
        x[3].id = 4;
        x[3].qs = 50;
        x[3].qe = 50;
        
        pmatch(x);
        
        return 0;
}

void pmatch(ITEM x[])
{
        for (int i = 0; i < MAX; i++)
                if (x[i].qs == x[i].qe)
                        printf("%d" "\n", x[i].id);
}
