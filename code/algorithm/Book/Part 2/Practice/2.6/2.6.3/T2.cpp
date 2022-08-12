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
// Raising Modulo Numbers
// 1≤Z≤10 1≤M≤45000 1≤H≤45000

//思路：
//对于H对求出exp[Ai^Bi mod M]，
//之后累加求和即可（注意同时取模，防止爆ll）

//解决方法：
//快速幂+快速乘
//(a+b)%mod=(a%mod+b%mod)%mod


inline ll quick_multiply(ll x,ll y,ll mod){
    return (x*y-(ll)((long double)x/mod*y)*mod+mod)%mod;     
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

int M,H;
void solve(){
    ll ans=0;
    int Ai,Bi;
    rep(0,i,H){
        cin>>Ai>>Bi;
        ans+=fast_power(Ai,Bi,M)%M;
        ans%=M;
    }
    cout<<ans<<endl;
}

int main(){
    //ios_base::sync_with_stdio(false);
    //cin.tie(NULL);
    frep;
    int Z;
    cin>>Z;
    while(Z--){
        cin>>M>>H;
        solve();
    }
    frepC;
    sys;
    return 0;
}

