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
//快速幂//满足结合律的运算均可使用快速幂加速
//求a^b mod m (b<=1e18)
ll fast_power(int a,int b,int mod){//O(logb)
    ll ret=1;
    while(b){//b在(二进制下)不为0
        if(b&1) ret=ret*a%mod;//判断最后一位是否为1，为一乘上a的？次方
        b>>=1;//二进制下右移一位
        a=a*a%mod;//a随位次变化提升
    }
    return ret;
}
void solve(){

}

int main(){
    frep;
    solve();
    frepC;
    sys;
    return 0;
}

