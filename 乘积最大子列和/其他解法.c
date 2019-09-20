
#include <stdio.h>
#include <stdlib.h>
typedef struct range {
    struct range *next;
    int start_idx;
    int end_idx;
} range;

range *CreateRange()
{
    range *temp = malloc(sizeof(range));
    if (temp != NULL)
    {
        temp->next = NULL;
    }
    else
        printf("No space!\n");
    return temp;
}

int IsEvenNeg(int *sig_flag, int start_idx, int end_idx)
{
    int neg_nums = 0;
    for (int i = start_idx; i <= end_idx; i++)
        if (sig_flag[i] > 0)
            neg_nums++;
    return !(neg_nums % 2);
}

int GetFirstNegIdx(int *sig_flag, int start_idx, int end_idx)
{
    for (int i = start_idx; i <= end_idx; i++)
    {
        if (sig_flag[i] > 0)
            return i;
    }
    //return start_idx;
}

int GetLastNegIdx(int *sig_flag, int start_idx, int end_idx)
{
    for (int i = end_idx; i >= start_idx; i--)
    {
        if (sig_flag[i] > 0)
            return i;
    }
}

int maxProduct(int* nums, int numsSize)
{
    /* 记录数组中元素符号，其中负数标记为1, 正数标记为-1,0为0 */
    int sig_flag[numsSize];
    int zero_nums = 0;  // 记录0的个数

    for (int i = 0; i < numsSize; i++)
    {
        if (nums[i] > 0)
            sig_flag[i] = -1;
        else if (nums[i] < 0)
            sig_flag[i] = 1;
        else 
        {
            sig_flag[i] = 0;
            zero_nums++;
        }
    }

    /* 确定各个区间的起始位置 */
    range *range_list_head = NULL;
    int need_creat_range = 1;
    range *new_range = NULL;
    for (int i = 0; i < numsSize; i++)  // 一定要注意区间位置划分的准确性，关系较大
    {
        if (sig_flag[i] != 0)
        {
            if (need_creat_range)  // 第一次进入非0区，需要创建一个区间范围
            {
                new_range = CreateRange();
                new_range->start_idx = i;
                need_creat_range = 0;
            }
            if (i + 1 < numsSize) // 判断是否将离开非0区
            {
                if (sig_flag[i+1] == 0)
                {
                    new_range->end_idx = i;
                    need_creat_range = 1;
                    new_range->next = range_list_head;
                    range_list_head = new_range;
                }
            }
            else
            {
                new_range->end_idx = numsSize - 1;
                new_range->next = range_list_head;
                range_list_head = new_range;
            }
        }
    }

    /* 对每个区间确定最大乘积 */
    int max_mul_res = zero_nums > 0 ? 0:nums[0];
    int current_mul_res;
    range *current_range = NULL;
    while (range_list_head != NULL)
    {
        current_range = range_list_head;
        current_mul_res = 1;
        if (IsEvenNeg(sig_flag, current_range->start_idx, current_range->end_idx))  // 区间内偶数个负数，则直接计算乘积
        {
            for (int i = current_range->start_idx; i <= current_range->end_idx; i++)
                current_mul_res *= nums[i];
            if (current_mul_res > max_mul_res)
                max_mul_res = current_mul_res;
        }
        else  // 区间内含有奇数个负数，需考虑两种情况
        {
            // 第一种情况，将第一个负数去除
            int temp_start = GetFirstNegIdx(sig_flag, current_range->start_idx, current_range->end_idx);
            if (temp_start < current_range->end_idx)
            {
                for (int i = temp_start+1; i <= current_range->end_idx; i++)
                    current_mul_res *= nums[i];
                if (current_mul_res > max_mul_res)
                    max_mul_res = current_mul_res;
            }
            
            
            current_mul_res = 1;
            // 考虑第二种情况，将最后一个负数去除
            int temp_end = GetLastNegIdx(sig_flag, current_range->start_idx, current_range->end_idx);
            if (temp_end > current_range->start_idx)
            {
                for (int i = current_range->start_idx; i <= temp_end-1; i++)
                    current_mul_res *= nums[i];
                if (current_mul_res > max_mul_res)
                    max_mul_res = current_mul_res;
            }
            
        }
        range_list_head = range_list_head->next;
    }
    return max_mul_res;
}