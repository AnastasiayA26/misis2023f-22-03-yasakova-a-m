#include <iostream>
#include <algorithm>
#include <vector>
int main(){
    int t;
    std::cin >> t;
    while (t--){
        int n, k, q;
        std::cin >> n >> k >> q;
        long long ans = 0;
        int ha[200007];
        long long tot = 0;
        for (int i = 0; i < n; i++){
            std::cin >> ha[i];
            if (ha[i] <= q){
                tot++;
            } else {
                if (tot >= k) ans+=(tot-k+1)*(tot-k+2)/2;
                tot = 0;
            }
        }
        if (tot >= k) ans+=(tot-k+2)*(tot-k+1)/2;
        std::cout << ans << "\n";
    }
    return 0;
}

