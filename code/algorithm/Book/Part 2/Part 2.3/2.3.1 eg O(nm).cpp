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
const int MAX=1005;
int n,m;
char s[MAX],t[MAX];
// 最长公共子序列问题(LCS:Longest Common Subsequence)
//1<=n,m<=1000
//比较si+1与tj+1时，上一状态有三种可能：
//si+1,tj si,tj si,tj+1
//当si+1=tj+1时 直接选取(si,tj)+1
//当si+1!=tj+1时 回到上一状态的最长长度
//加速方法 （递推）DP
int dp[MAX][MAX];
void solve(){//O(nm)做法
    rep(0,i,n){
        rep(0,j,m){
            if(s[i]==t[j]){
                dp[i+1][j+1]=dp[i][j]+1;
            }
            else {
                dp[i+1][j+1]=max(dp[i][j+1],dp[i+1][j]);
            }
        }
    }
    cout<<dp[n][m]<<endl;
}

int main(){
    //ios_base::sync_with_stdio(false);
    //cin.tie(NULL);
    frep;
    cin>>n>>m;
    rep(0,i,n){
        cin>>s[i];
    }
    rep(0,i,m){
        cin>>t[i];
    }
    solve();
    frepC;
    sys;
    return 0;
}

