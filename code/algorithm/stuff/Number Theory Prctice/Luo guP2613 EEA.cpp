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
const int mod=19260817;
int a,b;
ll x,y;
inline int getint()
{
    int res = 0, ch = getchar();
    while(!isdigit(ch) and ch != EOF)
        ch = getchar();
    while(isdigit(ch))
    {
        res = (res << 3) + (res << 1) + (ch - '0');
        res %= mod;//直接对MOD取余
        ch = getchar();
    }
    return res;
}

void exgcd(int a,int b,ll &x,ll &y){
    if(!b){
        x=1;
        y=0;
        return;
    }
    exgcd(b,a%b,x,y);
    int temp=y;
    y=x-a/b*y;
    x=temp;
}

void solve(){
    a=getint();
    b=getint();
    if(!b){
        cout<<"Angry!"<<endl;
        return;
    }
    exgcd(b,mod,x,y);
    x=(x%mod+mod)%mod;
    ll ANS=a*x%mod;
    cout<<ANS<<endl;
}

int main(){
    frep;
    solve();
    frepC;
    sys;
    return 0;
}

