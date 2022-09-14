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
const int MAX_N = 1e6;
int n;
int a[MAX_N + 1];

void solve(){
  int ans = -1;
  priority_queue<int> q;
  rep(0, i, n) {
    q.push(a[i]);
    if(q.top() == a[i])
      ans = i;
  } 

  cout << ans + 1 << endl;
}

int main(){
  //ios_base::sync_with_stdio(false);
  //cin.tie(NULL);
  frep;
  int t;
  cin >> t;
  while(t--) {
    cin >> n;
    memset(a, 0, sizeof a);
    rep(0, i, n) {
      cin >> a[i];
    }
    solve();
  }
  frepC;
  sys;
  return 0;
}

