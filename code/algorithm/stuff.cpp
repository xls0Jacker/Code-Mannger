#include<iostream>
#include<cstdio>
#define lon long long
using namespace std;
const int maxn=110;
lon n,p,a[maxn];
int main()
{
    lon ans=1;
    for(lon i=0;i<=1000000007;i+=10000000)
    {
        for(lon j=i+1;j<=i+10000000;j++)
        ans=(ans*j)%1000000007;
        cout<<ans<<",";
    }
    system("pause");
    return 0;
}
