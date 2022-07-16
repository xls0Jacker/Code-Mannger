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
    char m;
    cin>>m;
    string str;
    ll sum=0;
    Rep(1,i,n){
        str=to_string(i);
        sum+=count(str.begin(),str.end(),m);
    }
    cout<<sum<<endl;
}

int main(){
    frep;
    solve();
    frepC;
    sys;
    return 0;
}

