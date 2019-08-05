#include <stdio.h>
#include "specific_clock.h"

int main()
{
    int init_clock;  // 初始密码锁状态
    int expect_clcok;  // 目标密码锁状态
    int bit_length;  // 密码锁个数
    int temp_clock;

    int max_search;  // 最大搜索方案数
    int min_count;  // 最小按按钮次数
    int current_count;

    bit_length = GetClcokState(&init_clock);
    int temp_length = GetClcokState(&expect_clcok);

    if (bit_length != temp_length)
        return 1;
    max_search = (1 << bit_length);
    min_count = bit_length + 1;

    int solution;
    for (solution = 0; solution < max_search; solution++)  // 对所有可能的按钮方案进行枚举
    {
        current_count = CalCounts(solution, bit_length);
        if (current_count > min_count)
            break;
        temp_clock = init_clock;
        for (int i = 0; i < bit_length; i++)
        {
            int bit = GetBit(solution, i);
            if (bit)
                temp_clock = FlipState(temp_clock, i, bit_length);
        }
        if (!(temp_clock ^ expect_clcok))
        {
            min_count = current_count;
        }
    }
    // 输出结果!
    printf("%d\n", min_count);
}