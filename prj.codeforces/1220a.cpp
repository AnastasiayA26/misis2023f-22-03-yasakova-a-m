#include <iostream>
#include <algorithm>
#include <vector>
#include <iostream>

int main() {
    int n;
    std::cin >> n;

    std::string s;
    std::cin >> s;

    int countZero = count(s.begin(), s.end(), 'z');
    int countOne = count(s.begin(), s.end(), 'n');

    std::vector<int> result;
    while (countOne > 0) {
        result.push_back(1);
        countOne--;
    }

    while (countZero > 0) {
        result.push_back(0);
        countZero--;
    }

    for (int i = 0; i < result.size(); ++i) {
        std::cout << result[i];
        if (i < result.size() - 1) {
            std::cout << " ";
        }
    }
    std::cout << std::endl;

    return 0;
}
