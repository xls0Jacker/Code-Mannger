#include"bits/stdc++.h"
#define rep(a,i,n) for(int i=a;i<n;i++)
#define per(a,i,n) for(int i=n;i>a;i--)
#define Rep(a,i,n) for(int i=a;i<=n;i++)
#define Per(a,i,n) for(int i=n;i>=a;i--)
#define frep freopen("in.txt","r",stdin)
#define frepC freopen("CON","r",stdin)
#define sys system("pause")
using namespace std;
const int MAX_N=110;
const int MAX_M=100010;
int n,m;
int S[MAX_N][MAX_N];
int Way[MAX_M];

void solve(){
    cin>>n>>m;
    Rep(1,i,m){
        cin>>Way[i];
    }
    Rep(1,i,n){
        Rep(1,j,n){
            cin>>S[i][j];
        }
    }
    Rep(1,k,n){
        Rep(1,j,n){
            Rep(1,i,n){
                S[i][j]=min(S[i][j],S[i][k]+S[k][j]);
            }
        }
    }
    int Ans=0;
    Rep(2,i,m){
        Ans+=S[Way[i-1]][Way[i]];
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

