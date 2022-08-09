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
struct edge{
    int from,to,cost;
};
edge es[MAX_E];
int d[MAX_V];
int V,E;
//Bellman_Ford单源最短路
//对于一个为DAG的图，其可按拓扑序进行编号
//此时有递推关系如下:
//d[i]=min{d[j]+(从j到i边的权值)|e=(j,i)∈E}
//该算法在找单源最短路的同时也可以判断是否有负圈
void shortest_path(int s){//O(V*E)
    rep(0,i,V){
        d[i]=INF;
    }
    d[s]=0;
    while(true){
        bool update=false;
        rep(0,i,E){
            edge e=es[i];
            if(d[e.from]!=INF and d[e.to]>d[e.from]+d[e.cost]){
                d[e.to]=d[e.from]+d[e.cost];
                update=true;
            }
        }
        if(!update) break;
    }
}
//如果存在从s可达的负圈，那么在第|V|次循环中也会更新d的值
bool find_negative_loop(){
    memset(d,0,sizeof(d));
    rep(0,i,V){
        rep(0,j,E){
            edge e=es[j];
            if(d[e.to]>d[e.from]+e.cost){
                d[e.to]=d[e.from]+e.cost;
                if(i==V-1) return true;//如果第V次仍然更新了，则存在负圈
            }
        }
    }
    return false;
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

