#include <vector>
#include "Matrix.h"

class NeuralNetwork
{
private:
    std::vector<double> input_neurons, output_neurons, hidden_neurons;
    Matrix weights_ih, weights_ho, bias_h, bias_o, input_matrix, output_matrix, hidden_matrix;
    double learning_rate = 0.01;

public:
    NeuralNetwork(std::vector<double> input_neurons, std::vector<double> hidden_neurons, std::vector<double> output_neurons);
    ~NeuralNetwork();

    static double sigmoid(double x);
    static double sigmoid_derivative(double x);

    Matrix error_function(Matrix target, Matrix output);
    void train(std::vector<double> target, std::vector<double> input);

    std::vector<double> predict(std::vector<double> input);
};
