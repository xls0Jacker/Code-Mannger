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
const int MAX=25;
string s[MAX];
bool cmp(string a,string b){
    return a+b>b+a;//防止321>32//保证相邻最大
}

void solve(){
    int n;
    cin>>n;
    Rep(1,i,n){
        cin>>s[i];
    }
    sort(s+1,s+n+1,cmp);
    Rep(2,i,n){
        s[1]+=s[i];
    }
    cout<<s[1]<<endl;
}

int main(){
    frep;
    solve();
    frepC;
    sys;
    return 0;
}

