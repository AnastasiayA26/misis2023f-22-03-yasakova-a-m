#include<iostream>

int main() {
    int t;
    std::cin >> t;
    while (t--) {
        int n, m;
        std::cin >> n >> m;
        std::cout << std::max(n, m) << "\n";
    }
    return 0;
}