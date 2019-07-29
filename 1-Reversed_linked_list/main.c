/* 
    实现链表的每K元素进行反转的功能
    程序完成两部分内容：
    1. 将输入数据转换成链表结构
    2. 将链表每K个元素进行反转
    如：1->2->3->4->5, 每三个进行反转结果为 3->2->1->4->5
 */
#include"reversed_list.h"
#include<stdio.h>
#include<stdlib.h>

int main()
{
    /* 此部分将输入数据转换成链表结构 */
    char start_adress[6];
    int N, K;  // N为链表长度，K表示每多少元素反转
    node list = NULL;

    ReadFirstLine(start_adress, &N, &K);
    quene Q = CreateQuene(N - 1);  // 只需要N-1大小的队列，因为有一个链表开头节点不放入队列
    for (int i = 0; i < N; i++)
    {
        node input_node = FromInputToNode();
        if (IsEqualStr(input_node->adress, start_adress))
            list = input_node;
        else
            InQuene(Q, input_node);
    }
    node temp_list = list;  // 使用中间指针用于接下来形成完整链表
    while (!IsEmptyQuene(Q))
    {
        node next_node = OutQuene(Q);
        if (IsEqualStr(temp_list->next_adress, next_node->adress))
        {
            temp_list->next = next_node;
            temp_list = temp_list->next;
        }
        else
            InQuene(Q, next_node);
    }
    //PrintList(list, N);

    /* 此部分实现链表每K元素进行反转 */
    node start = list;  //  设置指针指向链表开始节点
    node new_list = malloc(sizeof(struct Node));  // 创建反转后的链表表头
    node new_list_end = new_list;
    stack s = CreateStack(K);
    while (start !=  NULL)
    {
        node move_ptr =  start;
        for (int i = 0; i < K; i++)
        {
            if (move_ptr != NULL)
            {
                PushStack(s, move_ptr);
                move_ptr = move_ptr->next;
            }
            else
                break;
        }
        if (IsFullStack(s))
        {
            while (!IsEmptyStack(s))
            {
                new_list_end->next = PopStack(s);
                new_list_end = new_list_end->next;
            }
            start = move_ptr;
        }
        else  // 不满K个元素的链表部分不进行反转
            new_list_end->next = start;
    }

    /* 打印排序后的链表 */
    node print_list = new_list->next;
    PrintList(print_list, N);
    return 0;
}