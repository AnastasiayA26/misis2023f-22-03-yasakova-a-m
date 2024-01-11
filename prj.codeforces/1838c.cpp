//1838c
#include <iostream>

int main() {

    int t; std::cin >> t;
    for(int tc = 1; tc <= t; ++tc) {

        int n, m; std::cin >> n >> m;

        for(int i = 0; i < n; ++i) {
            for(int j = 0; j < m; ++j) {
                if(i % 2 == 0) std::cout << (n / 2 + i / 2) * m + j + 1 << ' ';
                else std::cout << (i / 2) * m + j + 1 << ' ';
            }
            std::cout << '\n';
        }
    }
}
