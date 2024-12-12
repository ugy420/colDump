#include <stdio.h>
#include <math.h>

// Sigmoid activation function
double sigmoid(double x) {
    return 1.0 / (1.0 + exp(-x));
}

// Mean Squared Error calculation
double mean_squared_error(double target, double output) {
    return 0.5 * pow(target - output, 2);
}

int main() {
    double inputs[2] = {0.05, 0.1}; // Example input values

    double weights_input_hidden[2][2] = {{0.15, 0.2}, {0.25, 0.3}};
    double weights_hidden_output[2] = {0.4, 0.45};

    double bias_hidden[2] = {0.35, 0.35};
    double bias_output = 0.6;

    double target = 1.0;

    // Forward Propagation Steps:

    double hidden[2];
    for (int i = 0; i < 2; i++) {
        hidden[i] = inputs[0] * weights_input_hidden[0][i] + inputs[1] * weights_input_hidden[1][i] + bias_hidden[i];
        hidden[i] = sigmoid(hidden[i]);
        printf("Hidden neuron %d activation: %f\n", i+1, hidden[i]);
    }


    double output = 0.0;
    for (int i = 0; i < 2; i++) {
        output += hidden[i] * weights_hidden_output[i];
    }
    output += bias_output;
    output = sigmoid(output);

    printf("Output: %f\n", output);

    double error = mean_squared_error(target, output);
    printf("Error (Mean Squared Error): %f\n", error);

    return 0;
}
