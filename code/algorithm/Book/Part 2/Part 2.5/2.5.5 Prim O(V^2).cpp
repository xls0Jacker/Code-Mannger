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
const int MAX_V=1e4;
const int INF=1e9+7;
//Prim 最小生成树
//在集合X和V\X之间的边找到一条权值最短的边
//将这条边加入树T
//此时必定会产生一个圈
//也必然有一条与e不同的边f连接着集合X和V\X
//此时删去f边就得到了一棵新的生成树
//就这样不断加入新的边直到X=V
//此时就得到了一棵最小生成树
int cost[MAX_V][MAX_V];//cost[u][v]表示u->v的权值 (不存在情况下设为INF)
int mincost[MAX_V];//从集合x出发的边到每一个顶点的最小权值
bool used[MAX_V];//顶点i是否在集合x中
int V;//顶点数

int prim(){//O(|V|^2)
    rep(0,i,V){//O(|V|)
        mincost[i]=INF;
        used[i]=false;
    }
    mincost[0]=0;
    int res=0;
    while(true){//O(|V|^2)
        int v=-1;
        rep(0,u,V){//从不属于X的顶点中选取到其权值最小的顶点
            if(!used[u] and (v==-1 or mincost[u]<mincost[v])){
                v=u;
            }
        }
        if(v==-1) break;//找不到
        used[v]=true;//把顶点v加入X
        res+=mincost[v];//把边的长度加到结果里
        rep(0,u,V){
            mincost[u]=min(mincost[u],cost[v][u]);
        }
    }
    return res;
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

