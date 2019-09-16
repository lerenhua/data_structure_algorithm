#include <stdlib.h>
#include "matlib.h"

matrix I_matrix = {};
matrix *I_mat_ptr = &I_matrix;

/* ================================================================== *
 *                          InvMatrix                                 *
 * ================================================================== */
matrix *InvMatrix(matrix *m)
{
    /*
      求逆矩阵
      利用初等行变换求解矩阵的逆
     */

    // 与单位矩阵沿着列方向构建分块矩阵
    matrix *concat_matrix = ConcatMatrix(m, I_mat_ptr, 1, FLOAT_32);
    
    // 求逆算法主体
    // 沿着列方向，对指定行上元素化1,该列上其余元素化0
    int col = m->col;
    int row = m->row;
    //float temp = 0.0;
    for (int i = 0; i < col; i++)
    {
        // concat_matrix[i , i] 化1
        float temp = ((float **)concat_matrix->data) [i][i];
        ConstMulRow(concat_matrix, i, (1/(temp)));

        // 对i列其他元素化0
        for (int j = 0; j < row; j++)
        {
            if (j != i)
            {
                temp  = ((float **)concat_matrix->data) [j][i];
                ConstMulAddRow(concat_matrix, j, i, -(temp));
            }
        }
    }

    // 分离出逆矩阵
    return NULL;
}