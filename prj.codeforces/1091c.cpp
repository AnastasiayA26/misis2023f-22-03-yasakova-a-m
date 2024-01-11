#include <iostream>
#include <cmath>

long long n;

int main() {
    std::cin >> n;
    for(long long i = 1; i * i < n; i++) {
        if(n % i == 0) {
            std::cout << i + n * (i - 1)/2 << " ";
        }
    }
    for(long long i = (long long) sqrt(n); i >= 1; i--) {
        if(n % i == 0) {
            long long k = n / i;
            std::cout << k + n * (k - 1)/2 << " ";
        }
    }
}
