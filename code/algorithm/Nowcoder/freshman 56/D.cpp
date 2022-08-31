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
const int MAX_N=2e7;
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

int n,q;
int a[MAX_N+1];
bool vis[MAX_N+1];// 标记这个数是否出现过
int ans[MAX_N+1];// 前i位数的答案数组

void solve(){
  int pr=0;
  rep(0,i,n) {
    if(a[i] <= MAX_N) vis[a[i]] = true;
    while(vis[prime[pr]]) pr++;//出现的最小质数更新
    ans[i] = prime[pr];
  }

  int x;
  while(q--) {
    cin>>x;
    x--;// 化为从0开始的下标
    cout<<ans[x]<<endl;
  }
}

int main(){
    //ios_base::sync_with_stdio(false);
    //cin.tie(NULL);
    frep;
    sieve(2e7);//打质数表
    cin>>n>>q;
    rep(0,i,n) {
      cin>>a[i];
    }
    solve();
    frepC;
    sys;
    return 0;
}

