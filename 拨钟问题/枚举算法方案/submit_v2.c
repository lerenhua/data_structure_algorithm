#include <stdio.h>
#define OPTION_LENGTH 9

//extern int option_map[OPTION_LENGTH][OPTION_LENGTH];

/* 
  将输入保存至给定的数组
  args: state --- int数组
  return： 如果输入保存成功，则返回0;反之，出问题返回-1
 */
int GetInput(int *state);

/*
  将数组中元素进行累加
  args： option_times  int数组
  return： 如果累加成功则返回累加后的元素的值，该值大于等于0;反之，出现问题返回-1
 */
int CalCount(int *option_times, int length);

/* 
  根据给定的移动选项，对时钟状态进行变化
  args: state --- int数组，表示时钟状态
  args： option_times --- int数组，表示移动选项的记录
  return: 成功返回0,反之返回-1
 */
int MoveClock(int *state, int *option_times, int length);

/* 
  检查时钟状态是否都为12点
  args： state --- int数组，时钟状态
  return： 时钟状态都为12点则返回1, 反之返回0
 */
int AllTwelve(int *state, int length);


/* 
  将最后移动操作结果以规定格式输出
  args： option_times --- int数组，表示移动操作记录
  return： 输出成功返回0,反之返回-1
 */
int PrintResult(int *option_times, int length);

#include <stdlib.h>


int option_map[OPTION_LENGTH][OPTION_LENGTH] = {
            {1, 1, 0, 1, 1, 0, 0, 0, 0},
            {1, 1, 1, 0, 0, 0, 0, 0, 0},
            {0, 1, 1, 0, 1, 1, 0, 0, 0},
            {1, 0, 0, 1, 0, 0, 1, 0, 0},
            {0, 1, 0, 1, 1, 1, 0, 1, 0},
            {0, 0, 1, 0, 0, 1, 0, 0, 1},
            {0, 0, 0, 1, 1, 0, 1, 1, 0},
            {0, 0, 0, 0, 0, 0, 1, 1, 1},
            {0, 0, 0, 0, 1, 1, 0, 1, 1}
};
int main()
{
    int clock_state[9]; // 保存输入时钟状态
    int option_times[9]; // 保存对应移动操作进行的次数 ， 如option_times[0] 表示移动0操作进行的次数
    int min_count = 4 * 9 + 1;  // 表示最少进行的操作次数
    int current_count;
    int temp_state[9];
    int result[9];

    

    /* 处理输入 */
    if (GetInput(clock_state) < 0)
    {
        printf("Input Error!\n");
        exit(0);
    }

    /* 枚举算法主体 
       由于对于每一种移动操作最多有4次，因此可以确定最终拨动时钟次数的上限情况，所以使用枚举，以每种移动进行的次数进行枚举
       最终数组option_times保存对应操作进行的次数。
     */
    for (option_times[0] = 0; option_times[0] < 4; option_times[0]++)
        for (option_times[1] = 0; option_times[1] < 4; option_times[1]++)
            for (option_times[2] = 0; option_times[2] < 4; option_times[2]++)
                for (option_times[3] = 0; option_times[3] < 4; option_times[3]++)
                    for (option_times[4] = 0; option_times[4] < 4; option_times[4]++)
                        for (option_times[5] = 0; option_times[5] < 4; option_times[5]++)
                            for (option_times[6] = 0; option_times[6] < 4; option_times[6]++)
                                for (option_times[7] = 0; option_times[7] < 4; option_times[7]++)
                                    for (option_times[8] = 0; option_times[8] < 4; option_times[8]++)
                                    {

                                        current_count = CalCount(option_times, OPTION_LENGTH);
                                        if (current_count < min_count)  // 设置筛选，找出可行解下的最少操作次数
                                        {
                                            for (int i = 0; i < 9; i++)
                                                temp_state[i] = clock_state[i];
                                            MoveClock(temp_state, option_times, OPTION_LENGTH);
                                            if (AllTwelve(temp_state, OPTION_LENGTH))
                                            {
                                                for (int i = 0; i < 9; i++)
                                                    result[i] = option_times[i];
                                                min_count = current_count;
                                            }
                                        }
                                    }
    if (min_count != 4*9+1)
    {
        PrintResult(result, OPTION_LENGTH);
    }
    else
        printf("Error!\n");
}

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