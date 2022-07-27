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
const int MAX_W=21,MAX_H=21;
//Red and Black
//1<=W,H<=20
char M[MAX_W][MAX_H];
int W,H;
int ans;
bool vis[MAX_W][MAX_H];
void dfs(int i,int j){
    if((i<0 or i>=H or j<0 or j>=W) or vis[i][j] or M[i][j]=='#') return;
    ans++;//?
    vis[i][j]=true;
    dfs(i-1,j);
    dfs(i+1,j);
    dfs(i,j-1);
    dfs(i,j+1);
}

void solve(){
    ans=0;
    rep(0,i,H){
        rep(0,j,W){
            if(M[i][j]=='@'){
                dfs(i,j);
            }
        }
    }
    cout<<ans<<endl;
}

int main(){
    //ios_base::sync_with_stdio(false);
    //cin.tie(NULL);
    frep;
    while(cin>>W>>H and W!=0 and H!=0){
        memset(M,0,sizeof(M));
        memset(vis,0,sizeof(vis));
        rep(0,i,H){
            rep(0,j,W){
                cin>>M[i][j];
            }
        }
        solve();
    }
    frepC;
    sys;
    return 0;
}

