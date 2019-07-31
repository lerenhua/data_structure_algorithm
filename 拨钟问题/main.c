#include <stdio.h>
#define op_ids 9
#define clock_ids 9

int op_clock_map[op_ids][clock_ids] = {
    {1, 1, 0, 1, 1, 0, 0, 0, 0},
    {1, 1, 1, 0, 0, 0, 0, 0, 0},
    {0, 1, 1, 0, 1, 1, 0, 0, 0},
    {1, 0, 0, 1, 0, 0, 1, 0, 0},
    {0, 1, 0, 1, 1, 1, 0, 1, 0},
    {0, 0, 1, 0, 0, 1, 0, 0, 1},
    {0, 0, 0, 1, 1, 0, 1, 1, 0},
    {0, 0, 0, 0, 0, 0, 1, 1, 1},
    {0, 0, 0, 0, 1, 1, 0, 1, 1},    
};
// 全局最小操作次数，用于筛选出最少操作的序列
int min_count = 3 * op_ids +1;

int temp_op_series[op_ids];
int result_series[op_ids];

int SearchSolution(int * clock_state, int move_id, int current_count)
{
    if (current_count > min_count)
        return 0;
    if (move_id == op_ids) // 遍历完所有移动操作时检查此操作序列可否满足要求
    {
        int i;
        if (temp_op_series[3] == 1 && temp_op_series[4] == 1 && temp_op_series[7] == 1)
        {
            printf("\n");
        }
        for (i = 0; i < clock_ids; i++)
        {
            int sum = clock_state[i];
            for (int j = 0; j < op_ids; j++)
                sum += op_clock_map[j][i] * temp_op_series[j];
            if ((sum % 4) != 0)
                break;
        }
        if (i == op_ids)
        {
            if (current_count < min_count) // 如果有更优的解
            {
                min_count = current_count;
                for (int j = 0; j < op_ids; j++)
                {
                    result_series[j] = temp_op_series[j];
                }
                return 0;
            }
        }
        return 0;
    }

    int next_line = move_id + 1; 
    for (int i = 0; i < 4; i++)
    {
        temp_op_series[move_id] = i;
        SearchSolution(clock_state, next_line, current_count + temp_op_series[move_id]);
    }
}
void PrintResult(int * result)
{
    for (int i = 0; i < op_ids; i++)
        //if (result[i] != 0)
            printf("%d ", result[i]);
    printf("\n");
}

int main()
{
    int clock_state[clock_ids];
    // 处理输入
    for (int i = 0; i < 3; i++)
    {
        scanf("%d %d %d", &clock_state[3 * i + 0], &clock_state[3*i + 1], &clock_state[3*i + 2]);
    }
    PrintResult(clock_state);

    SearchSolution(clock_state, 0, 0);

    //Sort(result_series);
    PrintResult(result_series);
}