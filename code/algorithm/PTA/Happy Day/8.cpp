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
const int MAX=1e4+10;
int a1,a2;
int n;
int a[MAX];
int r=2;//右边界
void simplify(int x,int y){
    int z;
    z=x*y;
    if(z>=10){
        int tmp1=z%10;
        int tmp2=z/10;
        r++,a[r]=tmp2;
        r++,a[r]=tmp1;
    }
    else{
        r++,a[r]=z;
    }
}

void solve(){
    cin>>a1>>a2>>n;
    a[1]=a1; a[2]=a2;
    int i=1,j=2;
    while(r<=n){
        simplify(a[i],a[j]);
        i++,j++;
    }
    Rep(1,i,n){
        cout<<a[i];
        if(i!=n) cout<<" ";
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

