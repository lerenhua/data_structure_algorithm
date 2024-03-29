#include <stdio.h>
#include "specific_clock.h"



int GetClcokState(int *clock_state_ptr)
{
    char ch;
    for (int i = 0; i < 31; i++)
    {
        ch = getchar();
        if (ch != '\n')
        {
            if (ch == '0')
                *clock_state_ptr = (*clock_state_ptr) << 1;
            else
                *clock_state_ptr = ((*clock_state_ptr) << 1) | 1;
        }
        else
            return i;
    }
}

/* int GetBit(int bin_num, int pos)
{
    return ((bin_num >> pos) & 1);
}*/

/* int FlipBit(int bit_num, int pos)
{
    return (bit_num ^ (1 << pos));
}*/




int CalCounts(int solution, int len)
{
    int count = 0;
    for (int i = 0; i < len; i++)
    {
        if ((solution >> i) & 1)
            count++;
    }
    return count;
}