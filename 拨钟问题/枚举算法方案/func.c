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

int MoveClock(int *state, int *option_times, int length)
{
    for (int i = 0; i < length; i++)
    {
        if (option_times[i] > 0)  // 第i种移动被执行
        {
            if (option_times[i] > 4)  // 移动操作次数超过合理值
            {
                printf("The times of option %d is more than 4!\n", i);
                return -1;
            }
            for (int j = 0; j < length; j++)  //遍历第i种操作中移动的时钟
            {
                if (option_map[i][j] == 1)
                {
                    if (state[j] < 0)
                    {
                        printf("The state of clock can not be negative！\n");
                        return -1;
                    }
                    if ((state[j] + option_times[i]) > 3)
                    {
                        state[j] = (state[j] + option_times[i]) % 4;
                    }
                    else
                        state[j] = state[j] + option_times[i];
                }
            }
        }
    }
    return 0;
}

int AllTwelve(int *state, int length)
{
    for (int i = 0; i < length; i++)
    {
        if (state[i] != 0)  // 任意一个时钟状态不为12点则返回
            return 0;
    }
    return 1;
}

int PrintResult(int *option_times, int length)
{
    for (int i = 0; i < length; i++)
    {
        if (option_times[i] > 0)
        {
            for (int j = 0; j < option_times[i]; j++)
                printf("%d ", i+1);
        }
    }
    printf("\n");
    return 0;
}