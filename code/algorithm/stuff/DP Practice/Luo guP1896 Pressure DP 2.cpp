#include"bits/stdc++.h"
#define rep(a,i,n) for(int i=a;i<n;i++)
#define per(a,i,n) for(int i=n;i>a;i--)
#define Rep(a,i,n) for(int i=a;i<=n;i++)
#define Per(a,i,n) for(int i=n;i>=a;i--)
#define frep freopen("in.txt","r",stdin)
#define frepC freopen("CON","r",stdin)
#define sys system("pause")
using namespace std;
//不知道哪里错了
typedef long long ll;
const int MAX=11;
ll dp[MAX][MAX*MAX*2][1<<MAX];//第i行 该行成立的j状态下 k为国王的方案数
int status[1<<MAX];//存各行的成立状态数目和
int Num[1<<MAX];//成立状态下的国王数目
int n,k;//棋盘大小 国王数目
int s;//每一行合理状态数
void Pre(){//找到这一行行成立状态 及该状态下的国王数目//每一行Pre都是相同的，所以相当于每一行的Pre
    rep(0,i,1<<n){
        if(i & (i<<1)) continue;//判断行冲突
        int tmp=0;
        rep(0,j,n){//左移0~(n-1)位//1原本在第一位，这样可以完成所有遍历
            if(i & (1<<j)) tmp++;
        }
        status[s++]=i;//存合理状态
        Num[s]=tmp;//该状态下成立的国王数目
    }
}
ll ANS;
void DP(){
    //memset(dp,0,sizeof(dp));
    dp[0][1][0]=1;//初始化 第0行方0个国王的方案数为1
    Rep(1,i,n){//列举每一行
        Rep(1,j,s){//取一行的可用情况
            Rep(0,u,k){//列举每一个国王，找该行的成立条件
                if(u>=Num[j]){
                    Rep(1,v,s){//取i-1行的可用情况
                        if(!(status[v]&status[j]) and 
                        !(status[v]&(status[j]<<1)) and 
                        !(status[v]&(status[j]>>1))){//成立条件
                            dp[i][j][u]+=dp[i-1][v][u-Num[j]];
                        }
                    }
                }
            }
        }
    }
    Rep(1,i,s) ANS+=dp[n][i][k];//取k个国王下各成立状态下放置的方案数总和
    cout<<ANS<<endl;
}

void solve(){
    cin>>n>>k;
    Pre();
    DP();
}

int main(){
    frep;
    solve();
    frepC;
    sys;
    return 0;
}

