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
//多源最短路转单源最短路 反向建边
const int MAX=1e6;
int n,m;
struct Edge{
    int u,v;
    int l;
    int next;
}eg[MAX];
int head[MAX],cnt;
void add_edge(int a,int b,int c){
    cnt++;
    eg[cnt].u=a; eg[cnt].v=b;
    eg[cnt].l=c;
    eg[cnt].next=head[a];
    head[a]=cnt;
}

int dis[MAX];
bool vis[MAX];
void dijk(int s){
    memset(dis,0x3f,sizeof(dis));
    memset(vis,0,sizeof(vis));
    dis[s]=0;
    typedef pair<int,int> pii,mii;
    priority_queue<pii,vector<pii>,greater<pii>> q;
    q.push(mii(0,s));
    while(!q.empty()){
        int u=q.top().second;
        q.pop();
        if(vis[u]) continue;
        vis[u]=1;
        for(int i=head[u];i;i=eg[i].next){
            int v=eg[i].v; int l=eg[i].l;
            if(dis[v]>dis[u]+l){
                dis[v]=dis[u]+l;
                q.push(mii(dis[v],v));
            }
        }
    }
}
int sum;
int xx[MAX],yy[MAX],vv[MAX];
void solve(){
    cin>>n>>m;
    Rep(1,i,m){
        cin>>xx[i]>>yy[i]>>vv[i];
        add_edge(xx[i],yy[i],vv[i]);
    }
    dijk(1);
    Rep(1,i,n){//出发时间
        sum+=dis[i];
    }
    memset(head,0,sizeof(head));
    Rep(1,i,m){
        add_edge(yy[i],xx[i],vv[i]);
    }
    dijk(1);
    Rep(1,i,n){//返回时间
        sum+=dis[i];
    }
    cout<<sum<<endl;
}

int main(){
    frep;
    solve();
    frepC;
    sys;
    return 0;
}

