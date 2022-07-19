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
int x[20],n,k;//依照题目所设
bool isprime(int n){//判断是否质数
    int s=sqrt(double(n));
    for(int i=2;i<=s;i++){
        if(n%i==0)return false;
    }
    return true;
}
int rule(int left,int nowsum,int s,int e){
    if(!left) return isprime(nowsum);
    int sum=0;
    Rep(s,i,e){
        sum+=rule(left-1,nowsum+x[i],i+1,e);
    }
    return sum;
}
void solve(){
    cin>>n>>k;
    rep(0,i,n)cin>>x[i];
    cout<<rule(k,0,0,n-1)<<endl;//调用递归解决问题
}

int main(){
    //ios_base::sync_with_stdio(false);
    //cin.tie(NULL);
    frep;
    solve();
    frepC;
    sys;
    return 0;
}

