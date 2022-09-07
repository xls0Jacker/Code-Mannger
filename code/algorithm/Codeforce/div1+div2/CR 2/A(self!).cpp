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
const int MAX_N = 2000;
int n;
int a[MAX_N + 1];
void solve(){
  reverse(a, a + n);
  if(a[n-1]==*min_element(a,a+n) or a[0]==*max_element(a,a+n)){
    cout << *max_element(a,a+n) - *min_element(a,a+n) << endl;
  } else if(a[max_element(a,a+n) - a - 1] == *min_element(a,a+n)) {
    cout << *max_element(a,a+n) - *min_element(a,a+n) << endl;
  } else {
    cout << max(*max_element(a,a+n) - a[n-1], a[0] - *min_element(a,a+n)) << endl;
  }
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
    rep(0,i,n) {
      cin >> a[i];
    }
    solve();
  }
  frepC;
  sys;
  return 0;
}

