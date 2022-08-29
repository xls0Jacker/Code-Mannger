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
const int MAX_N=1e5;
int n;
int a[MAX_N+1];
bool check=1;
int _time;
void findu(int pos);
void findd(int pos) {
  if(check == 0) {
    return;
  }
  if(_time == 2) return;
  _time++;
  check = 0;
  rep(pos+1,i,n) {
    if(a[i] <= a[i-1]) continue;
    findu(i);
  }
}

void findu(int pos) {
  if(check == 1) {
    return;
  }
  if(_time == 2) return;
  _time++;
  check = 1;
  rep(pos+1,i,n) {
    if(a[i] >= a[i-1]) continue;
    findd(i);
  }
}

void solve(){
  rep(1,i,n){
    if(a[i] == a[i-1]) continue;
    if(a[i] < a[i-1]) {
      findd(i);
    } else {
      findu(i);
    }
  }
  if(_time == 2) cout<<"No"<<endl;
  else cout<<"Yes"<<endl;
}

int main(){
    //ios_base::sync_with_stdio(false);
    //cin.tie(NULL);
    frep;
    cin>>n;
    rep(0,i,n) {
      cin>>a[i];
    }
    solve();
    frepC;
    sys;
    return 0;
}

