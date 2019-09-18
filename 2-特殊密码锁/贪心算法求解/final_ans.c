#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#define MAX_LENGTH 32  // 最大密码锁

int GetInput(char *state_str)
{
    if (state_str == NULL)
    {
        printf("the buffer pointer is invalid！\n");
        return 1;
    }
    char ch;
    int count = 0;  // 输入字符个数计数
    ch = getchar();
    while (ch != '\n')
    {
        if (ch != '0' && ch != '1')  // 处理非法输入字符
        {
            printf("Invalid input char!\n");
            return -1;
        }
        if (count == MAX_LENGTH - 1)  // 处理输入字符串长度大于MAX_LENGHT
        {
            printf("The length of input char is too long!\n");
            return -1;
        }

        state_str[count] = ch;
        count++;
        ch = getchar();
    }
    state_str[count] = '\0';
    return count;
}

int Flip(char *ch)
{
    if (*ch == '0')
        (*ch) = '1';
    else 
        (*ch) = '0';
    return 0;
}

int FlipBit(char *state_str, int pos, int length)
{
    // 错误处理
    if (state_str == NULL)
    {
        printf("The buffer pointer is NUll!\n");
        return 1;
    }
    if (length >= MAX_LENGTH)
    {
        printf("too long \n");
        return 1;
    }
    if (pos < 0 || pos >= length)
    {
        printf("The position is out of range 0 to %d\n", length-1);
        return 1;
    }

    // 翻转状态
    if (pos == 0)
    {
        if (state_str[pos+1] == '0')
            state_str[pos+1] = '1';
        else 
            state_str[pos+1] = '0'; 
    }
    else if (pos == length-1)
    {
        Flip(&state_str[pos-1]);
    }
    else
    {
        Flip(&state_str[pos-1]);
        Flip(&state_str[pos+1]);
    }
    Flip(&state_str[pos]);
    
    return 0;
}


int main()
{
    int length;
    char init_state[MAX_LENGTH];  // 初始密码锁状态
    char except_state[MAX_LENGTH];  // 目标密码锁状态
    char temp_state[MAX_LENGTH];  // 中间状态

    /* 处理输入 */
    if ((length = GetInput(init_state)) < 0 || GetInput(except_state) < 0)  // 检查读取输入是否正确
    {
        printf("Error input!\n");
        exit(0);
    } 

    /* 算法主体 */
    /*
       使用贪心策略：根据前一位密码锁状态决定当前是否翻转。
       两种情况： 1. 首位不翻转情况下，从第二位开始检测前一位是否匹配，从而获得开关次数
                2. 首位翻转情况下，从第二位开始检测前一位是否匹配，得到开关次数
     */

    int case1_num = 0;
    int case2_num = 0;
    int ans = MAX_LENGTH + 1;

    memcpy(temp_state, init_state, MAX_LENGTH);

    int i;
    /* 第一种情况 */
    for (i  = 1; i < length; i++)
    {
        if (init_state[i-1] != except_state[i-1])
        {
            FlipBit(init_state, i, length);
            case1_num++;
        }
    }
    if (init_state[i-1] == except_state[i-1])
        ans = case1_num;
    /* 第二种情况 */
    FlipBit(temp_state, 0, length);
    case2_num++;
    for (int i  = 1; i < length; i++)
    {
        if (temp_state[i-1] != except_state[i-1])
        {
            FlipBit(temp_state, i, length);
            case2_num++;
        }
    }
    
    if (temp_state[i-1] == except_state[i-1])
        ans = fmin(ans, case2_num);

    if (ans != MAX_LENGTH + 1)
        printf("%d\n", ans);
    else
        printf("impossible\n");
}