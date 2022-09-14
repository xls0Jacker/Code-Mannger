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
const int MAX_M=2*1e5;
int m;
int M[3][MAX_M+1];
int vis[3][MAX_M+1];
int xx[]={-1,1,0,0};
int yy[]={0,0,1,-1};

void dfs(int x,int y,int T){
    bool f=false;
    rep(0,i,2){
        rep(0,j,m){
            if(vis[i][j]!=-1){
                f=1;
                break;
            }
        }
    }
    if(!f){
        cout<<T<<endl;
        return;
    }
    rep(0,i,4){
        int dx=x+xx[i],dy=y+yy[i];
        if(dx<0 or dy<0 or dx>=2 or dy>=m or T<=vis[dx][dy] or vis[dx][dy]==-1) continue;
        vis[dx][dy]=-1;//标记走过
        dfs(dx,dy,T+1);
    }
    dfs(x,y,T+1);//原地待机
}

void solve(){

}

int main(){
    //ios_base::sync_with_stdio(false);
    //cin.tie(NULL);
    frep;
    int t;
    cin>>t;
    while(t--){
        memset(M,0,sizeof(M));
        memset(vis,0,sizeof(vis));
        cin>>m;
        rep(0,i,2){
            rep(0,j,m){
                cin>>M[i][j];
            }
        }
        solve();
    }
    frepC;
    sys;
    return 0;
}

