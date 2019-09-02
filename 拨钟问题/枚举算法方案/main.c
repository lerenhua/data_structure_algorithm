#include <stdio.h>
#include "func.h"


int main()
{
    int clock_state[9]; // 保存输入时钟状态
    int option_times[9]; // 保存对应移动操作进行的次数 ， 如option_times[0] 表示移动0操作进行的次数
    int min_count = 4 * 9 + 1;  // 表示最少进行的操作次数
    int current_count;

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
        for (option_times[1] = 0; option_times[1] < 4; option_times[0]++)
            for (option_times[2] = 0; option_times[2] < 4; option_times[0]++)
                for (option_times[3] = 0; option_times[3] < 4; option_times[0]++)
                    for (option_times[4] = 0; option_times[4] < 4; option_times[0]++)
                        for (option_times[5] = 0; option_times[5] < 4; option_times[0]++)
                            for (option_times[6] = 0; option_times[6] < 4; option_times[0]++)
                                for (option_times[7] = 0; option_times[7] < 4; option_times[0]++)
                                    for (option_times[8] = 0; option_times[8] < 4; option_times[0]++)
                                    {
                                        current_count = CalCount(option_times);
                                        if (current_count < min_count)  // 设置筛选，找出可行解下的最少操作次数
                                        {
                                            MoveClock(clock_state, option_times);
                                            if (AllTwlve(clock_state))
                                                min_count = current_count;
                                        }
                                    }
    if (min_count != 4*9+1)
    {
        PrintResult(option_times);
    }
    else
        printf("Error!\n");
}