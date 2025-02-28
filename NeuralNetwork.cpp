#include "NeuralNetwork.h"
#include "Matrix.h"
#include <cmath>
#include <iostream>

NeuralNetwork::NeuralNetwork(std::vector<double> input_neurons, std::vector<double> hidden_neurons, std::vector<double> output_neurons)
    : input_neurons(input_neurons), hidden_neurons(hidden_neurons), output_neurons(output_neurons), weights_ih(hidden_neurons.size(), input_neurons.size()), weights_ho(output_neurons.size(), hidden_neurons.size()), bias_h(hidden_neurons.size(), 1), bias_o(output_neurons.size(), 1), input_matrix(Matrix::array_to_matrix(input_neurons)), hidden_matrix(Matrix::array_to_matrix(hidden_neurons)), output_matrix(Matrix::array_to_matrix(output_neurons))
{
    weights_ih.randomize();
    weights_ho.randomize();
    bias_h.randomize();
    bias_o.randomize();
    learning_rate = 0.01;
}

NeuralNetwork::~NeuralNetwork() {}



double NeuralNetwork::sigmoid(double x)
{
    return 1 / (1 + exp(-x));
}

double NeuralNetwork::sigmoid_derivative(double x)
{
    return x * (1 - x);
}

Matrix NeuralNetwork::error_function(Matrix target, Matrix output)
{
    auto error = Matrix::subtraction(target, output);
    return error;
}

void NeuralNetwork::train(std::vector<double> target, std::vector<double> input)
{
    Matrix input_to_matrix = Matrix::array_to_matrix(input);
    auto hidden_z = Matrix::multiply(weights_ih, input_to_matrix);
    hidden_z = Matrix::sum(hidden_z, bias_h);
    hidden_z.apply_function(sigmoid);

    auto output_z = Matrix::multiply(weights_ho, hidden_z);
    output_z = Matrix::sum(output_z, bias_o);
    output_z.apply_function(sigmoid);

    Matrix target_arr = Matrix::array_to_matrix(target);
    auto output_error = error_function(target_arr, output_z);

    auto derivate_output = Matrix::apply_function_static(output_z, sigmoid_derivative);
    auto hidden_transpose = Matrix::transpose(hidden_z);

    auto gradient = Matrix::hadamard(derivate_output, output_error);
    gradient = Matrix::multiply_by_scale(gradient, learning_rate);

    bias_o = Matrix::sum(bias_o, gradient);
    auto weights_ho_deltas = Matrix::multiply(gradient, hidden_transpose);
    weights_ho = Matrix::sum(weights_ho, weights_ho_deltas);

    auto weights_ho_transpose = Matrix::transpose(weights_ho);
    auto hidden_error = Matrix::multiply(weights_ho_transpose, output_error);

    auto derivate_hidden = Matrix::apply_function_static(hidden_z, sigmoid_derivative);
    auto input_transpose = Matrix::transpose(input_to_matrix);

    auto gradient_h = Matrix::hadamard(derivate_hidden, hidden_error);
    gradient_h = Matrix::multiply_by_scale(gradient_h, learning_rate);

    bias_h = Matrix::sum(bias_h, gradient_h);

    auto weights_ih_deltas = Matrix::multiply(gradient_h, input_transpose);
    weights_ih = Matrix::sum(weights_ih, weights_ih_deltas);
}

std::vector<double> NeuralNetwork::predict(std::vector<double> arr)
{
    auto input = Matrix::array_to_matrix(arr);
    auto hidden = Matrix::multiply(weights_ih, input);
    hidden = Matrix::sum(hidden, bias_h);
    hidden.apply_function(sigmoid);

    auto output = Matrix::multiply(weights_ho, hidden);
    output = Matrix::sum(output, bias_o);
    output.apply_function(sigmoid);

    auto final_output = output.matrix_to_array();
    return final_output;
}
