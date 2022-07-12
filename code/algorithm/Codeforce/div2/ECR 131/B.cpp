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
    int t;
    cin >> t;
    while (t--) {
    int n;
    cin >> n;
    cout << 2 << '\n';
    for (int i = 1; i <= n; ++i) if (i % 2 != 0)
      for (int j = i; j <= n; j *= 2)
        cout << j << ' ';
    cout << '\n';
    }
}

int main(){
    frep;
    solve();
    frepC;
    sys;
    return 0;
}