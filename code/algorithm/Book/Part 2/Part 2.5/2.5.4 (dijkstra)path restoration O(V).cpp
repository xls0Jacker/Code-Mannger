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
const int MAX_V=1e4,MAX_E=1e4;
const int INF=1e9+7;
//Dijkstra 单源最短路
//路径还原
//满足d[j]=d[k]+cost[k][j]的顶点k即是j的前驱节点
//此时用数组prev[j]=k
//在计算s到j的最短路时，不断把prev[j]替换直至j=s为止即可
//Bellman-Ford和Floyd-Warshall同理
int cost[MAX_V][MAX_E];//cost[u][v]表示边e=(u,v)的权值（不存在时设为INF）
int d[MAX_V];//顶点s出发的最短距离
bool used[MAX_V];//已经过的图
int V;

int _prev[MAX_V];//最短路上的前驱节点
void dijkstra(int s){//O(|V|^2)
    fill(d,d+V,INF);
    fill(used,used+V,false);

    fill(_prev,_prev+V,-1);

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
            _prev[u]=v;
        }
    }
}

vector<int> get_path(int t){
    vector<int>path;
    for(;t!=-1;t=_prev[t]) path.push_back(t);//不断沿着pre[t]走直到t=s
    reverse(path.begin(),path.end());//这样得到的时t到s的顺序，所以翻转一下
    return path;
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

