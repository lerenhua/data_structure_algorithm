#ifndef _POP_SEQ_H
#define _POP_SEQ_H

/******************************************/
/* 定义堆栈数据结构 */
/* 定义堆栈操作函数 */
/*********************************************/
typedef struct Stack * stack;
struct Stack 
{
    int capacity;  // 栈容量 
    int sp;  // 栈顶指针
    int * stack_data;  // 数组存储
};
/* 创建堆栈数据结构 */
stack CreateStack(int);
/* 判断堆栈是否满 */
int IsFullStack(stack);
/* 判断堆栈是否空 */
int IsEmptyStack(stack);
/* 判断给定元素是否与栈顶元素相同 */
int IsEqualStackTop(stack, int);
/* 入栈 */
int PushStack(stack, int);
/* 出栈 */
int PopStack(stack);

/****************************************/
/* 输入相关操作函数 */
/****************************************/
int ReadPopSeqFromInput(int*, int);

#endif