#include <stdio.h>
#include "utils.h"

int main()
{
    // 处理输入
    String * input_str = GetInputStr();
    String * print_str = CreateString(NULL);

    GenArrangement(input_str, 0);
    
}