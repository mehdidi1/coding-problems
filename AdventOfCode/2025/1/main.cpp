#include <cstdlib>
#include <iostream>
#include <string>

int main(int argc, char *argv[]) {
    int curr{50};
    std::string instr;
    int result{0};
    int step = 0;
    bool prevIs0 = false;
    while (std::cin >> instr) {
        int range = std::stoi(instr.substr(1, instr.size() - 1));
        if (instr[0] == 'L') {
            range = -range;
        }
        if (std::abs(range) >= 100) {
            result += std::abs(range / 100);
            range %= 100;
        }
        curr += range;
        if ((curr <= 0 || curr >= 100) && !prevIs0) {
            result++;
            std::cout << "step" << step << std::endl;
        }
        prevIs0 = (curr == 0 || curr == 100);
        curr = (curr % 100 + 100) % 100;
        step++;
    }
    std::cout << result << std::endl;

    return 0;
}
