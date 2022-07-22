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
int Pa,Pb;
int v[5];
int a,b;
void solve(){
    if(Pa>Pb){
        if(a>=1){
            cout<<"The winner is a: "<<Pa<<" + "<<a<<endl;
        }
        else {
            cout<<"The winner is b: "<<Pb<<" + "<<b<<endl;
        }
    }
    else {
        if(b==3){
            cout<<"The winner is b: "<<Pb<<" + "<<b<<endl;
        }
        else {
            cout<<"The winner is a: "<<Pa<<" + "<<a<<endl;
        }
    }
}

int main(){
    //ios_base::sync_with_stdio(false);
    //cin.tie(NULL);
    frep;
    cin>>Pa>>Pb;
    rep(0,i,3){
        cin>>v[i];
        if(v[i]==0){
            a++;
        }
        else {
            b++;
        }
    }
    solve();
    frepC;
    sys;
    return 0;
}

