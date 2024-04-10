#ifndef CHECK_BRACKETS_H
#define CHECK_BRACKETS_H

#include <iostream>
#include <fstream>
#include <stack>
#include <string>

std::string checkBrackets(const std::string& filename) {
    std::ifstream file(filename);
    if (!file.is_open()) {
        return "Unable to open file: " + filename;
    }

    std::ofstream resultFile("result.txt");
    if (!resultFile.is_open()) {
        return "Unable to open result file";
    }

    std::stack<char> brackets;

    std::string line;
    while (std::getline(file, line)) {
        for (char c : line) {
            if (c == '{') {
                brackets.push(c);
            } else if (c == '}') {
                if (brackets.empty() || brackets.top() != '{') {
                    resultFile << "There is a discrepancy\n";
                    return "There is a discrepancy";
                }
                brackets.pop();
            }
        }
    }

    if (!brackets.empty()) {
        resultFile << "There is a discrepancy\n";
        return "There is a discrepancy";
    }

    resultFile << "All brackets are in place\n";
    return "All brackets are in place";
}

#endif
