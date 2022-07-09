#include"bits/stdc++.h"
#define rep(a,i,n) for(int i=a;i<n;i++)
#define per(a,i,n) for(int i=n;i>a;i--)
#define Rep(a,i,n) for(int i=a;i<=n;i++)
#define Per(a,i,n) for(int i=n;i>=a;i--)
#define frep freopen("in.txt","r",stdin)
#define frepC freopen("CON","r",stdin)
#define sys system("pause")
typedef long long ll;
using namespace std;
unsigned long long n,ans;
void solve(){
    cin>>n;
    ans=n * (n-1) / 2 * (n-2) / 3 * (n-3) / 4;
    printf("%lld\n",ans);
}

int main(){
    frep;
    solve();
    frepC;
    sys;
    return 0;
}

