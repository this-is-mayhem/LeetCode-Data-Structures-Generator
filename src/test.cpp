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

void test_generate_tree() {
    std::string data = "[3,9,20,null,null,15,7]";
    //     3
    //   /   \
    //  9    20
    //       / \
    //      15  7
    TreeNode* root = generate_tree(data);
    printTree(root);  // Output should be: 3 9 20 null null 15 7 null null
}

int main() {
    test_generate_matrix();
    test_generate_tree();
}