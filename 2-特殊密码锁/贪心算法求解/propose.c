#include <stdio.h>
#include <stdlib.h>

#define MAX_LENGTH 32

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
    /* 
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
                //tag = 0;  // 当前位匹配而前一位不匹配，不存在解
                //break;
                FlipBit(init_state, i, length);
                num++;

            }
        }
    }
    if ((!dismatch))
        tag = 1;
    else
        tag = 0;
    
    // 输出结果
    if (tag)
        printf("%d\n", num);
    else
    {
        printf("impossible\n");
    }
    printf("\n");
    int i;
    for (i = 0; i < length; i++)
    {
        if (init_state[i] != expect_state[i])
        {
            if (i == 0)
            {
                FlipBit(init_state, i, length);
                printf("%s\n%s\n\n", init_state, expect_state);
                num++;
            }
            else if (i < (length - 1))
            {
                if (dismatch)
                {
                    FlipBit(init_state, i, length);
                    printf("%s\n%s\n\n", init_state, expect_state);

                    num++;
                    dismatch = 0;
                }
                else
                    dismatch = 1;
            }
            else
            {
                if (dismatch)
                {
                    printf("%d\n", num + 1);
                }
                else
                    printf("impossible\n");
            }
            
        }
        else // 当前位匹配
        {
            if (i == 0)
                continue;
            else if (i < (length - 1))
            {
                if (dismatch)
                {
                    FlipBit(init_state, i, length);
                    printf("%s\n%s\n\n", init_state, expect_state);

                    num++;
                    dismatch = 1;
                }
                else 
                    continue;
            }
            else
            {
                if (dismatch)
                    printf("impossible\n");
                else
                    printf("%d\n", num);
            }   
        }
    }*/
    int i;
    if (init_state[0] != expect_state[0])
    {
        FlipBit(init_state, 0, length);
        num++;
    }
    for (i = 2; i < length; i++)
    {
        if (init_state[i - 1] != expect_state[i - 1])
        {
            FlipBit(init_state, i, length);
            num++;
        }
    }
    if (init_state[i] != expect_state[i])
        printf("impossible\n");
    else
        printf("%d\n", num);

    
}