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
const int MAX_M=2000;
const int MAX_N=26;
// 最廉价的回文串 Cheapest Palindrome
// 0<=m≤2000 0<=n≤26

//思路：
//定义dp[i][j]为字串si...j为回文串的最小费用，
//有dp[i][j]=min(dp[i+1][j]+cost[i],dp[i][j-1]+cost[j]),
//当首尾字母相同时，更新答案dp[i][j]=min(dp[i][j],dp[i+1][j-1]);
//i=M-1->0 , j=0->i(->M-1)

int m,n;
string s;
int dp[MAX_M+1][MAX_M+1];
int cost[MAX_M+1];//字符-'a'转为数字
void solve(){
    Per(0,i,m-1){
        rep(i+1,j,m){
            dp[i][j]=min(dp[i+1][j]+cost[s[i]-'a'],dp[i][j-1]+cost[s[j]-'a']);
            if(s[i]==s[j]){
                dp[i][j]=min(dp[i][j],dp[i+1][j-1]);
            }
        }
    }
    cout<<dp[0][m-1]<<endl;
}

int main(){
    //ios_base::sync_with_stdio(false);
    //cin.tie(NULL);
    frep;
    cin>>n>>m;
    cin>>s;
    char c;//字符 
    int FI,FD;//增加费用 删除费用
    rep(0,i,n){
        cin>>c>>FI>>FD;
        cost[c-'a']=min(FI,FD);
    }
    solve();
    frepC;
    sys;
    return 0;
}

