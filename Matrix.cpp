#include <iostream>
#include "Matrix.h"
#include <stdexcept>
#include <vector>

Matrix::Matrix(int rows, int cols) : rows(rows), cols(cols) {
    data = new double*[rows];
    for (int i = 0; i < rows; i++) {
        data[i] = new double[cols]();
    }
}

Matrix::~Matrix() {
    for (int i = 0; i < rows; i++) {
        delete[] data[i];
    }
    delete[] data;
}

Matrix::Matrix(const Matrix& other) : rows(other.rows), cols(other.cols) {
    data = new double*[rows];
    for (int i = 0; i < rows; i++) {
        data[i] = new double[cols];
        for (int j = 0; j < cols; j++) {
            data[i][j] = other.data[i][j];
        }
    }
}

Matrix& Matrix::operator=(const Matrix& other) {
    if (this == &other) return *this;

    for (int i = 0; i < rows; i++) {
        delete[] data[i];
    }
    delete[] data;

    rows = other.rows;
    cols = other.cols;
    
    data = new double*[rows];
    for (int i = 0; i < rows; i++) {
        data[i] = new double[cols];
        for (int j = 0; j < cols; j++) {
            data[i][j] = other.data[i][j];
        }
    }
    return *this;
}

Matrix Matrix::sum(const Matrix& matrix_A, const Matrix& matrix_B) {
    if (matrix_A.rows != matrix_B.rows || matrix_A.cols != matrix_B.cols) {
        throw std::invalid_argument("As matrizes devem ter as mesmas dimensões para soma!");
    }

    Matrix result(matrix_A.rows, matrix_A.cols);
    for (int i = 0; i < matrix_A.rows; i++) {
        for (int j = 0; j < matrix_A.cols; j++) {
            result.data[i][j] = matrix_A.data[i][j] + matrix_B.data[i][j];
        }
    }
    return result;
}

Matrix Matrix::subtraction(const Matrix& matrix_A, const Matrix& matrix_B) {
    if (matrix_A.rows != matrix_B.rows || matrix_A.cols != matrix_B.cols) {
        throw std::invalid_argument("As matrizes devem ter as mesmas dimensões para subtração!");
    }

    Matrix result(matrix_A.rows, matrix_A.cols);
    for (int i = 0; i < matrix_A.rows; i++) {
        for (int j = 0; j < matrix_A.cols; j++) {
            result.data[i][j] = matrix_A.data[i][j] - matrix_B.data[i][j];
        }
    }
    return result;
}

Matrix Matrix::multiply_by_scale(const Matrix& matrix, double scale) {
    Matrix result(matrix.rows, matrix.cols);
    for (int i = 0; i < matrix.rows; i++) {
        for (int j = 0; j < matrix.cols; j++) {
            result.data[i][j] = matrix.data[i][j] * scale;
        }
    }
    return result;
}

Matrix Matrix::multiply(const Matrix& matrix_A, const Matrix& matrix_B) {
    if (matrix_A.cols != matrix_B.rows) {
        throw std::invalid_argument("As matrizes não podem ser multiplicadas");
    }

    Matrix result(matrix_A.rows, matrix_B.cols);
    for (int i = 0; i < result.rows; i++) {
        for (int j = 0; j < result.cols; j++) {
            for (int k = 0; k < matrix_A.cols; k++) {
                result.data[i][j] += matrix_A.data[i][k] * matrix_B.data[k][j];
            }
        }
    }
    return result;
}

Matrix Matrix::hadamard(const Matrix& matrix_A, const Matrix& matrix_B) {
    Matrix result(matrix_A.rows, matrix_A.cols);
    for (int i = 0; i < matrix_A.rows; i++) {
        for (int j = 0; j < matrix_A.cols; j++) {
            result.data[i][j] = matrix_A.data[i][j] * matrix_B.data[i][j];
        }
    }
    return result;
}

Matrix Matrix::transpose(const Matrix& matrix) {
    Matrix result(matrix.cols, matrix.rows);
    for (int i = 0; i < matrix.rows; i++) {
        for (int j = 0; j < matrix.cols; j++) {
            result.data[j][i] = matrix.data[i][j];
        }
    }
    return result;
}

void Matrix::randomize() {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            data[i][j] = ((double)rand() / RAND_MAX) * 2 - 1;
        }
    }
}

void Matrix::apply_function(double (*func)(double)) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            data[i][j] = func(data[i][j]);
        }
    }
}

Matrix Matrix::apply_function_static(const Matrix& matrix, double (*func)(double)) {
    Matrix new_matrix(matrix.rows, matrix.cols);
    for (int i = 0; i < matrix.rows; i++) {
        for (int j = 0; j < matrix.cols; j++) {
            new_matrix.data[i][j] = func(matrix.data[i][j]);
        }
    }
    return new_matrix;
}

Matrix Matrix::array_to_matrix(const std::vector<double>& arr) {
    Matrix new_matrix(arr.size(), 1);
    for (size_t i = 0; i < arr.size(); i++) {
        new_matrix.data[i][0] = arr[i];
    }
    return new_matrix;
}

std::vector<double> Matrix::matrix_to_array() const {
    std::vector<double> arr;
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            arr.push_back(data[i][j]);
        }
    }
    return arr;
}

void Matrix::print() const {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            std::cout << data[i][j] << " ";
        }
        std::cout << std::endl;
    }
}
