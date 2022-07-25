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
const int MAX_N=5005;
const int INF=1e9+7;
//Roadblocks
//1<=N<=5000 1<=R<=1e5
//到某个顶点v的次短路要不是到其他某个顶点u的最短路加上u->v的边
//要不是到其他某个顶点u的次短路加上u->v的边
//因此我们不仅要记录最短路距离，还要记录次短路的距离
//在dijkstra的算法上进行适当改写即可完成目标
struct edge{
    int from,to,cost;
};
typedef pair<int,int> P;

vector<edge> G[MAX_N];
int N,R;
int dist[MAX_N];
int dist2[MAX_N];
void add_edge(int a,int b,int c){
    G[a].push_back({a,b,c});
}

void solve(){
    priority_queue<P,vector<P>,greater<P>> que;
    fill(dist,dist+N,INF);
    fill(dist2,dist2+N,INF);
    dist[0]=0;
    que.push(P(0,0));
    while(!que.empty()){
        P p=que.top();que.pop();
        int v=p.second,d=p.first;
        if(dist2[v]<d) continue;//该顶点已找到次短距离
        rep(0,i,G[v].size()){
            edge &e=G[v][i];
            int d2=d+e.cost;//假设该路径为次短路
            if(dist[e.to]>d2){//若该路径为最短路，值交换    
                swap(dist[e.to],d2);
                que.push(P(dist[e.to],e.to));
            }
            if(dist2[e.to]>d2 and dist[e.to]<d2){//存储最小次短路径
                dist2[e.to]=d2;
                que.push(P(dist2[e.to],e.to));
            }
        }
    }
    cout<<dist2[N-1]<<endl;
}

int main(){
    //ios_base::sync_with_stdio(false);
    //cin.tie(NULL);
    frep;
    cin>>N>>R;
    int xx,yy,vv;
    rep(0,i,R){
        cin>>xx>>yy>>vv;
        xx--,yy--;
        add_edge(xx,yy,vv);
        add_edge(yy,xx,vv);
    }
    solve();
    frepC;
    sys;
    return 0;
}

