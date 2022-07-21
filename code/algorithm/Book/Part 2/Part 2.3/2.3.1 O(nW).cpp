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
//01背包问题
//1<=n<=100 1<=wi,vi<=100 1<=W<=10000
//针对每个物品是否放入背包进行搜索
//加速方法 记忆化
int dp[MAX][MAX];
int rec(int i,int j){//物品位次 当前容量//O(nW)做法//函数内只会调用两次递归(第二次直接返回)
    if(dp[i][j]>=0){//已计算过
        return dp[i][j];
    }
    int res;
    if(i==n){//无物可装
        res=0;
    }
    else if(j<w[i]){//装不下
        res=rec(i+1,j);
    }
    else {
        res=max(rec(i+1,j),rec(i+1,j-w[i])+v[i]);
    }
    return dp[i][j]=res;
}
void solve(){
    memset(dp,-1,sizeof(dp));//O(n)
    cout<<rec(0,W)<<endl;
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

