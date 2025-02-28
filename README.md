# Neural Network in C++

This project implements a simple neural network in C++ to solve basic binary classification tasks. It uses a feed-forward neural network with one hidden layer and backpropagation for training. The goal of this neural network is to predict the XOR function using training data.

---


## Features
- **Feedforward Neural Network:** The network has input, hidden, and output layers.
- **Training Algorithm:** Backpropagation with gradient descent is used to update weights and biases.
- **Activation Function:** Sigmoid activation function is used for both the hidden and output layers.
- **Matrix Operations:** A custom `Matrix` class is implemented for handling matrix operations such as multiplication, addition, subtraction, and transposition.

## Files

- **NeuralNetwork.h:** Contains the neural network class declaration and function prototypes.
- **NeuralNetwork.cpp:** Implements the neural network's constructor, training function, and prediction logic.
- **Matrix.h:** Defines the `Matrix` class for handling basic matrix operations.
- **Matrix.cpp:** Implements matrix operations like multiplication, addition, subtraction, etc.
- **main.cpp:** A simple main function that initializes the neural network and trains it on XOR data.

## How It Works

1. **Network Architecture:** The network consists of an input layer, a hidden layer, and an output layer.
2. **Training:** The training loop randomly selects input-output pairs, computes the output through the network, calculates the error, and adjusts the weights and biases using backpropagation.
3. **Prediction:** Once training is complete, the network makes predictions on new inputs.


## Compilation and Usage

To compile and run this project, you can use the following commands:

1. **Compile the project:**
   ```bash
   g++ -g -o main main.cpp NeuralNetwork.cpp Matrix.cpp -std=c++11
   ```

2. **Run the program:**
   ```bash
   ./main
    ```

The network will train on XOR data and print predictions for inputs `[0, 0]` and `[1, 0]` after training.


