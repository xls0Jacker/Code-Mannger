#include"bits/stdc++.h"
#define rep(a,i,n) for(int i=a;i<n;i++)
#define per(a,i,n) for(int i=n;i>a;i--)
#define Rep(a,i,n) for(int i=a;i<=n;i++)
#define Per(a,i,n) for(int i=n;i>=a;i--)
#define frep freopen("in.txt","r",stdin)
#define frepC freopen("CON","r",stdin)
#define sys system("pause")
using namespace std;
//Topo Sort
const int MAX=5e3+2;
const int mod=80112002;
int n,m;
vector<int>eg[MAX];

void add_edge(int a,int b){
    eg[a].push_back(b);
}

int ind[MAX],outd[MAX];//出度和入度
int Num[MAX];//当前结点边数目
void solve(){
    cin>>n>>m;
    int x,y;
    Rep(1,i,m){
        cin>>x>>y;
        add_edge(x,y);
        outd[x]++;//左节点出度
        ind[y]++;//右节点入度
    }
    queue<int>q;
    Rep(1,i,n){
        if(!ind[i]){
            Num[i]=1;
            q.push(i);
        }
    }
    while(!q.empty()){
        int u=q.front();
        q.pop();
        for(auto v:eg[u]){
            ind[v]--;
            //增加内容
            Num[v]=(Num[v]+Num[u])%mod;
            //End
            if(!ind[v]) q.push(v);
        }
    }
    int Ans=0;
    Rep(1,i,n){
        if(!outd[i]) Ans=(Ans+Num[i])%mod;//可能有多个最佳消费者
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

