#include <iostream>
#include <vector>

int main()
{
    int t,n,m,k,x1,y1,b;
    std::cin >> t;
    while(t--)
    {
        bool co=0;
        std::cin >> n >> m >> k;
        int x[k] , y[k] ;
        std::cin >> x1 >> y1;
        b=(x1+y1)%2;
        for(int i=0; i<k;i++)
        {
            std::cin >> x[i] >> y[i];
        }
        for(int i=0; i<k;i++)
            if((x[i]+y[i])%2==b)
            {
                co=1;
                break;
            }
        if(co>0)  std::cout << "NO" << std::endl;
        else       std::cout << "YES" << std::endl;
    }
}
 
