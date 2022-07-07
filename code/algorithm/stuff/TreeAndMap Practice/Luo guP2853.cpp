#include"bits/stdc++.h"
#define rep(a,i,n) for(int i=a;i<n;i++)
#define per(a,i,n) for(int i=n;i>a;i--)
#define Rep(a,i,n) for(int i=a;i<=n;i++)
#define Per(a,i,n) for(int i=n;i>=a;i--)
#define frep freopen("in.txt","r",stdin)
#define frepC freopen("CON","r",stdin)
#define sys system("pause")
using namespace std;
const int MAX=1e4;
int k,n,m;
vector<int>eg[MAX];

void add_edge(int a,int b){
    eg[a].push_back(b);
}

bool vis[MAX];
int Yes[MAX];
int Pos[MAX];
void dfs(int s){
    vis[s]=1;
    Yes[s]++;
    for(auto i:eg[s]){
        if(!vis[i]){
            dfs(i);
        }
    }
}

void solve(){
    cin>>k>>n>>m;
    int pos;
    Rep(1,i,k){
        cin>>pos;
        Pos[pos]++;//可能一个位置有多头奶牛
    }
    int x,y;
    Rep(1,i,m){
        cin>>x>>y;
        add_edge(x,y);
    }
    Rep(1,i,n){
        if(Pos[i]){
            Pos[i]--;
            memset(vis,0,sizeof(vis));
            dfs(i);
        }
        if(Pos[i]!=0) i--;//保持此处循环至所有奶牛走光
    }
    int Ans=0;
    Rep(1,i,n){
        if(Yes[i]==k) Ans++;
    }
    cout<<Ans<<endl;
}

int main(){
    frep;
    solve();
    frepC;
    sys;
    return 0;
}

