#include "NeuralNetwork.h"
#include <iostream>
#include <vector>
#include <cmath>

int main()
{

    // std::vector<double> input_neurons = {0.5, 0.3};
    // std::vector<double> hidden_neurons = {0.0, 0.0};
    // std::vector<double> output_neurons = {0.0};

    // NeuralNetwork nn(input_neurons, hidden_neurons, output_neurons);

    // std::vector<double> target = {0.9};
    // nn.train(target, input_neurons);

    // std::vector<double> output = nn.predict(input_neurons);

    // std::cout << "Previsão da rede neural: " << output[0] << std::endl;

    Matrix m(3, 3);
    m.randomize();
     for (int i = 0; i < m.rows; i++)
    {
        for (int j = 0; j < m.cols; j++)
        {
            std::cout << m.data[i][j] << std::endl;
        }
        std::cout << "fim da matrix m";
    }
    Matrix result = m.apply_function(sqrt); // Aplica raiz quadrada a todos os elementos
    
    for (int i = 0; i < result.rows; i++)
    {
        for (int j = 0; j < result.cols; j++)
        {
            std::cout << result.data[i][j] << std::endl;
        }
        
    }
    
    return 0;
}
