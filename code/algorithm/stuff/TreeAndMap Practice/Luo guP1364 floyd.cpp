#include"bits/stdc++.h"
#define rep(a,i,n) for(int i=a;i<n;i++)
#define per(a,i,n) for(int i=n;i>a;i--)
#define Rep(a,i,n) for(int i=a;i<=n;i++)
#define Per(a,i,n) for(int i=n;i>=a;i--)
#define frep freopen("in.txt","r",stdin)
#define frepC freopen("CON","r",stdin)
#define sys system("pause")
using namespace std;
const int MAX=1e3;
int S[MAX][MAX];
int n;

void Init(){
    Rep(1,i,n){
        Rep(1,j,n){
            if(i==j) S[i][j]=0;
            else S[i][j]=0x3f3f3f3f;
        }
    }
}

void add_edge(int a,int b){
    S[a][b]=S[b][a]=1;
}

int Popula[MAX];
void solve(){
    cin>>n;
    Init();
    int peo,x,y;
    Rep(1,i,n){
        cin>>peo>>x>>y;
        Popula[i]=peo;
        if(x) add_edge(i,x);
        if(y) add_edge(i,y);
    }
    Rep(1,k,n){
        Rep(1,j,n){
            Rep(1,i,n){
                S[i][j]=min(S[i][j],S[i][k]+S[k][j]);
            }
        }
    }
    int ANS=0x3f3f3f3f;
    Rep(1,i,n){
        int sum=0;
        Rep(1,j,n){
            sum+=S[i][j]*Popula[j];
        }
        if(ANS>sum){
            ANS=sum;
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

