#ifndef FUNC_H
#define FUNC_H

/* 从输入读取密码锁状态， 返回长度 */
int GetStateFromInput(char * state_str);

/* 位翻转 */
int FlipBit(char *state_str , int pos, int length);


#endif