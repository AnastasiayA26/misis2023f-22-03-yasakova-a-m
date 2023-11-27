#include <iostream>
#include <vector>

int main()
{
    std::vector<int> home, guest;

    int n;
    std::cin>>n;

    for(int i=0;i<n;i++){
        int a,b;
        std::cin>>a>>b;

        home.push_back(a);
        guest.push_back(b);
    }

    int cnt=0;
    for(int i=0;i<n;i++){
        int homeclr=home[i];
        for(int j=0;j<n;j++){
            if(j==i) continue;
            if(homeclr==guest[j]) cnt++;
        }
    }
    std::cout<<cnt<<std::endl;

    return 0;
}