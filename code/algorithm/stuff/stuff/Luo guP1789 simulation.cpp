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
const int MAX=1e3;
int mp[MAX][MAX];
int n,m,k;//棋盘大小 火把数 萤石数
int xx[]={0,1,-1,0,0,1,1,-1,-1,2,-2,0,0,1,1,2,2,2,2,-1,-1,-2,-2,-2,-2};//火把范围前13位 萤石范围前25位
int yy[]={0,0,0,1,-1,1,-1,1,-1,0,0,2,-2,2,-2,1,-1,2,-2,2,-2,1,-1,2,-2};
void solve(){
    cin>>n>>m>>k;
    int x,y;
    Rep(1,j,m){
        cin>>x>>y;
        Rep(0,i,12){
            int dx=x+xx[i],dy=y+yy[i];
            if(dx>0 and dx<=n and dy>0 and dy<=n){
                mp[dx][dy]=1;
            }
        }
    }
    Rep(1,j,k){
        cin>>x>>y;
        Rep(0,i,24){
            int dx=x+xx[i],dy=y+yy[i];
            if(dx>0 and dx<=n and dy>0 and dy<=n){
                mp[dx][dy]=1;
            }
        }
    }
    int ANS=0;
    Rep(1,i,n){
        Rep(1,j,n){
            if(!mp[i][j]) ANS++;
        }
    }
    cout<<ANS<<endl;
}

int main(){
    frep;
    solve();
    frepC;
    sys;
    return 0;
}

