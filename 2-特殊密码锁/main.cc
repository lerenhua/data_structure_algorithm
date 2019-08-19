#include <stdio.h>
#include "specific_clock.h"
#include <iostream>

inline int FlipState(int bit_num, int pos, int len)
{
    int temp;
    if (pos == 0)
    {
        temp = FlipBit(bit_num, 0);
        return FlipBit(temp, 1);
    }
    else if (pos == (len - 1))
    {
        temp = FlipBit(bit_num, pos);
        return FlipBit(temp, pos - 1);
    }
    else
    {
        temp = FlipBit(bit_num, pos);
        temp = FlipBit(temp, pos - 1);
        return FlipBit(temp, pos + 1);
    }
}

int main()
{
    int init_clock = 0;  // 初始密码锁状态
    int expect_clcok = 0;  // 目标密码锁状态
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
        //current_count = CalCounts(solution, bit_length);
        temp_clock = init_clock;


        current_count = 0;        
        for (int i = 0; i < bit_length; i++)
        {
            int bit = GetBit(solution, i);
            if (bit)
            {
                temp_clock = FlipState(temp_clock, i, bit_length);
                current_count++;
            }
        }

        

        if (!(temp_clock ^ expect_clcok))
        {
            min_count = current_count;
        }
        if (current_count > min_count)
            break;
    }
    // 输出结果!
    if (min_count == (bit_length + 1))
        //printf("impossible\n");
        std::cout << "impossible";
    else
        //printf("%d\n", min_count);
        std::cout << min_count;
    return 0;
}