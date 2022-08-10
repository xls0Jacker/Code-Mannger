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
const int MAX_E=1e4;
//Kruskal 最小生成树
//按照边的权值的顺序从小到大查看一遍
//如果不产生圈(重边也算在内)，将这一条边加入到生成树中
//(原理证明与Prim算法类似)
//判断圈的方法：
//现将连接顶点u和顶点v的边e加入到生成树中
//如果加入之前u和v不在同一个连接分量中,那么加入e不会产生圈
//反之，产生圈
const int MAX_N=1e6;
int par[MAX_N],_rank[MAX_N];//数组par表示的是父亲的编号 par[x]=x时，x是所在树的根
//并查集的实现
void Init(int n){//初始化
    rep(0,i,n){
        par[i]=i;
        _rank[i]=0;
    }
}

int find(int x){//查询x的根
    if(par[x]==x){
        return x;
    }
    else {
        return par[x]=find(par[x]);
    }
}

void unite(int x,int y){//合并x和y所属的集合
    x=find(x);
    y=find(y);
    if(x==y){//本身就在同一集合
        return;
    }
    //rank不同
    if(_rank[x]<_rank[y]){//rank小的向rank大的连边
        par[x]=y;
    }
    else {
        par[y]=x;
        if(_rank[x]==_rank[y]) _rank[x]++;//x的高度增加
    }
    
}

bool same(int x,int y){//判断x和y是否属于同一集合
    return find(x)==find(y);
}

//<!------------------------------------->//
struct edge{
    int u,v,cost;
};
bool cmp(const edge& e1,const edge& e2){
    return e1.cost<e2.cost;
}

edge es[MAX_E];
int V,E;

int krsukal(){
    sort(es,es+E,cmp);
    Init(V);
    int res=0;
    rep(0,i,E){
        edge e=es[i];
        if(!same(e.u,e.v)){//加入之前u和v不在同一个连接分量中
            unite(e.u,e.v);//将连接顶点u和顶点v的边e加入到生成树中
            res+=e.cost;
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

