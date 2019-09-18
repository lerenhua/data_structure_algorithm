/* 使用位操作，提高程序空间资源利用率 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#define MAX_LENGTH 32  // 最大密码锁

/* 此输入函数注意指针state指向的变量 应当在创建时显示初始化为0 */
int GetInput(int *state)
{
    char ch;
    int count = 0; // 输入字符计数
    while ((ch = getchar()) != '\n')
    {
        if (ch == '0')
        {
            (*state) = (*state) << 1;
        }
        else if (ch == '1')
        {
            (*state) = ((*state) << 1) ^ 1;
        }
        else
        {
            printf("Invalid character!\n");
            return -1;
        }
        count++;
    }
    return count;
}

int GetBit(int state, int pos, int length)
{
    if (state < 0 )  // 高位不能为1否则为非法状态
    {
        return -1;
    }
    if (pos < 0 || pos > (length-1))
    {
        printf("out of range!\n");
        return -1;
    }
    return ((state >> (length - 1 - pos)) & 1);
}

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


int main()
{
    int init_state = 0;
    int except_state = 0;
    int temp_state;
    int length;  // 密码锁长度

    /* 处理输入 */
    if ((length = GetInput(&init_state)) < 0 || GetInput(&except_state) < 0)  // 检查读取输入是否正确
    {
        printf("Error input!\n");
        exit(0);
    }

    int case1_num = 0;
    int case2_num = 0;
    int ans = MAX_LENGTH + 1;
    
    // 第一种情况
    temp_state = init_state;

    for (int i  = 1; i < length; i++)
    {
        if (GetBit(temp_state, i-1, length) != GetBit(except_state, i-1, length))
        {
            FlipBit(&temp_state, i, length);
            case1_num++;
        }
    }
    if (GetBit(temp_state, length-1, length) == GetBit(except_state, length-1, length))
        ans = case1_num;

    // 第二种情况
    FlipBit(&init_state, 0, length);
    case2_num++;
    for (int i  = 1; i < length; i++)
    {
        if (GetBit(init_state, i-1, length) != GetBit(except_state, i-1, length))
        {
            FlipBit(&init_state, i, length);
            case2_num++;
        }
    }
    if (GetBit(init_state, length-1, length) == GetBit(except_state, length-1, length))
        ans = fmin(ans, case2_num);
    

    // 处理输出
    if (ans != MAX_LENGTH + 1)
        printf("%d\n", ans);
    else
        printf("impossible\n");
}