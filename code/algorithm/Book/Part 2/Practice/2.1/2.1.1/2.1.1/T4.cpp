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
const int MAX_H=10,MAX_W=20;
const int INF=114514;
//Curling 2.0
//2<=w<=20 1<=h<=10
//0-->空地
//1-->障碍物
//2-->起点
//3-->终点

//思路：
//当次数超过10次时仍无法到达终点
//若能够到达终点，刷新最小值
//每次找到我的当前非0和2的位置
//为1需要考虑退位，为3不需要
int H,W;
int M[MAX_H][MAX_W];
int Sx,Sy;
int ans;
int xx[]={-1,1,0,0};
int yy[]={0,0,-1,1};
void dfs(int x,int y,int cnt){
    if(cnt==10 and M[x][y]!=3) return;
    else if(M[x][y]==3){
        ans=min(ans,cnt);
        return;
    }
    rep(0,i,4){
        int dx=x+xx[i],dy=y+yy[i];
        if(dx>=0 and dx<H and dy>=0 and dy<W){
            if(M[dx][dy]==1) continue;
        }
        while(dx>=0 and dx<H and dy>=0 and dy<W and M[dx][dy]!=3 and M[dx][dy]!=1){//找1或着3
            dx+=xx[i],dy+=yy[i];
        }
        if(dx<0 or dx>=H or dy<0 or dy>=W) continue;//没找到1或者3
        int sign=M[dx][dy];
        int tx=dx,ty=dy;
        if(M[dx][dy]==1){//若找到1 还原位置
            M[dx][dy]=0;//摧毁障碍物
            dx-=xx[i],dy-=yy[i];
        }
        dfs(dx,dy,cnt+1);
        M[tx][ty]=sign;//还原标记
    }
}
void solve(){
    dfs(Sx,Sy,0);
    if(ans==INF){
        cout<<-1<<endl;
    }
    else {
        cout<<ans<<endl;
    }
}

int main(){
    //ios_base::sync_with_stdio(false);
    //cin.tie(NULL);
    frep;
    while(cin>>W>>H and W!=0 and H!=0){
        memset(M,0,sizeof(M));
        rep(0,i,H){
            rep(0,j,W){
                cin>>M[i][j];
                if(M[i][j]==2){
                    Sx=i,Sy=j;
                }
            }
        }
        ans=INF;
        solve();
    }
    frepC;
    sys;
    return 0;
}

