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
const int MAX=1e3;
int n;
int a[MAX];
void solve(){
    cin>>n;
    Rep(1,i,n){
        a[i]=i;
    }
    do{
        Rep(1,i,n){
            printf("%5d",a[i]);
        }
        cout<<endl;
    } while(next_permutation(a+1,a+n+1));
}

int main(){
    frep;
    solve();
    frepC;
    sys;
    return 0;
}
