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
//取模转取整
//𝑛 𝑚𝑜𝑑 𝑚=𝑛 −𝑚 ⌊𝑛/𝑚⌋
//求：∑_(𝑘=1)^𝑛▒〖𝑛 𝑚𝑜𝑑 𝑘〗, 𝑛 ≤10^9
ll n;
void solve(){
    cin>>n;
    ll ANS=0;
    for(int l=1,r=1;l<=n;l=r+1){//O(sqrt(n))
        r=n/(n/l);
        ANS+=(r-l+1)*(r+l)/2 * n/l * (r-l+1);//l l+1 l+2 ... r
        //          |不需要|？
    }
    cout<<n*n-ANS<<endl;
}


int main(){
    frep;
    solve();
    frepC;
    sys;
    return 0;
}

