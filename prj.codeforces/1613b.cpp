#include <iostream>
#include <vector>
#include <algorithm>

int main() {
    int t;
    std::cin >> t;

    while (t--) {
        int n;
        std::cin >> n;
        std::vector<int> arr(n);

        for (int i = 0; i < n; i++) {
            std::cin >> arr[i];
        }

        std::sort(arr.begin(), arr.end());

        for (int i = 0; i < n / 2; i++) {
            std::cout << arr[n - i - 1] << " " << arr[0] << std::endl;
        }
    }

    return 0;
}

