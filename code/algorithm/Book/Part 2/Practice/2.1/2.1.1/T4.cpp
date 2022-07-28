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
//Curling 2.0
//2<=w<=20 1<=h<=10
//0-->空地
//1-->障碍物
//2-->起点
//3-->终点
int w,h;
int M[MAX_H+1][MAX_W+1];
int Sx,Sy,Gx,Gy;
bool dfs(int x,int y,int cnt){//第x行 第y列 第cnt次人工操作
    bool f1=false;//障碍物查询
    bool f2=false;//终点查询
    rep(x,i,w){//查询列
        if(M[x][i]==1){
            f1=true;
        }
        else if(M[x][i]==2){
            f2=true;
        }
    }
    if(!f){//列没有，查询行
        rep(y,i,h){
            if(M[i][y]==1){
                f1=true;
            }
            else if(M[i][y]==2){
                f2=true;
            }
        }
    }
    if(cnt==10 and !f1) return false;//次数超限 或 所在行和列没有障碍物
    if(f2) return true;
    //查询左端
    rep(0,i,x){
        if(M[x][i]==1){
            M[x][i]=0;
            dfs(x,i+1,cnt+1);
        }
    }
    //查询右端
    rep(x,i,w){
        if(M[x][i]==1){
            M[x][i]=0;
            dfs(x,i-1,cnt+1);
        }
    }
    //查询上端
    rep(0,i,y){
        if(M[i][y]==1){
            M[i][y]=0;
            dfs(i+1,y,cnt+1);
        }
    }
    //查询下端
    rep(y,i,h){
        if(M[i][y]==1){
            M[i][y]=0;
            dfs(i-1,y,cnt+1);
        }
    }
}

void solve(){
    if(dfs(0,0,0)) puts("YES");
    else puts("NO");
}

int main(){
    //ios_base::sync_with_stdio(false);
    //cin.tie(NULL);
    frep;
    while(cin>>w>>h and w!=0 and h!=0){
        memset(M,0,sizeof(M));
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
        solve();
    }
    frepC;
    sys;
    return 0;
}

