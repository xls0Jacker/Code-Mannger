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
const int MAX_N=1005,MAX_ML=10005,MAX_MD=10005;
const int INF=1e9+7;
//Layout
//2<=N<=1000 1<=ML,MD<=10000 1<=AL<BL<=N 1<=AD<BD<=N 1<=DL,DD<=1e6
//按照题意有:(记每头牛的位置为d[i])
//d[i]<=d[i+1](牛是按照编号进行排列的)
//d[AL]+DL>=d[BL]
//d[AD]+DD<=d[BD]
//我们发现有一个共同特点：
//关系式两边都只出现了一个变量（差分约束系统）
//因此，对于每条权值为w的边e=(v,u)，都有d(v)+w>=d(u)成立（d(v)表示s到v的最短距离）
//故我们做以下转换：
//d[i+1]+0>=d[i]
//d[AL]+DL>=d[BL]
//d[BD]-DD>=d[AD]
//由于存在负权，我们使用Ballman-Ford算法求解
int N,ML,MD;//牛个数 关系好牛对数 关系差牛对数
int AL[MAX_ML],BL[MAX_ML],DL[MAX_ML];//好牛对
int AD[MAX_MD],BD[MAX_MD],DD[MAX_MD];//差牛对

int d[MAX_N];//最短距离
bool updated;//是否更新

void update(int &x,int y){//简化运算
    if(x>y){
        x=y;
        updated=true;
    }
}
void bellmanford(){
    Rep(0,k,N){
        updated=false;
        rep(0,i,N-1){
            if(d[i+1]<INF) update(d[i],d[i+1]);
        }
        rep(0,i,ML){
            if(d[AL[i]-1]<INF) update(d[BL[i]-1],d[AL[i]-1]+DL[i]);
        }
        rep(0,i,MD){
            if(d[BD[i]-1]<INF) update(d[AD[i]-1],d[BD[i]-1]-DD[i]);
        }
    }
}
void solve(){
    //检查负圈
    fill(d,d+N,0);
    bellmanford();
    if(updated){
        cout<<-1<<endl;
        return;
    }

    fill(d,d+N,INF);
    d[0]=0;
    bellmanford();
    int res=d[N-1];
    if(res==INF) res=-2;
    cout<<res<<endl;
}

int main(){
    //ios_base::sync_with_stdio(false);
    //cin.tie(NULL);
    frep;
    cin>>N>>ML>>MD;
    rep(0,i,ML){
        cin>>AL[i]>>BL[i]>>DL[i];
    }
    rep(0,i,MD){
        cin>>AD[i]>>BD[i]>>DD[i];
    }
    solve();
    frepC;
    sys;
    return 0;
}

