#include "algebra.h"
#include <stdio.h>
#include <math.h>

Matrix create_matrix(int row, int col)
{
    Matrix m;
    m.rows = row;
    m.cols = col;
    return m;
}

Matrix add_matrix(Matrix a, Matrix b)
{
    // ToDo
    Matrix c;
    int i, j;
    if (a.rows == b.rows && a.cols == b.cols)
    {
        c.rows = a.rows;
        c.cols = a.cols;
        for (i = 0; i < a.rows; i++)
        {
            for (j = 0; j < b.rows; j++)
            {
                c.data[i][j] = a.data[i][j] + b.data[i][j];
            }
        }
        return c;
    }
    else
    {
        printf("Error: Matrix a and b must have the same rows and cols.\n");
        return create_matrix(0, 0);
    }
}

Matrix sub_matrix(Matrix a, Matrix b)
{
    // ToDo
    Matrix c;
    int i, j;
    if (a.rows == b.rows && a.cols == b.cols)
    {
        c.rows = a.rows;
        c.cols = a.cols;
        for (i = 0; i < a.rows; i++)
        {
            for (j = 0; j < b.rows; j++)
            {
                c.data[i][j] = a.data[i][j] - b.data[i][j];
            }
        }
        return c;
    }
    else
    {
        printf("Error: Matrix a and b must have the same rows and cols.\n");
        return create_matrix(0, 0);
    }
}

Matrix mul_matrix(Matrix a, Matrix b)
{
    // ToDo
    int i, j, k;
    Matrix c;
    if (a.cols == b.rows)
    {
        c.rows = a.rows;
        c.cols = b.cols;
        for (i = 0; i < a.cols; i++)
        {
            for (j = 0; j < a.cols; j++)
            {
                c.data[i][j] = 0;
                for (k = 0; k < a.cols; k++)
                {
                    c.data[i][j] = c.data[i][j] + a.data[i][k] * b.data[k][j];
                }
            }
        }
        return c;
    }
    else
    {
        printf("Error: The number of cols of matrix a must be equal to the number of rows of matrix b.\n");
        return create_matrix(0, 0);
    }
}

Matrix scale_matrix(Matrix a, double k)
{
    // ToDo
    if (a.rows > 0 && a.cols > 0)
    {
        Matrix c;
        int i, j;
        c.rows = a.rows;
        c.cols = a.cols;
        for (i = 0; i < a.rows; i++)
        {
            for (j = 0; j < a.cols; j++)
            {
                c.data[i][j] = k * a.data[i][j];
            }
        }
        return c;
    }
    else
        return create_matrix(0, 0);
}

Matrix transpose_matrix(Matrix a)
{
    // ToDo
    Matrix c;
    int i, j;
    if (a.rows > 0 && a.cols > 0)
    {
        c.rows = a.cols;
        c.cols = a.rows;
        for (i = 0; i < a.rows; i++)
        {
            for (j = 0; j < a.cols; j++)
            {
                c.data[j][i] = a.data[i][j];
            }
        }
        return c;
    }
    else
        return create_matrix(0, 0);
}

double det_matrix(Matrix a)
{
    // ToDo
    int i, j, n, k;
    double num = 0;
    Matrix c;
    if (a.rows == a.cols)
    {
        n = a.rows;
        if (n > 2)
        {
            for (i = 0; i < a.cols; i++)
            {
                c.rows = a.rows - 1;
                c.cols = a.cols - 1;
                for (j = 0; j < c.rows; j++)
                {
                    for (k = 0; k < c.cols; k++)
                    {
                        if (k >= i)
                            c.data[j][k] = a.data[j + 1][k + 1];
                        else
                            c.data[j][k] = a.data[j + 1][k];
                    }
                }
                num = num + ((2 + i) % 2 ? -1 : 1) * det_matrix(c) * a.data[0][i];
            }
            return num;
        }
        else if (n == 2)
        {
            num = a.data[0][0] * a.data[1][1] - a.data[0][1] * a.data[1][0];
            return num;
        }
        else if (n == 1)
        {
            num = a.data[0][0];
            return num;
        }
    }
    else
    {
        printf("Error:atrix must be a square matrix.\n");
        return 0;
    }
}

Matrix inv_matrix(Matrix a)
{
    // ToDo
    if (a.rows == a.cols && det_matrix(a) != 0)
    {
        Matrix c, d, e;
        int i, j, k, n;
        e.rows = e.cols = a.rows;
        d.rows = d.cols = c.rows = c.cols = a.rows - 1;
        for (i = 0; i < a.rows; i++)
        {
            for (j = 0; j < a.cols; j++)
            {
                for (k = 0; k < c.rows; k++)
                {
                    for (n = 0; n < c.cols; n++)
                    {
                        if (k >= j && n >= i)
                            c.data[k][n] = a.data[k + 1][n + 1];
                        else if (k < j && n >= i)
                            c.data[k][n] = a.data[k][n + 1];
                        else if (k >= j && n < i)
                            c.data[k][n] = a.data[k + 1][n];
                        else
                            c.data[k][n] = a.data[k][n];
                    }
                }
                d.data[i][j] = ((i + j + 2) % 2 ? -1 : 1) * det_matrix(c);
            }
        }
        for (i = 0; i < e.rows; i++)
        {
            for (j = 0; j < e.cols; j++)
            {
                e.data[i][j] = 1 / det_matrix(a) * d.data[i][j];
            }
        }
        return e;
    }
    else if (a.rows != a.cols)
    {
        printf("Error: The matrix must be a square matrix.\n");
        return create_matrix(0, 0);
    }
    else if (det_matrix(a) == 0)
    {
        printf("Error: The matrix is singular.\n");
        return create_matrix(0, 0);
    }
}

int rank_matrix(Matrix a)
{
    // ToDo
    int i, j, rank, k, temp, n;
    if (a.rows <= a.cols)
        rank = a.rows;
    else
        rank = a.cols;
    n = rank;
    for (i = 0; i < n; i++)
    {
        if (a.data[i][i] == 0)
        {
            for (j = i + 1; j < a.rows; j++)
            {
                if (a.data[j][i] != 0)
                {
                    for (k = 0; k < a.cols; k++)
                    {
                        temp = a.data[i][k];
                        a.data[i][k] = a.data[j][k];
                        a.data[j][k] = temp;
                    }
                    break;
                }
            }
            if (j == a.rows)
            {
                rank = rank - 1;
                continue;
            }
        }
        for (j = i + 1; j < a.rows; j++)
        {
            for (k = 0; k < a.cols; k++)
            {
                a.data[j][k] = a.data[j][k] - a.data[j][k] / a.data[i][k] * a.data[i][k];
            }
        }
    }
    return rank;
    return 0;
}

double trace_matrix(Matrix a)
{
    // ToDo
    double num = 0;
    int i;
    if (a.rows == a.cols)
    {
        for (i = 0; i < a.rows; i++)
            num = num + a.data[i][i];
        return num;
    }
    else
    {
        printf("Error:atrix must be a square matrix.\n");
        return 0;
    }
}

void print_matrix(Matrix a)
{
    for (int i = 0; i < a.rows; i++)
    {
        for (int j = 0; j < a.cols; j++)
        {
            // 按行打印，每个元素占8个字符的宽度，小数点后保留2位，左对齐
            printf("%-8.2f", a.data[i][j]);
        }
        printf("\n");
    }
}