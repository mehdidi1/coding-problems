#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

using ll = long long;

// Helper to safely check if a character is whitespace (including \r)
bool is_whitespace(char c) { return c == ' ' || c == '\r' || c == '\t'; }

// Helper function to check if a column is entirely whitespace
bool is_column_empty(const std::vector<std::string> &input, int col_index) {
    for (const std::string &line : input) {
        if (col_index < line.size() && !is_whitespace(line[col_index])) {
            return false;
        }
    }
    return true;
}

ll solve_problem(const std::vector<ll> &numbers, char op) {
    if (op == '+') {
        ll sum = 0;
        for (ll n : numbers)
            sum += n;
        return sum;
    } else if (op == '*') {
        ll product = 1;
        for (ll n : numbers)
            product *= n;
        return product;
    }
    return 0;
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

    int current_col = 0;
    while (current_col < max_width) {
        while (current_col < max_width &&
               is_column_empty(input_lines, current_col)) {
            current_col++;
        }

        if (current_col >= max_width)
            break;

        int start_col = current_col;
        int end_col = start_col;
        while (end_col < max_width && !is_column_empty(input_lines, end_col)) {
            end_col++;
        }

        std::vector<ll> current_numbers;

        char current_op = '+';
        if (start_col < input_lines[op_line_index].size()) {
            current_op = input_lines[op_line_index][start_col];
        }

        for (size_t r = 0; r < op_line_index; ++r) {
            std::string problem_segment = "";
            for (int c = start_col; c < end_col; ++c) {
                if (c < input_lines[r].size() &&
                    !is_whitespace(input_lines[r][c])) {
                    problem_segment += input_lines[r][c];
                }
            }
            if (!problem_segment.empty()) {
                try {
                    current_numbers.push_back(std::stoll(problem_segment));
                } catch (...) {
                }
            }
        }

        if (!current_numbers.empty()) {
            grand_total += solve_problem(current_numbers, current_op);
        }

        current_col = end_col;
    }

    std::cout << grand_total << std::endl;

    return 0;
}
