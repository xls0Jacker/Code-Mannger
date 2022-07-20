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
//硬币问题
//0<=C1,C2,C5,C10,C50,C100,C500<=1e9 0<=A<=1e9
//优先使用面值大的硬币
const int V[]={1,5,10,50,100,500};
int C[6],A;
void solve(){//O(1)做法
    int ans=0;
    Per(0,i,5){
        int t=min(A/V[i],C[i]);
        A-=t*V[i];
        ans+=t;
    }
    cout<<ans<<endl;
}

int main(){
    //ios_base::sync_with_stdio(false);
    //cin.tie(NULL);
    frep;
    rep(0,i,6){
        cin>>C[i];
    }
    cin>>A;
    solve();
    frepC;
    sys;
    return 0;
}

