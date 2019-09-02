#include "func.h"
#include <stdio.h>

int GetInput(int *state)
{
    int temp[3];
    for (int i = 0; i < 3; i++)
    {
        scanf("%d %d %d", &temp[0], &temp[1], &temp[2]);
        for (int j = 0; j < 3; j++)
            state[i*3 + j] = temp[j];
    }
    return 0;
}

int CalCount(int *option_times, int length)
{
    if (length < 0)
    {
        printf("the length of option times can not be negative!\n");
        return -1;
    }

    int sum = 0;
    for (int i = 0; i < length; i++)
    {
        if (option_times[i] < 0)
        {
            printf("the element of option times can not be negative!\n");
            return -1;
        }
        sum += option_times[i];
    }
    return sum;
}

int MoveClock(int *state, int *option_times, int map[3][3])
{
    
}

int AllTwelve(int *state, int length)
{}

int PrintResullt(int *option_times)
{}