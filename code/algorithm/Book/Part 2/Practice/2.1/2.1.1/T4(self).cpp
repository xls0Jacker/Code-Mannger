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
int w,h;
int M[MAX_H+1][MAX_W+1];
int Sx,Sy,Gx,Gy;
int ans;
bool vis[MAX_H+1][MAX_W+1][4];//每一个点的上下左右是否走过//0-左 1-右 2-上 3-下
void dfs(int x,int y,int cnt){//第x行 第y列 返回值为第cnt次人工操作
    cout<<"cnt: "<<cnt<<endl;
    cout<<"Pos: "<<x<<" "<<y<<endl;
    rep(0,i,h){
        rep(0,j,w){
            cout<<M[i][j]<<" ";
        }
        cout<<endl;
    }
    bool f1=false;//障碍物查询
    bool f2=false;//终点查询
    rep(0,i,w){//查询列
        if(M[x][i]==1){
            f1=true;
        }
        else if(M[x][i]==3){//还需处理终点路上是否有障碍物
            if(i<y){
                bool f=false;
                rep(i,j,y){
                    if(M[x][j]==1){
                        f=true;
                        break;
                    }
                }
                if(!f) f2=true;
            }
            else if(i>y){
                bool f=false;
                rep(y,j,i){
                    if(M[x][j]==1){
                        f=true;
                        break;
                    }
                }
                if(!f) f2=true;
            }
        }
    }
    if(!f1){//列没有，查询行
        rep(0,i,h){
            if(M[i][y]==1){
                f1=true;
            }
            else if(M[i][y]==3){
                if(i<x){
                    bool f=false;
                    rep(i,j,x){
                        if(M[j][y]==1){
                            f=true;
                            break;
                        }
                    }
                    if(!f) f2=true;
                }
                else if(i>x){
                    bool f=false;
                    rep(x,j,i){
                        if(M[j][y]==1){
                            f=true;
                            break;
                        }
                    }
                    if(!f) f2=true;
                }
            }
        }
    }
    cout<<"下一次是否可以到达终点： "<<f2<<endl;
    if(f2) {
        ans=min(ans,(cnt+1));//更新最小答案
        cout<<"当前答案:"<<ans<<endl;
        return;
    }
    if(cnt>=10 and !f1) return;//次数超限 且 所在行和列没有障碍物
    //查询左端
    if(!vis[x][y][0])
    rep(0,i,y){
        if(M[x][i]==1){
            M[x][i]=0;
            vis[x][y][0]=true;
            M[x][i+1]=6;
            dfs(x,i+1,cnt+1);
            //vis[x][y][0]=false;
            M[x][i]=1;
            //M[x][i+1]=0;
        }
    }
    //查询右端
    if(!vis[x][y][1])
    rep(y,i,w){
        if(M[x][i]==1){
            M[x][i]=0;
            vis[x][y][1]=true;
            M[x][i-1]=6;
            dfs(x,i-1,cnt+1);
            //vis[x][y][1]=false;
            M[x][i]=1;
            //M[x][i-1]=0;
        }
    }
    //查询上端
    if(!vis[x][y][2])
    rep(0,i,x){
        if(M[i][y]==1){
            M[i][y]=0;
            vis[x][y][2]=true;
            M[i+1][y]=6;
            dfs(i+1,y,cnt+1);
            //vis[x][y][2]=false;
            M[i][y]=1;
            //M[i+1][y]=0;
        }
    }
    //查询下端
    if(!vis[x][y][3])
    rep(x,i,h){
        if(M[i][y]==1){
            M[i][y]=0;
            vis[x][y][3]=true;
            M[i-1][y]=6;
            dfs(i-1,y,cnt+1);
            //vis[x][y][3]=false;
            M[i][y]=1;//还原
            //M[i-1][y]=0;
        }
    }
    //cnt未到10次四周无障碍物和终点
    cnt--;
    return;
}

void solve(){
    cout<<"地图大小："<<"h: "<<h<<" w: "<<w<<endl;
    dfs(Sx,Sy,0);
    cout<<ans<<endl;
    cout<<"ANS上面（悲）"<<endl;
    cout<<"寄！"<<endl;
}

int main(){
    //ios_base::sync_with_stdio(false);
    //cin.tie(NULL);
    frep;
    while(cin>>w>>h and w!=0 and h!=0){
        memset(M,0,sizeof(M));
        memset(vis,0,sizeof(vis));
        rep(0,i,h){
            rep(0,j,w){
                cin>>M[i][j];
                if(M[i][j]==2){
                    Sx=i,Sy=j;
                }
                else if(M[i][j]==3){
                    Gx=i,Gy=j;
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

