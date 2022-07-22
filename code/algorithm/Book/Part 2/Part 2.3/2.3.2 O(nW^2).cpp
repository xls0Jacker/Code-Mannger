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
const int MAX=105;
int n,W;
int w[MAX],v[MAX];
//完全背包问题
//1<=n<=100 1<=W<=1e4 1<=wi,vi<=100
/*  
    递推关系：
    dp[0][j]=0;
    dp[i+1][j]=max{dp[i][j-k*w[i]]+k*v[i])|0<=k};
*/
int dp[MAX][MAX];
void solve(){//O(nW^2)做法
    rep(0,i,n){
        Rep(0,j,W){
            for(int k=0;k*w[i]<=j;k++){
                dp[i+1][j]=max(dp[i+1][j],dp[i][j-k*w[i]]+k*v[i]);
            }
        }
    }
    cout<<dp[n][W]<<endl;
}

int main(){
    //ios_base::sync_with_stdio(false);
    //cin.tie(NULL);
    frep;
    cin>>n;
    rep(0,i,n){//O(n)
        cin>>w[i];
    }
    rep(0,i,n){//O(n)
        cin>>v[i];
    }
    cin>>W;
    solve();
    frepC;
    sys;
    return 0;
}

