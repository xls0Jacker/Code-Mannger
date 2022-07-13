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
//二分记得sort一遍

int n;
bool check(int m){

}

int binary(){
    int l=-1,r=n;
    while(l+1!=r){
        int m=(l+r)/2;
        if(check(m)){
            l=m;
        }
        else {
            r=m;
        }
    }
    return r;//return m//看情况
}

void solve(){

}

int main(){
    frep;
    solve();
    frepC;
    sys;
    return 0;
}

