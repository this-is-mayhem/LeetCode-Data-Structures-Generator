#include "generator_functions.h"
#include <sstream>
#include <queue>
#include <algorithm>

using matrix_int = std::vector<std::vector<int>>;


matrix_int generate_matrix(const std::string& str) {
	matrix_int result;
	std::vector<int> row;
    std::stringstream ss(str);
    char ch;
    int num;

    while (ss >> ch) {
        if (ch == '[') {
            // start of a new row
            row.clear();
        }
        else if (ch == ']') {
            // end of a row
            if (!row.empty()) {
                result.push_back(row);
                row.clear();
            }
        }
        else if (isdigit(ch) || ch == '-') {
            // parse the number
            ss.unget();
            ss >> num;
            row.push_back(num);
        }
        else if (ch == ',') {
            // skip the commas
            continue;
        }
    }

    return result;
}

TreeNode* generate_tree(const std::string& data) {
    if (data.empty() || data == "[]") return nullptr;

    // Remove the brackets
    std::string str = data.substr(1, data.size() - 2);
    // Replace commas with spaces
    std::replace(str.begin(), str.end(), ',', ' ');
    // Use stringstream to parse the values
    std::stringstream ss(str);
    std::string val;
    std::vector<std::string> nodes;

    while (ss >> val) {
        nodes.push_back(val);
    }

    if (nodes.empty()) return nullptr;

    TreeNode* root = new TreeNode(stoi(nodes[0]));
    std::queue<TreeNode*> q;
    q.push(root);
    int i = 1;

    while (!q.empty() && i < nodes.size()) {
        TreeNode* current = q.front();
        q.pop();

        if (nodes[i] != "null") {
            current->left = new TreeNode(stoi(nodes[i]));
            q.push(current->left);
        }
        i++;

        if (i >= nodes.size()) break;

        if (nodes[i] != "null") {
            current->right = new TreeNode(stoi(nodes[i]));
            q.push(current->right);
        }
        i++;
    }

    return root;
}