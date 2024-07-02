#include "binary_tree.h"
#include <queue>
#include <iostream>

void printTree(TreeNode* root) {
    if (!root) return;

    std::queue<TreeNode*> q;
    q.push(root);

    while (!q.empty()) {
        TreeNode* current = q.front();
        q.pop();

        if (current) {
            std::cout << current->val << " ";
            q.push(current->left);
            q.push(current->right);
        }
        else {
            std::cout << "null ";
        }
    }
    std::cout << std::endl;
}