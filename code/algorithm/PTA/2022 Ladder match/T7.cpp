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
//19分
const int MAX=1e4;
bool mp[MAX][MAX];
int n,m;
int q;

void solve(){
    cin>>n>>m>>q;
    bool sign;
    int num;
    Rep(1,i,q){
        cin>>sign>>num;
        if(!sign){//行
            Rep(1,j,m){
                mp[num][j]=1;
            }
        }
        else{//列
            Rep(1,j,n){
                mp[j][num]=1;
            }
        }
    }
    ll ANS=0;
    Rep(1,i,n){
        Rep(1,j,m){
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

