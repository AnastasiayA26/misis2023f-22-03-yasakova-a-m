#include <iostream>
#include <string>
#include <cmath>

int main() {
    std::string s, t;
    std::cin >> s;
    std::cin >> t;

    int i = 0;
    while (s[s.length() - 1 - i] == t[t.length() - 1 - i]) {
        i++;
        if (i == std::min(s.length(), t.length())) {
            break;
        }
    }

    std::cout << s.length() + t.length() - 2 * i;

    return 0;
}
