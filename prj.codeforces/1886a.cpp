#include <iostream>

int main() {
    int t;
    std::cin >> t;

    while (t--) {
        int n;
        std::cin >> n;

        if (n <= 5 or (n <= 5  and n % 3 == 0)) {
            std::cout << "NO" << std::endl;
        }
        else {
            if(n% 3 == 0  and (n > 11)){
                std::cout << "YES" << std::endl;
                std::cout << "1 4 " << n - 5 << std::endl;
            }
            else{
                if(n % 3 != 0) {
                    std::cout << "YES" << std::endl;
                    std::cout << "1 2 " << n - 3 << std::endl;
                }
                else{
                    std::cout << "NO" << std::endl;
                }
            }
        }
    }

    return 0;
}
