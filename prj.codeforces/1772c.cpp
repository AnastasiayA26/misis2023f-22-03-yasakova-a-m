#include <iostream>
int main()
{
    int t; std::cin>>t;
    while(t--)
    {
        int k,n;
        std::cin>>k>>n;

        int dif=1;
        int ans=1;

        for(int i=1 ; i<=k ; i++)
        {
            std::cout<<ans<<" ";
            if(n-(dif+ans)>=(k-(i+1)))
            {
                ans+=dif;
                dif++;
            }
            else ans++;
        }
        std::cout<<std::endl;
    }
    return 0;
}
