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
//求解 ax≡1(mod b) 的解//TLE*2
int n,b,x,y;
int exgcd(int a,int b,int &x,int &y){
    if(!b){
        x=1;
        y=0;
        return a;
    }
    int g=exgcd(b,a%b,x,y);
    int y1=y,x1=x;
    x=y1;
    y=x1-(a/b)*y1;
    /*//精简版
    int r=exgcd(b,a%b,x,y);
    int temp;
    y=x-(a/b)*y;
    x=temp;
    */
    return g;
}
void solve(){
    cin>>n>>b;
    Rep(1,i,n){
        int gcd=exgcd(i,b,x,y);
        x=(x%b+b)%b;
        cout<<x<<endl;
    }
}

int main(){
    frep;
    solve();
    frepC;
    sys;
    return 0;
}

