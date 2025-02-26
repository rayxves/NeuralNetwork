#ifndef MATRIX_H
#define MATRIX_H

#include <vector>

class Matrix
{
public:
    double **data;
    int rows;
    int cols;

    Matrix(int rows, int cols);
    ~Matrix();

    static Matrix sum(const Matrix &matrix_A, const Matrix &matrix_B);
    static Matrix subtraction(const Matrix &matrix_A, const Matrix &matrix_B);
    static Matrix multiply_by_scale(const Matrix &matrix, int scale);
    static Matrix multiply(const Matrix &matrix_A, const Matrix &matrix_B);
    static Matrix hadamard(const Matrix &matrix_A, const Matrix &matrix_B);
    static Matrix transpose(const Matrix &matrix);
    void randomize();
     Matrix apply_function(double (*func)(double));
    static Matrix array_to_matrix(std::vector<double> arr);
    static std::vector<double> matrix_to_array(Matrix &matrix);
    void print(const Matrix &matrix);
};

#endif