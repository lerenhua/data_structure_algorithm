/* 测试函数正确性 */

#include <stdio.h>
#include "specific_clock.h"

int main()
{
    int state = 0;
    int state_len = GetClcokState(&state);
    printf("%x", state);
    return 0;
}