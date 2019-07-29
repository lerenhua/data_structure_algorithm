/* 判断给定序列是否是堆栈pop的结果 */

#include"pop_seq.h"
#include<stdio.h>
#include<stdlib.h>

int main()
{
    char* yes = "yes";
    char* no = "no";
    int m, n, k;  // m n k分别是堆栈容量，输入序列大小，序列个数
    scanf("%d %d %d", &m, &n, &k);
    int * seq = malloc(sizeof(int) * n);
    for (int l = 0; l < k; l++)
    {
        ReadPopSeqFromInput(seq, n);
        int j = 0;  // 设置指针，用于指明输入序列当前与栈顶比较的元素
        stack s = CreateStack(m);
        for (int i = 1; i <= n; i++)
        {
            if (IsFullStack(s))
            {
                printf("%s\n", no);
                break;
            }
            else
            {
                PushStack(s, i);
                while (IsEqualStackTop(s, seq[j]))
                {

                    PopStack(s);
                    j++;  
                }
            }
        }
        if (!IsFullStack(s))
        {
            if (IsEmptyStack(s))
                printf("%s\n", yes);
            else 
                printf("%s\n", no);
        }
    }
}