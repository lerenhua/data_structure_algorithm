#include <stdio.h>
#include "func.h"

int GetStateFromInput(char *state_str)
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
            return 1;
        }
        if (count == MAX_LENGTH - 1)  // 处理输入字符串长度大于MAX_LENGHT
        {
            printf("The length of input char is too long!\n");
            return 1;
        }

        state_str[count] = ch;
        count++;
        ch = getchar();
    }
    state_str[count] = '\0';
    return 0;
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