#include <stdio.h>
#include "func.h"

int option_map[OPTION_LENGTH][OPTION_LENGTH] = {
            {1, 1, 0, 1, 1, 0, 0, 0, 0},
            {1, 1, 1, 0, 0, 0, 0, 0, 0},
            {0, 1, 1, 0, 1, 1, 0, 0, 0},
            {1, 0, 0, 1, 0, 0, 1, 0, 0},
            {0, 1, 0, 1, 1, 1, 0, 1, 0},
            {0, 0, 1, 0, 0, 1, 0, 0, 1},
            {0, 0, 0, 1, 1, 0, 1, 1, 0},
            {0, 0, 0, 0, 0, 0, 1, 1, 1},
            {0, 0, 0, 0, 1, 1, 0, 1, 1}
};

int main()
{
    int option;

    scanf("%d", &option);
    switch (option)
    {
    case 1: 
        {
            /* 
               测试GetInput函数：将 3 3 0
                                  2 2 2
                                  2 1 2 类似数据读入，存储至int数组
             */
            int state[9];
            if (!GetInput(state))
            {
                for (int i = 0; i < 9; i++)
                    printf("%d\t", state[i]);
                printf("\n");
            }
            else
                printf("Error Happen!\n");
            break;
        }
    case 2:
        {
            /* 
              测试CalCount函数
             */
            #define LENGTH 5
            int counts[LENGTH] = {1, 2, 3, 4, 5};
            int sum;
            if ((sum = CalCount(counts, LENGTH)) > 0)
                printf("The sum is %d\n", sum);
            else
                printf("Error Happen!\n");
            break;
        }
    case 3:
        {

            /* 
              测试MoveClock函数
             
            int option2clock_maps[3][3] = {
                {1, 0, 0},
                {0, 1, 0},
                {0, 0, 1}
            };
            int clock1_state[3] = {0, 3, 4};
            int clock2_state[3] = {1, 3, 0};
            int options1[3] = {2, 4, 5};
            int options2[3] = {0, 2, 4};

            // 第一种组合
            if (!MoveClock(clock1_state, options1, option2clock_maps))
            {
                for (int i = 0; i < 3; i++)
                    printf("%d\t", clock1_state[i]);
                printf("\n");            
            }
            else
                printf("the combination of clock1_state and options1 is error!\n");

            // 第二种组合
            if (!MoveClock(clock1_state, options2, option2clock_maps))
            {
                for (int i = 0; i < 3; i++)
                    printf("%d\t", clock1_state[i]);
                printf("\n");            
            }
            else
                printf("the combination of clock1_state and options2 is error!\n");

            // 第三种组合
            if (!MoveClock(clock2_state, options1, option2clock_maps))
            {
                for (int i = 0; i < 3; i++)
                    printf("%d\t", clock2_state[i]);
                printf("\n");            
            }
            else
                printf("the combination of clock2_state and options1 is error!\n");

            // 第四种组合
            if (!MoveClock(clock2_state, options2, option2clock_maps))
                {
                    for (int i = 0; i < 3; i++)
                        printf("%d\t", clock2_state[i]);
                    printf("\n");            
                }
                else
                    printf("the combination of clock2_state and options2 is error!\n");
            */}
    case 4:
        {
            /* 
              测试AllTwlve函数
             */
            int state1[3] = {3, 0, 1};
            int state2[3] = {0, 0, 0};

            // 第一种情况
            if (AllTwelve(state1, 3))
                printf("The clock is all twelve\n");
            else 
                printf("The clock is not all twelve\n");

            // 第二种情况
            if (AllTwelve(state2, 3))
                printf("The clock is all twelve\n");
            else 
                printf("The clock is not all twelve\n");
        }
    default:
        break;
    }
}