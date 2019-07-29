#ifndef _R_LIST_H
#define _R_LIST_H

/* 声明链表节点结构体 */
// struct Node;
typedef struct Node * node;
struct Node 
{
    char * adress;
    int data;
    char * next_adress;
    node next;
};


/**********************************************/
/*                                            */
/* 声明输入转换成链表所要使用的队列数据结构及相关函数 */
/*                                            */
/*********************************************/
//struct Quene;
typedef struct Quene * quene;
struct Quene 
{
    int capacity;
    int size;
    int start_idx;
    int end_idx;
    node * quene_data; 
};
/* 创建队列 */
quene CreateQuene(int capacity);
/* 判断队列是否为空 */
int IsEmptyQuene(quene Q);
int IsFullQuene(quene Q);
/* 元素入队 */
int InQuene(quene Q, node node_ptr);
/* 元素出队 */
node OutQuene(quene Q);

/********************/
/*                  */
/* 输入及处理相关函数 */
/*                 */
/*******************/
/* 读入第一行数据 */
int ReadFirstLine(char * start_adress, int * N, int * K);
/* 读入链表节点数据 */
node FromInputToNode();
/* 判断字符串是否相等 */
int IsEqualStr(char * str1, char * str2);

/**************************/
/*                        */
/* 堆栈数据结构及相关操作函数 */
/*                        */
/**************************/
typedef struct MetaStack * stack;
struct MetaStack
{
    int sp;
    int capacity;
    node * data;
};
/* 创建堆栈数据结构并初始化 */
stack CreateStack(int capacity);
/* 入栈 */
int PushStack(stack, node);
/* 出栈 */
node PopStack(stack);
/* 判断栈是否满 */
int IsFullStack(stack);
/* 判断栈是否空 */
int IsEmptyStack(stack);
/* 将堆栈清空 */
//int ClearStack(stack);

/* 打印链表 */
int PrintList(node, int);
#endif