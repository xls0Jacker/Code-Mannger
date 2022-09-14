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

int n;
void solve(){
  vector<int> v;
  Rep(1, i, n) {
    v.push_back(i);
  }

  if(n % 2 == 0) {
    reverse(v.begin(), v.begin() + n - 2);
    rep(0, i, n) {
      cout << v[i] << " ";
    }
  } else {
    swap(v[0], v[n - 3]);
    reverse(v.begin(), v.begin() + n - 3);
    rep(0, i, n) {
      cout << v[i] << " ";
    }
  }

  cout << endl;
}

int main(){
  //ios_base::sync_with_stdio(false);
  //cin.tie(NULL);
  frep;
  int t;
  cin >> t;
  while(t--) {
    cin >> n;
    solve();
  }
  frepC;
  sys;
  return 0;
}

