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
const int MAX=1e6;
int N;
float a[MAX],M;
void solve(){
    cin>>N>>M;
    Rep(1,i,N){
        cin>>a[i];
    }
    Rep(1,i,N){
        if(a[i]<M){
            cout<<"On Sale! ";
            printf("%.1lf\n",a[i]);
        }
    }
}

int main(){
    frep;
    solve();
    frepC;
    sys;
    return 0;
}

