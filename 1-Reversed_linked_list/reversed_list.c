#include"reversed_list.h"
#include<stdio.h>
#include<stdlib.h>


/* 定义队列相关操作函数 */
quene CreateQuene(int capacity)
{
    if (capacity < 1)
    {
        printf("the capacity of quene is not reasonable!\n");
        return NULL;
    }
    quene Q = malloc(sizeof(struct Quene));
    if (Q != NULL)
    {
        node * quene_data = malloc(sizeof(node) * capacity);
        if (quene_data != NULL)
        {
            Q->capacity = capacity;
            Q->size = 0;
            Q->start_idx = Q->end_idx = 0;
            Q->quene_data = quene_data;
            return Q;
        }
        return NULL;
    }
}
int IsEmptyQuene(quene Q)
{
    return (!Q->size);
}
int IsFullQuene(quene Q)
{
    return (Q->capacity == Q->size);
}
int InQuene(quene Q, node node_ptr)
{
    if (IsFullQuene(Q))
    {
        printf("The quene is full !!\n");
        return 0;
    }
    else
    {
        Q->quene_data[Q->end_idx] = node_ptr;  //元素入队
        Q->size++;
        if (Q->end_idx < Q->capacity)
            Q->end_idx += 1;
        else
            Q->end_idx = 0;
        return 1;
    }
}
node OutQuene(quene Q)
{
    if (IsEmptyQuene(Q))
    {
        printf("The quene is empty!\n");
        return NULL;
    }
    else
    {
        node temp = Q->quene_data[Q->start_idx];
        Q->size -= 1;
        if (Q->start_idx < Q->capacity)
            Q->start_idx += 1;
        else
            Q->start_idx = 0;
        return temp;
    }
    
}

/* 输入及处理相关函数 */
int ReadFirstLine(char * start_adress, int * N, int * K)
{
    printf("Please input start adress, N, K:\n");
    scanf("%s %d %d", start_adress, N, K);
    return 0;
}
node FromInputToNode()
{
    char * adress = malloc(sizeof(char) * 6);
    char * next = malloc(sizeof(char) * 6);
    int data;
    printf("Please input node of list with the format (Adress Data Next):");
    scanf("%s %d %s", adress, &data, next);
    node new_node = malloc(sizeof(struct Node));
    if (new_node != NULL)
    {
        new_node->adress = adress;
        new_node->data = data;
        new_node->next_adress = next;
        new_node->next = NULL;
        return new_node;
    }
    return NULL;
}
int IsEqualStr(char * str1, char * str2)
{
    /* 
        判断两个字符串是否相同，
        若相同，返回1
        不同， 返回0
     */
    int str1_len = 0;
    while(str1[str1_len] != '\0')  //获取字符串长度
        str1_len++; 
    int str2_len = 0;
    while (str2[str2_len] != '\0')
        str2_len++;
    if (str1_len != str2_len)
        return 0;
    else
    {
        for (int i = 0; i < str1_len; i++)
        {
            if (str1[i] != str2[i])
                return 0;
        }
        return 1;
    }
}

/* 堆栈数据结构操作函数 */
stack CreateStack(int capacity)
{
    /*  */
    stack temp = malloc(sizeof(struct MetaStack));
    if (temp != NULL)
    {
        node * temp_data = malloc(sizeof(node)*capacity);
        if (temp_data != NULL)
        {
            temp->data = temp_data;
            temp->sp = -1;
            temp->capacity = capacity;
            return temp;
        }
    }
    return NULL;
}
int PushStack(stack S, node list_node)
{
    if (IsFullStack(S))
    {
        printf("The stack is full!\n");
        return 0;
    }
    else
    {
        S->sp += 1;
        S->data[S->sp] = list_node;
        return 1;
    }
}

node PopStack(stack S)
{
    if (IsEmptyStack(S))
    {
        printf("The stack is empty!\n");
        return NULL;
    }
    else
    {
        node temp = S->data[S->sp];
        S->sp -= 1;
        return temp;
    }
}
int IsFullStack(stack s)
{
    return (s->sp + 1) == s->capacity;
}
int IsEmptyStack(stack s)
{
    return s->sp < 0;
}

int PrintList(node print_list, int N)
{
    for (int i = 0; i < N; i++)
    {
        printf("%s %d %s\n", print_list->adress, print_list->data, print_list->next_adress);
        print_list = print_list->next;
    }
    return 0;
}