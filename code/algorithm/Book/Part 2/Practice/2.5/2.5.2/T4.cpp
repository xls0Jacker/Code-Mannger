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
const int MAX_N=2000,MAX_M=10000;
// 干草吃完了 Out of Hay
// 2≤N≤2000 1≤M≤10000
// 1≤A,B≤N,1≤L≤1,000,000,000

//猜想：
//输出最小生成树的最长边

//解决方法：
//考虑到数据的输入方式及规模，
//我们使用kruskal算法来求最小生成树，
//将每次所加的值放置于一个数组中，
//最后输出数组最大值即可

//猜想正确

//证明：
//

int par[MAX_N+1],_rank[MAX_N+1];//数组par表示的是父亲的编号 par[x]=x时，x是所在树的根
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
struct Edge{
    int u,v,cost;
};
bool cmp(const Edge& e1,const Edge& e2){
    return e1.cost<e2.cost;
}

Edge eg[MAX_M+1];
int N,M;
int a[MAX_M+1];
int cnt;
void krsukal(){
    sort(eg,eg+M,cmp);
    Init(N);
    rep(0,i,M){
        Edge e=eg[i];
        if(!same(e.u,e.v)){//加入之前u和v不在同一个连接分量中
            unite(e.u,e.v);//将连接顶点u和顶点v的边e加入到生成树中
            a[cnt++]=e.cost;
        }
    }
}

void solve(){
    krsukal();
    cout<<*max_element(a,a+cnt)<<endl;
}

int main(){
    //ios_base::sync_with_stdio(false);
    //cin.tie(NULL);
    frep;
    cin>>N>>M;
    int A,B,L;
    rep(0,i,M){
        cin>>A>>B>>L;
        eg[i]=(Edge){A,B,L};
    }
    solve();
    frepC;
    sys;
    return 0;
}

