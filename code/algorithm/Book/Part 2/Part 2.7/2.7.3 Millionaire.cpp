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
const int MAX_M=15;
//Millinaire
//0<=P<=1.0 1<=X<=1e6 1<=M<=15

//对于最后一场，有3中情况
//1. 持有1e6以上的钱 不需要赌 有1的概率可以带回家
//2. 持有500000以上的钱 全赌 有P的概率带回家
//3. 持有500000及以下的钱 有0的概率带回家
//对于前面几场，钱根据场数不断对折，
//我们可以发现，第一场有2^M+1种可能
//对这几种可能进行穷竭搜索即可
//在此基础上优化为dp即可
int X,M;//初始金额 场次
double P;//每一场的概率
double dp[2][(1<<MAX_M)+1]; 
void solve(){
    //初始化
    int n=1<<M+1;//第一场的可能
    double *prv=dp[0],*nxt=dp[1];
    memset(prv,0,sizeof(double)*(n+1));
    prv[n]=1.0;//第一场的初始概率
    //dp
    rep(0,r,M){
        Rep(0,i,n){//2^M+1种可能
            int jub=min(i,n-i);//后半部分没必要考虑，取前半部分
            double t=0.0;
            Rep(0,j,jub){//对这几种可能计算全概率存进dp
                t=max(t,P*prv[i+j]+(1-P)*prv[i-j]);
            }
            nxt[i]=t;//存入下一场最大概率
        }
        swap(prv,nxt);//向前推进
    }
    int i=(ll)X*n/1000000;
    printf("%.6lf\n",prv[i]);
}

int main(){
    //ios_base::sync_with_stdio(false);
    //cin.tie(NULL);
    frep;
    cin>>M>>P>>X;
    solve();
    frepC;
    sys;
    return 0;
}

