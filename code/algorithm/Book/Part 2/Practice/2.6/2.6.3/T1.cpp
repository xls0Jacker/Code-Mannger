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
// 取模问题 Pseudoprime numbers
// 2<p≤1e9 1<a<p

//思路：
//快速幂求出exp[a^p mod p]，
//之后判断是否满足条件即可（exp[]的值为a 且 p不为素数）

ll quick_multiply(ll a,ll b,int mod){//快速乘 //防爆ll
    ll ans=0;
    while(b){
        ans=(ans+(b%2*a)%mod)%mod;
        a=(a<<1)%mod;
        b>>=1;
    }
    return ans;
}

ll fast_power(int a,int b,int mod){//快速幂
    ll ret=1;
    while(b){
        if(b&1) ret=quick_multiply(ret,(ll)a,mod);
        b>>=1;
        a=quick_multiply(((ll)a),(ll)a,mod);
    }
    return ret;
}

int p,a;
bool is_prime(int n){//素性测试
    for(int i=2;i*i<=n;i++){
        if(n%i==0) return false;
    }
    return n!=1;//1为例外
}

int main(){
    //ios_base::sync_with_stdio(false);
    //cin.tie(NULL);
    frep;
    while(cin>>p>>a and p!=0 and a!=0){
        if(fast_power(a,p,p)==a and !is_prime(p)) puts("yes");
        else puts("no");
    }
    //solve();
    frepC;
    sys;
    return 0;
}

