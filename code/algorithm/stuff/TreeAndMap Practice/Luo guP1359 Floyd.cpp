#include"bits/stdc++.h"
#define sys system("pause")
#define rep(a,i,n) for(int i=a;i<n;i++)
#define per(a,i,n) for(int i=n;i>a;i--)
#define Rep(a,i,n) for(int i=a;i<=n;i++)
#define Per(a,i,n) for(int i=n;i>=a;i--)
#define frep freopen("in.txt","r",stdin)
#define frepC freopen("CON","r",stdin)
using namespace std;
//Floyd

//邻接矩阵
const int MAX_N=210,MAX_M=210;
int S[MAX_N][MAX_M];

//stuff
int n;
void solve(){
    memset(S,0x3f,sizeof(S));
    cin>>n;
    Rep(1,i,n){
        Rep(i+1,j,n){
            cin>>S[i][j];
        }
    }
    //Floyd
    Rep(1,k,n){
        Rep(1,j,n){
            Rep(1,i,n){
                S[i][j]=min(S[i][j],S[i][k]+S[k][j]);
            }
        }
    }
    cout<<S[1][n]<<endl;
}

int main(){
    frep;
    solve();
    frepC;
    sys;
    return 0;
}

