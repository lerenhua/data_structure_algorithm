#include"pop_seq.h"
#include<stdio.h>
#include<stdlib.h>

stack CreateStack(int capacity)
{
    /* 创建堆栈数据结构并初始化

       capacity:表示栈的容量
       成功则返回堆栈数据结构的地址,出错则返回NULL
     */
    if (capacity < 0)
    {
        printf("Error Capacity!\n");
        return NULL; 
    }
    stack temp = malloc(sizeof(struct Stack));
    if (temp != NULL)
    {
        int * stack_data = malloc(sizeof(int) * capacity);
        if (stack_data != NULL)
        {
            temp->capacity = capacity;
            temp->sp = -1;
            temp->stack_data = stack_data;
            return temp;
        }
    }
    return NULL;
}

int IsFullStack(stack s)
{
    /* 判断堆栈是否满
       堆栈已满，则返回1;反之，返回0
     */
    return (s->sp + 1) >= s->capacity;
}
int IsEmptyStack(stack s)
{
    /* 判断堆栈是否为空
       堆栈空则返回1;反之，返回0
     */
    return s->sp < 0;
}
int IsEqualStackTop(stack s, int element)
{
    /* 判断给定元素是否与栈顶元素相同
       若相同，则返回1;反之，返回0
     */
    if (IsEmptyStack(s))
    {
        // printf("stack can not empty!\n");
        return 0;
    }
    if (s->stack_data[s->sp] != element)
        return 0;
    else
        return 1;
}
int PushStack(stack s, int element)
{
    /* 将元素入栈
       成功则返回1;反之为0 
     */
    if (!IsFullStack(s))
    {
        s->sp++;
        s->stack_data[s->sp] = element;
        return 1;
    }
    return 0;
}
int PopStack(stack s)
{
    /* 元素出栈
       成功则返回该元素;反之为0 
     */
    if (!IsEmptyStack(s))
    {
        int temp = s->stack_data[s->sp];
        s->sp--;
        return temp;
    }
    return 0;
}
int ReadPopSeqFromInput(int* input_seq, int size)
{
    /* 将输入序列读取到数组中 */
    for (int i = 0; i < size; i++)
    {
        scanf("%d", &input_seq[i]);
    }
    return 0;
}