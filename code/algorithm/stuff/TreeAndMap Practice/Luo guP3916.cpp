#include"bits/stdc++.h"
#define sys system("pause")
#define rep(a,i,n) for(int i=a;i<n;i++)
#define per(a,i,n) for(int i=n;i>a;i--)
#define Rep(a,i,n) for(int i=a;i<=n;i++)
#define Per(a,i,n) for(int i=n;i>=a;i--)
#define frep freopen("in.txt","r",stdin)
#define frepC freopen("CON","r",stdin)
using namespace std;
const int MAX=1e5+10;
int n,m;
vector<int>eg[MAX];

void add_edge(int a,int b){//反向建边
    eg[b].push_back(a);
}

int A[MAX];
void dfs(int x,int d){
    if(A[x]) return;
    A[x]=d;
    rep(0,i,eg[x].size()){
        dfs(eg[x][i],d);
    }
}


void solve(){
    cin>>n>>m;
    int x,y;
    Rep(1,i,m){
        cin>>x>>y;
        add_edge(x,y);
    }
    per(0,i,n) dfs(i,i);
    Rep(1,i,n) cout<<A[i]<<" ";
    cout<<endl;
}

int main(){
    frep;
    solve();
    frepC;
    sys;
    return 0;
}

