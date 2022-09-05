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

ll N, D;
priority_queue<ll> a;
void solve(){
  ll ans=0;
  while(N > 0){
    N -= (D / a.top() + 1);
    if (N < 0)
      break;
    a.pop();
    ans++;
  }
  cout << ans << endl;
}

int main(){
  //ios_base::sync_with_stdio(false);
  //cin.tie(NULL);
  frep;
  cin >> N >> D;
  ll temp;
  rep(0, i, N) {
    cin>>temp;
    a.push(temp);
  }
  solve();
  frepC;
  sys;
  return 0;
}
