#include <stdio.h>
#include <stdlib.h>

/* 测试IsEvenNeg函数 */
int IsEvenNeg(int *sig_flag, int start_idx, int end_idx);

/* 测试GetFirstNegIdx函数 */
int GetFirstNegIdx(int *sig_flag, int start_idx, int end_idx);

/* 测试GetLastNegIdx函数 */
int GetLastNegIdx(int *sig_flag, int start_idx, int end_idx);
/*
int main()
{
    int sig[7] = {1, -1, 0, 1, 0, 0, -1};
    if (IsEvenNeg(sig, 0, 6))
        printf("The function is correct!\n");
    else
        printf("The function is Error!\n");
    
    printf("the first negative number index is %d", GetFirstNegIdx(sig, 0, 6));
    printf("the last negative number index is %d", GetLastNegIdx(sig, 0, 6));
    return 0;
}*/

int maxProduct(int* nums, int numsSize);

int main()
{
    int nums[22] = {-5, 2, 4, 6, -1, 1, 1, -1, 2, 5, -1, 1, 1, 1, -1, -1, -1, 0, -1, 0, -1, 0};
    int res = maxProduct(nums, 22);
    printf("the max multiply is %d\n", res);
    return 0;
}
