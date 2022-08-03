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
const int MAX_N=1e6;
const int mod=1e9;
// 求和方案 Sumsets
// 1≤N≤1e6

//猜想：
//经过简单的模拟我发现：
//(设0=0 1=1)
//3=2=1+1，
//5=4=2+3，
//7=6=3+5，
//9=8=4+7...
//定义dp[i]位第i个数的组合数，有
//dp[i]={
//dp[i-1],i&1=1
//dp[i-1]+dp[i/2],i&1=0    
//}

int N;
ll dp[MAX_N+1];
void prev(){
    dp[0]=dp[1]=1;
    dp[2]=2;
    rep(3,i,MAX_N+1){
        dp[i]=dp[i-1];
        if((i&1)==0){
            dp[i]+=dp[i/2];
        }
        dp[i]%=mod;
    }
}
void solve(){
    cout<<dp[N]<<endl;
}

int main(){
    //ios_base::sync_with_stdio(false);
    //cin.tie(NULL);
    frep;
    prev();
    while(cin>>N){
        solve();
    }
    frepC;
    sys;
    return 0;
}

