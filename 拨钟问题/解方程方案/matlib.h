/*
  用于矩阵相关操作的库，定义了矩阵相关数据结构，提供函数原型
 */
#ifndef _MATLIB_H
#define _MATLIB_H

/* 用于声明矩阵数据类型的宏 */
#define INT_32 1
#define FLOAT_32 2

/* 定义了矩阵的数据结构 */
typedef struct Matrix 
{
    void **data;  // 指向二维数组的指针
    int row;  // 矩阵行数
    int col;  // 矩阵列数
    int dtype;  // 指定矩阵数据类型，使用上述声明的宏
} matrix;

/* 用于提供函数原型 */
#define _PROTOTYPE(func, args) func args

_PROTOTYPE(matrix *InvMatrix, (matrix *m));
_PROTOTYPE(matrix *ConcatMatrix, (matrix *m1, matrix *m2, int axis, int dtype));
_PROTOTYPE(matrix *SepMatrix, (matrix *m, matrix *sep_m1, matrix *sep_m2, int axis, int index));

_PROTOTYPE(int ExchangeRow, (matrix *m, int i, int j));
_PROTOTYPE(int ConstMulRow, (matrix *m, int i, int k));
_PROTOTYPE(int ConstMulAddRow, (matrix *m, int i, int j, float k));

#endif