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
int s,v;
void solve(){
    cin>>s>>v;
    int Mint=(s/v+H_24-H_8)%H_24;
    int tmp=H_8-Mint;
    int h=0,m=0;
    while(tmp-60>=0){
        tmp-=60;
        h++;
    }
    m=tmp;
    cout<<8-h<<":"<<50-m<<endl;
}

int main(){
    frep;
    solve();
    frepC;
    sys;
    return 0;
}

