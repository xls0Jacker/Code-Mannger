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
const int MAX_N=1048576;
// 整除链 X-factor Chains
// 0<X≤2^20（1e6+  1048576）

//思路；
//任意一个合数可以拆成一定质数的乘积，
//将一个数按照其质因子分解一定是最长的，
//而这个最长序列的次数是：集合中数的个数的阶乘/集合中出现的每个数的个数的阶乘的乘积，如：
//100： 2 2 5 5 => 4!/2!*2!=6

//解决方法：
//获取这个数的质因子和其质因子的指数，
//根据排列组合获得其答案

int _prime[MAX_N+1];//质因数的指数
int cnt;//不同质因数的个数
int sum;//质因数的个数
void divide(int n) {//分解质因数，获得其底数和指数
    for (int i = 2; i <= n / i; i++) {
        if (n % i == 0) {
            int s = 0;
            while (n % i == 0) {
                n /= i;
                s++;
            }
            //cout << i << ' ' << s << endl;   //i为底数，s为指数
            _prime[cnt++]=s;
            sum+=s;
        }
    }
    // if (n > 1) cout << n << ' ' << 1 << endl;
    // puts("");
    if(n>1){
        _prime[cnt++]=1;
        sum+=1;
    }
}

ll fac(int x){//计算阶乘
    ll temp = 1;
    for(int i = 2; i <= x; i++)
        temp *= i;
    return temp;
}

int X;
void solve(){
    divide(X);
    ll ans=fac(sum);
    rep(0,i,cnt){
        ans/=fac(_prime[i]);
    }
    cout<<sum<<" "<<ans<<endl;
}

int main(){
    //ios_base::sync_with_stdio(false);
    //cin.tie(NULL);
    frep;
    while(cin>>X){
        memset(_prime,0,sizeof(_prime));
        cnt=0;
        sum=0;
        solve();
    }
    frepC;
    sys;
    return 0;
}

