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
const int MAX_N=1e4;
const int MAX_M=2e4;
const int INF=1e9+7;
// 道路建设 Road Construction
// 1≤N≤10000 0≤M≤20000
// 1≤u,v≤N,1≤d≤1000,1≤c≤1000

//思路：
//改写dijkstra最短路算法，
//使其在计算最短路径时同时计算最小价格，
//保证在多个最短路径中选出价格最小的方案。
struct Edge{
    int v;
    int d;//最短路径
    int c;//修建花费
};
vector<Edge> eg[MAX_M+1];

void add_edge(int x,int y,int z,int w){
    eg[x].push_back({y,z,w});
}

int N,M;
void prev(){
    rep(0,i,N){
        eg[i].clear();
    }
    int u,v,d,c;
    rep(0,i,M){
        cin>>u>>v>>d>>c;
        u--,v--;
        add_edge(u,v,d,c);
        add_edge(v,u,d,c);
    }
}

bool operator>(Edge a,Edge b){//按最短路径下的最小价格排列
    if(a.d==b.d) return a.c>b.c;
    else return a.d>b.d;
}

ll ans;
bool vis[MAX_N+1];
void dijkstra(int s){
    ans=0;
    memset(vis,0,sizeof(vis));
    priority_queue<Edge,vector<Edge>,greater<Edge>> q;
    q.push({s,0,0});
    while(q.size()){
        Edge p=q.top(); q.pop();
        int v=p.v;
        if(vis[v]) continue;
        vis[v]=true;
        ans+=p.c;
        for(int i=0;i<eg[v].size();i++){
            Edge e=eg[v][i];
            q.push({eg[v][i].v,p.d+eg[v][i].d,eg[v][i].c});
        }
    }
}
void solve(){
    dijkstra(0);
    cout<<ans<<endl;
}

int main(){
    //ios_base::sync_with_stdio(false);
    //cin.tie(NULL);
    frep;
    while(cin>>N>>M and N!=0 and M!=0){
        prev();
        solve();
    }
    frepC;
    sys;
    return 0;
}

