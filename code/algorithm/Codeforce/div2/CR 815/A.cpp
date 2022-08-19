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

ll a,b,c,d;
void solve(){
    ll mul1=a*d;
    ll mul2=c*b;
    if(mul1==mul2) {
        cout<<0<<endl;
    } else if((mul1!=0 and mul2%mul1==0) or (mul2!=0 and mul1%mul2==0)) {
        cout<<1<<endl;
    } else {
        cout<<2<<endl;
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //frep;
    int t;
    cin>>t;
    while(t--){
        cin>>a>>b>>c>>d;
        solve();
    }
    //frepC;
    //sys;
    return 0;
}

