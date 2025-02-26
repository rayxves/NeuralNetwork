#include <iostream>
#include "Matrix.h"
#include <vector>

Matrix::Matrix(int rows, int cols)
{
    this->rows = rows;
    this->cols = cols;

    data = new double *[rows];
    for (int i = 0; i < rows; i++)
    {
        data[i] = new double[cols]{0};
    }
}

Matrix::~Matrix()
{
    for (int i = 0; i < rows; i++)
    {
        delete[] data[i];
    }
    delete[] data;
}

Matrix Matrix::sum(const Matrix &matrix_A, const Matrix &matrix_B)
{
    Matrix result(matrix_A.rows, matrix_A.cols);

    for (int i = 0; i < matrix_A.rows; i++)
    {
        for (int j = 0; j < matrix_A.cols; j++)
        {
            result.data[i][j] = matrix_A.data[i][j] + matrix_B.data[i][j];
        }
    }

    return result;
}

Matrix Matrix::subtraction(const Matrix &matrix_A, const Matrix &matrix_B)
{
    Matrix result(matrix_A.rows, matrix_A.cols);

    for (int i = 0; i < matrix_A.rows; i++)
    {
        for (int j = 0; j < matrix_A.cols; j++)
        {
            result.data[i][j] = matrix_A.data[i][j] - matrix_B.data[i][j];
        }
    }

    return result;
}

Matrix Matrix::multiply_by_scale(const Matrix &matrix, int scale)
{
    Matrix result(matrix.rows, matrix.cols);

    for (int i = 0; i < matrix.rows; i++)
    {
        for (int j = 0; j < matrix.cols; j++)
        {
            result.data[i][j] = matrix.data[i][j] * scale;
        }
    }

    return result;
}

Matrix Matrix::multiply(const Matrix &matrix_A, const Matrix &matrix_B)
{
    if (matrix_A.cols != matrix_B.rows)
    {
        throw std::invalid_argument("Matrices cannot be multiplied");
    }

    Matrix result(matrix_A.rows, matrix_B.cols);

    for (int i = 0; i < result.rows; i++)
    {
        for (int j = 0; j < result.cols; j++)
        {
            for (int k = 0; k < matrix_A.cols; k++)
            {
                result.data[i][j] += matrix_A.data[i][k] * matrix_B.data[k][j];
            }
        }
    }

    return result;
}

Matrix Matrix::hadamard(const Matrix &matrix_A, const Matrix &matrix_B)
{
    Matrix result(matrix_A.rows, matrix_A.cols);

    for (int i = 0; i < matrix_A.rows; i++)
    {
        for (int j = 0; j < matrix_A.cols; j++)
        {
            result.data[i][j] = matrix_A.data[i][j] * matrix_B.data[i][j];
        }
    }

    return result;
}

Matrix Matrix::transpose(const Matrix &matrix)
{
    Matrix result(matrix.cols, matrix.rows);
    for (int i = 0; i < matrix.rows; i++)
    {
        for (int j = 0; j < matrix.cols; j++)
        {
            result.data[j][i] = matrix.data[i][j];
        }
    }
    return result;
}

void Matrix::randomize()
{
    for (int i = 0; i < rows; i++)
        for (int j = 0; j < cols; j++)
            data[i][j] = ((double)rand() / RAND_MAX) * 2 - 1;
}

Matrix Matrix::apply_function(double (*func)(double))
{
    Matrix result(rows, cols);
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            result.data[i][j] = func(data[i][j]);
        }
    }
    return result;
}

Matrix Matrix::array_to_matrix(std::vector<double> arr)
{
    auto new_arr = Matrix(arr.size(), 1);
    for (size_t i = 0; i < arr.size(); i++)
    {
        new_arr.data[i][0] = arr[i];
    }
    return new_arr;
}

std::vector<double> Matrix::matrix_to_array(Matrix &matrix)
{
    std::vector<double> arr;
    for (int i = 0; i < matrix.rows; i++)
    {
        for (int j = 0; j < matrix.cols; j++)
        {
            arr.push_back(matrix.data[i][j]);
        }
    }
    return arr;
}
void Matrix::print(const Matrix &matrix)
{
    for (int i = 0; i < matrix.rows; i++)
    {
        for (int j = 0; j < matrix.cols; j++)
        {
            std::cout << matrix.data[i][j] << " ";
        }
        std::cout << std::endl;
    }
}