#ifndef MATRIX_H
#define MATRIX_H

#include <vector>

class Matrix
{
public:
    int rows, cols;
    double **data;

    Matrix(int rows, int cols);
    ~Matrix();

    Matrix(const Matrix &other);
    Matrix &operator=(const Matrix &other);

    static Matrix sum(const Matrix &matrix_A, const Matrix &matrix_B);
    static Matrix subtraction(const Matrix &matrix_A, const Matrix &matrix_B);
    static Matrix multiply_by_scale(const Matrix &matrix, double scale);
    static Matrix multiply(const Matrix &matrix_A, const Matrix &matrix_B);
    static Matrix hadamard(const Matrix &matrix_A, const Matrix &matrix_B);
    static Matrix transpose(const Matrix &matrix);

    void randomize();
    void apply_function(double (*func)(double));
    static Matrix apply_function_static(const Matrix& matrix, double (*func)(double));
    static Matrix array_to_matrix(const std::vector<double> &arr);
    std::vector<double> matrix_to_array() const;
    void print() const;
};

#endif