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
//求斐波拉契数列 an=a(n-1)+a(n-2) a0=0 a1=1 n>1
int fib(int n){//O(2^n)做法
    if(n<=1) return n;
    return fib(n-1)+fib(n-2);
}
void solve(){ 
    int n;
    cin>>n;
    cout<<fib(n)<<endl;
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

