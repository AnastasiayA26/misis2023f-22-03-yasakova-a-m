#include <iostream>
#include <vector>

int main() {
    int t, n, m, k, x1, y1, b;
    std::cin >> t;
    while (t--) {
        bool co = false;
        std::cin >> n >> m >> k;
        std::vector<int> x(k);
        std::vector<int> y(k);

        std::cin >> x1 >> y1;
        b = (x1 + y1) % 2;

        for (int i = 0; i < k; i++) {
            std::cin >> x[i] >> y[i];
        }

        for (int i = 0; i < k; i++) {
            if ((x[i] + y[i]) % 2 == b) {
                co = true;
                break;
            }
        }

        if (co) {
            std::cout << "NO" << std::endl;
        } else {
            std::cout << "YES" << std::endl;
        }
    }

    return 0;
}

 
