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
int x,y,m;
ll fast_power(ll a,int b,int mod){//O(logb)
    ll ret=1;
    while(b){//b在(二进制下)不为0
        if(b&1) ret=ret*a%mod;//判断最后一位是否为1，为一乘上a的？次方
        b>>=1;//二进制下右移一位
        a=a*a%mod;//a随位此变化提升
    }
    return ret;
}

void solve(){
    cin>>x>>y>>m;
    ll ANS=fast_power(x,y,m);
    cout<<x<<"^"<<y<<" mod "<<m<<"="<<ANS<<endl;
}

int main(){
    frep;
    solve();
    frepC;
    sys;
    return 0;
}

