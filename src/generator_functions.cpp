#include "generator_functions.h"
#include <sstream>
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