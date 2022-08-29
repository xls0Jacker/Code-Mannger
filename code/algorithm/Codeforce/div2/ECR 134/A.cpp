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
  char a;
  vector<char> v;
  rep(0,i,2) {
    rep(0,j,2) {
      cin>>a;
      v.push_back(a);
    }
  }
  sort(v.begin(),v.end());
  int count=unique(v.begin(),v.end())-v.begin();//不重复个数
  cout<<count-1<<endl;
}

int main(){
    //ios_base::sync_with_stdio(false);
    //cin.tie(NULL);
    frep;
    int t;
    cin>>t;
    while(t--) {
      solve();
    }
    frepC;
    sys;
    return 0;
}

