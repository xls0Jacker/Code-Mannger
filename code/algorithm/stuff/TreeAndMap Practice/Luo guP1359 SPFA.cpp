#include"bits/stdc++.h"
#define sys system("pause")
#define rep(a,i,n) for(int i=a;i<n;i++)
#define per(a,i,n) for(int i=n;i>a;i--)
#define Rep(a,i,n) for(int i=a;i<=n;i++)
#define Per(a,i,n) for(int i=n;i>=a;i--)
#define frep freopen("in.txt","r",stdin)
#define frepC freopen("CON","r",stdin)
using namespace std;
//SPFA//TLE两个

//链式向前星
const int MAX=1e5;

struct Edge{
    int u,v;
    int l;
    int next;
}eg[MAX];

int head[MAX],counts;

//加边
void add_edge(int a,int b,int c){
    counts++;
    eg[counts].u=a;eg[counts].v=b;eg[counts].l=c;
    eg[counts].next=head[a];
    head[a]=counts;
}

//SPFA
int dis[MAX];//dis[i] 源点s->i的最短距离
bool inq[MAX];//inq[i] 表示i是否在对列
const int INF=0x3f3f3f3f;
int n;//节点数

void spfa(int s){//源点
    for(int i=1;i<=n;i++){//所有点距离更新为无穷大 且状态为不在队中
        dis[i]=INF;
        inq[i]=false;
    }
    //加入源点开始寻找最短路径
    dis[s]=0;
    queue<int> q;
    q.push(s);
    inq[s]=true;
    //类bfs
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
    cout<<dis[n]<<endl;
}

//stuff
void solve(){
    cin>>n;
        int value;
        Rep(1,i,n){
            Rep(i+1,j,n){
            cin>>value;
            add_edge(i,j,value); 
            }
        }
    spfa(1);
}

int main(){
    frep;
    solve();
    frepC;
    sys;
    return 0;
}
