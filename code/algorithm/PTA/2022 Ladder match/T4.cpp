#include"bits/stdc++.h"
#define rep(a,i,n) for(int i=a;i<n;i++)
#define per(a,i,n) for(int i=n;i>a;i--)
#define Rep(a,i,n) for(int i=a;i<=n;i++)
#define Per(a,i,n) for(int i=n;i>=a;i--)
#define frep freopen("in.txt","r",stdin)
#define frepC freopen("CON","r",stdin)
#define sys system("pause")
typedef unsigned long long ll;
using namespace std;
ll factorial(ll n){
    ll f;
    // if(n==0 or n==1)  
    //     f=1;  
    // else  
    //     f=factorial(n-1)*n;  
    // return f;  
    return (n==0 or n==1)?f=1:f=factorial(n-1)*n; 
}
ll a,b;
void solve(){
    cin>>a>>b;
    ll sum=a+b;
    ll ANS=factorial(sum);
    cout<<ANS<<endl;
}

int main(){
    frep;
    solve();
    frepC;
    sys;
    return 0;
}

