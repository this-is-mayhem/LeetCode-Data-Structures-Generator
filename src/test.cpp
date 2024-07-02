#include "generator_functions.h"
#include <iostream>

void test_generate_matrix() {
    std::string input = "[[9,9,8,1],[5,6,2,6],[8,2,6,4],[6,2,2,2]]";
    std::vector<std::vector<int>> matrix = generate_matrix(input);

    // Print the matrix to verify the result
    for (const auto& row : matrix) {
        for (int num : row) {
            std::cout << num << " ";
        }
        std::cout << std::endl;
    }
}

int main() {
    test_generate_matrix();
}