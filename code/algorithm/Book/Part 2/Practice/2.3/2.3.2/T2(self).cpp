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
const int MAX_A=1e6;
const int MAX_T=1000;
// 蚂蚁问题 Ant Counting
// 1≤T≤1000,1≤S≤B≤A

//题目大意:
//对于任取S个到B个（S<B）数，求其最大的组成的不同集合的数目之和；

//对于每一个数均有取与不取的区别，
//每一段数互不影响，
//对每一段判断有多少种不同的集合即可
//定义dp[i][j][k]为到第i段的j位置时当前集合数的数目为k时的最大组合种类数，有
//dp[i][j+1][k]={
//dp[i][j][k+1]+1 选
//dp[i][j][k] 不选
//}

//空间优化一下，
//dp[j&1][k]={
//dp[(j+1)&1][k+1]+1  选
//dp[j&1][k] 不选
//}

//再优化：
//dp[j&1]={
//dp[(j+1)&1]+1 选
//dp[j&1] 不选
//}
//解决方法：
//先将类型按照升序排列，（解决无序问题）
//到达其段的最大值后判断是否出现过，
//最后将结果求和输出
int T,A,S,B;
int a[MAX_A+1];
int dp[2];
void solve(){
    Rep(S,i,B){
        int k=0;
        rep(0,j,A){
            
        }
    }
}

int main(){
    //ios_base::sync_with_stdio(false);
    //cin.tie(NULL);
    frep;
    cin>>T>>A>>S>>B;
    rep(0,i,A){
        cin>>a[i];
    }
    solve();
    frepC;
    sys;
    return 0;
}

