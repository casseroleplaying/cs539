#include<stdio.h>
#define LWRCS(c) ((c >= 'a' && c <= 'z'))

int main(void)
{
        char a = 'a';
        char b = 'B';
        
        if (LWRCS(a))
                printf("%c", a);
        if (!LWRCS(b))
                printf("%c", b);
        printf("%d", (5>3?1:0));
        
        return 0;
} 
