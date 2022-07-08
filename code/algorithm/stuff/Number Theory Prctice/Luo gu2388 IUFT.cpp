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
//求1!*2!*...*n!末尾有多少个0？
//不是非常懂
void solve(){
    int n;
    cin>>n;
    int ANS=0;
    for(int j=5;j<=n;j*=5){
            ANS += j * (n / j) * (n / j - 1) >> 1;
            ANS += (n / j) * (n % j + 1);
    }
    cout<<ANS<<endl;
}

int main(){
    frep;
    solve();
    frepC;
    sys;
    return 0;
}

