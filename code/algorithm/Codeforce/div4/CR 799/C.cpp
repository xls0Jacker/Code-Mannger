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
char mp[20][20];
bool vis[20][20];
int xx[]={-1,-1,1,1};
int yy[]={1,-1,1,-1};
struct st{
    int x,y;
};
void bfs(){
    Rep(2,i,7){
        Rep(2,j,7){
            st res;
            res.x=i;res.y=j;
            int cnt=0;
            rep(0,i,4){
            int dx=res.x+xx[i];
            int dy=res.y+yy[i];
            if(mp[dx][dy]=='#'){
                cnt++;
            }
        }
        if(cnt==4) {
            cout<<res.x<<" "<<res.y<<endl;
            return;
        }
        }
    }
    
}

int t;
void solve(){
    cin>>t;
    Rep(1,i,t){
        Rep(1,i,8){
            Rep(1,j,8){
                cin>>mp[i][j];
            }
        }
        bfs();
    }
}

int main(){
    frep;
    solve();
    frepC;
    sys;
    return 0;
}

