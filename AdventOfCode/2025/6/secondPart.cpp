#include <algorithm>
#include <cctype>
#include <iostream>
#include <string>
#include <vector>

using ll = long long;

bool is_whitespace(char c) { return c == ' ' || c == '\r' || c == '\t'; }

bool is_column_empty(const std::vector<std::string> &input, int col_index) {
    for (const std::string &line : input) {
        if (col_index < line.size() && !is_whitespace(line[col_index])) {
            return false;
        }
    }
    return true;
}

ll solve_problem(const std::vector<ll> &numbers, char op) {
    if (numbers.empty())
        return 0;

    ll result = numbers[0];

    if (op == '+') {
        for (size_t i = 1; i < numbers.size(); ++i) {
            result += numbers[i];
        }
    } else if (op == '*') {
        for (size_t i = 1; i < numbers.size(); ++i) {
            result *= numbers[i];
        }
    }
    return result;
}

int main() {
    std::vector<std::string> input_lines;
    std::string line;

    while (std::getline(std::cin, line)) {
        if (!line.empty() && line.back() == '\r') {
            line.pop_back();
        }
        input_lines.push_back(line);
    }

    while (!input_lines.empty() && input_lines.back().empty()) {
        input_lines.pop_back();
    }

    if (input_lines.empty())
        return 0;

    ll grand_total = 0;
    int max_width = 0;
    for (const auto &l : input_lines)
        max_width = std::max(max_width, (int)l.size());

    size_t op_line_index = input_lines.size() - 1;

    int current_col = max_width - 1;
    while (current_col >= 0) {

        while (current_col >= 0 && is_column_empty(input_lines, current_col)) {
            current_col--;
        }

        if (current_col < 0)
            break;

        int end_col = current_col;

        int start_col = end_col;
        while (start_col >= 0 && !is_column_empty(input_lines, start_col)) {
            start_col--;
        }

        std::vector<ll> current_numbers;
        char current_op = '+';

        for (int c = end_col; c > start_col; --c) {
            if (c < input_lines[op_line_index].size() &&
                !is_whitespace(input_lines[op_line_index][c])) {
                current_op = input_lines[op_line_index][c];
                break;
            }
        }

        for (int c = end_col; c > start_col; --c) {
            std::string number_str = "";

            for (size_t r = 0; r < op_line_index; ++r) {
                if (c < input_lines[r].size() &&
                    !is_whitespace(input_lines[r][c])) {
                    number_str += input_lines[r][c];
                }
            }

            if (!number_str.empty()) {
                try {
                    current_numbers.push_back(std::stoll(number_str));
                } catch (...) {
                }
            }
        }

        if (!current_numbers.empty()) {
            grand_total += solve_problem(current_numbers, current_op);
        }

        current_col = start_col;
    }

    std::cout << grand_total << std::endl;

    return 0;
}
