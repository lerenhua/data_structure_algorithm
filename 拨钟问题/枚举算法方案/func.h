#ifndef _FUNC_H
#define _FUNC_H
#define OPTION_LENGTH 9

extern int option_map[OPTION_LENGTH][OPTION_LENGTH];

/* 
  将输入保存至给定的数组
  args: state --- int数组
  return： 如果输入保存成功，则返回0;反之，出问题返回-1
 */
int GetInput(int *state);

/*
  将数组中元素进行累加
  args： option_times  int数组
  return： 如果累加成功则返回累加后的元素的值，该值大于等于0;反之，出现问题返回-1
 */
int CalCount(int *option_times, int length);

/* 
  根据给定的移动选项，对时钟状态进行变化
  args: state --- int数组，表示时钟状态
  args： option_times --- int数组，表示移动选项的记录
  return: 成功返回0,反之返回-1
 */
int MoveClock(int *state, int *option_times, int length);

/* 
  检查时钟状态是否都为12点
  args： state --- int数组，时钟状态
  return： 时钟状态都为12点则返回1, 反之返回0
 */
int AllTwelve(int *state, int length);


/* 
  将最后移动操作结果以规定格式输出
  args： option_times --- int数组，表示移动操作记录
  return： 输出成功返回0,反之返回-1
 */
int PrintResult(int *option_times, int length);

#endif