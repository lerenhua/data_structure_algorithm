
int maxProduct(int* nums, int numsSize)
{
    int current_mul_res  = 1;
    int max_mul_res = nums[0];
    for (int i = 0; i < numsSize; i++)
    {
        current_mul_res *= nums[i];
        if (current_mul_res > max_mul_res)
            max_mul_res = current_mul_res;
        if (current_mul_res == 0)
            current_mul_res++;
    }
    return max_mul_res;
}