#include<stdio.h>
#include<stdlib.h>

int main()
{
    //char * str = NULL;
    char * str = malloc(sizeof(char) * 6);
    scanf("%s", str);
    printf("%s", str);
    return 0;
}