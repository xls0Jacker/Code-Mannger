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
const int MAX_A=1e5;
const int MAX_T=1000;
const int mod=1e6;
// 蚂蚁问题 Ant Counting
// 1≤T≤1000,1≤S≤B≤A

//题目大意:
//对于任取S个到B个（S<B）数，求其最大的组成的不同集合的数目之和；

//思路：
//定义dp[i][j]为使用前i的家族可以组成个数j的集合数，有
//dp[i][j]=(dp[i][j]+dp[i-1][j-k])//使用前(i-1)个家族的集合数加上使用第i个家族的k个所组成的集合数

//空间优化 失败 存在dp[0][0]=1特判 不能按照奇偶性对其进行优化
int T,A,S,B;
int a[MAX_A+1];
ll dp[MAX_T+1][MAX_A+1];
int F_member[MAX_A+1];
void prev(){
    rep(0,i,A){
        F_member[a[i]]++;
    }
}
void solve(){
    dp[0][0]=1;//空集数目为1
    ll total=F_member[0];
    Rep(1,i,T){
        total+=F_member[i];
        Rep(0,k,F_member[i]){
            Per(k,j,total){
                dp[i][j]=(dp[i][j]+dp[i-1][j-k])%mod;
            }
        }
    }
    ll ans=0;
    Rep(S,i,B){
        ans+=dp[T][i];
        ans%=mod;
    }
    cout<<ans<<endl;
}

int main(){
    //ios_base::sync_with_stdio(false);
    //cin.tie(NULL);
    frep;
    cin>>T>>A>>S>>B;
    rep(0,i,A){
        cin>>a[i];
    }
    prev();
    solve();
    frepC;
    sys;
    return 0;
}

