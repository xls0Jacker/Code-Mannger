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
    string s;
    getline(cin,s);
    s.erase(remove(s.begin(),s.end(),' '),s.end());
    cout<<s.size()<<endl;
}

int main(){
    frep;
    solve();
    frepC;
    sys;
    return 0;
}

