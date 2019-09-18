#include <stdio.h>
#include <stdlib.h>
#include "func.h"

int main()
{
    char init_state[MAX_LENGTH];
    char expect_state[MAX_LENGTH];
    int length;  // 密码锁的长度
    int dismatch;  // 用于标识前一处理位的匹配状态
    int tag;  // 标识输出结果
    int num = 0;

    // 处理输入
    length = GetStateFromInput(init_state);
    if (length < 0)
    {
        printf("cant not input !\n");
        exit(0);
    }
    if (GetStateFromInput(expect_state) != length)
    {   
        printf("Input Error!\n");
        exit(0);
    }

    // 算法主体
    int i;
    for (i = 0; i < length; i++)
    {
        if (init_state[i] != expect_state[i]) // 当前位与期望状态不匹配
        {
            
            if (dismatch || i == 0)  // 如果当前位的前一位状态不匹配，则可以对当前位进行翻转
            {
                FlipBit(init_state, i, length);
                num++;
                dismatch = 0;
            }
            else
            {
                dismatch = 1;
                continue;
            }
        }
        else
        {
            if (dismatch)
            {
                tag = 0;  // 当前位匹配而前一位不匹配，不存在解
                break;
            }
        }
    }
    if ((i == length) && (!dismatch))
        tag = 1;
    
    // 输出结果
    if (tag)
        printf("%d\n", num);
    else
    {
        printf("impossible\n");
    }
    
}