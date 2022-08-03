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
const int MAX_X=300,MAX_Y=300;
const int INF=1e9+7;
//Meteor Shower
//1≤M≤50000 0<=Xi,Yi<=300 0<=Ti<=1000

//思路：
//想象每一个流星为5个砸一个格子的障碍物
//不断更新各障碍物的最小出现时间（预先将每一格设为INF，若全部处理完成后仍为INF则为安全点）
//再用一个数组来存到达点(i,j)的最短时间
//当这个点为安全点时跳出
//每一步的可走条件为：
//在第一象限内 到达上一步的最短时间+1<当前格子流星下坠的最短时间 当前格子未走过（若预设未INF，未走过则为INF）
int MinDL[MAX_X+5][MAX_Y+5];//流星最小下坠时间(Minimum Deadline)
int MinT[MAX_X+5][MAX_Y+5];//到达当前位置的最短时间
//人可以逃到流星雨范围外，数组开大一些
int M;//流星数目

void prev(){//预处理
    rep(0,i,305){
        rep(0,j,305){
            MinDL[i][j]=INF;
            MinT[i][j]=INF;
        }
    }
}

int xx[]={1,-1,0,0};
int yy[]={0,0,1,-1};
void DeadLine(int x,int y,int t){//找出流星下坠最短时间
    MinDL[x][y]=min(t,MinDL[x][y]);
    rep(0,i,4){
        int dx=x+xx[i],dy=y+yy[i];
        if(dx<0 or dy<0) continue;//流星砸到第一象限外面（此处第一象限指以0为起点）
        MinDL[dx][dy]=min(t,MinDL[dx][dy]);
    }
}

struct st{//坐标
    int x,y;
};

int bfs(){
    if(MinDL[0][0]==0){//起点就不合法
        return -1;
    }
    queue<st>q;
    q.push({0,0});
    MinT[0][0]=0;
    while(q.size()){
        st res=q.front();q.pop();
        if(MinDL[res.x][res.y]==INF) return MinT[res.x][res.y];
        rep(0,i,4){
            int dx=res.x+xx[i],dy=res.y+yy[i];
            if(dx<0 or dy<0 or MinT[dx][dy]!=INF or MinT[res.x][res.y]+1>=MinDL[dx][dy]) continue;//可走条件不符
            q.push({dx,dy});
            MinT[dx][dy]=MinT[res.x][res.y]+1;
        }
    }
    return -1;//走不到安全点
}

void solve(){
    int ans=bfs();
    cout<<ans<<endl;
}

int main(){
    //ios_base::sync_with_stdio(false);
    //cin.tie(NULL);
    frep;
    cin>>M;
    int X,Y,T;
    prev();//预设数组为INF
    rep(0,i,M){//找出流星下坠最短时间
        cin>>X>>Y>>T;
        DeadLine(X,Y,T);
    }
    solve();
    frepC;
    sys;
    return 0;
}

