

int maxProduct(int *nums, int numSize)
{
    int max_mul_res = -(1 << 30);  // 最大乘积, 此处初始化时应当赋值最小的负数

    /* 使用枚举会超时 */
    for (int i = 0; i < numSize; i++)
    {
        int current_mul_res = 1;  // 当前最大乘积
        for (int j = i; j < numSize; j++)
        {
            current_mul_res *= nums[j];
            if (current_mul_res > max_mul_res)
                max_mul_res = current_mul_res;
        }
    }
    return max_mul_res;
}