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
const int MAX_N=1000,MAX_M=1000;

//思路：  
//将致病的细胞周围d区域内的格子标记为1，
//计算机器人在不走出格子且不被蒸发的最小步数。

int n,m,sx,sy,d;

void solve(){
  if((sx-1>d and m-sy>d) or (n-sx>d and sy-1>d) ) {
    cout<<n+m-2<<endl;
  } else {
    cout<<-1<<endl;
  }
}

int main(){
    //ios_base::sync_with_stdio(false);
    //cin.tie(NULL);
    frep;
    int t;
    cin>>t;
    while(t--) {
      cin>>n>>m>>sx>>sy>>d;
      solve();
    }
    frepC;
    sys;
    return 0;
}

