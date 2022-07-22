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
const int MAX=105;
char c;
int N;
char mp1[MAX][MAX],mp2[MAX][MAX];
void solve(){
    bool f=false;
    rep(0,i,N){
        rep(0,j,N){
            if(mp2[i][j]!=mp1[i][j]){
                f=1;
                break;
            }
        }
    }
    if(!f) cout<<"bu yong dao le"<<endl;
    rep(0,i,N){
        rep(0,j,N){
            if(mp2[i][j]=='@'){
                mp2[i][j]=c;
            }
        }
    }
    rep(0,i,N){
        rep(0,j,N){
            cout<<mp2[i][j];
        }
        cout<<endl;
    }
}

int main(){
    //ios_base::sync_with_stdio(false);
    //cin.tie(NULL);
    frep;
    cin>>c>>N;
    cin.get();
    string s;
    rep(0,i,N){
        getline(cin,s);
        rep(0,j,N){
            mp1[i][j]=s[j];
        }
    }
    rep(0,i,N){
        rep(0,j,N){
            cin>>mp1[i][j];
            mp2[N-i-1][N-j-1]=mp1[i][j];
        }
    }
    solve();
    frepC;
    sys;
    return 0;
}

