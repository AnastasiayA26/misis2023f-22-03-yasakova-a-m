#include<iostream>
#include<algorithm>
#include<vector>

int main()
{
    int t;
    std::cin>>t;
    while(t--)
    {
        int n;
        std::cin>>n;
        std::vector<int> v;
        for(int i=0;i<n;i++)
        {
            int x;
            std::cin>>x;
            if(x!=i)v.push_back(x);
        }
        int ans;
        ans=v[0];
        for (int i=0;i<v.size();i++)
        {
            ans&=v[i];
        }
        std::cout<<ans<<std::endl;
    }
}