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
const int MAX=114514;
int a[MAX];
void solve(){
    Rep(1,i,10){
        cin>>a[i];
    }
    int n;
    cin>>n;
    int cnt=0;
    Rep(1,i,10){
        if(n+30>=a[i]){
            cnt++;
        }
    }
    cout<<cnt<<endl;
}

int main(){
    frep;
    solve();
    frepC;
    sys;
    return 0;
}

