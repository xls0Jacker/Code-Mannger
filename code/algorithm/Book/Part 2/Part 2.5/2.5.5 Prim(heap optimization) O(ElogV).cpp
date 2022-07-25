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
const int MAX_V=1e4;
const int INF=1e9+7;
//Prim 最小生成树 堆优化
struct edge{
    int to,cost;
};
typedef pair<int,int> P;

int mincost[MAX_V];//从集合x出发的边到每一个顶点的最小权值
bool vis[MAX_V];//顶点i是否在集合x中
int V;

vector<edge>eg[MAX_V];

int prim(){
    rep(0,i,V){
        mincost[i]=INF;
        vis[i]=false;
    }
    mincost[0]=0;
    int res=0;
    priority_queue<P,vector<P>,greater<P>> que;
    que.push(P(0,0));//集合间边的最小权值 集合V\X的顶点
    int res=0;
    while(!que.empty()){
        P p=que.top();que.pop();
        int v=p.second;
        vis[v]=true;//把顶点加入X
        if(mincost[v]<p.first) continue;
        rep(0,i,eg[v].size()){
            edge e=eg[v][i];
            if(!vis[e.to] and mincost[e.to]>e.cost){
                res+=e.cost;
                if(mincost[e.to]!=INF){
                    res-=e.cost;
                }
            }
            mincost[e.to]=e.cost;
            que.push(P(mincost[e.to],e.to));
        }
    }
    return res;
}

void solve(){
    
}

int main(){
    //ios_base::sync_with_stdio(false);
    //cin.tie(NULL);
    frep;
    solve();
    frepC;
    sys;
    return 0;
}

