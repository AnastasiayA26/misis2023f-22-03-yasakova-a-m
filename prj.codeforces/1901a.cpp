#include <iostream>
using namespace std;
int main()
{
    int t;
    cin>>t;
    while(t--){
        int n,x;int f[100]={0};
        cin>>n>>x;
        for(int i=1;i<=n;++i){
            cin>>f[i];
        }
        int max=0;
        for(int i=0;i<n;++i){
            int t=f[i+1]-f[i];
            if(t>max){
                max=t;
            }
        }
        int a=(x-f[n])*2;
        if(a>max){
            max=a;
        }
        cout<<max<<endl;
    }
}
