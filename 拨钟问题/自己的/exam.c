// 找出同乡个数

#include <stdio.h>
#include <stdlib.h>
#define MAX_N 1000
int InitSet(int *set)
{
    for (int i = 0; i < MAX_N + 1; i++)
        set[i] = -1;
    return 0;
}

int FindSetHead(int *set, int index)
{
    if (set[index] < 0)
        return index;
    else 
    {
        while (set[index] > 0)
            index = set[index];
        return index;
    }
}

int MergeSet(int *set, int set_head_a, int set_head_b)
{
    if (set_head_a == 1 || set_head_b == 1)
    {
        int head_master, head_slave;
        if (set_head_a == 1)
        {
            head_master = set_head_a;
            head_slave = set_head_b;
        }
        else
        {
            head_master = set_head_b;
            head_slave = set_head_a;
        }
        set[head_master] += set[head_slave];
        set[head_slave]  = head_master;

    }
    else if (set[set_head_a] < set[set_head_b])
    {
        set[set_head_a] += set[set_head_b];
        set[set_head_b] = set_head_a;
    }
    else
    {
        set[set_head_b] += set[set_head_a];
        set[set_head_a] = set_head_b;
    }
    return 0;
}

int main()
{
    int N, M;
    int set[MAX_N + 1]; // 便于索引,直接使用1001个空间
    while (scanf("%d %d", &N, &M) != EOF)
    {
        InitSet(set);
        int a, b, c;
        for (int i = 0; i < M; i++)
        {
            scanf("%d %d %d", &a, &b, &c);
            if (c==1)
            {
                int a_head = FindSetHead(set, a);
                int b_head = FindSetHead(set, b);

                if (a_head != b_head)
                    MergeSet(set, a_head, b_head);
            }
        }
        printf("%d\n", -set[1] - 1);
    }
}