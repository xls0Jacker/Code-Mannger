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
string Fancy(string a){
    string s="";
    for (int i = 1; i < a.size(); i++) {
        if (a[i] % 2 == a[i-1] % 2) {
        s += max(a[i], a[i-1]);
        }
    }
    return s;
}
void solve(){
    string a,b;
    cin>>a>>b;
    a=Fancy(a);
    b=Fancy(b);
    if(a!=b) cout<<a<<endl<<b<<endl;
    else cout<<a<<endl;
}

int main(){
    frep;
    solve();
    frepC;
    sys;
    return 0;
}

