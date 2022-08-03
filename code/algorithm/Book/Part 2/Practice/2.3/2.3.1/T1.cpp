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
const int MAX_N=350;
// 保龄球 Cow Bowling
// 1≤N≤350

//思路：
//有以下递推关系式存在：
//定义dp[i][j]为选择(i-1)行元素j或者(j+1)之后的权值之和，有
//dp[i][j]=max(dp[i-1][j],dp[i-1][j-1])+M[i][j]，
//最后对于第N-1行找最大值输出即可

//对于该递推关系式，可知只存在dp[i],dp[i+1]，
//通过奇偶优化，可减小体积
int N;
int dp[2][MAX_N+1];//体积优化
int M[MAX_N+1][MAX_N+1];
void solve(){
    dp[0][0]=M[0][0];
    rep(1,i,N){
        Rep(0,j,i){
            dp[i&1][j]=max(dp[(i-1)&1][j],dp[(i-1)&1][j-1])+M[i][j];
        }
    }
    int ans=-1;
    rep(0,i,N){
        ans=max(dp[(N-1)&1][i],ans);
    }
    cout<<ans<<endl;
}

int main(){
    //ios_base::sync_with_stdio(false);
    //cin.tie(NULL);
    frep;
    while(cin>>N){
        rep(0,i,N){
            Rep(0,j,i){
                cin>>M[i][j];
            }
        }
        solve();
    }
    frepC;
    sys;
    return 0;
}

