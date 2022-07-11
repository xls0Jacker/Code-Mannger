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
//1. 找最长路 2. 找路径
const int MAX=1e5;
struct Edge{
    int u,v;
    int l=-1;
    int next;
}eg[MAX];
int head[MAX],cnt;
void add_edge(int a,int b){
    cnt++;
    eg[cnt].u=a;eg[cnt].v=b;
    eg[cnt].next=head[a];
    head[a]=cnt;
}
int dis[MAX];
bool inq[MAX];
const int INF=0x3f3f3f3f;
int n;
void spfa(int s){
    for(int i=1;i<=n;i++){
        dis[i]=INF;
        inq[i]=false;
    }
    dis[s]=0;
    queue<int> q;
    q.push(s);
    inq[s]=true;
    while(!q.empty()){
        int u=q.front();
        q.pop();
        inq[u]=false;
        for(int i=head[u];i;i=eg[i].next){
            int v=eg[i].v;
            if(dis[u]+eg[i].l<dis[v]){
                dis[v]=dis[u]+eg[i].l;
                if(!inq[v]){
                    q.push(v);
                    inq[v]=true;
                }
            }
        }
    }
}

void solve(){
    cin>>n;
    int k;
    rep(0,i,n){
        cin>>k;
        int y;
        Rep(1,j,k){
            cin>>y;
            add_edge(i,y);
        }
    }
    spfa(0);
    sort(dis,dis+n);
    cout<<-dis[0]+1<<endl;//包括本身
}

int main(){
    frep;
    solve();
    frepC;
    sys;
    return 0;
}

