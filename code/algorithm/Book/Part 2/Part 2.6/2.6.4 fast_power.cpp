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
//Carmichael Numbers
//2<n<65000
//通过快速幂运算判断x在区间(1,n)内是否都成立
//存在一个不成立则不是
//除此之外，根据题意，当n为素数时必然不成立

//素性测试 O(sqrt(n))
bool is_prime(int n){//O(sqrt(n))
    for(int i=2;i*i<=n;i++){
        if(n%i==0) return false;
    }
    return n!=1;//1为例外
}
//快速幂 O(logn)//个人更倾向于stuff中的fast_power
ll mod_power(ll x,ll n,ll mod){//O(logn)
    ll res=1;
    while(n>0){
        if(n&1) res=res*x%mod;
        x=x*x%mod;
        n>>=1;
    }
    return res;
}
int n;
void solve(){
    while(cin>>n){
        bool f=1;
        if(n==0) break;
        if(is_prime(n)){
            f=0;
        }
        rep(2,i,n){
            if(mod_power(i,n,n)!=i){
                f=0;
                break;
            }
        }
        if(f) printf("The number %d is a Carmichael number.\n",n);
        else printf("%d is normal.\n",n);
    }
}

int main(){
    //ios_base::sync_with_stdio(false);
    //cin.tie(NULL);
    frep;
    solve();
    frepC;
    sys;
    return 0;
}

