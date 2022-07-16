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

void solve(){
    double sum=0;
    double n=0;
    int k;
    cin>>k;
    while(1){
        n++;
        sum+=1/n;
        if(sum>k){
            break;
        }
    }
    cout<<n<<endl;
}

int main(){
    frep;
    solve();
    frepC;
    sys;
    return 0;
}

