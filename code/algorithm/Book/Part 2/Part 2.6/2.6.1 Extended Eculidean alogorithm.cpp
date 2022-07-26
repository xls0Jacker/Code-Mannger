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
//双六
//1<=a,b<=1e9
//拓展欧几里得算法
//返回值为gcd(a,b) x,y为满足ax+by=gac(a,b)的解
int extgcd(int a,int b,int &x,int &y){
    int d=a;
    if(b!=0){
        d=extgcd(b,a%b,y,x);
        y-=(a/b)*x;
    }
    else {
        x=1,y=0;
    }
    return d;
}

int _a,_b,x,y;
void solve(){
    int gcd=extgcd(_a,_b,x,y);
    if(gcd!=1){
        cout<<-1<<endl;
        return;
    }
    if(x > 0){
        printf("%d 0 0 %d\n", x, -y);
    }
    else {
        printf("0 %d %d 0\n", y, -x);
    }
}

int main(){
    //ios_base::sync_with_stdio(false);
    //cin.tie(NULL);
    frep;
    cin>>_a>>_b;
    solve();
    frepC;
    sys;
    return 0;
}

