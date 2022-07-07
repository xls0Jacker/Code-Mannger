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
int n,m;//结点数目及其坐标 通路数
struct Edge{
    int u,v;
    double l;
    int next;
}eg[MAX];

int head[MAX],counts;
void add_edge(int a,int b,double c){
    counts++;
    eg[counts].u=a; eg[counts].v=b;
    eg[counts].l=c;
    eg[counts].next=head[a];
    head[a]=counts;
}

struct node{//坐标化
    double x,y;
};

double localize(node a,node b){//坐标距离化
    double distance=sqrt((a.x-b.x)*(a.x-b.x)+(a.y-b.y)*(a.y-b.y));
    return distance;//>=0 可用Dijkstra
}

double dis[MAX];
bool inq[MAX];
const double INF=114514;
void spfa(int s){
    Rep(1,i,n){
        dis[i]=INF;
    }
    queue<int>q;
    q.push(s);
    inq[s]=true;
    dis[s]=0;
    while(!q.empty()){
        int u=q.front();
        q.pop();
        inq[u]=false;
        for(int i=head[u];i;i=eg[i].next){
            int v=eg[i].v; double l=eg[i].l;
            if(dis[v]>dis[u]+l){
                dis[v]=dis[u]+l;
                if(!inq[v]) {
                    q.push(v);
                    inq[v]=true;
                }
            }
        }
    }
}

node Node[MAX];
void solve(){
    cin>>n;
    int dx,dy;
    Rep(1,i,n){//存点
        cin>>dx>>dy;
        Node[i].x=dx;
        Node[i].y=dy;
    }
    cin>>m;
    Rep(1,i,m){//建无向图
        cin>>dx>>dy;
        add_edge(dx,dy,localize(Node[dx],Node[dy]));
        add_edge(dy,dx,localize(Node[dx],Node[dy]));
    }
    int s,t;
    cin>>s>>t;
    spfa(s);
    printf("%.2lf\n",dis[t]);
}

int main(){
    frep;
    solve();
    frepC;
    sys;
    return 0;
}

