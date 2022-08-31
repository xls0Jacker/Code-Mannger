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
const int MAX_N=10;

int n;
vector<int> v;
void solve() {
  bool f=true;
  rep(0,i,v.size()) {
    if(!f) {
      v.erase(v.begin()+i);
    }
    f=false;
  }

  rep(0,i,v.size()) {
    cout<<v[i]<<" ";
  }
  cout<<endl;
}
int main(){
    //ios_base::sync_with_stdio(false);
    //cin.tie(NULL);
    frep;
    cin>>n;
    int tmp;
    rep(0,i,n) {
      cin>>tmp;
      v.push_back(tmp);
    }
    solve();
    frepC;
    sys;
    return 0;
}

