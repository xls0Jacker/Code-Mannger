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
//线段上的格点数
//-1e9<=x1,x2,y1,y2<=1e9

//辗转相除法
int gcd(int a,int b){//O(log max(a,b))
    if(b==0) return a;
    return gcd(b,a%b);
}

int a,b,c,d;

void solve(){
    if(a==c and b==d){
        cout<<0<<endl;
        return;
    }
    cout<<gcd(abs(a-c),abs(b-d))-1<<endl;
}

int main(){
    //ios_base::sync_with_stdio(false);
    //cin.tie(NULL);
    frep;
    cin>>a>>b>>c>>d;
    solve();
    frepC;
    sys;
    return 0;
}

