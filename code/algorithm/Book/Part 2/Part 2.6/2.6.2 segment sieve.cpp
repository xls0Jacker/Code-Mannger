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
const int MAX_L=1e6+5,MAX_SQRT_B=1e6+5;
ll a,b;
//区间内素数的个数
//a<b<=1e12
//b-a<=1e6
//提醒：由于数据太大，不可使用埃氏筛法结合素数判断完成该题

//区间筛法
//由素数判定知,b的素数可能成立区间在[0,sqrt(b))
//故在区间[0,sqrt(b))筛选的同时，删除区间[a,b)内其倍数
//最终所得个数为答案
bool is_prime[MAX_L];
bool is_prime_small[MAX_SQRT_B];
//is_prime[i-a]=true-->i为素数
void segment_sieve(ll a,ll b){
    //初始化
    for(int i=0;(ll)i*i<b;i++) is_prime_small[i]=true;
    for(int i=0;i<b-a;i++) is_prime[i]=true;
    //筛除
    for(int i=2;(ll)i*i<b;i++){
        if(is_prime_small[i]){
            for(int j=2*i;(ll)j*j<b;j+=i) is_prime_small[j]=false;//筛[0,sqrt(b))
            for(ll j=max(2ll,(a+i-1)/i)*i;j<b;j+=i) is_prime[j-a]=false;//筛[a,b)
        }
    }
}
void solve(){
    segment_sieve(a,b);
    int res=0;
    Rep(0,i,b-a){
        if(is_prime[i]){
            res++;
        }
    }
    cout<<res<<endl;
}

int main(){
    //ios_base::sync_with_stdio(false);
    //cin.tie(NULL);
    frep;
    cin>>a>>b;
    solve();
    frepC;
    sys;
    return 0;
}
