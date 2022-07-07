#include"bits/stdc++.h"
#define rep(a,i,n) for(int i=a;i<n;i++)
#define per(a,i,n) for(int i=n;i>a;i--)
#define Rep(a,i,n) for(int i=a;i<=n;i++)
#define Per(a,i,n) for(int i=n;i>=a;i--)
#define frep freopen("in.txt","r",stdin)
#define frepC freopen("CON","r",stdin)
#define sys system("pause")
using namespace std;
const int MAX=1e6;
int n,m;
struct Edge{
    int u,v;
    int l;
    int next;
}eg[MAX];

int head[MAX],counts;
void add_edge(int a,int b,int c){
    counts++;
    eg[counts].u=a; eg[counts].v=b; eg[counts].l=c;
    eg[counts].next=head[a];
    head[a]=counts;
}

int dis[MAX];
bool vis[MAX];
void bfs(int s){
    queue<int>q;
    q.push(s);
    while(!q.empty()){
        int u=q.front();
        q.pop();
        if(vis[u]) continue;
        vis[u]=1;
        for(int i=head[u];i;i=eg[i].next){
            int v=eg[i].v,l=eg[i].l;
            if(!vis[v]){
                dis[v]=dis[u] xor l;
                q.push(v);
            }
        }
    }
}
void solve(){
    int q;
    cin>>n>>m>>q;
    int x,y,value;
    Rep(1,i,m){
        cin>>x>>y>>value;
        add_edge(x,y,value);
        add_edge(y,x,value);
    }
    bfs(1);
    int u,v;
    Rep(1,i,q){
        cin>>u>>v;
        cout<<(dis[u] xor dis[v])<<endl;
    }
}

int main(){
    frep;
    solve();
    frepC;
    sys;
    return 0;
}

