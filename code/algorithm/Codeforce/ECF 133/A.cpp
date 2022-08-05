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
const int MAX_N=1e9;
int n;

void solve(){
    int res=n%3;
    if(n==1){
        cout<<2<<endl;
    }
    else if(n%3==0){
        cout<<n/3<<endl;
    }
    else cout<<n/3+1<<endl;
}

int main(){
    //ios_base::sync_with_stdio(false);
    //cin.tie(NULL);
    frep;
    int t;
    cin>>t;
    while(t--){
        cin>>n;
        solve();
    }
    frepC;
    sys;
    return 0;
}

