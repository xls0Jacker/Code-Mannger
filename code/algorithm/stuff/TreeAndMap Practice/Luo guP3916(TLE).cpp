#include"bits/stdc++.h"
#define sys system("pause")
#define rep(a,i,n) for(int i=a;i<n;i++)
#define per(a,i,n) for(int i=n;i>a;i--)
#define Rep(a,i,n) for(int i=a;i<=n;i++)
#define Per(a,i,n) for(int i=n;i>=a;i--)
#define frep freopen("in.txt","r",stdin)
#define frepC freopen("CON","r",stdin)
using namespace std;

const int MAX=1e5+10;
int n,m;
struct Edge{
    int u,v;
    int l;
    int next;
}eg[MAX];

int head[MAX],counts;
void add_edge(int a,int b){
    counts++;
    eg[counts].u=a;eg[counts].v=b;eg[counts].l=1;
    eg[counts].next=head[a];
    head[a]=counts;
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
            int v=eg[i].v,l=eg[i].l;
            if(dis[v]>dis[u]+l){
                dis[v]=dis[u]+l;
                q.push(mii(dis[v],v));
            }
        }
    }
}

bool f;
int tmp[MAX];
void distance(){
    f=0;
    Rep(1,i,n){
        dijk(i);
        int cnt=0;
        Rep(1,j,n){
            if(dis[j]==0x3f3f3f3f){
                dis[j]=-1;
            }
            else{
                cnt++;//从1开始
                tmp[cnt]=j;
            }
        }
        sort(tmp+1,tmp+cnt+1,greater<int>());
        cout<<tmp[1]<<" ";
    }
}



void solve(){
    cin>>n>>m;
    int x,y;
    Rep(1,i,m){
        cin>>x>>y;
        add_edge(x,y);
    }
    distance();
    cout<<endl;
}

int main(){
    frep;
    solve();
    frepC;
    sys;
    return 0;
}

