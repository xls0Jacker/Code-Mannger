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

ll n;
void solve(){
  ll a,b,c;
  if(n==1)
    cout << 3 << endl;
  else if((n-1) % 3 != 0){
    a = n - (n - 1) / 3;
    b = a + 1;
    cout << b * b - a * a << endl;
  }else{
    a = (n - 1) / 3;
    b = a + 2;
    cout << b * b - a * a << endl;
  }
}

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  frep;
  cin>>n;
  solve();
  frepC;
  sys;
  return 0;
}
