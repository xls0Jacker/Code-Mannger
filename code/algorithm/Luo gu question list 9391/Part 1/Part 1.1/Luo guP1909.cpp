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

void solve(){
    int n;
    cin>>n;
    int num,value;
    int Min=1e9+7;
    Rep(1,i,3){
        cin>>num>>value;
        int v=value*ceil(n/1.0/num);
        Min=min(Min,v);
    }
    cout<<Min<<endl;
}

int main(){
    frep;
    solve();
    frepC;
    sys;
    return 0;
}

