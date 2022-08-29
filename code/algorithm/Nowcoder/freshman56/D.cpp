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
int prime[MAX_N+1];//第i个素数
bool is_prime[MAX_N+1];//is_prime[i]为true时表示i为素数
int sieve(int n){//O(nloglogn)
    int p=0;//素数的个数
    Rep(0,i,n) is_prime[i]=true;
    is_prime[0]=is_prime[1]=false;
    Rep(2,i,n){
        if(is_prime[i]){
            prime[p++]=i;
            for(int j=i*2;j<=n;j+=i) is_prime[j]=false;
        }
    }
    return p;
}

int total;
void prev() {
  total=sieve(2*1e5);//统计素数个数
}


int n,q;
vector<int> v;


void solve(){
  while(q--) {
    int req;
    cin>>req;
    sort(v.begin(),v.begin()+req);
    rep(0,i,req) {
      if(is_prime[v[i]]) {
        if(find(v.begin(),v.begin()+req,v[i]) != v.end()) continue;
        cout<<v[i]<<endl;
      }
    }
  }
}

int main(){
    //ios_base::sync_with_stdio(false);
    //cin.tie(NULL);
    frep;
    prev();//打素数表
    cin>>n>>q;
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

