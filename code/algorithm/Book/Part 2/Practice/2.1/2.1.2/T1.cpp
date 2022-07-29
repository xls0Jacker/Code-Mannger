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
const int MAX_H=1000,MAX_W=1000;
//奶酪 Cheese
//1≤H≤1000,1≤W≤1000,1≤N≤9

//思路：
//初始体力为0 
//要保证可以吃到奶酪，
//奶酪工厂的数值必定从1逐一升到N，
//只要从1开始逐位找，每次求出最短路即可
//找得到增量不为零
//找不到增量为0（题目保证一定有路，可以不考虑）
int H,W,N;
char M[MAX_H+1][MAX_W+1];
bool vis[MAX_H+1][MAX_W+1];
int Sx,Sy;
int xx[]={-1,1,0,0};
int yy[]={0,0,1,-1};

struct st{//坐标
    int x,y;
    int dis;
};
int bfs(int Fx,int Fy){//终点坐标
    queue<st>q;
    q.push({Sx,Sy,0});
    vis[Sx][Sy]=1;//标记起点
    while(!q.empty()){
        st res=q.front();q.pop();
        if(res.x==Fx and res.y==Fy) return res.dis;//找到终点
        rep(0,i,4){
            int dx=res.x+xx[i];
            int dy=res.y+yy[i];
            int dist=res.dis+1;
            //（奶酪工厂不吃也可以走）
            if(vis[dx][dy] or (dx<0 or dx>=H or dy<0 or dy>=W) or M[dx][dy]=='X') continue;
            q.push({dx,dy,dist});
            vis[dx][dy]=1;
        }
    }
    return 0;//没路（题目保证一定有路，可以不考虑）
}
char n;
char sign='1';
int sum=0;
void Find(){
    rep(0,i,H){
        rep(0,j,W){
            if(M[i][j]==sign and sign!=n){
                int cnt=bfs(i,j);//路程增量
                Sx=i,Sy=j;//更新起点
                sign=sign+1;//（冷知识：'9'+1=':'）
                sum+=cnt;
                return;
            }
        }
    }
}
void solve(){
    n=N+'0'+1;//化为字符
    while(sign!=n){
        memset(vis,0,sizeof(vis));
        Find();
    }
    cout<<sum<<endl;
}

int main(){
    //ios_base::sync_with_stdio(false);
    //cin.tie(NULL);
    frep;
    cin>>H>>W>>N;
    rep(0,i,H){
        rep(0,j,W){
            cin>>M[i][j];
            if(M[i][j]=='S'){
                Sx=i,Sy=j;
            }
        }
    }
    solve();
    frepC;
    sys;
    return 0;
}

