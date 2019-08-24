#include "func.h"
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
}