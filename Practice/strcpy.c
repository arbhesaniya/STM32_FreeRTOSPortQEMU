#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    
    char *c;
    c=malloc(6);
    
    char *d="hello";
    
    // strcpy(c,d);
    
    while(*d!='\0'){
        *c++=*d++;
    }
    *c='\0';
    
    int i=0;
    while(i<5)
    {
        i++;
        c--;
    }
    
    printf("c is at %s \n", c);

    return 0;
}
