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
const int MAX_N=100;
const int INF=1e9+7;
// 连接农场 Agri-Net
// 3≤N≤100 
// 保证多组测试数据的 N 总和不超过 100

//思路：
//最小生成树模板题，
//考虑到题目说了为邻接矩阵，
//这里使用Prim算法求解最小生成树
int cost[MAX_N+1][MAX_N+1];//有权图邻接矩阵
int mincost[MAX_N+1];
bool used[MAX_N+1];
int N;

int prim(){
    rep(0,i,N){
        mincost[i]=INF;
        used[i]=false;
    }
    mincost[0]=0;
    int res=0;
    while(true){
        int v=-1;
        rep(0,u,N){
            if(!used[u] and (v==-1 or mincost[u]<mincost[v])){
                v=u;
            }
        }
        if(v==-1) break;
        used[v]=true;
        res+=mincost[v];
        rep(0,u,N){
            mincost[u]=min(mincost[u],cost[v][u]);
        }
    }
    return res;
}
void solve(){
    cout<<prim()<<endl;
}

int main(){
    //ios_base::sync_with_stdio(false);
    //cin.tie(NULL);
    frep;
    while(cin>>N){
        memset(cost,0,sizeof(cost));
        memset(mincost,0,sizeof(mincost));
        memset(used,0,sizeof(used));
        rep(0,i,N){
            rep(0,j,N){
                cin>>cost[i][j];
            }
        }
        solve();
    }
    frepC;
    sys;
    return 0;
}

