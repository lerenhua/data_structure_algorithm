#ifndef __CLOCK_H
#define __CLOCK_H

#define GetBit(bin_num, pos) \
    ((bin_num >> pos) & 1)

#define FlipBit(bit_num, pos) \
    (bit_num ^ (1 << pos))

/* 从输入中读取密码锁状态 */
int GetClcokState(int *);

/* 获取指定二进制位处的值 */
//int GetBit(int, int);

/* 在指定二进制位处设置值 */
//int FlipBit(int, int);

//inline int FlipState(int bit_num, int pos, int len);

/* 计算所给数二进制 1 的个数 */
int CalCounts(int, int);

#endif