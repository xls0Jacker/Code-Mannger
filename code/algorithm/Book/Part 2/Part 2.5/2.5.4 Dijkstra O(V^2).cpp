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
const int MAX_V=1e6,MAX_E=1e6;
const int INF=1e9+7;
//Dijkstra 单源最短路
//对Bellman_Ford算法进行以下修改：
//1. 找到最短距离已经确定的顶点，从它出发更新相邻顶点的最短距离
//2. 此后不需要再关心1中的"最短距离已经确定的顶点"
int cost[MAX_V][MAX_E];//cost[u][v]表示边e=(u,v)的权值（不存在时设为INF）
int d[MAX_V];//顶点s出发的最短距离
bool used[MAX_V];//已经过的图
int V;
void dijkstra(int s){//O(|V|^2)
    fill(d,d+V,INF);
    fill(used,used+V,false);
    d[s]=0;

    while(true){
        int v=-1;
        rep(0,u,V){//从尚未使用的顶点中选则一个距离最小的顶点
            if(!used[u] and (v==-1 or d[u]<d[v])) v=u;
        }
        if(v==-1) break;
        used[v]=true;
        
        rep(0,u,V){//更新v到所有点的最短距离
            d[u]=min(d[u],d[v]+cost[v][u]);
        }
    }

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

