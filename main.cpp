#include <iostream>
#include <vector>
#include "NeuralNetwork.h"
#include "Matrix.h"

int main() {
    std::vector<double> input_neurons = {1.0, 1.0};  
    std::vector<double> hidden_neurons = {0.0, 0.0, 0.0};  
    std::vector<double> output_neurons = {0.0}; 

    NeuralNetwork nn(input_neurons, hidden_neurons, output_neurons);

    std::vector<std::vector<double>> inputs = {
        {1.0, 1.0},
        {1.0, 0.0},
        {0.0, 1.0},
        {0.0, 0.0}
    };

    std::vector<std::vector<double>> outputs = {
        {0.0},
        {1.0},
        {1.0},
        {0.0}
    };

    bool train = true;

    
    while (train) {
        for (int i = 0; i < 100; ++i) {  
            int index = rand() % 4; 
            nn.train(outputs[index], inputs[index]);
        }

        std::vector<double> prediction_00 = nn.predict({0.0, 0.0});
        std::vector<double> prediction_10 = nn.predict({1.0, 0.0});

        std::cout << "Prediction for [0, 0]: " << prediction_00[0] << std::endl;
        std::cout << "Prediction for [1, 0]: " << prediction_10[0] << std::endl;

        if (prediction_00[0] < 0.1 && prediction_10[0] > 0.9) {
            train = false;
            std::cout << "Training completed!" << std::endl;
        }
  
    }

    return 0;
}
