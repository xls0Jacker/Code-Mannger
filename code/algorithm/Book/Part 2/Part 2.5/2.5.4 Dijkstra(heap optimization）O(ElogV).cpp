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
//Dijkstra 堆优化 
//使用优先队列来寻找未访问过的最小值
struct edge{
    int from,to,cost;
};
typedef pair<int,int> P;

int V;
vector<edge> G[MAX_V];
int d[MAX_V];
void dijkstra(int s){//O(|E|log|V|)
    priority_queue<P,vector<P>,greater<P>> que;//按照first由小到大排
    fill(d,d+V,INF);
    d[s]=0;
    que.push(P(0,s));
    while(!que.empty()){
        P p=que.top();que.pop();
        int v=p.second;
        if(d[v]<p.first) continue;//?
        rep(0,i,G[v].size()){
            edge e=G[v][i];
            if(d[e.to]>d[e.from]+e.cost){
                d[e.to]=d[e.from]+e.cost;
                que.push(P(d[e.to],e.to));
            }
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

