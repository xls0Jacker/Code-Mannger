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
//定义dp[i+1][j]为在前i位数中取j个，最终有
//dp[i+1][j]=dp[i+1][j-1]+dp[i][j]-dp[i][j-1-a[i]];
int T,A,S,B;
ll dp[MAX_T+10][MAX_A+1010];
int famliy[MAX_T+1];
void solve(){
    dp[0][0]=1;
    Rep(1,i,T){
        Rep(0,j,B){
            if (j == 0) {
                dp[i][0] = dp[i - 1][0]; 
            }
            else if(j>=1 and j<=famliy[i]){
                dp[i][j]=dp[i-1][j]+dp[i][j-1];
            }
            else if(j>=1){
                dp[i][j]=dp[i][j-1]+dp[i-1][j]-dp[i-1][j-1-famliy[i]]+mod;
            }
			dp[i][j]=(dp[i][j]+mod)%mod;
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
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //frep;
    cin>>T>>A>>S>>B;
    int t;
    rep(0,i,A){
        cin>>t;
        famliy[t]++;
    }
    solve();
    //frepC;
    //sys;
    return 0;
}

