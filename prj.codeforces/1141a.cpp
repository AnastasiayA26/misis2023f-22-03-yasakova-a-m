#include <iostream>

int main() {
    int a, m;
    std::cin >> a >> m;

    int x2 = 0, x3 = 0, x12 = 0, x13 = 0;

    while (a > 0) {
        if (a % 2 == 0) {
            a = a / 2;
            x2++;
        } else if (a % 3 == 0) {
            a = a / 3;
            x3++;
        } else {
            break;
        }
    }

    while (m > 0) {
        if (m % 2 == 0) {
            m = m / 2;
            x12++;
        } else if (m % 3 == 0) {
            m = m / 3;
            x13++;
        } else {
            break;
        }
    }

    if (x12 < x2 or x13 < x3) {
        std::cout << "-1" << std::endl;
    } else if (a == m) {
        int x1 = x12 + x13;
        int x = x2 + x3;
        std::cout << x1 - x << std::endl;
    } else {
        std::cout << -1 << std::endl;
    }

    return 0;
}