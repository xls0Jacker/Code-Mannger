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
const int MAX_N=10000;
const int MAX_M=2e5;
// 拯救你的猫 Save your cats
// 1≤N≤10000 1≤M≤2e5
// −10000≤x,y≤10000 1≤p,q≤N

//思路：
//求解删除的最小代价，
//即是求所有边的代价和-最大生成树

//解决方法：
//使用一个二维数组任意两点间的距离存储距离，（优化：写一个函数来得到距离，减少一定的时间和空间复杂度）
//连边时调用这个数组（注意是双向边），
//并且把边的距离求和，
//之后根据题目输入及数据特点，
//使用krsukal算法求最大生成树（边改为负权，结果加上负号）


//但是！此方法误差过大，无法通过！

//优化思路：
//将krsukal算法改写，
//使same()时答案改写，
//这样就排除了减法的误差了
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
    int u,v;
    double cost;
};
bool cmp(const Edge& e1,const Edge& e2){
    return e1.cost<e2.cost;
}

Edge eg[MAX_M+1];
int N,M;

double krsukal(){
    sort(eg,eg+M,cmp);
    Init(N);
    double res=0;//!!!
    rep(0,i,M){
        Edge e=eg[i];
        if(!same(e.u,e.v)){//加入之前u和v不在同一个连接分量中
            unite(e.u,e.v);//将连接顶点u和顶点v的边e加入到生成树中
        }
        else {
            res+=e.cost;//注意，是改这里！
        }
    }
    return res;
}

struct st{
    double x,y;
}node[MAX_N+1];

double Get_d(int x,int y){//求解两点间的距离
    return sqrt((node[x].x-node[y].x)*(node[x].x-node[y].x)+(node[x].y-node[y].y)*(node[x].y-node[y].y));
}
void solve(){
    double ans=-krsukal();
    printf("%.3lf\n",ans);
}

int main(){
    //ios_base::sync_with_stdio(false);
    //cin.tie(NULL);
    frep;
    cin>>N>>M;
    rep(0,i,N){
        cin>>node[i].x>>node[i].y;
    }
    int x,y;
    rep(0,i,M){
        cin>>x>>y;
        x--,y--;
        eg[i]=(Edge){x,y,-Get_d(x,y)};
    }
    solve();
    frepC;
    sys;
    return 0;
}

