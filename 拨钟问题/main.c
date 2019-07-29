#include "clock_op.h"
#include <stdio.h>
#include <stdlib.h>

int main()
{
    Stack  global_stack;
    InitStack(&global_stack, StateOptiosMap_ptr, MAXCAPACITY);  // 初始化全局堆栈

    StateOptionsMap * current_som = NULL;
    // 记录未到12点的时钟，1表示未到达12点，0表示到达12点
    int no_zero_clock[9];  
    // 记录可进行打移动选项
    int available_option[9];
    clock_state temp_state;

    CopyState(init_state, temp_state);
    current_som = CreateMap(temp_state);

    while (!IsAllZero(temp_state))
    {
        // 时钟未全部到达12点则进入循环
        FindZeroClock(no_zero_clock, temp_state);
        FindAvailableOptions(available_option, no_zero_clock, move_clcok_map);
        SortAndPush(available_option, move_clock_array, current_som);
        while (IsEmptyOptions(current_som)) // 如果当前时钟状态没有可以移动的选项，则从全局堆栈恢复之前的状态
        {
            current_som = PopStack(&global_stack);
            PopStack(&(current_som->options));
        }
        MoveClock(current_som, temp_state)
        PushStack(&global_stack, current_som);
        current_som = CreateMap(temp_state)
    }

    int result_length = global_stack.size;
    int * result = malloc(sizeof(int) * result_length);
    for (int i = 0; i < result_length; i++)
    {
        current_som = PopStack(&global_stack);
        result[i] = TopStack(&current_som->options);
    }
    Sort(result);
    PrintResult(result);
    return 0;
}