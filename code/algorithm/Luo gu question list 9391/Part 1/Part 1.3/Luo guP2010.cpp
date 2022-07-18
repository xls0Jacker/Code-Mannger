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
int i,j,n,m,a,b,c,sum,ans;
int s[13]={0,31,29,31,30,31,30,31,31,30,31,30,31};
void solve(){
    cin>>n>>m;
    for (i=1;i<=12;i++)
        for (j=1;j<=s[i];j++){
            c=(j%10)*1000+(j/10)*100+(i%10)*10+(i/10);//计算前四位//也是后四位来算的
            sum=c*10000+i*100+j;
            if (sum<n||sum>m) continue;//判断该回文串是否在范围内
            ans++;
        }
    cout<<ans<<endl;
}

int main(){
    frep;
    solve();
    frepC;
    sys;
    return 0;
}

