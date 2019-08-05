#ifndef __CLOCK_H
#define __CLOCK_H

/* 从输入中读取密码锁状态 */
int GetClcokState(int *);

/* 获取指定二进制位处的值 */
int GetBit(int, int);

/* 在指定二进制位处设置值 */
int FlipBit(int, int);

int FlipState(int, int, int);

/* 计算所给数二进制 1 的个数 */
int CalCounts(int, int);

#endif