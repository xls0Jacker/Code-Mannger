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
const int MAX_N=2*1e5;
int a[]={512,256,128,64,32,16,8,4,2};
int n;
void solve(){
  vector<int> v;
    int tmp;
    rep(0,i,n){
      cin>>tmp;
      v.push_back(tmp);
    }
  int m=n;
  ll sum=0;
  while( m>=9 ){
    sort(v.begin(),v.end(),greater());
    rep(0,i,9){
      sum+=a[i]*v[i];
    }
    v.erase(v.begin(),v.begin()+9);
  }
  if( m!=0 ) {
    sort(v.begin(),v.end());
    int j=8;
    rep(0,i,m){
      sum+=a[j]*v[i];
      j--;
    }
  }
  cout<<sum<<endl;
}

int main(){
    //ios_base::sync_with_stdio(false);
    //cin.tie(NULL);
    frep;
    cin>>n;
    solve();
    frepC;
    sys;
    return 0;
}

