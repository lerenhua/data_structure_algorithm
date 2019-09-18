//#include "func.h"
#include <stdio.h>

// 对GetStateFromInput函数的测试
/* int main()
{
    char *state;//[MAX_LENGTH];
    while (1)
    {
        printf("Please input :\n");
        GetStateFromInput(state);
        printf("%s", state);
        printf("\n");
    }
}*/

/* 
int main()
{
    char state[MAX_LENGTH] = {"100010"};
    while (1)
    {
        int pos;
        printf("please input position:\n");
        scanf("%d", &pos);
        FlipBit(state, pos, 6);
        printf("%s\n", state);
    }
}*/

int FlipBit(int *state, int pos, int length)
{
    if (pos < 0 || pos > (length-1))
    {
        return -1;
    }
    if (pos == 0)
    {
        (*state) = (*state) ^ (3 << (length-2));
    }
    else if (pos == length -1)
    {
        (*state) = (*state) ^ 3;
    }
    else
    {
        (*state) = (*state) ^ (7 << (length-2 - pos));
    }
    return 0;
}

int main(int argc, char const *argv[])
{
    int i = 0x2B;
    FlipBit(&i, 0, 7);
    printf("%x\n", i);
    
    i = 0x2B;
    FlipBit(&i, 6, 7);
    printf("%x\n", i);

    i = 0x2B;
    FlipBit(&i, 4, 7);
    printf("%x\n", i);
    return 0;
}
