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
int H_8=8*60;
int H_24=24*60;
double s,v;
void solve(){
    cin>>s>>v;
    int Mint=H_24+H_8-ceil(s/v)-10;
    int h,m;
    if(Mint>=H_24) Mint-=H_24;
    h=Mint/60;
    m=Mint%60;
    if(h<10){
        if(m<10) cout<<0<<h<<":"<<0<<m<<endl;
        else cout<<0<<h<<":"<<m<<endl;
    }
    else{
        if(m<10) cout<<h<<":"<<0<<m<<endl;
        else cout<<h<<":"<<m<<endl;
    }
}

int main(){
    frep;
    solve();
    frepC;
    sys;
    return 0;
}

