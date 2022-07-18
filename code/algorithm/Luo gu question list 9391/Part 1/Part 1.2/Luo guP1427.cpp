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
const int MAX=1e7;
int a[MAX];
void solve(){
    int tmp;
    cin>>tmp;
    int cnt=0;
    while(tmp!=0){
        a[++cnt]=tmp;
        cin>>tmp;
    }
    Per(1,i,cnt){
        cout<<a[i]<<" ";
    }
    cout<<endl;
}

int main(){
    frep;
    solve();
    frepC;
    sys;
    return 0;
}

